#ifndef TIMER_H_
#define TIMER_H_

#include "STD_TYPES.h"
#include "BIT_MANIPULATE.h"
#include "Timer0_Cfg.h"
#include "Register.h"

typedef enum {NORMAL, CTC} enuTimerMode_t;
typedef enum {NORMAL_OPERATION, TOGGLE_ON_COMPARE_MATCH, CLEAR_ON_COMPARE_MATCH, SET_ON_COMPARE_MATCH} enuTimerCompareOutputMode_t;
typedef enum {NO_CLOCK, NO_PRESCALER, PRESCALER_8, PRESCALER_64, PRESCALER_256, PRESCALER_1024, 
				  EXTERNAL_CLOCK_FALL_EDGE, EXTERNAL_CLOCK_RISE_EDGE} enuTimerClock_t;
typedef enum {TIMER_INT_DIS, TIMER_INT_EN} enuTimerIntEn_t;

typedef struct
{
	/* Selecting the timer module mode */
	enuTimerMode_t enuTimerMode;
	/* Selecting the behavior of the compare match mode output */ 
	enuTimerCompareOutputMode_t enuTimerCompareOutputMode; 
	/* Selecting the clock source to be used for the selected module	*/
	enuTimerClock_t enuTimerClock;
	/* Selecting whether to enable or disable timer module interrupts */ 
	enuTimerIntEn_t enuTimerIntEn;		
} strTimerConfigType_t;

const strTimerConfigType_t strTimerConfigParameters;

/* Input Parameter(s): void																	*
 * Return Value		: enuErrorStatus (enum)												*
 * Description			: Initialize timer group according to the configuration	*/
enuErrorStatus_t Timer_Init(void);
/* Input Parameter(s): u32TimerValueUS (uint32_t) - *pfCallback (pointer to function)	*																	*
 * Return Value		: enuErrorStatus (enum)															*
 * Description			: Initiate a timer delay using the timer module							*/
enuErrorStatus_t Timer_Start(uint32_t u32TimerValueUS, void(*pfCallback)(void));
/* Input Parameter(s): void													*
 * Return Value		: enuErrorStatus (enum)								*
 * Description			: Stop the functionality of the timer module	*/
enuErrorStatus_t Timer_Stop(void);
/* Input Parameter(s): void												*
 * Return Value		: enuErrorStatus (enum)							*
 * Description			: Check periodically for the timer flag	*/
enuErrorStatus_t Timer_GetStatus(void);

#endif /* TM_H_ */