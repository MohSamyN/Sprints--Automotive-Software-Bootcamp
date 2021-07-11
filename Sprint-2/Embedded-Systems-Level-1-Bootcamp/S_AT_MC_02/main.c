#include "Timer0.h"
#include "DIO.h"


/* App: Toggling the LED every one second */
void Timer_CallBack(void);

int main(void)
{
	DIO_Init();
	Timer_Init();
	Timer_Start(10000, &Timer_CallBack);
   while(1) 
   {
		Timer_GetStatus();
   }
}


void Timer_CallBack(void)
{
	static uint32_t Counter = 0;
	
	if(Counter == 100)
	{
		DIO_Toggle(0);
		Counter = 0;		
	}
	else
	{
		Counter++;
	}
	Timer_Start(10000, &Timer_CallBack);
}