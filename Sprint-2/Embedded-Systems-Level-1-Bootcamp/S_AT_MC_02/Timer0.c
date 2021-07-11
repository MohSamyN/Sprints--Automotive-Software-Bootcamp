#include "Timer0.h"


/* Internal Macros */
#define TIMER_TIMER_MODE									2u
#define TIMER_TIMER_COMPARE_OUTPUT_MODE				4u
#define TIMER_TIMER_CLOCK									8u
#define TIMER_TIMER_INTERRUPT_ENABLE					2u
#define TIMER_TC0_WGM00										3u
#define TIMER_TC0_WGM01										6u
#define TIMER_TC0_WGM_VALUE_LOW							0u
#define TIMER_TC0_WGM_VALUE_HIGH							1u
#define TIMER_TC0_COMPARE_OUTPUT_MODE_START_BIT		4u
#define TIMER_TC0_COMPARE_OUTPUT_MODE_MASK			0x03
#define TIMER_TC0_OVERFLOW_INT_BIT						0u
#define TIMER_TC0_OUTPUT_COMPARE_MATCH_INT_BIT		1u
#define TIMER_GLOBAL_INT_EN_BIT							7u
#define TIMER_CLOCK_SELECT_START_BIT					0u
#define TIMER_CLOCK_SELECT_MASK							0x07
#define TIMER_TIMER_VALUE(TIME, PRESCALER, CLK)		((float)TIME / 1000000) * ((float)CLK / PRESCALER)
#define TIMER_TICKS_VALUE_8_BITS(TIME)					(255 - TIME)

typedef enum {TIMER_INIT_UNDONE, TIMER_INIT_DONE, TIMER_TIMER_INPROGRESS, TIMER_TIMER_DONE} enuTimerGroupState_t;
static enuTimerGroupState_t enuTimerGroupState = {TIMER_INIT_UNDONE};
static uint16_t au16TimerPrescalerValues[6] = {1, 1, 8, 64, 256, 1024};
static void(*pfTimerCallback)(void);
	
/* Timer0 ISR Function Prototypes */
void __vector_11(void) __attribute__((signal));
void __vector_10(void) __attribute__((signal));


/* Input Parameter(s): void																	*
 * Return Value		: enuErrorStatus (enum)												*
 * Description			: Initialize timer group according to the configuration	*/
