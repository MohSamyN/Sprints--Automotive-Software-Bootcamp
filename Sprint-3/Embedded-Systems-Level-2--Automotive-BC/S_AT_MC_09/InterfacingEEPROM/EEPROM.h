#ifndef EEPROM_H_
#define EEPROM_H_

#include "TWI.h"
#include "STD_TYPES.h"

/*************************************************************************************************
* Parameters	: u8TWIBitRate, enuTWIPrescalerSelect
* Return Value	: enuErrorStatus_t
* Description  : Initialize the TWI module to start using the external EEPROM
*************************************************************************************************/
enuErrorStatus_t EEPROM_Init(uint8_t u8TWIBitRate, enuTWIPrescalerSelect_t enuTWIPrescalerSelect);
/*************************************************************************************************
* Parameters	: u16Address, u8Data
* Return Value	: enuErrorStatus_t
* Description  : Initialize one DIO pin according to the configuration
*************************************************************************************************/
enuErrorStatus_t EEPROM_Write(uint16_t u16Address, uint8_t u8Data);
/*************************************************************************************************
* Parameters	: u16Address, pu8Data
* Return Value	: enuErrorStatus_t
* Description  : Initialize one DIO pin according to the configuration
*************************************************************************************************/
enuErrorStatus_t EEPROM_Read(uint16_t u16Address, uint8_t* pu8Data);

#endif /* EEPROM_H_ */