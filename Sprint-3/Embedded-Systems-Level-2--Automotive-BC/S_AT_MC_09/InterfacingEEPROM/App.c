#include "App.h"


void App_Init(void)
{
	UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
	EEPROM_Init(32, TWI_FOSC_OVER_1);
}

void App_Update(void)
{
	uint8_t au8Command[6];
	uint8_t au8Address[16];
	uint16_t u16Address;
	uint8_t u8Data;
	
	UART_ReceiveString(au8Command);
	if((au8Command[0] == 'W') && (au8Command[1] == 'R') && (au8Command[2] == 'I') && (au8Command[3] == 'T') && (au8Command[4] == 'E')) 
	{
		UART_ReceiveString(au8Address);
		u16Address = atoi((char*)au8Address);
		UART_SendString((uint8_t*)"OK\r");
		UART_ReceiveData((uint16_t*)&u8Data);
		UART_SendString((uint8_t*)"\rOK\r\r");
		EEPROM_Write(u16Address, u8Data);		
	}
	else if((au8Command[0] == 'R') && (au8Command[1] == 'E') && (au8Command[2] == 'A') && (au8Command[3] == 'D'))
	{
		UART_ReceiveString(au8Address);
		u16Address = atoi((char*)au8Address);
		UART_SendString((uint8_t*)"OK\r");
		EEPROM_Read(u16Address, &u8Data);
		UART_SendString((uint8_t*)"The data stored is: ");
		UART_SendData(u8Data);
	}
	else
	{
	}
}
