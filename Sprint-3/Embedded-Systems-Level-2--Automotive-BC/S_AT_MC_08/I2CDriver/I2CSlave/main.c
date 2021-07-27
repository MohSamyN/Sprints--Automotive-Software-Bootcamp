#include "DIO.h"
#include "TWI.h"


int main(void)
{
   enuTWIStatus_t enuTWIStatus;
	uint8_t u8Data;
	
	DIO_PortInit(PORTD, 0xFF, 0x00);
	TWI_SlaveInit(0xA0, TWI_DISABLE_GENERAL_CALL_RECOGNITION, TWI_ENABLE_ACKNOWLEDGE);
	// Slave Read
	TWI_Listen();
	TWI_CheckStatus(&enuTWIStatus);
	if(enuTWIStatus == TWI_SLAVE_SLA_W_ACK_CONDITION_CODE)
	{	
		TWI_Read(&u8Data);
		TWI_CheckStatus(&enuTWIStatus);
		if(enuTWIStatus == TWI_SLAVE_PREVIOUSLY_SLA_W_ACK_CONDITION_CODE)
		{		
			DIO_PortWrite(PORTD, u8Data);
		}
	}
   while(1) 
   {
   }
}

