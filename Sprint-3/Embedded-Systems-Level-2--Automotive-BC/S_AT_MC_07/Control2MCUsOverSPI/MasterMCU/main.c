#include "UART.h"
#include "SPI.h"


int main(void)
{
   uint8_t au8Data[255];
	 
	UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
	SPI_Init(SPI_FOSC_OVER_128, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
   while (1) 
   {
		UART_ReceiveString(au8Data);
		SPI_SendString(au8Data);
   }
}

