#include "UART.h"


typedef volatile uint8_t* const pu8UARTRegisterAddress;

#define UBRRH_R																	*((pu8UARTRegisterAddress) 0x40)
#define UCSRC_R																	*((pu8UARTRegisterAddress) 0x40)
#define UDR_R																		*((pu8UARTRegisterAddress) 0x2C)
#define UCSRA_R																	*((pu8UARTRegisterAddress) 0x2B)
#define UCSRB_R																	*((pu8UARTRegisterAddress) 0x2A)
#define UBRRL_R																	*((pu8UARTRegisterAddress) 0x29)

/* Internal Macros */
#define UART_BAUDRATE_MIN_VALUE												0u
#define UART_BAUDRATE_MAX_VALUE												1000000u
#define UART_CHARACTER_SIZE_MIN_VALUE										-1l
#define UART_CHARACTER_SIZE_MAX_VALUE										8u
#define UART_CHARACTER_SIZE_STATE4_VALUE									4u
#define UART_CHARACTER_SIZE_STATE5_VALUE									5u
#define UART_CHARACTER_SIZE_STATE6_VALUE									6u
#define UART_STOP_BIT_SELECT_MIN_VALUE										-1l
#define UART_STOP_BIT_SELECT_MAX_VALUE										2u
#define UART_PARITY_MODE_MIN_VALUE											-1l
#define UART_PARITY_MODE_MAX_VALUE											4u
#define UART_PARITY_MODE_STATE1_VALUE										1u
#define UART_BAUDRATE_REGISTER_VALUE(FREQUENCY, BAUDRATE)			((FREQUENCY / (16ul * BAUDRATE)) - 1)
#define UART_BAUDRATE_MSB_REGISTER_ACCESS_VALUE							255u
#define UART_URSEL_BIT															7u
#define UART_UBRRH_START_BIT													0u
#define UART_UBRRH_VALUE(BAUDRATE)											((BAUDRATE & 0x0F00) >> 8)
#define UART_UBRRH_MASK															0x0F
#define UART_UBRRL_START_BIT													0u
#define UART_UBRRL_VALUE(BAUDRATE)											(BAUDRATE & 0x00FF)
#define UART_UBRRL_MASK															0xFF
#define UART_UPM_START_BIT														4u
#define UART_UPM_MASK															0x03
#define UART_USBS_BIT															3u
#define UART_UCSZ_START_BIT													1u
#define UART_UCSZ_2LSB_VALUES(CHARACTER_SIZE)							(CHARACTER_SIZE & 0x03)
#define UART_UCSZ_MASK															0x03
#define UART_UCSZ2_BIT															2u
#define UART_UCSZ2_VALUE(CHARACTER_SIZE)									((CHARACTER_SIZE & 0x04) >> 2)
#define UART_TXEN_BIT															3u
#define UART_TXB8_BIT															0u
#define UART_TXB8_VALUE(DATA_FRAME)											((DATA_FRAME & 0x0100) >> 8)
#define UART_TXC_BIT																6u
#define UART_RXEN_BIT															4u
#define UART_RXC_BIT																7u
#define UART_DATA_BIT_EIGHT													8u
#define UART_RXB8_BIT															1u
#define UART_MAX_STRING_SIZE													255u

typedef enum {UART_INIT_UNDONE, UART_INIT_DONE} enuUARTGroupState_t;
static enuUARTGroupState_t enuUARTGroupState = UART_INIT_UNDONE;

static enuUARTCharacterSize_t enuUARTCharacterSizeState;


