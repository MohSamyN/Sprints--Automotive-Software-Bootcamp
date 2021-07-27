#ifndef APP_H_
#define APP_H_

#define F_CPU															8000000u
#include "LCD.h"
#include "Keypad.h"
#include "DCFan.h"
#include "Button.h"
#include "LM35.h"
#include <stdlib.h>

/*************************************************************************************************
* Parameters	: void
* Return Value	: void
* Description  : Initialize all ECUAL-based drivers 
*************************************************************************************************/
void App_Init(void);
/*************************************************************************************************
* Parameters	: void
* Return Value	: void
* Description  : Monitor the status of the required application
*************************************************************************************************/
void App_Update(void);

#endif /* APP_H_ */