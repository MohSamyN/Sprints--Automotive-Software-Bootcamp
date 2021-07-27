#include "TWI.h"

typedef volatile uint8_t* const pu8TWIRegisterAddress;

/* TWI Registers */
#define TWCR_R													*((pu8TWIRegisterAddress) 0x56)
#define TWDR_R													*((pu8TWIRegisterAddress) 0x23)
#define TWAR_R													*((pu8TWIRegisterAddress) 0x22)
#define TWSR_R													*((pu8TWIRegisterAddress) 0x21)
#define TWBR_R													*((pu8TWIRegisterAddress) 0x20)

/* Internal Macros */
#define TWI_BIT_RATE_MIN_VALUE							9u
#define TWI_BIT_RATE_MAX_VALUE							128u
#define TWI_PRESCALER_SELECT_MIN_VALUE					-1l
#define TWI_PRESCALER_SELECT_MAX_VALUE					4u
#define TWI_SLAVE_ADDRESS_MIN_VALUE						0x00
#define TWI_SLAVE_ADDRESS_MAX_VALUE						0xEF
#define TWI_PRESCALER_SELECT_START_BIT					0u
#define TWI_PRESCALER_SELECT_MASK						0x03
#define TWI_EN_BIT											2u
#define TWI_START_CONDITION_BIT							5u
#define TWI_INT_FLAG_BIT									7u
#define TWI_SLA_SHIFT_BY_ONE								1u
#define TWI_WRITE_CONDITION_BIT							0u
#define TWI_STOP_CONDITION_BIT							4u
#define TWI_SLAVE_ADDRESS_BYTE							0u
#define TWI_LOCATION_ADDRESS_BYTE						1u
#define TWI_EN_ACK_BIT										6u
#define TWI_TWGCE_BIT										0u
#define TWI_TWEA_BIT											6u
#define TWI_GET_STATUS(REG)								(REG & 0xF8)

typedef enum {TWI_INIT_UNDONE, TWI_INIT_DONE} enuTWIState_t;
static enuTWIState_t enuTWIState = TWI_INIT_UNDONE;


