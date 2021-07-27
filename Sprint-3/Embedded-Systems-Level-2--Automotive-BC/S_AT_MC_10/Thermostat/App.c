#include "App.h"


void App_Init(void)
{
	LCD_Init(LCD_DATA_FOUR_BIT_MODE, LCD_CURSOR_OFF);
	Keypad_Init(KEYPAD_4X3);
	DCFan_Init(PB3);
	Button_Init(PA7, BUTTON_ACTIVE_LOW);
	LM35_Init();	
}

void App_Update(void)
{
	enuButtonStates_t enuButtonStates;
	static uint8_t au8PressedKey[3] = "99\n";
	static uint8_t au8Temperature[3] = "00\n";
	static uint8_t u8Temperature = 0;
	static uint8_t u8PressedKey = 0;
	

	Button_GetState(PA7, &enuButtonStates);
	if(enuButtonStates == BUTTON_PRESSED)
	{
		LCD_Clear();
		LCD_SetCursorPosition(0, 0);
		LCD_DisplayString((uint8_t*)"Enter Req Temp:");
		LCD_SetCursorPosition(0, 1);
		Keypad_GetChar(&au8PressedKey[0]);
		LCD_DisplayChar(au8PressedKey[0]);		
		Keypad_GetChar(&au8PressedKey[1]);
		LCD_DisplayChar(au8PressedKey[1]);
		LCD_Clear();
	}
	else
	{
		LCD_SetCursorPosition(0, 0);
		LCD_DisplayString((uint8_t*)"Current Temp:");
		LM35_ReadTemperature(&u8Temperature);
		itoa(u8Temperature, (char*)au8Temperature, 10);
		if(u8Temperature < 10)
		{
			LCD_DisplayChar(au8Temperature[0]);
			LCD_DisplayChar(' ');
		}
		else
		{
			LCD_DisplayChar(au8Temperature[0]);
			LCD_DisplayChar(au8Temperature[1]);
		}	
		LCD_SetCursorPosition(0, 1);
		LCD_DisplayString((uint8_t*)"Req Temp:");
		LCD_DisplayChar(au8PressedKey[0]);
		LCD_DisplayChar(au8PressedKey[1]);
		u8PressedKey = atoi((char*)au8PressedKey);
		if(u8Temperature > u8PressedKey)
		{
			DCFan_Start(PB3);
		}
		else
		{
			DCFan_Stop(PB3);
		}
	}	
}
