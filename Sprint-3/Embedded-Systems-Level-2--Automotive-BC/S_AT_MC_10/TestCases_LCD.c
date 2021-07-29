#include "LCD.h"
#include "STD_TYPES.h"


typedef enum {TC_FAILED, TC_PASSED} enuTestCase_t;

/** TC_LCD_Init **/
/* LCDDataMode */
enuTestCase_t TC_LCD_Init_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_Init(3, LCD_CURSOR_OFF);
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_Init_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_Init(LCD_DATA_FOUR_BIT_MODE, LCD_CURSOR_OFF);
	if(enuErrorStatus == E_OK)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_Init_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_Init(5, LCD_CURSOR_OFF);
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_Init_004(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_Init(7, LCD_CURSOR_OFF);
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_Init_005(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_Init(LCD_DATA_EIGHT_BIT_MODE, LCD_CURSOR_OFF);
	if(enuErrorStatus == E_OK)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_Init_006(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_Init(9, LCD_CURSOR_OFF);
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

/* LCDCursorMode */
enuTestCase_t TC_LCD_Init_007(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_Init(LCD_DATA_FOUR_BIT_MODE, -1);
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_Init_008(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_Init(LCD_DATA_FOUR_BIT_MODE, LCD_CURSOR_OFF);
	if(enuErrorStatus == E_OK)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_Init_009(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_Init(LCD_DATA_FOUR_BIT_MODE, LCD_CURSOR_ON);
	if(enuErrorStatus == E_OK)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_Init_010(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_Init(LCD_DATA_FOUR_BIT_MODE, 2);
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}


/** TC_LCD_Clear **/
enuTestCase_t TC_LCD_Clear_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	LCD_Init(LCD_DATA_FOUR_BIT_MODE, LCD_CURSOR_OFF);
	enuErrorStatus = LCD_Clear();
	if(enuErrorStatus == E_OK)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_Clear_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_Clear();
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

/** TC_LCD_SetCursorPosition **/
enuTestCase_t TC_LCD_SetCursorPosition_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	LCD_Init(LCD_DATA_FOUR_BIT_MODE, LCD_CURSOR_OFF);
	enuErrorStatus = LCD_SetCursorPosition(0, -1);
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_SetCursorPosition_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	LCD_Init(LCD_DATA_FOUR_BIT_MODE, LCD_CURSOR_OFF);	
	enuErrorStatus = LCD_SetCursorPosition(0, 0);
	if(enuErrorStatus == E_OK)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_SetCursorPosition_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	LCD_Init(LCD_DATA_FOUR_BIT_MODE, LCD_CURSOR_OFF);	
	enuErrorStatus = LCD_SetCursorPosition(0, 1);
	if(enuErrorStatus == E_OK)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_SetCursorPosition_004(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	LCD_Init(LCD_DATA_FOUR_BIT_MODE, LCD_CURSOR_OFF);
	enuErrorStatus = LCD_SetCursorPosition(0, 2);
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_SetCursorPosition_005(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_SetCursorPosition(0, 0);
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}


/** TC_LCD_DisplayChar **/
enuTestCase_t TC_LCD_DisplayChar_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	LCD_Init(LCD_DATA_FOUR_BIT_MODE, LCD_CURSOR_OFF);
	enuErrorStatus = LCD_DisplayChar('T');
	if(enuErrorStatus == E_OK)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_DisplayChar_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_DisplayChar('T');
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}


/** TC_LCD_DisplayString **/
enuTestCase_t TC_LCD_DisplayString_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	LCD_Init(LCD_DATA_FOUR_BIT_MODE, LCD_CURSOR_OFF);
	enuErrorStatus = LCD_DisplayString("TEST");
	if(enuErrorStatus == E_OK)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}

enuTestCase_t TC_LCD_DisplayString_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = LCD_DisplayString("TEST");
	if(enuErrorStatus == E_ERROR)
	{
		enuTestCase = TC_PASSED;
	}
	else
	{
		enuTestCase = TC_FAILED;
	}
	return enuTestCase;
}
