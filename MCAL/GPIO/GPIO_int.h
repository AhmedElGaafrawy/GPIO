/*
 *       GPIO_int.h
 *
 *       Created on: Jul 24, 2020
 *       Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_02_GPIO_GPIO_INT_H_
#define MCAL_02_GPIO_GPIO_INT_H_


#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/errorStates.h"

#include "GPIO_config.h"
#include "GPIO_priv.h"


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuInit.                                        **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pointer to GPIO_strPins_Info struct.                  **/
/** Functionality   : Setting the initial direction and Value of GPIO pins. **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuInit(GPIO_strPins_Info * Copy_PstrInit);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuSetPinDirection.                             **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pin Number and its Direction(Input or Output).        **/
/** Functionality   : Setting the direction of specific pin at run time.    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuSetPinDirection(uint_8 Copy_u8PinID, uint_8 Copy_u8PinDirection);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuSetPinValue.                                 **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pin number and its Value(High or Low).                **/
/** Functionality   : Setting the value of specific pin at run time.        **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuSetPinValue(uint_8 Copy_u8PinID, uint_8 Copy_u8PinValue);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuTogglePinValue.                              **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pin number.                                           **/
/** Functionality   : Toggling the value of specific pin at run time.       **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuTogglePinValue(uint_8 Copy_u8PinID);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuGetPinValue.                                 **/
/** Return Type     : ERROR_STATES enum and The the pin value as a pointer. **/
/** Arguments       : Pin number, pointer to var will contain the pin value.**/
/** Functionality   : Getting the value of specific pin at run time.        **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuGetPinValue(uint_8 Copy_u8PinID, puint_8 Copy_Pu8PinValue);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



typedef enum
{
	PA0,         PA1,         PA2,         PA3,
    PA4,         PA5,         PA6,         PA7,
	PA8,         PA9,         PA10,        PA11,
	PA12,                                  PA15,


	PB0,         PB1,                      PB3,
	PB4,         PB5,         PB6,         PB7,
	PB8,         PB9,         PB10,        PB11,
	PB12,        PB13,        PB14,        PB15,

	PC13,        PC14,        PC15,


	PIN_INPUT_ANALOG=(0x0),         PIN_INPUT_FLOAT=(0x4),
	PIN_INPUT_PULL_UP=(0x8),        PIN_INPUT_PULL_DOWN=(0xC),

	PIN_OUTPUT_PP_10MHZ=(0x1),      PIN_OUTPUT_PP_2MHZ=(0x2),      PIN_OUTPUT_PP_50MHZ=(0x3),
	PIN_OUTPUT_OD_10MHZ=(0x5),      PIN_OUTPUT_OD_2MHZ=(0x6),      PIN_OUTPUT_OD_50MHZ=(0x7),

	PIN_OUTPUT_AFPP_10MHZ=(0x9),    PIN_OUTPUT_AFPP_2MHZ=(0xA),    PIN_OUTPUT_AFPP_50MHZ=(0xB),
	PIN_OUTPUT_AFOD_10MHZ=(0xD),    PIN_OUTPUT_AFOD_2MHZ=(0xE),    PIN_OUTPUT_AFOD_50MHZ=(0xF),

	PIN_LOW=0,    					PIN_HIGH
}GPIO_info_enu_ForApp;


#endif /* MCAL_02_GPIO_GPIO_INT_H_ */
