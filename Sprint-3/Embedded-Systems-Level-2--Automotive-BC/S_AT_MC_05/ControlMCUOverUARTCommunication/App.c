#include "App.h"


void App_Init(void)
{
	UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
	LED_Init(PA0, LED_ACTIVE_HIGH);
	LED_Init(PA1, LED_ACTIVE_HIGH);
	LED_Init(PA2, LED_ACTIVE_HIGH);
}

void App_Update(void)
{
	uint8_t u8Command[6];
	
	UART_ReceiveString(u8Command);
	if((u8Command[0] == 'S') && (u8Command[1] == 'T') && (u8Command[2] == 'A') && (u8Command[3] == 'R') && (u8Command[4] == 'T'))
	{
		LED_Off(PA0);
		LED_Off(PA1);
		LED_On(PA2);
		UART_SendString((uint8_t*)"Green LED is on\n");		
	}
	else if((u8Command[0] == 'W') && (u8Command[1] == 'A') && (u8Command[2] == 'I') && (u8Command[3] == 'T'))
	{
		LED_Off(PA0);
		LED_On(PA1);
		LED_Off(PA2);	
		UART_SendString((uint8_t*)"Yellow LED is on\n");			
	}
	else if((u8Command[0] == 'S') && (u8Command[1] == 'T') && (u8Command[2] == 'O') && (u8Command[3] == 'P'))
	{
		LED_On(PA0);
		LED_Off(PA1);
		LED_Off(PA2);
		UART_SendString((uint8_t*)"Red LED is on\n");
	}	
	else if((u8Command[0] == 'A') && (u8Command[1] == 'T'))
	{
		UART_SendString((uint8_t*)"OK\n");
	}
	else
	{
	}
}
