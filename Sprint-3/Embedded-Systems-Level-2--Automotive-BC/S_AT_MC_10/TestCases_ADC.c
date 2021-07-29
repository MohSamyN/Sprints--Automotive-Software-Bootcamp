#include "ADC.h"
#include "STD_TYPES.h"


typedef enum {TC_FAILED, TC_PASSED} enuTestCase_t;

/** TC_ADC_Init **/
/* ADCReferenceSelectionBits */
enuTestCase_t TC_ADC_Init_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(-1, ADC_DISABLE_LEFT_ADJUST_RESULT, ADC_DIVISOR_FACTOR_IS_2);
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

enuTestCase_t TC_ADC_Init_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(ADC_AREF, ADC_DISABLE_LEFT_ADJUST_RESULT, ADC_DIVISOR_FACTOR_IS_2);
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

enuTestCase_t TC_ADC_Init_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(ADC_INTERNAL_VOLTAGE_REFERNECE, ADC_DISABLE_LEFT_ADJUST_RESULT, ADC_DIVISOR_FACTOR_IS_2);
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

enuTestCase_t TC_ADC_Init_004(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(4, ADC_DISABLE_LEFT_ADJUST_RESULT, ADC_DIVISOR_FACTOR_IS_2);
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

enuTestCase_t TC_ADC_Init_005(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(2, ADC_DISABLE_LEFT_ADJUST_RESULT, ADC_DIVISOR_FACTOR_IS_4);
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

/* ADCLeftAdjustResult */
enuTestCase_t TC_ADC_Init_006(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(ADC_AVCC, -1, ADC_DIVISOR_FACTOR_IS_4);
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

enuTestCase_t TC_ADC_Init_007(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(ADC_AVCC, ADC_DISABLE_LEFT_ADJUST_RESULT, ADC_DIVISOR_FACTOR_IS_4);
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

enuTestCase_t TC_ADC_Init_008(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(ADC_AVCC, ADC_ENABLE_LEFT_ADJUST_RESULT, ADC_DIVISOR_FACTOR_IS_4);
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

enuTestCase_t TC_ADC_Init_009(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(ADC_AVCC, 2, ADC_DIVISOR_FACTOR_IS_4);
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

/* ADCPrescalerSelectBits */
enuTestCase_t TC_ADC_Init_010(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(ADC_INTERNAL_VOLTAGE_REFERNECE, ADC_ENABLE_LEFT_ADJUST_RESULT, -1);
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

enuTestCase_t TC_ADC_Init_011(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(ADC_INTERNAL_VOLTAGE_REFERNECE, ADC_ENABLE_LEFT_ADJUST_RESULT, 0);
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

enuTestCase_t TC_ADC_Init_012(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(ADC_INTERNAL_VOLTAGE_REFERNECE, ADC_ENABLE_LEFT_ADJUST_RESULT, ADC_DIVISOR_FACTOR_IS_128);
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

enuTestCase_t TC_ADC_Init_013(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = ADC_Init(ADC_INTERNAL_VOLTAGE_REFERNECE, ADC_ENABLE_LEFT_ADJUST_RESULT, 8);
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


/** TC_ADC_ReadChannel **/
enuTestCase_t TC_ADC_ReadChannel_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint16_t u16Data;
	
	ADC_Init(ADC_AVCC, ADC_DISABLE_LEFT_ADJUST_RESULT, ADC_DIVISOR_FACTOR_IS_128);
	enuErrorStatus = ADC_ReadChannel(ADC0, &u16Data);
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

enuTestCase_t TC_ADC_ReadChannel_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	uint16_t u16Data;
	
	enuErrorStatus = ADC_ReadChannel(ADC0, &u16Data);
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
