#include "TWI.h"
#include "STD_TYPES.h"


typedef enum {TC_FAILED, TC_PASSED} enuTestCase_t;

/** TC_TWI_MasterInit **/
/* TWIBitRate */
enuTestCase_t TC_TWI_MasterInit_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_MasterInit(9, TWI_FOSC_OVER_1);
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

enuTestCase_t TC_TWI_MasterInit_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_MasterInit(10, TWI_FOSC_OVER_1);
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

enuTestCase_t TC_TWI_MasterInit_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_MasterInit(127, TWI_FOSC_OVER_1);
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

enuTestCase_t TC_TWI_MasterInit_004(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_MasterInit(128, TWI_FOSC_OVER_1);
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

/* TWIPrescalerSelect */
enuTestCase_t TC_TWI_MasterInit_005(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_MasterInit(64, -1);
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

enuTestCase_t TC_TWI_MasterInit_006(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_MasterInit(64, TWI_FOSC_OVER_1);
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

enuTestCase_t TC_TWI_MasterInit_007(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_MasterInit(64, TWI_FOSC_OVER_64);
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

enuTestCase_t TC_TWI_MasterInit_008(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_MasterInit(64, 4);
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


/** TC_TWI_SlaveInit **/
/* TWISlaveAddress */
enuTestCase_t TC_TWI_SlaveInit_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(-1, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
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

enuTestCase_t TC_TWI_SlaveInit_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(0x00, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
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

enuTestCase_t TC_TWI_SlaveInit_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(0xEF, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
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

enuTestCase_t TC_TWI_SlaveInit_004(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(0xF0, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
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

/* TWIGeneralCallRecognitionEnable */
enuTestCase_t TC_TWI_SlaveInit_005(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(0xA0, -1, TWI_DISABLE_ACKNOWLEDGE);
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

enuTestCase_t TC_TWI_SlaveInit_006(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(0xA0, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
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

enuTestCase_t TC_TWI_SlaveInit_007(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(0xA0, TWI_ENABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
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

enuTestCase_t TC_TWI_SlaveInit_008(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(0xA0, 2, TWI_DISABLE_ACKNOWLEDGE);
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

/* TWIEnableAcknowledgeBit */
enuTestCase_t TC_TWI_SlaveInit_009(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(0xA0, TWI_ENABLE_GENERAL_CALL_RECOGNITION, -1);
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

enuTestCase_t TC_TWI_SlaveInit_010(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(0xA0, TWI_ENABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
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

enuTestCase_t TC_TWI_SlaveInit_011(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(0xA0, TWI_ENABLE_GENERAL_CALL_RECOGNITION, TWI_ENABLE_ACKNOWLEDGE);
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

enuTestCase_t TC_TWI_SlaveInit_012(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_SlaveInit(0xA0, TWI_ENABLE_GENERAL_CALL_RECOGNITION, 2);
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


/** TC_TWI_Write **/
enuTestCase_t TC_TWI_Write_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	TWI_MasterInit(64, TWI_FOSC_OVER_1);
	enuErrorStatus = TWI_Write(0xAA);
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

enuTestCase_t TC_TWI_Write_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	TWI_SlaveInit(0xA0, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
	enuErrorStatus = TWI_Write(0xAA);
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

enuTestCase_t TC_TWI_Write_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_Write(0xAA);
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


/** TC_TWI_Read **/
enuTestCase_t TC_TWI_Read_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t u8Data;
	
	TWI_MasterInit(64, TWI_FOSC_OVER_1);
	enuErrorStatus = TWI_Read(&u8Data);
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

enuTestCase_t TC_TWI_Read_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t u8Data;	
	
	TWI_SlaveInit(0xA0, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
	enuErrorStatus = TWI_Read(&u8Data);
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

enuTestCase_t TC_TWI_Read_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint8_t u8Data;	
	
	enuErrorStatus = TWI_Read(&u8Data);
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


/** TC_TWI_CheckStatus **/
enuTestCase_t TC_TWI_CheckStatus_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	enuTWIStatus_t enuTWIStatus;
	
	TWI_MasterInit(64, TWI_FOSC_OVER_1);
	enuErrorStatus = TWI_CheckStatus(&enuTWIStatus);
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

enuTestCase_t TC_TWI_CheckStatus_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	enuTWIStatus_t enuTWIStatus;
	
	TWI_SlaveInit(0xA0, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
	enuErrorStatus = TWI_CheckStatus(&enuTWIStatus);
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

enuTestCase_t TC_TWI_CheckStatus_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	enuTWIStatus_t enuTWIStatus;
	
	enuErrorStatus = TWI_CheckStatus(&enuTWIStatus);
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


/** TC_TWI_Start **/
enuTestCase_t TC_TWI_Start_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	TWI_MasterInit(64, TWI_FOSC_OVER_1);
	enuErrorStatus = TWI_Start();
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

enuTestCase_t TC_TWI_Start_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	TWI_SlaveInit(0xA0, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
	enuErrorStatus = TWI_Start();
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

enuTestCase_t TC_TWI_Start_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_Start();
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


/** TC_TWI_Stop **/
enuTestCase_t TC_TWI_Stop_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	TWI_MasterInit(64, TWI_FOSC_OVER_1);
	enuErrorStatus = TWI_Stop();
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

enuTestCase_t TC_TWI_Stop_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	TWI_SlaveInit(0xA0, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
	enuErrorStatus = TWI_Stop();
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

enuTestCase_t TC_TWI_Stop_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_Stop();
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


/** TC_TWI_Listen **/
enuTestCase_t TC_TWI_Listen_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	TWI_MasterInit(64, TWI_FOSC_OVER_1);
	enuErrorStatus = TWI_Listen();
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

enuTestCase_t TC_TWI_Listen_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	TWI_SlaveInit(0xA0, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_DISABLE_ACKNOWLEDGE);
	enuErrorStatus = TWI_Listen();
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

enuTestCase_t TC_TWI_Listen_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = TWI_Listen();
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
