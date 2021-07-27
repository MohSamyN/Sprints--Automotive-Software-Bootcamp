#include "TWI.h"


int main(void)
{
   enuTWIStatus_t enuTWIStatus;
	
	TWI_MasterInit(71, TWI_FOSC_OVER_64);
	// Master Write
	TWI_Start();
	TWI_CheckStatus(&enuTWIStatus);
	if(enuTWIStatus == TWI_MASTER_START_CONDITION_CODE)
	{
		TWI_Write(0xA0);	
		TWI_CheckStatus(&enuTWIStatus);
		if(enuTWIStatus == TWI_MASTER_SLA_W_ACK_CONDITION_CODE)
		{
			TWI_Write((uint8_t)'A');
			TWI_CheckStatus(&enuTWIStatus);
			if(enuTWIStatus == TWI_MASTER_DATA_W_ACK_CONDITION_CODE)
			{
				TWI_Stop();
			}
		}
	}
   while(1) 
   {
   }
}