/*************************************************************************************************
* Parameters	: u32UARTBaudrate, enuUARTCharacterSize, enuUARTStopBitSelect, enuUARTParityMode,
*					  enuUARTDoubleTransmissionSpeed
* Return Value	: enuErrorStatus_t
* Description  : Initialize UART module according to the configuration
*************************************************************************************************/
enuErrorStatus_t UART_Init(uint32_t u32UARTBaudrate, enuUARTCharacterSize_t enuUARTCharacterSize, enuUARTStopBitSelect_t enuUARTStopBitSelect, enuUARTParityMode_t enuUARTParityMode)
{
	enuErrorStatus_t enuRetVar;
	volatile uint16_t u16BaudrateValue;
	
	/* Checking that all configurations are correctly configured */
	if((u32UARTBaudrate >= UART_BAUDRATE_MIN_VALUE)												&& (u32UARTBaudrate <= UART_BAUDRATE_MAX_VALUE)						&&
		(enuUARTCharacterSize > UART_CHARACTER_SIZE_MIN_VALUE)								&& (enuUARTCharacterSize < UART_CHARACTER_SIZE_MAX_VALUE)		&&
		(enuUARTCharacterSize != UART_CHARACTER_SIZE_STATE4_VALUE)							&& (enuUARTCharacterSize != UART_CHARACTER_SIZE_STATE5_VALUE)	&& (enuUARTCharacterSize != UART_CHARACTER_SIZE_STATE6_VALUE)	&&
		(enuUARTStopBitSelect > UART_STOP_BIT_SELECT_MIN_VALUE)								&& (enuUARTStopBitSelect < UART_STOP_BIT_SELECT_MAX_VALUE)		&&
		(enuUARTParityMode > UART_PARITY_MODE_MIN_VALUE)										&& (enuUARTParityMode < UART_PARITY_MODE_MAX_VALUE)				&& (enuUARTParityMode != UART_PARITY_MODE_STATE1_VALUE))
	{
		/* Calculating the value loaded into the UBRR register according to the following formula: *
		 * Baudrate Register Value [UBRR] = (Oscillator Frequency [Fosc] / (16 * Baudrate)) - 1    */
		u16BaudrateValue = UART_BAUDRATE_REGISTER_VALUE(F_CPU, u32UARTBaudrate);
		/* Checking if Baudrate value is greater than 255 to access the 4 MSB of UBRRH register */
		if(u16BaudrateValue > UART_BAUDRATE_MSB_REGISTER_ACCESS_VALUE)
		{
			/* Disabling the UCSRC register to have access on UBRRH register */
			CLEAR_BIT(UCSRC_R, UART_URSEL_BIT);
			/* Enabling the UBRRH register to use it */
			SET_BIT(UBRRH_R, UART_URSEL_BIT);
			/* Inserting the 4 MSBs into the UBRRH register */
			ASSIGN_BITS(UBRRH_R, UART_UBRRH_START_BIT, UART_UBRRH_VALUE(u16BaudrateValue), UART_UBRRH_MASK);
		}
		else
		{
		}
		/* Inserting the rest of LSBs into the UBRRL register */
		ASSIGN_BITS(UBRRL_R, UART_UBRRL_START_BIT, UART_UBRRL_VALUE(u16BaudrateValue), UART_UBRRL_MASK);
		/* Enabling the UCSRC register to have access on it */
		SET_BIT(UCSRC_R, UART_URSEL_BIT);
		/* Selecting whether the parity mode is disabled, even or odd parity */
		ASSIGN_BITS(UCSRC_R, UART_UPM_START_BIT, enuUARTParityMode, UART_UPM_MASK);
		/* Selecting whether the stop bit is one bit or two bits */
		ASSIGN_BIT(UCSRC_R, UART_USBS_BIT,  enuUARTStopBitSelect);
		/* Selecting the character size (ranging from 5 bits to 9 bits) */
		ASSIGN_BITS(UCSRC_R, UART_UCSZ_START_BIT, UART_UCSZ_2LSB_VALUES(enuUARTCharacterSize), UART_UCSZ_MASK);
		ASSIGN_BIT(UCSRB_R, UART_UCSZ2_BIT, UART_UCSZ2_VALUE(enuUARTCharacterSize));
		enuUARTCharacterSizeState = enuUARTCharacterSize;
		enuUARTGroupState = UART_INIT_DONE;		
		enuRetVar = E_OK;			
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/*************************************************************************************************
* Parameters	: u16Data
* Return Value	: enuErrorStatus_t
* Description  : Initiate a data transmission from UART module to external module
*************************************************************************************************/
enuErrorStatus_t UART_SendData(uint16_t u16Data)
{
	enuErrorStatus_t enuRetVar;
	
	if(enuUARTGroupState == UART_INIT_DONE)
	{
		/* Enabling the transmit enable to start transmission */
		SET_BIT(UCSRB_R, UART_TXEN_BIT);
		/* Inserting the first byte data to be transmitted into the data register */
		UDR_R = (uint8_t)u16Data;
		/* Checking if the the frame is of 9-bit long, to add the ninth bit into UCSRB register */
		if(enuUARTCharacterSizeState == UART_NINE_CHARACTER_BITS)
		{
			ASSIGN_BIT(UCSRB_R, UART_TXB8_BIT, UART_TXB8_VALUE(u16Data));
		}
		else
		{
		}
		/* Waiting for the data until it has successfully been transmitted */
		while(IS_BIT_CLEAR(UCSRA_R, UART_TXC_BIT));
		/* Clearing transmission complete flag */
		SET_BIT(UCSRA_R, UART_TXC_BIT);
		/* Disabling the transmit enable to stop transmission */
		CLEAR_BIT(UCSRB_R, UART_TXEN_BIT);	
		enuRetVar = E_OK;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/*************************************************************************************************
* Parameters	: *pu16Data
* Return Value	: enuErrorStatus_t
* Description  : Initiate a data reception on UART module from external module
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveData(uint16_t* pu16Data)
{
	enuErrorStatus_t enuRetVar;
	
	if(enuUARTGroupState == UART_INIT_DONE)
	{
		/* Enabling the receive enable to start reception */
		SET_BIT(UCSRB_R, UART_RXEN_BIT);
		/* Waiting for the data until it has successfully been received */
		while(IS_BIT_CLEAR(UCSRA_R, UART_RXC_BIT));
		/* Clearing transmission complete flag */
		SET_BIT(UCSRA_R, UART_RXC_BIT);
		/* Inserting the received data into the data variable */
		*pu16Data = UDR_R;
		/* Checking if the the frame is of 9-bit long, fetch the ninth bit into the data array */
		if(enuUARTCharacterSizeState == UART_NINE_CHARACTER_BITS)
		{
			ASSIGN_BIT(*pu16Data, UART_DATA_BIT_EIGHT, GET_BIT(UCSRB_R, UART_RXB8_BIT));
		}
		else
		{
		}		
		/* Disabling the receive enable to stop reception */
		CLEAR_BIT(UCSRB_R, UART_RXEN_BIT);
		enuRetVar = E_OK;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;	
}

/*************************************************************************************************
* Parameters	: *pu16Data
* Return Value	: enuErrorStatus_t
* Description  : Initiate a data transmission from UART module to external module
*************************************************************************************************/
enuErrorStatus_t UART_SendString(uint8_t* pu8String)
{
	enuErrorStatus_t enuRetVar;
	uint8_t u8LoopIndex = 0;
	uint8_t u8Flag = LOW;	
	
	if(enuUARTGroupState == UART_INIT_DONE)
	{
		/* Enabling the transmit enable to start transmission */
		SET_BIT(UCSRB_R, UART_TXEN_BIT);
		do
		{		
			/* Inserting the data to be transmitted into the data register */
			UDR_R = *(pu8String + u8LoopIndex);
			/* Waiting for the data until it has successfully been transmitted */
			while(IS_BIT_CLEAR(UCSRA_R, UART_TXC_BIT));
			/* Clearing transmission complete flag */
			SET_BIT(UCSRA_R, UART_TXC_BIT);
			/* Incrementing the index of the input string */
			u8LoopIndex++;
			/* Checking if the next element in the input string is \n or \r */
			if((*(pu8String + u8LoopIndex) == '\n') || (*(pu8String + u8LoopIndex) == '\r') || (u8LoopIndex == UART_MAX_STRING_SIZE))
			{
				/* Inserting the data to be transmitted into the data register */
				UDR_R = *(pu8String + u8LoopIndex);
				/* Waiting for the data until it has successfully been transmitted */
				while(IS_BIT_CLEAR(UCSRA_R, UART_TXC_BIT));
				/* Clearing transmission complete flag */
				SET_BIT(UCSRA_R, UART_TXC_BIT);
				/* Raising the flag to break the loop */
				u8Flag = HIGH;
			}
			else
			{
			}
		} while(u8Flag == LOW);
		/* Disabling the transmit enable to stop transmission */
		CLEAR_BIT(UCSRB_R, UART_TXEN_BIT);
		enuRetVar = E_OK;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;	
}

/*************************************************************************************************
* Parameters	: *pu16Data - u8BufferMaxSize
* Return Value	: enuErrorStatus_t
* Description  : Initiate a data reception on UART module from external module
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveString(uint8_t* pu8String)
{
	enuErrorStatus_t enuRetVar;
	uint8_t u8LoopIndex = 0;
	uint8_t u8Flag = LOW;
	
	if(enuUARTGroupState == UART_INIT_DONE)
	{
		/* Enabling the receive enable to start reception */
		SET_BIT(UCSRB_R, UART_RXEN_BIT);
		do
		{
			/* Waiting for the data until it has successfully been received */
			while(IS_BIT_CLEAR(UCSRA_R, UART_RXC_BIT));
			/* Clearing reception complete flag */
			SET_BIT(UCSRA_R, UART_RXC_BIT);
			/* Adding the value of the received data from the UART data register into the data variable */
			*(pu8String + u8LoopIndex) = UDR_R;
			/* Checking if the value of the last received data is not \n or \r */
			if((*(pu8String + u8LoopIndex) != '\n') && (*(pu8String + u8LoopIndex) != '\r'))
			{
				/* Incrementing the index of the array */
				u8LoopIndex++;
			}
			else
			{
				/* Raising the flag to break the loop */
				u8Flag = HIGH;
			}
		} while(u8Flag == LOW);
		/* Disabling the receive enable to stop reception */
		CLEAR_BIT(UCSRB_R, UART_RXEN_BIT);
		enuRetVar = E_OK;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}