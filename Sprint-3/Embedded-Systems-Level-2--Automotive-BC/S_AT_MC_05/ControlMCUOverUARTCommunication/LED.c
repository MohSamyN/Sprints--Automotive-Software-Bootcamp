#include "LED.h"


/* Internal Macros */
#define LED_MAX_NO															255u

typedef enum {LED_INIT_UNDONE, LED_INIT_DONE} enuLEDState_t;
static enuLEDState_t enuLEDState[LED_MAX_NO] = {LED_INIT_UNDONE};
	
static enuLEDConnectionType_t enuLEDConnectionTypeState[LED_MAX_NO];


/*************************************************************************************************
* Parameters	: enuDIOPinNo, enuLEDConnectionType
* Return Value	: enuErrorStatus_t
* Description  : Initialize one LED according to the configuration
*************************************************************************************************/
enuErrorStatus_t LED_Init(enuDIOPinNo_t enuDIOPinNo, enuLEDConnectionType_t enuLEDConnectionType)
{
   enuErrorStatus_t enuRetVar;
	
	if((enuLEDConnectionType == LED_ACTIVE_LOW) || (enuLEDConnectionType == LED_ACTIVE_HIGH))
	{
		/* Initializing the LED as output */
		DIO_PinInit(enuDIOPinNo, OUTPUT, NO_CONNECTION);
		/* Turning off the LED before using it */
		DIO_PinWrite(enuDIOPinNo, ~enuLEDConnectionType);
		enuLEDConnectionTypeState[enuDIOPinNo] = enuLEDConnectionType;
	   enuLEDState[enuDIOPinNo] = LED_INIT_DONE;
		enuRetVar = E_OK;
   }
	else
	{
		enuRetVar = E_ERROR;
	}
   return enuRetVar;
}

/*************************************************************************************************
* Parameters	: enuDIOPinNo
* Return Value	: enuErrorStatus_t
* Description  : Turn on the required LED
*************************************************************************************************/
enuErrorStatus_t LED_On(enuDIOPinNo_t enuDIOPinNo)
{
   enuErrorStatus_t enuRetVar;
    
   if(enuLEDState[enuDIOPinNo] == LED_INIT_DONE)
   {
	   /* Turning on the required LED */
	   DIO_PinWrite(enuDIOPinNo, enuLEDConnectionTypeState[enuDIOPinNo]);
	   enuRetVar = E_OK;
   }
   else
   {
	   enuRetVar = E_ERROR;
   }
   return enuRetVar;	
}

/*************************************************************************************************
* Parameters	: enuDIOPinNo
* Return Value	: enuErrorStatus_t
* Description  : Turn off the required LED
*************************************************************************************************/
enuErrorStatus_t LED_Off(enuDIOPinNo_t enuDIOPinNo)
{
   enuErrorStatus_t enuRetVar;
   
   if(enuLEDState[enuDIOPinNo] == LED_INIT_DONE)
   {
	   /* Turning off the required LED */
	   DIO_PinWrite(enuDIOPinNo, ~enuLEDConnectionTypeState[enuDIOPinNo]);
	   enuRetVar = E_OK;
   }
   else
   {
	   enuRetVar = E_ERROR;
   }
   return enuRetVar;	
}

/*************************************************************************************************
* Parameters	: enuDIOPinNo
* Return Value	: enuErrorStatus_t
* Description  : Toggle the state of the required LED
*************************************************************************************************/
/* A function to toggle the state of the required LED */
enuErrorStatus_t LED_Toggle(enuDIOPinNo_t enuDIOPinNo)
{
   enuErrorStatus_t enuRetVar;
   
   if(enuLEDState[enuDIOPinNo] == LED_INIT_DONE)
   {
	   /* Turning on the required LED */
	   DIO_PinToggle(enuDIOPinNo);
	   enuRetVar = E_OK;
   }
   else
   {
	   enuRetVar = E_ERROR;
   }
   return enuRetVar;	
}

