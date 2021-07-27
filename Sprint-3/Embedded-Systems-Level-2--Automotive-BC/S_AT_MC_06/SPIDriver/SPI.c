#include "SPI.h"

typedef volatile uint8_t* const pu8SPIRegisterAddress;

#define SPDR_R																				*((pu8SPIRegisterAddress) 0x2F)
#define SPSR_R																				*((pu8SPIRegisterAddress) 0x2E)
#define SPCR_R																				*((pu8SPIRegisterAddress) 0x2D)

/* Internal Macros */
#define SPI_CLOCK_RATE_SELECT_MIN_VALUE											-1l
#define SPI_CLOCK_RATE_SELECT_MAX_VALUE											8u
#define SPI_MSTR_BIT																		4u
#define SPI_SPR_START_BIT																0u
#define SPI_SPR_MASK																		0x03
#define SPI_SPI2X_BIT																	0u
#define SPI_SPI2X_VALUE(CLOCK_RATE_SELECT)										((CLOCK_RATE_SELECT & 0x04) >> 2)
#define SPI_CPHA_BIT																		2u
#define SPI_CPOL_BIT																		3u
#define SPI_DORD_BIT																		5u
#define SPI_SPIE_BIT																		7u
#define SPI_SPIF_BIT																		7u
#define SPI_SPE_BIT																		6u

typedef enum {SPI_INIT_UNDONE, SPI_INIT_DONE} enuSPIState_t;
static enuSPIState_t enuSPIState = SPI_INIT_UNDONE;


