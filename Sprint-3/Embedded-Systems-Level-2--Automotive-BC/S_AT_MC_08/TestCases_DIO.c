#include "DIO.h"
#include "STD_TYPES.h"


typedef enum {TC_FAILED, TC_PASSED} enuTestCase_t;

/** TC_DIO_PinInit **/
/* DIOPinNo */
enuTestCase_t TC_DIO_PinInit_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(-1, INPUT, NO_CONNECTION);
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

enuTestCase_t TC_DIO_PinInit_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(PA0, INPUT, NO_CONNECTION);
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

enuTestCase_t TC_DIO_PinInit_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(PD7, INPUT, NO_CONNECTION);
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

enuTestCase_t TC_DIO_PinInit_004(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(32, INPUT, NO_CONNECTION);
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

/* DIOPinDirection */
enuTestCase_t TC_DIO_PinInit_005(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(PB0, -1, NO_CONNECTION);
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

enuTestCase_t TC_DIO_PinInit_006(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(PB0, INPUT, NO_CONNECTION);
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

enuTestCase_t TC_DIO_PinInit_007(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(PB0, OUTPUT, NO_CONNECTION);
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

enuTestCase_t TC_DIO_PinInit_008(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(PB0, 2, NO_CONNECTION);
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

/* DIOPinPullupResistorEnable */
enuTestCase_t TC_DIO_PinInit_009(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(PC0, INPUT, -1);
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

enuTestCase_t TC_DIO_PinInit_010(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(PC0, INPUT, NO_CONNECTION);
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

enuTestCase_t TC_DIO_PinInit_011(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(PC0, INPUT, PULL_UP_ENABLE);
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

enuTestCase_t TC_DIO_PinInit_012(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinInit(PC0, INPUT, 2);
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


/** TC_DIO_PortInit **/
/* DIOPortNo */
enuTestCase_t TC_DIO_PortInit_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(-1, 0x00, 0x00);
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

enuTestCase_t TC_DIO_PortInit_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(PORTA, 0x00, 0x00);
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

enuTestCase_t TC_DIO_PortInit_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(PORTD, 0x00, 0x00);
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

enuTestCase_t TC_DIO_PortInit_004(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(4, 0x00, 0x00);
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

/* DIOPortDirection */
enuTestCase_t TC_DIO_PortInit_005(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(PORTB, -1, 0x0F);
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

enuTestCase_t TC_DIO_PortInit_006(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(PORTB, 0x00, 0x0F);
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

enuTestCase_t TC_DIO_PortInit_007(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(PORTB, 0xFF, 0x0F);
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

enuTestCase_t TC_DIO_PortInit_008(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(PORTB, 256, 0x0F);
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

/* DIOPortPullupResistorEnable */
enuTestCase_t TC_DIO_PortInit_009(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(PORTC, 0x0F, -1);
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

enuTestCase_t TC_DIO_PortInit_010(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(PORTC, 0x0F, 0x00);
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

enuTestCase_t TC_DIO_PortInit_011(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(PORTC, 0x0F, 0xFF);
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

enuTestCase_t TC_DIO_PortInit_012(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortInit(PORTC, 0x0F, 256);
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


/** TC_DIO_PinWrite **/
enuTestCase_t TC_DIO_PinWrite_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	DIO_PinInit(PA0, OUTPUT, NO_CONNECTION);
	enuErrorStatus = DIO_PinWrite(PA0, HIGH);
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

enuTestCase_t TC_DIO_PinWrite_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinWrite(PA0, HIGH);
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


/** TC_DIO_PortWrite **/
enuTestCase_t TC_DIO_PortWrite_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	DIO_PortInit(PORTA, 0xFF, 0x00);
	enuErrorStatus = DIO_PortWrite(PORTA, 0xFF);
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

enuTestCase_t TC_DIO_PortWrite_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortWrite(PORTA, 0xFF);
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


/** TC_DIO_PinRead **/
enuTestCase_t TC_DIO_PinRead_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t u8PinData;
	
	DIO_PinInit(PA0, INPUT, PULL_UP_ENABLE);
	enuErrorStatus = DIO_PinRead(PA0, &u8PinData);
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

enuTestCase_t TC_DIO_PinRead_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t u8PinData;
	
	enuErrorStatus = DIO_PinRead(PA0, &u8PinData);
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


/** TC_DIO_PortRead **/
enuTestCase_t TC_DIO_PortRead_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t u8PortData;	
	
	DIO_PortInit(PORTA, 0x00, 0xFF);
	enuErrorStatus = DIO_PortWrite(PORTA, &u8PortData);
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

enuTestCase_t TC_DIO_PortRead_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t u8PortData;	
	
	enuErrorStatus = DIO_PortWrite(PORTA, &u8PortData);
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


/** TC_DIO_PinToggle **/
enuTestCase_t TC_DIO_PinToggle_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	DIO_PinInit(PA0, OUTPUT, NO_CONNECTION);
	enuErrorStatus = DIO_PinToggle(PA0);
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

enuTestCase_t TC_DIO_PinToggle_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PinToggle(PA0);
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


/** TC_DIO_PortToggle **/
enuTestCase_t TC_DIO_PortToggle_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	DIO_PortInit(PORTA, 0xFF, 0x00);
	enuErrorStatus = DIO_PortToggle(PORTA);
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

enuTestCase_t TC_DIO_PortToggle_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = DIO_PortToggle(PORTA);
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
