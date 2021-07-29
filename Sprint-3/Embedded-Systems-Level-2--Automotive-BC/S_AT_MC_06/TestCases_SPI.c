#include "SPI.h"
#include "STD_TYPES.h"


typedef enum {TC_FAILED, TC_PASSED} enuTestCase_t;

/** TC_SPI_Init **/
/* SPIClockRateSelect */
enuTestCase_t TC_SPI_Init_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(-1, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_4, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_64_WITH_DOUBLE_SPEED, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_004(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(2, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

/* SPIClockPhase */
enuTestCase_t TC_SPI_Init_005(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_16, -1, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_006(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_16, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_007(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_16, SPI_CPHA_HIGH, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_008(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_16, 2, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

/* SPIClockPolarity */
enuTestCase_t TC_SPI_Init_009(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_64_WITHOUT_DOUBLE_SPEED, SPI_CPHA_HIGH, -1, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_010(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_64_WITHOUT_DOUBLE_SPEED, SPI_CPHA_HIGH, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_011(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_64_WITHOUT_DOUBLE_SPEED, SPI_CPHA_HIGH, SPI_CPOL_HIGH, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_012(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_64_WITHOUT_DOUBLE_SPEED, SPI_CPHA_HIGH, 2, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

/* SPIMasterSlaveSelect */
enuTestCase_t TC_SPI_Init_013(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_128, SPI_CPHA_LOW, SPI_CPOL_HIGH, -1, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_014(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_128, SPI_CPHA_LOW, SPI_CPOL_HIGH, SPI_SLAVE_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_015(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_128, SPI_CPHA_LOW, SPI_CPOL_HIGH, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_016(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_128, SPI_CPHA_LOW, SPI_CPOL_HIGH, 2, SPI_MSB_TRANSMITTED_FIRST);
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

/* SPIDataOrder */
enuTestCase_t TC_SPI_Init_017(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_2, SPI_CPHA_HIGH, SPI_CPOL_LOW, SPI_MASTER_MODE, -1);
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

enuTestCase_t TC_SPI_Init_018(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_2, SPI_CPHA_HIGH, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_019(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_2, SPI_CPHA_HIGH, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_LSB_TRANSMITTED_FIRST);
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

enuTestCase_t TC_SPI_Init_020(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_Init(SPI_FOSC_OVER_2, SPI_CPHA_HIGH, SPI_CPOL_LOW, SPI_MASTER_MODE, 2);
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


/** TC_SPI_SendChar **/
enuTestCase_t TC_SPI_SendChar_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	SPI_Init(SPI_FOSC_OVER_4, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
	enuErrorStatus = SPI_SendChar(0xAA);
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

enuTestCase_t TC_SPI_SendChar_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = SPI_SendChar(0xAA);
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


/** TC_SPI_ReceiveChar **/
enuTestCase_t TC_SPI_ReceiveChar_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t u8Char;
	
	SPI_Init(SPI_FOSC_OVER_4, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
	enuErrorStatus = SPI_ReceiveChar(&u8Char);
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

enuTestCase_t TC_SPI_ReceiveChar_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t u8Char;
	
	enuErrorStatus = SPI_ReceiveChar(&u8Char);
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


/** TC_SPI_SendString **/
enuTestCase_t TC_SPI_SendString_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t au8String[5] = "TEST\n";
	
	SPI_Init(SPI_FOSC_OVER_4, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
	enuErrorStatus = SPI_SendString(au8String);
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

enuTestCase_t TC_SPI_SendString_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t au8String[5] = "TEST\n";
	
	enuErrorStatus = SPI_SendString(au8String);
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


/** TC_SPI_ReceiveString **/
enuTestCase_t TC_SPI_ReceiveString_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t au8String[255];
	
	SPI_Init(SPI_FOSC_OVER_4, SPI_CPHA_LOW, SPI_CPOL_LOW, SPI_MASTER_MODE, SPI_MSB_TRANSMITTED_FIRST);
	enuErrorStatus = SPI_ReceiveString(au8String);
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

enuTestCase_t TC_SPI_ReceiveString_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t au8String[255];
	
	enuErrorStatus = SPI_ReceiveString(au8String);
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




enuErrorStatus_t SPI_SendString(uint8_t* pu8Data);

enuErrorStatus_t SPI_ReceiveString(uint8_t* pu8Data);