/*************************************************************************************************
* Parameters	: u8TWIBitRate, enuTWIPrescalerSelect
* Return Value	: enuErrorStatus_t
* Description  : Initialize the TWI module as Master according to the configuration parameters
*************************************************************************************************/
enuErrorStatus_t TWI_MasterInit(uint8_t u8TWIBitRate, enuTWIPrescalerSelect_t enuTWIPrescalerSelect)
{
	enuErrorStatus_t enuRetVar;

	if((u8TWIBitRate > TWI_BIT_RATE_MIN_VALUE)						&& (u8TWIBitRate < TWI_BIT_RATE_MAX_VALUE) && 
		(enuTWIPrescalerSelect > TWI_PRESCALER_SELECT_MIN_VALUE)	&& (enuTWIPrescalerSelect < TWI_PRESCALER_SELECT_MAX_VALUE))
	{	   
		/* Selecting the bit rate and the prescaler of the bit rate generator unit according to the following equation: *
		 * SCL_Frequency = CPU_Clock_Frequency / (16 + (2 * (BitRate) * (4 ^ PrescalerSelect)))							*/
		TWBR_R = u8TWIBitRate;
		ASSIGN_BITS(TWSR_R, TWI_PRESCALER_SELECT_START_BIT,  enuTWIPrescalerSelect, TWI_PRESCALER_SELECT_MASK);
		/* Enabling the TWI module */
		SET_BIT(TWCR_R, TWI_EN_BIT);
		enuTWIState = TWI_INIT_DONE;
		enuRetVar = E_OK;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;	
}

/*************************************************************************************************
* Parameters	: u8TWISlaveAddress, enuTWIGeneralCallRecognitionEnable, enuTWIEnableAcknowledgeBit
* Return Value	: enuErrorStatus_t
* Description  : Initialize the TWI module as Slave according to the configuration parameters
*************************************************************************************************/
enuErrorStatus_t TWI_SlaveInit(uint8_t u8TWISlaveAddress, enuTWIGeneralCallRecognitionEnable_t enuTWIGeneralCallRecognitionEnable,
										 enuTWIEnableAcknowledgeBit_t enuTWIEnableAcknowledgeBit)
{
	enuErrorStatus_t enuRetVar;

	if((u8TWISlaveAddress >= TWI_SLAVE_ADDRESS_MIN_VALUE)	&& (u8TWISlaveAddress <= TWI_SLAVE_ADDRESS_MAX_VALUE)																			&&
		((enuTWIGeneralCallRecognitionEnable == TWI_DISABLE_GENERAL_CALL_RECOGNITION) || (enuTWIGeneralCallRecognitionEnable == TWI_ENABLE_GENERAL_CALL_RECOGNITION))	&&
		((enuTWIEnableAcknowledgeBit == TWI_DISABLE_ACKNOWLEDGE)								|| (enuTWIEnableAcknowledgeBit == TWI_ENABLE_ACKNOWLEDGE)))
	{	   
		/* Adding the slave address of the TWI unit */
		TWAR_R = u8TWISlaveAddress;
		/* Assigning whether recognition of general call is enabled or not */
		ASSIGN_BIT(TWAR_R, TWI_TWGCE_BIT, enuTWIGeneralCallRecognitionEnable);
		/* Selecting whether the acknowledge bit is enabled or not */
		ASSIGN_BIT(TWCR_R, TWI_TWEA_BIT, enuTWIEnableAcknowledgeBit);
		/* Enabling the TWI module */
		SET_BIT(TWCR_R, TWI_EN_BIT);
		enuTWIState = TWI_INIT_DONE;
		enuRetVar = E_OK;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;	
}

/*************************************************************************************************
* Parameters	: u8Data
* Return Value	: enuErrorStatus_t
* Description  : Write the input data on the TWI bus
*************************************************************************************************/
enuErrorStatus_t TWI_Write(uint8_t u8Data)
{
	enuErrorStatus_t enuRetVar;

	if(enuTWIState == TWI_INIT_DONE)
	{
		/* Loading the input data byte into the data register */
		TWDR_R = u8Data;
		/* Clearing the TWI interrupt flag */
		SET_BIT(TWCR_R, TWI_INT_FLAG_BIT);
		/* Enabling the TWI module */
		SET_BIT(TWCR_R, TWI_EN_BIT);
		/* Clearing the previous start condition */
		CLEAR_BIT(TWCR_R, TWI_START_CONDITION_BIT);
		/* Waiting for the data to be transmitted */
		while(IS_BIT_CLEAR(TWCR_R, TWI_INT_FLAG_BIT));
		enuRetVar = E_OK;		
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/*************************************************************************************************
* Parameters	: pu8Data
* Return Value	: enuErrorStatus_t
* Description  : Read the data from the TWI bus
*************************************************************************************************/
enuErrorStatus_t TWI_Read(uint8_t* pu8Data)
{
	enuErrorStatus_t enuRetVar;

	if(enuTWIState == TWI_INIT_DONE)
	{
		/* Clearing the TWI interrupt flag */
		SET_BIT(TWCR_R, TWI_INT_FLAG_BIT);
		/* Enabling the TWI module */
		SET_BIT(TWCR_R, TWI_EN_BIT);
		/* Waiting for the data to be received */
		while(IS_BIT_CLEAR(TWCR_R, TWI_INT_FLAG_BIT));
		/* Fetching the value of the received data from the data register */
		*pu8Data = TWDR_R;
		enuRetVar = E_OK;		
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/*************************************************************************************************
* Parameters	: penuTWIStatus
* Return Value	: enuErrorStatus_t
* Description  : Check the current status of the TWI module
*************************************************************************************************/
enuErrorStatus_t TWI_CheckStatus(enuTWIStatus_t* penuTWIStatus)
{
	enuErrorStatus_t enuRetVar;

	if(enuTWIState == TWI_INIT_DONE)
	{
		/* Checking the current status of the TWI module */
		*penuTWIStatus = TWI_GET_STATUS(TWSR_R);
		enuRetVar = E_OK;		
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/*************************************************************************************************
* Parameters	: void
* Return Value	: enuErrorStatus_t
* Description  : Send a start condition on the TWI bus
*************************************************************************************************/
enuErrorStatus_t TWI_Start(void)
{
	enuErrorStatus_t enuRetVar;

	if(enuTWIState == TWI_INIT_DONE)
	{
		/* Initiating the transmission operation by a START condition bit */
		SET_BIT(TWCR_R, TWI_START_CONDITION_BIT);
		/* Clearing the TWI interrupt flag */
		SET_BIT(TWCR_R, TWI_INT_FLAG_BIT);
		/* Enabling the TWI module */
		SET_BIT(TWCR_R, TWI_EN_BIT);
		/* Waiting for the start bit to be transmitted */
		while(IS_BIT_CLEAR(TWCR_R, TWI_INT_FLAG_BIT));
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/*************************************************************************************************
* Parameters	: void
* Return Value	: enuErrorStatus_t
* Description  : Send a stop condition on the TWI bus
*************************************************************************************************/
enuErrorStatus_t TWI_Stop(void)
{
	enuErrorStatus_t enuRetVar;

	if(enuTWIState == TWI_INIT_DONE)
	{
		/* Clearing the TWI interrupt flag */
		SET_BIT(TWCR_R, TWI_INT_FLAG_BIT);
		/* Enabling the TWI module */
		SET_BIT(TWCR_R, TWI_EN_BIT);
		/* Terminating the transmission operation by a STOP condition bit */
		SET_BIT(TWCR_R, TWI_STOP_CONDITION_BIT);
		enuRetVar = E_OK;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/*************************************************************************************************
* Parameters	: void
* Return Value	: enuErrorStatus_t
* Description  : Wait for any device to be called
*************************************************************************************************/
enuErrorStatus_t TWI_Listen(void)
{
	enuErrorStatus_t enuRetVar;

	if(enuTWIState == TWI_INIT_DONE)
	{
		/* Waiting for the module to be addressed */
		while(IS_BIT_CLEAR(TWCR_R, TWI_INT_FLAG_BIT));		
		enuRetVar = E_OK;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}



