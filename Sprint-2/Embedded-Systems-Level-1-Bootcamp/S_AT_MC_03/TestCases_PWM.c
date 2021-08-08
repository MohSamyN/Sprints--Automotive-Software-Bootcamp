#include "PWM.h"
#include "STD_TYPES.h"


typedef enum {TC_FAILED, TC_PASSED} enuTestCase_t;


/** TC_PWM_Init **/
enuTestCase_t TC_PWM_Init_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = PWM_Init();
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


/** TC_PWM_Start **/
enuTestCase_t TC_PWM_Start_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	PWM_Init();
	enuErrorStatus = PWM_Start(0);
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

enuTestCase_t TC_PWM_Start_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	PWM_Init();
	enuErrorStatus = PWM_Start(100);
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

enuTestCase_t TC_PWM_Start_003(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	PWM_Init();
	enuErrorStatus = PWM_Start(101);
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

enuTestCase_t TC_PWM_Start_004(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = PWM_Start(50);
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


/** TC_PWM_Stop **/
enuTestCase_t TC_PWM_Stop_001(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	PWM_Init();
	enuErrorStatus = PWM_Stop();
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

enuTestCase_t TC_PWM_Stop_002(void)
{
	enuErrorStatus_t enuErrorStatus;
	enuTestCase_t enuTestCase;
	
	enuErrorStatus = PWM_Stop();
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
