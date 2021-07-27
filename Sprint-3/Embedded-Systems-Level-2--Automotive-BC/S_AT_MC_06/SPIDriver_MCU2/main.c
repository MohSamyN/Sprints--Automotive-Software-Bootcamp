#include "SPI.h"
#include "DIO.h"


int main(void)
{	
	uint8_t u8Data;

	DIO_PortInit(PORTD, 0xFF, 0x00);
	SPI_Init(SPI_FOSC_OVER_128, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_SLAVE_MODE, SPI_MSB_TRANSMITTED_FIRST); 
	SPI_ReceiveChar(&u8Data);
	DIO_PortWrite(PORTD, u8Data);	
	while (1) 
	{
	}
}

