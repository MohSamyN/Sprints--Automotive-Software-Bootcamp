#include "DIO.h"

/* Testing App | 2 Buttons - 2 LEDs */
/* Pushing Button1 --> Turns LED1 On	*
 * Pushing Button2 --> Toggles LED2		*/
int main(void)
{
    DIO_Init();
	
	uint8_t u8Button1;
	uint8_t u8Button2;
	while(1)
	{
		DIO_Read(0, &u8Button1);
		DIO_Read(2, &u8Button2);	
		if(u8Button1 == LOW)
		{
			DIO_Write(1, HIGH);
		}
		else
		{
			DIO_Write(1, LOW);
		}
		if(u8Button2 == LOW)
		{
			DIO_Toggle(3);
			do 
			{
				DIO_Read(2, &u8Button2);

			} while(u8Button2 == LOW);
		}
		else
		{
		}
	}
}

