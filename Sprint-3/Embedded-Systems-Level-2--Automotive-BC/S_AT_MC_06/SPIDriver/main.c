#include "SPI.h"


int main(void)
{	
	SPI_Init(SPI_FOSC_OVER_128, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);  
	DIO_PinWrite(PB4, LOW);
	SPI_SendChar((uint8_t)'A');
	while(1) 
   {
   }
}

