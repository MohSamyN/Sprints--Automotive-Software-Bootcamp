#include "UART.h"
#include "STD_TYPES.h"


typedef enum {TC_FAILED, TC_PASSED} enuTestCase_t;

/** TC_UART_Init **/
/* Baudrate */
enuTestCase_t TC_UART_Init_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(-1, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(0, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(1000000, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_004(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(1000001, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

/* Character Bits */
enuTestCase_t TC_UART_Init_005(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, -1, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_006(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, UART_FIVE_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_007(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, UART_NINE_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_008(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, 8, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_009(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, 4, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_010(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, 5, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_011(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, 6, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

/* Stop Bits */
enuTestCase_t TC_UART_Init_012(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, UART_EIGHT_CHARACTER_BITS, -1, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_013(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_014(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_TWO_STOP_BITS, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_015(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, UART_EIGHT_CHARACTER_BITS, 2, UART_DISABLE_PARITY);
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

/* Parity Bits */
enuTestCase_t TC_UART_Init_016(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, -1);
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

enuTestCase_t TC_UART_Init_017(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
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

enuTestCase_t TC_UART_Init_018(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_ENABLE_ODD_PARITY);
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

enuTestCase_t TC_UART_Init_019(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, 4);
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

enuTestCase_t TC_UART_Init_020(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, 1);
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


/** TC_UART_SendData **/
enuTestCase_t TC_UART_SendData_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
	enuErrorStatus = UART_SendData(0xAA);
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

enuTestCase_t TC_UART_SendData_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = UART_SendData(0xAA);
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


/** TC_UART_ReceiveData **/
enuTestCase_t TC_UART_ReceiveData_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint16_t u16Data;
	
	UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
	enuErrorStatus = UART_ReceiveData(&u16Data);
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

enuTestCase_t TC_UART_ReceiveData_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint16_t u16Data;	
	
	enuErrorStatus = UART_ReceiveData(&u16Data);
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


/** TC_UART_SendString **/
enuTestCase_t TC_UART_SendString_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t au8String[5] = "TEST\n";
	
	UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
	enuErrorStatus = UART_SendString(au8String);
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

enuTestCase_t TC_UART_SendString_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t au8String[5] = "TEST\n";	
	
	enuErrorStatus = UART_SendString(au8String);
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


/** TC_UART_ReceiveString **/
enuTestCase_t TC_UART_ReceiveString_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t au8String[255];
	
	UART_Init(9600, UART_EIGHT_CHARACTER_BITS, UART_ONE_STOP_BIT, UART_DISABLE_PARITY);
	enuErrorStatus = UART_ReceiveString(au8String);
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

enuTestCase_t TC_UART_ReceiveString_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t au8String[255];	
	
	enuErrorStatus = UART_ReceiveString(au8String);
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
