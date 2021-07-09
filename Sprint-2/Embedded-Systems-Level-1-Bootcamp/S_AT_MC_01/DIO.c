#include "DIO.h"


/* Internal Macros */
#define DIO_PINS_NO										32u
#define DIO_DIRECTION_STATES							2u
#define DIO_PORT_NO(PIN_NO)								(PIN_NO / 8)
#define DIO_PIN_NO(PIN_NO)								(PIN_NO % 8)

typedef enum {DIO_INIT_UNDONE, DIO_INIT_DONE} enuDIOState_t;
static enuDIOState_t aenuDIOGroupState[DIO_GROUPS_NO] = {DIO_INIT_UNDONE};

typedef enum {PORTA, PORTB, PORTC, PORTD} enuDIOPorts_t;


/* Input Parameter(s): void																			*
 * Return Value		: enuErrorStatus (enum)														*
 * Description			: Initialize all the DIO groups according to the configuration	*/
enuErrorStatus_t DIO_Init(void)
{
	enuErrorStatus_t enuRetVar;
	const strDIOConfigType_t *pstrConfig;
	uint8_t u8LoopIndex;
	uint8_t u8ErrorFlag = TRUE;
	
	for(u8LoopIndex = 0; ((u8LoopIndex < DIO_GROUPS_NO) && (u8ErrorFlag == TRUE)); u8LoopIndex++)
	{
		pstrConfig = &astrDIOConfigParameters[u8LoopIndex];
		if((pstrConfig->enuPinNo < DIO_PINS_NO) && (pstrConfig->enuPinDir < DIO_DIRECTION_STATES))
		{
			switch(DIO_PORT_NO(pstrConfig->enuPinNo))
			{
				case PORTA:
				{
					/* Setting the direction of data [Input / Output] */
					ASSIGN_BIT(DDRA_R, DIO_PIN_NO(pstrConfig->enuPinNo), pstrConfig->enuPinDir);
					/* Selecting whether a pull-up resistor is connected to the selected pin or not */
					ASSIGN_BIT(PORTA_R, DIO_PIN_NO(pstrConfig->enuPinNo), pstrConfig->enuPullupResEn);					
				}
				break;
				case PORTB:
				{
					/* Setting the direction of data [Input / Output] */
					ASSIGN_BIT(DDRB_R, DIO_PIN_NO(pstrConfig->enuPinNo), pstrConfig->enuPinDir);
					/* Selecting whether a pull-up resistor is connected to the selected pin or not */
					ASSIGN_BIT(PORTB_R, DIO_PIN_NO(pstrConfig->enuPinNo), pstrConfig->enuPullupResEn);
				}
				break;
				case PORTC:
				{
					/* Setting the direction of data [Input / Output] */
					ASSIGN_BIT(DDRC_R, DIO_PIN_NO(pstrConfig->enuPinNo), pstrConfig->enuPinDir);
					/* Selecting whether a pull-up resistor is connected to the selected pin or not */
					ASSIGN_BIT(PORTC_R, DIO_PIN_NO(pstrConfig->enuPinNo), pstrConfig->enuPullupResEn);
				}
				break;
				case PORTD:
				{
					/* Setting the direction of data [Input / Output] */
					ASSIGN_BIT(DDRD_R, DIO_PIN_NO(pstrConfig->enuPinNo), pstrConfig->enuPinDir);
					/* Selecting whether a pull-up resistor is connected to the selected pin or not */
					ASSIGN_BIT(PORTD_R, DIO_PIN_NO(pstrConfig->enuPinNo), pstrConfig->enuPullupResEn);
				}
				break;
				default:
				{
					u8ErrorFlag = FALSE;
				}			
			}
			aenuDIOGroupState[u8LoopIndex] = DIO_INIT_DONE;
		}
		else
		{
			u8ErrorFlag = FALSE;
		}
	}
	if(u8ErrorFlag == TRUE)
	{
		enuRetVar = E_OK;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/* Input Parameter(s): u8GroupID (uint8_t) - u8Data (uint8_t)				*
 * Return Value		: enuErrorStatus (enum)										*
 * Description			: Write a digital value into the selected DIO pin	*/
enuErrorStatus_t DIO_Write(uint8_t u8GroupId, uint8_t u8Data)
{
	enuErrorStatus_t enuRetVar;
	const strDIOConfigType_t *pstrConfig;
	
	if((u8GroupId < DIO_GROUPS_NO) && (aenuDIOGroupState[u8GroupId] == DIO_INIT_DONE) && (astrDIOConfigParameters[u8GroupId].enuPinDir == OUTPUT))
	{
		pstrConfig = &astrDIOConfigParameters[u8GroupId];
		switch(DIO_PORT_NO(pstrConfig->enuPinNo))
		{
			case PORTA:
			{
				/* Writing the value into the corresponding pin */
				ASSIGN_BIT(PORTA_R, DIO_PIN_NO(pstrConfig->enuPinNo), u8Data);				
				enuRetVar = E_OK;
			}
			break;
			case PORTB:
			{
				/* Writing the value into the corresponding pin */
				ASSIGN_BIT(PORTB_R, DIO_PIN_NO(pstrConfig->enuPinNo), u8Data);
				enuRetVar = E_OK;
			}
			break;
			case PORTC:
			{
				/* Writing the value into the corresponding pin */
				ASSIGN_BIT(PORTC_R, DIO_PIN_NO(pstrConfig->enuPinNo), u8Data);
				enuRetVar = E_OK;
			}
			break;
			case PORTD:
			{
				/* Writing the value into the corresponding pin */
				ASSIGN_BIT(PORTD_R, DIO_PIN_NO(pstrConfig->enuPinNo), u8Data);
				enuRetVar = E_OK;
			}
			break;
			default:
			{
				enuRetVar = E_ERROR;			
			}
		}
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/* Input Parameter(s): u8GroupID (uint8_t) - u8Data (uint8_t)				*
 * Return Value		: enuErrorStatus (enum)										*
 * Description			: Read a digital value from the selected DIO pin	*/
enuErrorStatus_t DIO_Read(uint8_t u8GroupId, uint8_t* pu8Data)
{
	enuErrorStatus_t enuRetVar;
	const strDIOConfigType_t *pstrConfig;
	
	if((u8GroupId < DIO_GROUPS_NO) && (aenuDIOGroupState[u8GroupId] == DIO_INIT_DONE) && (astrDIOConfigParameters[u8GroupId].enuPinDir == INPUT))
	{
		pstrConfig = &astrDIOConfigParameters[u8GroupId];
		switch(DIO_PORT_NO(pstrConfig->enuPinNo))
		{
			case PORTA:
			{
				/* Reading the value from the corresponding pin */
				*pu8Data = GET_BIT(PINA_R, DIO_PIN_NO(pstrConfig->enuPinNo));
				enuRetVar = E_OK;
			}		
			break;	
			case PORTB:
			{
				/* Reading the value from the corresponding pin */
				*pu8Data = GET_BIT(PINB_R, DIO_PIN_NO(pstrConfig->enuPinNo));
				enuRetVar = E_OK;
			}
			break;
			case PORTC:
			{
				/* Reading the value from the corresponding pin */
				*pu8Data = GET_BIT(PINC_R, DIO_PIN_NO(pstrConfig->enuPinNo));
				enuRetVar = E_OK;
			}
			break;
			case PORTD:
			{
				/* Reading the value from the corresponding pin */
				*pu8Data = GET_BIT(PIND_R, DIO_PIN_NO(pstrConfig->enuPinNo));
				enuRetVar = E_OK;
			}
			break;
			default:
			{
				enuRetVar = E_ERROR;
			}
		}
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/* Input Parameter(s): u8GroupID (uint8_t)										*
 * Return Value		: enuErrorStatus (enum)										*
 * Description			: Toggle the digital value of the selected DIO pin	*/
enuErrorStatus_t DIO_Toggle(uint8_t u8GroupId)
{
	enuErrorStatus_t enuRetVar;
	const strDIOConfigType_t *pstrConfig;
	uint8_t u8Data;
	
	if((u8GroupId < DIO_GROUPS_NO) && (aenuDIOGroupState[u8GroupId] == DIO_INIT_DONE) && (astrDIOConfigParameters[u8GroupId].enuPinDir == OUTPUT))
	{
		pstrConfig = &astrDIOConfigParameters[u8GroupId];
		switch(DIO_PORT_NO(pstrConfig->enuPinNo))
		{
			case PORTA:
			{
				/* Reading the value from the corresponding pin */
				u8Data = GET_BIT(PINA_R, DIO_PIN_NO(pstrConfig->enuPinNo));
				/* Writing the value into the corresponding pin */
				ASSIGN_BIT(PORTA_R, DIO_PIN_NO(pstrConfig->enuPinNo), ~u8Data);
				enuRetVar = E_OK;
			}
			break;
			case PORTB:
			{
				/* Reading the value from the corresponding pin */
				u8Data = GET_BIT(PINB_R, DIO_PIN_NO(pstrConfig->enuPinNo));
				/* Writing the value into the corresponding pin */
				ASSIGN_BIT(PORTB_R, DIO_PIN_NO(pstrConfig->enuPinNo), ~u8Data);
				enuRetVar = E_OK;
			}
			break;
			case PORTC:
			{
				/* Reading the value from the corresponding pin */
				u8Data = GET_BIT(PINC_R, DIO_PIN_NO(pstrConfig->enuPinNo));
				/* Writing the value into the corresponding pin */
				ASSIGN_BIT(PORTC_R, DIO_PIN_NO(pstrConfig->enuPinNo), ~u8Data);
				enuRetVar = E_OK;
			}
			break;
			case PORTD:
			{
				/* Reading the value from the corresponding pin */
				u8Data = GET_BIT(PIND_R, DIO_PIN_NO(pstrConfig->enuPinNo));
				/* Writing the value into the corresponding pin */
				ASSIGN_BIT(PORTD_R, DIO_PIN_NO(pstrConfig->enuPinNo), ~u8Data);
				enuRetVar = E_OK;
			}
			break;
			default:
			{
				enuRetVar = E_ERROR;
			}
		}
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;	
}