#ifndef UART_H_
#define UART_H_

#include "STD_TYPES.h"
#include "BIT_MANIPULATE.h"

#define F_CPU															8000000u

typedef enum {UART_DISABLE_PARITY, UART_ENABLE_EVEN_PARITY = 2, UART_ENABLE_ODD_PARITY} enuUARTParityMode_t;
typedef enum {UART_ONE_STOP_BIT, UART_TWO_STOP_BITS} enuUARTStopBitSelect_t;
typedef enum {UART_FIVE_CHARACTER_BITS, UART_SIX_CHARACTER_BITS, UART_SEVEN_CHARACTER_BITS, UART_EIGHT_CHARACTER_BITS, UART_NINE_CHARACTER_BITS = 7} enuUARTCharacterSize_t;

/*************************************************************************************************
* Parameters	: u32UARTBaudrate, enuUARTCharacterSize, enuUARTStopBitSelect, enuUARTParityMode
* Return Value	: enuErrorStatus_t
* Description  : Initialize UART module according to the configuration
*************************************************************************************************/
enuErrorStatus_t UART_Init(uint32_t u32UARTBaudrate, enuUARTCharacterSize_t enuUARTCharacterSize, enuUARTStopBitSelect_t enuUARTStopBitSelect, enuUARTParityMode_t enuUARTParityModed);
/*************************************************************************************************
* Parameters	: u16Data
* Return Value	: enuErrorStatus_t
* Description  : Initiate a data transmission from UART module to external module
*************************************************************************************************/
enuErrorStatus_t UART_SendData(uint16_t u16Data);
/*************************************************************************************************
* Parameters	: *pu16Data
* Return Value	: enuErrorStatus_t
* Description  : Initiate a data reception on UART module from external module
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveData(uint16_t* pu16Data);
/*************************************************************************************************
* Parameters	: *pu16Data
* Return Value	: enuErrorStatus_t
* Description  : Initiate a data transmission from UART module to external module
*************************************************************************************************/
enuErrorStatus_t UART_SendString(uint8_t* pu8String);
/*************************************************************************************************
* Parameters	: *pu16Data
* Return Value	: enuErrorStatus_t
* Description  : Initiate a data reception on UART module from external module
*************************************************************************************************/
enuErrorStatus_t UART_ReceiveString(uint8_t* pu8String);

#endif /* UART_H_ */