enuErrorStatus_t Timer_Init(void)
{
	enuErrorStatus_t enuRetVar = E_OK;
	const strTimerConfigType_t *pstrConfig;
	
	pstrConfig = &strTimerConfigParameters;
	if((pstrConfig->enuTimerMode < TIMER_TIMER_MODE) && (pstrConfig->enuTimerCompareOutputMode < TIMER_TIMER_COMPARE_OUTPUT_MODE) && 
		(pstrConfig->enuTimerClock < TIMER_TIMER_CLOCK) && (pstrConfig->enuTimerIntEn < TIMER_TIMER_INTERRUPT_ENABLE))
	{
		/* Selecting the timer module mode */
		switch(pstrConfig->enuTimerMode)
		{
			case NORMAL:
			{
				/* Selecting the timer mode */
				ASSIGN_BIT(TCCR0_R, TIMER_TC0_WGM00, TIMER_TC0_WGM_VALUE_LOW);
				ASSIGN_BIT(TCCR0_R, TIMER_TC0_WGM01, TIMER_TC0_WGM_VALUE_LOW);
				/* Selecting whether to enable or disable interrupts */
				ASSIGN_BIT(TIMSK_R, TIMER_TC0_OVERFLOW_INT_BIT, pstrConfig->enuTimerIntEn);
			}
			break;
			case CTC:
			{
				/* Selecting the CTC mode */
				ASSIGN_BIT(TCCR0_R, TIMER_TC0_WGM00, TIMER_TC0_WGM_VALUE_LOW);
				ASSIGN_BIT(TCCR0_R, TIMER_TC0_WGM01, TIMER_TC0_WGM_VALUE_HIGH);
				/* Selecting whether to enable or disable interrupts */
				ASSIGN_BIT(TIMSK_R, TIMER_TC0_OUTPUT_COMPARE_MATCH_INT_BIT, pstrConfig->enuTimerIntEn);
			}
			break;
			default:
			{
				enuRetVar = E_ERROR;
			}
		}
		/* Selecting the behavior of the compare match mode output */
		ASSIGN_BITS(TCCR0_R, TIMER_TC0_COMPARE_OUTPUT_MODE_START_BIT, pstrConfig->enuTimerCompareOutputMode, TIMER_TC0_COMPARE_OUTPUT_MODE_MASK);
		/* Enabling/disabling the global interrupt depending on whether the module interrupts are chosen to be enabled or not */
		ASSIGN_BIT(SREG_R, TIMER_GLOBAL_INT_EN_BIT, pstrConfig->enuTimerIntEn);
		enuTimerGroupState = TIMER_INIT_DONE;		
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/* Input Parameter(s): u32TimerValueUS (uint32_t) - *pfCallback (pointer to function)	*																	*
 * Return Value		: enuErrorStatus (enum)															*
 * Description			: Initiate a timer delay using the timer module							*/
enuErrorStatus_t Timer_Start(uint32_t u32TimerValueUS, void(*pfCallback)(void))
{
	enuErrorStatus_t enuRetVar = E_OK;
	const strTimerConfigType_t *pstrConfig;
	float fTimerValue;
	
	if(((enuTimerGroupState == TIMER_INIT_DONE) || (enuTimerGroupState == TIMER_TIMER_DONE)) && (strTimerConfigParameters.enuTimerClock != NO_CLOCK))
	{
		pstrConfig = &strTimerConfigParameters;
		/* Calculating the timer value required according to the equation: fTimerValue(counts) = (fTimerValue(secs) / (Prescaler / ClockFrequency)) */
		if((pstrConfig->enuTimerClock != EXTERNAL_CLOCK_FALL_EDGE) && (pstrConfig->enuTimerClock != EXTERNAL_CLOCK_RISE_EDGE))
		{
			fTimerValue = TIMER_TIMER_VALUE(u32TimerValueUS, au16TimerPrescalerValues[pstrConfig->enuTimerClock], F_CPU);
		}
		else
		{
			fTimerValue = 255;
		}
		/* Selecting the timer module mode */
		switch(pstrConfig->enuTimerMode)
		{
			case NORMAL:
			{
				/* Loading the timer value counts into TCNT register */
				TCNT0_R = (uint8_t)(TIMER_TICKS_VALUE_8_BITS(((uint8_t)(fTimerValue))));
			}
			break;
			case CTC:
			{
				/* Loading the timer value counts into OCR0 register */
				OCR0_R = (uint8_t)(TIMER_TICKS_VALUE_8_BITS(((uint8_t)(fTimerValue))));
			}
			break;
			default:
			{
				enuRetVar = E_ERROR;	
			}
		}
		/* Starting the timer by loading the pre-configured clock prescaler value */
		ASSIGN_BITS(TCCR0_R, TIMER_CLOCK_SELECT_START_BIT, pstrConfig->enuTimerClock, TIMER_CLOCK_SELECT_MASK);
		/* Storing the context of the input callback function into a temporary pointer to a function */
		pfTimerCallback = pfCallback;
		enuTimerGroupState = TIMER_TIMER_INPROGRESS;

	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}

/* Input Parameter(s): void													*
 * Return Value		: enuErrorStatus (enum)								*
 * Description			: Stop the functionality of the timer module	*/
enuErrorStatus_t Timer_Stop(void)
{
	enuErrorStatus_t enuRetVar = E_OK;
	
	if((enuTimerGroupState == TIMER_TIMER_INPROGRESS) && (strTimerConfigParameters.enuTimerClock != NO_CLOCK))
	{
		/* Stopping the timer by loading a No Clock condition */
		ASSIGN_BITS(TCCR0_R, TIMER_CLOCK_SELECT_START_BIT, NO_CLOCK, TIMER_CLOCK_SELECT_MASK);
		enuTimerGroupState = TIMER_TIMER_DONE;
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;	
}

/* Input Parameter(s): void												*
 * Return Value		: enuErrorStatus (enum)							*
 * Description			: Check periodically for the timer flag	*/
enuErrorStatus_t Timer_GetStatus(void)
{
	enuErrorStatus_t enuRetVar = E_OK;
	const strTimerConfigType_t *pstrConfig;
	
	if((enuTimerGroupState == TIMER_TIMER_INPROGRESS) && (strTimerConfigParameters.enuTimerIntEn == TIMER_INT_DIS))
	{
		pstrConfig = &strTimerConfigParameters;
		switch(pstrConfig->enuTimerMode)
		{
			case NORMAL:
			{
				/* Checking timer 0 overflow flag */
				if(IS_BIT_SET(TIFR_R, TIMER_TC0_OVERFLOW_INT_BIT))
				{
					/* Clearing timer 0 overflow flag by writing one */
					SET_BIT(TIFR_R, TIMER_TC0_OVERFLOW_INT_BIT);
					/* Stopping the timer by loading a No Clock condition */
					ASSIGN_BITS(TCCR0_R, TIMER_CLOCK_SELECT_START_BIT, NO_CLOCK, TIMER_CLOCK_SELECT_MASK);
					enuTimerGroupState = TIMER_TIMER_DONE;
					/* Calling the call back function */
					pfTimerCallback();
				}
				else
				{
				}						
			}
			break;
			case CTC:
			{
				/* Checking timer 0 output compare flag */
				if(IS_BIT_SET(TIFR_R, TIMER_TC0_OUTPUT_COMPARE_MATCH_INT_BIT))
				{
					/* Clearing timer 0 output compare flag by writing one */
					SET_BIT(TIFR_R, TIMER_TC0_OUTPUT_COMPARE_MATCH_INT_BIT);
					/* Stopping the timer by loading a No Clock condition */
					ASSIGN_BITS(TCCR0_R, TIMER_CLOCK_SELECT_START_BIT, NO_CLOCK, TIMER_CLOCK_SELECT_MASK);
					enuTimerGroupState = TIMER_TIMER_DONE;
					/* Calling the call back function */
					pfTimerCallback();
				}
				else
				{
				}						
			}
			break;
			default:
			{
				enuRetVar = E_ERROR;
			}
		}
	}
	else
	{
		enuRetVar = E_ERROR;
	}
	return enuRetVar;
}


/* Timer0 ISR Function Definitions */
/* Timer0 ISR Overflow Function */
void __vector_11(void)
{
	enuTimerGroupState = TIMER_TIMER_DONE;
	/* Stopping the timer by loading a No Clock condition */
	ASSIGN_BITS(TCCR0_R, TIMER_CLOCK_SELECT_START_BIT, NO_CLOCK, TIMER_CLOCK_SELECT_MASK);
	/* Calling the call back function */
	pfTimerCallback();
}

/* Timer0 ISR Compare Match Function */
void __vector_10(void)
{
	enuTimerGroupState = TIMER_TIMER_DONE;
	/* Stopping the timer by loading a No Clock condition */
	ASSIGN_BITS(TCCR0_R, TIMER_CLOCK_SELECT_START_BIT, NO_CLOCK, TIMER_CLOCK_SELECT_MASK);
	/* Calling the call back function */
	pfTimerCallback();	
}
