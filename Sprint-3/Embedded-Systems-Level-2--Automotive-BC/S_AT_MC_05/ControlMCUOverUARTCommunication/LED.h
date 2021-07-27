#ifndef LED_H_
#define LED_H_

#include "DIO.h"
#include "STD_TYPES.h"

typedef enum {LED_ACTIVE_LOW, LED_ACTIVE_HIGH} enuLEDConnectionType_t;

/*************************************************************************************************
* Parameters	: enuDIOPinNo, enuLEDConnectionType
* Return Value	: enuErrorStatus_t
* Description  : Initialize one LED according to the configuration
*************************************************************************************************/
enuErrorStatus_t LED_Init(enuDIOPinNo_t enuDIOPinNo, enuLEDConnectionType_t enuLEDConnectionType);
/*************************************************************************************************
* Parameters	: enuDIOPinNo
* Return Value	: enuErrorStatus_t
* Description  : Turn on the required LED
*************************************************************************************************/
enuErrorStatus_t LED_On(enuDIOPinNo_t enuDIOPinNo);
/*************************************************************************************************
* Parameters	: enuDIOPinNo
* Return Value	: enuErrorStatus_t
* Description  : Turn off the required LED
*************************************************************************************************/
enuErrorStatus_t LED_Off(enuDIOPinNo_t enuDIOPinNo);
/*************************************************************************************************
* Parameters	: enuDIOPinNo
* Return Value	: enuErrorStatus_t
* Description  : Toggle the state of the required LED
*************************************************************************************************/
/* A function to toggle the state of the required LED */
enuErrorStatus_t LED_Toggle(enuDIOPinNo_t enuDIOPinNo);

#endif /* LED_H_ */

