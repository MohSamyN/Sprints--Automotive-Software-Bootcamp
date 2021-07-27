#include "UART.h"


int main(void)
{
	uint8_t u8String[255];
	
	UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
	UART_ReceiveString(u8String);
	UART_SendString(u8String);
	while(1)
	{
	}
}