/*************************************************************************************************
* Parameters	: enuSPIClockRateSelect, enuSPIClockPhase, enuSPIClockPolarity,
*					  enuSPIMasterSlaveSelect, enuSPIDataOrder
* Return Value	: enuErrorStatus_t
* Description  : Initialize the SPI module according to the configuration
*************************************************************************************************/
enuErrorStatus_t SPI_Init(enuSPIClockRateSelect_t enuSPIClockRateSelect, enuSPIClockPhase_t enuSPIClockPhase, enuSPIClockPolarity_t enuSPIClockPolarity,
enuSPIMasterSlaveSelect_t enuSPIMasterSlaveSelect, enuSPIDataOrder_t enuSPIDataOrder)
{
	enuErrorStatus_t enuRetVar;
	
	/* Checking that all configurations are correctly configured */
	if((enuSPIClockRateSelect > SPI_CLOCK_RATE_SELECT_MIN_VALUE) && (enuSPIClockRateSelect < SPI_CLOCK_RATE_SELECT_MAX_VALUE)	&&
		((enuSPIClockPhase == SPI_CPHA_LOW)					|| (enuSPIClockPhase == SPI_CPHA_HIGH))				&&
		((enuSPIClockPolarity == SPI_CPOL_LOW)				|| (enuSPIClockPolarity == SPI_CPOL_HIGH))			&&
		((enuSPIMasterSlaveSelect == SPI_SLAVE_MODE)		|| (enuSPIMasterSlaveSelect == SPI_MASTER_MODE))	&&
		((enuSPIDataOrder == SPI_MSB_TRANSMITTED_FIRST)	|| (enuSPIDataOrder == SPI_LSB_TRANSMITTED_FIRST)))
	{
		/* Initialize DIO pins to work as SPI module pins */
		if(enuSPIMasterSlaveSelect == SPI_SLAVE_MODE)
		{
			/* Initialize SS pin as input */
			DIO_PinInit(PB4, INPUT, NO_CONNECTION);
			/* Initialize MOSI pin as input */
			DIO_PinInit(PB5, INPUT, NO_CONNECTION);
			/* Initialize MISO pin as output */
			DIO_PinInit(PB6, OUTPUT, NO_CONNECTION);
			/* Initialize SCK pin as input */
			DIO_PinInit(PB7, INPUT, NO_CONNECTION);
		}
		else
		{
			/* Initialize SS pin as output */
			DIO_PinInit(PB4, OUTPUT, NO_CONNECTION);
			/* Initialize MOSI pin as output */
			DIO_PinInit(PB5, OUTPUT, NO_CONNECTION);
			/* Initialize MISO pin as input */
			DIO_PinInit(PB6, INPUT, NO_CONNECTION);
			/* Initialize SCK pin as output */
			DIO_PinInit(PB7, OUTPUT, NO_CONNECTION);	
		}
		/* Selecting the mode of SPI module, whether it is master of slave */
		ASSIGN_BIT(SPCR_R, SPI_MSTR_BIT, enuSPIMasterSlaveSelect);
		/* Selecting the SCK rate of the device configured as a Master */
		ASSIGN_BITS(SPCR_R, SPI_SPR_START_BIT, enuSPIClockRateSelect, SPI_SPR_MASK);
		/* Selecting whether the double speed feature is disabled or enabled according to the selected SCK rate */
		ASSIGN_BIT(SPSR_R, SPI_SPI2X_BIT, SPI_SPI2X_VALUE(enuSPIClockRateSelect));
		/* Selecting the SCK clock phase of the device */
		ASSIGN_BIT(SPCR_R, SPI_CPHA_BIT, enuSPIClockPhase);
		/* Selecting the SCK clock polarity of the device */
		ASSIGN_BIT(SPCR_R, SPI_CPOL_BIT, enuSPIClockPolarity);
		/* Selecting the data order of the data word, whether it is MSB first or LSB first */
		ASSIGN_BIT(SPCR_R, SPI_DORD_BIT, enuSPIDataOrder);
		/* Starting the SPI module */
		SET_BIT(SPCR_R, SPI_SPE_BIT);
		enuSPIState = SPI_INIT_DONE;
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
* Description  : Send a character to another module
*************************************************************************************************/
enuErrorStatus_t SPI_SendChar(uint8_t u8Data)
{
	enuErrorStatus_t enuRetVar;
	
	if(enuSPIState == SPI_INIT_DONE)
	{
		/* Adding the value of the data to be transmitted inside the SPI data register */
		SPDR_R = u8Data;
		/* Waiting for the data until it has successfully been transmitted */
		while(IS_BIT_CLEAR(SPSR_R, SPI_SPIF_BIT));
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
* Description  : Receive a character from another module
*************************************************************************************************/
enuErrorStatus_t SPI_ReceiveChar(uint8_t* pu8Data)
{
	enuErrorStatus_t enuRetVar;
	
	if(enuSPIState == SPI_INIT_DONE)
	{
		/* Waiting for the data until it has successfully been received */
		while(IS_BIT_CLEAR(SPSR_R, SPI_SPIF_BIT));
		/* Adding the value of the received data from the SPI data register into the data variable */
		*pu8Data = SPDR_R;
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
* Description  : Send a string to another module
*************************************************************************************************/
enuErrorStatus_t SPI_SendString(uint8_t* pu8Data)
{
	enuErrorStatus_t enuRetVar;
	uint8_t u8LoopIndex = 0;
	uint8_t u8Flag = LOW;
	
	if(enuSPIState == SPI_INIT_DONE)
	{
		do
		{
			/* Adding the value of the data to be transmitted inside the SPI data register */
			SPDR_R = *(pu8Data + u8LoopIndex);
			/* Waiting for the data until it has successfully been transmitted */
			while(IS_BIT_CLEAR(SPSR_R, SPI_SPIF_BIT));
			/* Incrementing the index of the input string */
			u8LoopIndex++;
			/* Checking if the next element in the input string is \n or \r */
			if((*(pu8Data + u8LoopIndex) == '\n') || (*(pu8Data + u8LoopIndex) == '\r'))
			{
				/* Adding the value of the data to be transmitted inside the SPI data register */
				SPDR_R = *(pu8Data + u8LoopIndex);
				/* Waiting for the data until it has successfully been transmitted */
				while(IS_BIT_CLEAR(SPSR_R, SPI_SPIF_BIT));
				/* Raising the flag to break the loop */
				u8Flag = HIGH;
			}
			else
			{
			}
		} while(u8Flag == LOW);
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
* Description  : Receive a string from another module
*************************************************************************************************/
enuErrorStatus_t SPI_ReceiveString(uint8_t* pu8Data)
{
	enuErrorStatus_t enuRetVar;
	uint8_t u8LoopIndex = 0;
	uint8_t u8Flag = LOW;
	
	if(enuSPIState == SPI_INIT_DONE)
	{
		do
		{
			/* Waiting for the data until it has successfully been received */
			while(IS_BIT_CLEAR(SPSR_R, SPI_SPIF_BIT));
			/* Adding the value of the received data from the SPI data register into the data variable */
			*(pu8Data + u8LoopIndex) = SPDR_R;
			/* Checking if the value of the last received data is not \n or \r */
			if((*(pu8Data + u8LoopIndex) != '\n') && (*(pu8Data + u8LoopIndex) != '\r'))
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
		enuRetVar = E_OK;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}