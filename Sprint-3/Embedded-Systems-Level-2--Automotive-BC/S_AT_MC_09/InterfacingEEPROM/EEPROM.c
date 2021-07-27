#include "EEPROM.h"


/* Internal Macros */
#define EEPROM_TWI_BIT_RATE_MIN_VALUE										9u
#define EEPROM_TWI_BIT_RATE_MAX_VALUE										128u
#define EEPROM_TWI_PRESCALER_SELECT_MIN_VALUE							-1l
#define EEPROM_TWI_PRESCALER_SELECT_MAX_VALUE							4u
#define EEPROM_SLAVE_ADDRESS													0xA0
#define EEPROM_PAGE_NUMBER(ADDRESS)											((ADDRESS >> 7) & 0x0E)
#define EEPROM_WRITE_BIT_VALUE												0u
#define EEPROM_READ_BIT_VALUE													1u

typedef enum {EEPROM_INIT_UNDONE, EEPROM_INIT_DONE} enuEEPROMState_t;
static enuEEPROMState_t enuEEPROMState = EEPROM_INIT_UNDONE;


/*************************************************************************************************
* Parameters	: u8TWIBitRate, enuTWIPrescalerSelect
* Return Value	: enuErrorStatus_t
* Description  : Initialize the TWI module to start using the external EEPROM
*************************************************************************************************/
enuErrorStatus_t EEPROM_Init(uint8_t u8TWIBitRate, enuTWIPrescalerSelect_t enuTWIPrescalerSelect)
{
	enuErrorStatus_t enuRetVar = E_OK;
	
	if((u8TWIBitRate > EEPROM_TWI_BIT_RATE_MIN_VALUE)							&& (u8TWIBitRate < EEPROM_TWI_BIT_RATE_MAX_VALUE) &&
		(enuTWIPrescalerSelect > EEPROM_TWI_PRESCALER_SELECT_MIN_VALUE)	&& (enuTWIPrescalerSelect < EEPROM_TWI_PRESCALER_SELECT_MAX_VALUE))
	{	
		/* Initializing the TWI module as master with the input configuration parameters */
		TWI_MasterInit(u8TWIBitRate, enuTWIPrescalerSelect);
		enuEEPROMState = EEPROM_INIT_DONE;
		enuRetVar = E_OK;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/*************************************************************************************************
* Parameters	: u16Address, u8Data
* Return Value	: enuErrorStatus_t
* Description  : Initialize one DIO pin according to the configuration
*************************************************************************************************/
enuErrorStatus_t EEPROM_Write(uint16_t u16Address, uint8_t u8Data)
{
	enuErrorStatus_t enuRetVar;
	enuTWIStatus_t enuTWIStatus;
	
	if(enuEEPROMState == EEPROM_INIT_DONE)
	{
		/* Sending a start condition to start communication */
		TWI_Start();
		/* Checking the status of the TWI module */
		TWI_CheckStatus(&enuTWIStatus);
		if(enuTWIStatus == TWI_MASTER_START_CONDITION_CODE)
		{
			/* Sending the slave address of EEPROM + the page number + write condition */
			TWI_Write(EEPROM_SLAVE_ADDRESS | EEPROM_PAGE_NUMBER(u16Address) | EEPROM_WRITE_BIT_VALUE);
			/* Checking the status of the TWI module */
			TWI_CheckStatus(&enuTWIStatus);
			if(enuTWIStatus == TWI_MASTER_SLA_W_ACK_CONDITION_CODE)
			{
				/* Sending the byte address of the desired location in the EEPROM */
				TWI_Write((uint8_t)u16Address);
				/* Checking the status of the TWI module */
				TWI_CheckStatus(&enuTWIStatus);
				if(enuTWIStatus == TWI_MASTER_DATA_W_ACK_CONDITION_CODE)
				{
					/* Sending the desired data in order to be written in this specific location */
					TWI_Write(u8Data);
					/* Checking the status of the TWI module */		
					TWI_CheckStatus(&enuTWIStatus);
					if(enuTWIStatus == TWI_MASTER_DATA_W_ACK_CONDITION_CODE)
					{
						/* Sending a stop condition to stop communication */
						TWI_Stop();	
						enuRetVar = E_OK;
					}
					else
					{
						enuRetVar = E_ERROR;
					}
				}
				else
				{
					enuRetVar = E_ERROR;
				}
			}
			else
			{
				enuRetVar = E_ERROR;
			}
		}
		else
		{
			enuRetVar = E_ERROR;		
		}
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;	
}

/*************************************************************************************************
* Parameters	: u16Address, pu8Data
* Return Value	: enuErrorStatus_t
* Description  : Initialize one DIO pin according to the configuration
*************************************************************************************************/
enuErrorStatus_t EEPROM_Read(uint16_t u16Address, uint8_t* pu8Data)
{
	enuErrorStatus_t enuRetVar;
	enuTWIStatus_t enuTWIStatus;
	
	if(enuEEPROMState == EEPROM_INIT_DONE)
	{
		/* Sending a start condition to start communication */		
		TWI_Start();
		/* Checking the status of the TWI module */
		TWI_CheckStatus(&enuTWIStatus);
		if(enuTWIStatus == TWI_MASTER_START_CONDITION_CODE)
		{		
			/* Sending the slave address of EEPROM + the page number + write condition */			
			TWI_Write(EEPROM_SLAVE_ADDRESS | EEPROM_PAGE_NUMBER(u16Address) | EEPROM_WRITE_BIT_VALUE);
			/* Checking the status of the TWI module */
			TWI_CheckStatus(&enuTWIStatus);
			if(enuTWIStatus == TWI_MASTER_SLA_W_ACK_CONDITION_CODE)
			{
				/* Sending the byte address of the desired location in the EEPROM */				
				TWI_Write((uint8_t)u16Address);
				/* Checking the status of the TWI module */		
				TWI_CheckStatus(&enuTWIStatus);
				if(enuTWIStatus == TWI_MASTER_DATA_W_ACK_CONDITION_CODE)
				{
					/* Sending a restart condition to start communication */		
					TWI_Start();
					/* Checking the status of the TWI module */				
					TWI_CheckStatus(&enuTWIStatus);
					if(enuTWIStatus == TWI_MASTER_RESTART_CONDITION_CODE)
					{
						/* Sending the slave address of EEPROM + the page number + read condition */
						TWI_Write(EEPROM_SLAVE_ADDRESS | EEPROM_PAGE_NUMBER(u16Address) | EEPROM_READ_BIT_VALUE);
						/* Checking the status of the TWI module */				
						TWI_CheckStatus(&enuTWIStatus);
						if(enuTWIStatus == TWI_MASTER_SLA_R_ACK_CONDITION_CODE)
						{
							/* Reading the desired data from this specific location */
							TWI_Read(pu8Data);
							/* Checking the status of the TWI module */				
							TWI_CheckStatus(&enuTWIStatus);
							if((enuTWIStatus == TWI_MASTER_DATA_R_ACK_CONDITION_CODE) || (enuTWIStatus == TWI_MASTER_DATA_R_NACK_CONDITION_CODE))
							{
								/* Sending a stop condition to stop communication */
								TWI_Stop();
								enuRetVar = E_OK;
							}
							else
							{
								enuRetVar = E_ERROR;								
							}
						}
						else
						{
							enuRetVar = E_ERROR;
						}
					}
					else
					{
						enuRetVar = E_ERROR;
					}
				}
				else
				{
					enuRetVar = E_ERROR;
				}
			}
			else
			{
				enuRetVar = E_ERROR;
			}
		}
		else
		{
			enuRetVar = E_ERROR;		
		}
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;	
}