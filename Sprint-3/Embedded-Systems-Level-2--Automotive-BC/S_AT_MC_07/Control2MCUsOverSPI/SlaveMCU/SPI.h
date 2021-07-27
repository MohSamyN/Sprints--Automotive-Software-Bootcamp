#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"
#include "STD_TYPES.h"
#include "BIT_MANIPULATE.h"

#define F_CPU																		8000000u

typedef enum {SPI_FOSC_OVER_4, SPI_FOSC_OVER_16, SPI_FOSC_OVER_64_WITHOUT_DOUBLE_SPEED, SPI_FOSC_OVER_128,
				  SPI_FOSC_OVER_2, SPI_FOSC_OVER_8, SPI_FOSC_OVER_32, SPI_FOSC_OVER_64_WITH_DOUBLE_SPEED} enuSPIClockRateSelect_t;
typedef enum {SPI_CPHA_LOW, SPI_CPHA_HIGH} enuSPIClockPhase_t;
typedef enum {SPI_CPOL_LOW, SPI_CPOL_HIGH} enuSPIClockPolarity_t;
typedef enum {SPI_SLAVE_MODE, SPI_MASTER_MODE} enuSPIMasterSlaveSelect_t;
typedef enum {SPI_MSB_TRANSMITTED_FIRST, SPI_LSB_TRANSMITTED_FIRST} enuSPIDataOrder_t;

/*************************************************************************************************
* Parameters	: enuSPIClockRateSelect, enuSPIClockPhase, enuSPIClockPolarity,
*					  enuSPIMasterSlaveSelect, enuSPIDataOrder
* Return Value	: enuErrorStatus_t
* Description  : Initialize the SPI module according to the configuration
*************************************************************************************************/
enuErrorStatus_t SPI_Init(enuSPIClockRateSelect_t enuSPIClockRateSelect, enuSPIClockPhase_t enuSPIClockPhase, enuSPIClockPolarity_t enuSPIClockPolarity,
								  enuSPIMasterSlaveSelect_t enuSPIMasterSlaveSelect, enuSPIDataOrder_t enuSPIDataOrder);
/*************************************************************************************************
* Parameters	: u8Data
* Return Value	: enuErrorStatus_t
* Description  : Send a character to another module  
*************************************************************************************************/
enuErrorStatus_t SPI_SendChar(uint8_t u8Data);
/*************************************************************************************************
* Parameters	: pu8Data
* Return Value	: enuErrorStatus_t
* Description  : Receive a character from another module
*************************************************************************************************/
enuErrorStatus_t SPI_ReceiveChar(uint8_t* pu8Data);
/*************************************************************************************************
* Parameters	: pu8Data
* Return Value	: enuErrorStatus_t
* Description  : Send a string to another module
*************************************************************************************************/
enuErrorStatus_t SPI_SendString(uint8_t* pu8Data);
/*************************************************************************************************
* Parameters	: pu8Data
* Return Value	: enuErrorStatus_t
* Description  : Receive a string from another module
*************************************************************************************************/
enuErrorStatus_t SPI_ReceiveString(uint8_t* pu8Data);

#endif /* SPI_H_ */