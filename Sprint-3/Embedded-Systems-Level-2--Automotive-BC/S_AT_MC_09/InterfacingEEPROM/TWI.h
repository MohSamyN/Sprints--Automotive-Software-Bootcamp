#ifndef TWI_H_
#define TWI_H_

#include "STD_TYPES.h"
#include "BIT_MANIPULATE.h"

#define F_CPU																				8000000u

typedef enum {TWI_FOSC_OVER_1, TWI_FOSC_OVER_4, TWI_FOSC_OVER_16, TWI_FOSC_OVER_64} enuTWIPrescalerSelect_t;
typedef enum {TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_ENABLE_GENERAL_CALL_RECOGNITION} enuTWIGeneralCallRecognitionEnable_t;
typedef enum {TWI_DISABLE_ACKNOWLEDGE, TWI_ENABLE_ACKNOWLEDGE} enuTWIEnableAcknowledgeBit_t;
typedef enum 
{
	TWI_MASTER_START_CONDITION_CODE													= 0x08,
	TWI_MASTER_RESTART_CONDITION_CODE												= 0x10,
	TWI_MASTER_SLA_W_ACK_CONDITION_CODE												= 0x18,
	TWI_MASTER_SLA_W_NACK_CONDITION_CODE											= 0x20,
	TWI_MASTER_DATA_W_ACK_CONDITION_CODE											= 0x28,
	TWI_MASTER_DATA_W_NACK_CONDITION_CODE											= 0x30,
	TWI_MASTER_ARBITRATION_LOST_CONDITION_CODE									= 0x38,
	TWI_MASTER_SLA_R_ACK_CONDITION_CODE												= 0x40,
	TWI_MASTER_SLA_R_NACK_CONDITION_CODE											= 0x48,
	TWI_MASTER_DATA_R_ACK_CONDITION_CODE											= 0x50,
	TWI_MASTER_DATA_R_NACK_CONDITION_CODE											= 0x58,
	TWI_SLAVE_SLA_W_ACK_CONDITION_CODE												= 0x60,
	TWI_SLAVE_ARBITRATION_LOST_SLA_W_ACK_RECEIVED_CONDITION_CODE			= 0x68,
	TWI_SLAVE_GENERAL_CALL_CONDITION_ACK_CODE										= 0x70,
	TWI_SLAVE_ARBITRATION_LOST_GENERAL_CALL_ACK_RECEIVED_CONDITION_CODE	= 0x78,
	TWI_SLAVE_PREVIOUSLY_SLA_W_ACK_CONDITION_CODE								= 0x80,
	TWI_SLAVE_PREVIOUSLY_SLA_W_NACK_CONDITION_CODE								= 0x88,
	TWI_SLAVE_PREVIOUSLY_GENERAL_CALL_ACK_CONDITION_CODE						= 0x90,
	TWI_SLAVE_PREVIOUSLY_GENERAL_CALL_NACK_CONDITION_CODE						= 0x98,
	TWI_SLAVE_STOP_OR_REPEATED_START_CONDITION_CODE								= 0xA0,
	TWI_SLAVE_SLA_R_ACK_CONDITION_CODE												= 0xA8,
	TWI_SLAVE_ARBITRATION_LOST_CONDITION_CODE										= 0xB0,
	TWI_SLAVE_DATA_ACK_CONDITION_CODE												= 0xB8,
	TWI_SLAVE_DATA_NACK_CONDITION_CODE												= 0xC0,
	TWI_SLAVE_LAST_DATA_RECEIVED_ACK_CONDITION_CODE								= 0xC8,
	TWI_NO_RELEVANT_STATE_CONDITION_CODE											= 0xF8,
	TWI_BUS_ERROR_CONDITION_CODE														= 0x00				  				  
} enuTWIStatus_t;	

/*************************************************************************************************
* Parameters	: u8TWIBitRate, enuTWIPrescalerSelect
* Return Value	: enuErrorStatus_t
* Description  : Initialize the TWI module as Master according to the configuration parameters
*************************************************************************************************/
enuErrorStatus_t TWI_MasterInit(uint8_t u8TWIBitRate, enuTWIPrescalerSelect_t enuTWIPrescalerSelect);
/*************************************************************************************************
* Parameters	: u8TWISlaveAddress, enuTWIGeneralCallRecognitionEnable, enuTWIEnableAcknowledgeBit
* Return Value	: enuErrorStatus_t
* Description  : Initialize the TWI module as Slave according to the configuration parameters
*************************************************************************************************/
enuErrorStatus_t TWI_SlaveInit(uint8_t u8TWISlaveAddress, enuTWIGeneralCallRecognitionEnable_t enuTWIGeneralCallRecognitionEnable, 
										 enuTWIEnableAcknowledgeBit_t enuTWIEnableAcknowledgeBit);
/*************************************************************************************************
* Parameters	: u8Data
* Return Value	: enuErrorStatus_t
* Description  : Write the input data on the TWI bus
*************************************************************************************************/										 
enuErrorStatus_t TWI_Write(uint8_t u8Data);
/*************************************************************************************************
* Parameters	: pu8Data
* Return Value	: enuErrorStatus_t
* Description  : Read the data from the TWI bus
*************************************************************************************************/
enuErrorStatus_t TWI_Read(uint8_t* pu8Data);
/*************************************************************************************************
* Parameters	: penuTWIStatus
* Return Value	: enuErrorStatus_t
* Description  : Check the current status of the TWI module
*************************************************************************************************/
enuErrorStatus_t TWI_CheckStatus(enuTWIStatus_t* penuTWIStatus);
/*************************************************************************************************
* Parameters	: void
* Return Value	: enuErrorStatus_t
* Description  : Send a start condition on the TWI bus
*************************************************************************************************/
enuErrorStatus_t TWI_Start(void);
/*************************************************************************************************
* Parameters	: void
* Return Value	: enuErrorStatus_t
* Description  : Send a stop condition on the TWI bus
*************************************************************************************************/
enuErrorStatus_t TWI_Stop(void);
/*************************************************************************************************
* Parameters	: void
* Return Value	: enuErrorStatus_t
* Description  : Wait for any device to be called 
*************************************************************************************************/
enuErrorStatus_t TWI_Listen(void);

#endif /* TWI_H_ */