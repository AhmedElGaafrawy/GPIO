/*
 *       GPIO_prog.c
 *
 *       Created on: Jul 24, 2020
 *       Author: Ahmed El-Gaafrawy
 */

#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/errorStates.h"

#include "GPIO_config.h"
#include "GPIO_priv.h"


uint_8 GPIO_Au8PullDown[GPC15]={0};
uint_8 GPIO_u8PDFlag=0;

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MGPIO_enuInit.                                        **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pointer to GPIO_strPins_Info struct.                  **/
/** Functionality   : Setting the initial direction and Value of GPIO pins. **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MGPIO_enuInit(GPIO_strPins_Info * Copy_PstrInit)
{
	ERROR_STATES Local_enuErrorState =ES_NOT_OK;

	uint_8 Local_u8Iterator =0 , Local_u8Pin=0;
	uint_8 Local_Au8SelectedPins[32]={0};

	uint_32 Local_u32PinConfig = Copy_PstrInit-> GPIO_u32Mode_and_CNF;

	if (Copy_PstrInit->GPIO_u32Mode_and_CNF == GPIO_PIN_INPUT_PULL_DOWN)
	{
		Local_u32PinConfig = GPIO_PIN_INPUT_PULL_UP;
		GPIO_u8PDFlag=GPIO_ONE;
	}

	for(Local_u8Iterator=0;Local_u8Iterator<32;Local_u8Iterator++)
	{
		Local_u8Pin=( (Copy_PstrInit->GPIO_u32Pins >>Local_u8Iterator) & GPIO_ONE);
		if (Local_u8Pin)
		{
			Local_Au8SelectedPins[Local_u8Iterator]=Local_u8Pin;
			if (GPIO_u8PDFlag)
			{
				GPIO_Au8PullDown[Local_u8Iterator]=Local_u8Pin;
			}
		}

	}

	GPIO_u8PDFlag=GPIO_ZERO;

	for(Local_u8Iterator=0;Local_u8Iterator<32;Local_u8Iterator++)
	{
		if (Local_Au8SelectedPins[Local_u8Iterator])
		{
			switch(Local_u8Iterator)
			{
			case GPA0:	case GPA1:	case GPA2:	case GPA3:
			case GPA4:	case GPA5:	case GPA6:	case GPA7:
				PORTA->CRL &=~( (GPIO_MASKED_MODE)   << ((Local_u8Iterator-GPA0)*GPA4));
				PORTA->CRL |= ( (Local_u32PinConfig) << ((Local_u8Iterator-GPA0)*GPA4));
				Local_enuErrorState =ES_OK;

				break;


			case GPA8:	case GPA9:	case GPA10:
			case GPA11: case GPA12:
				PORTA->CRH &=~( (GPIO_MASKED_MODE)   << ((Local_u8Iterator-GPA8)*GPA4));
				PORTA->CRH |= ( (Local_u32PinConfig) << ((Local_u8Iterator-GPA8)*GPA4));
				Local_enuErrorState =ES_OK;

				break;


			case GPA15:
				PORTA->CRH &=~( (GPIO_MASKED_MODE)   << ((Local_u8Iterator-GPA6)*GPA4));
				PORTA->CRH |= ( (Local_u32PinConfig) << ((Local_u8Iterator-GPA6)*GPA4));
				Local_enuErrorState =ES_OK;

				break;


			case GPB0:	case GPB1:
				PORTB->CRL &=~( (GPIO_MASKED_MODE)   << ((Local_u8Iterator-GPB0)*GPA4));
				PORTB->CRL |= ( (Local_u32PinConfig) << ((Local_u8Iterator-GPB0)*GPA4));
				Local_enuErrorState =ES_OK;

				break;


			case GPB3:	case GPB4:	case GPB5:
			case GPB6:	case GPB7:
				PORTB->CRL &=~( (GPIO_MASKED_MODE)   << ((Local_u8Iterator-GPA15)*GPA4));
				PORTB->CRL |= ( (Local_u32PinConfig) << ((Local_u8Iterator-GPA15)*GPA4));
				Local_enuErrorState =ES_OK;

				break;


			case GPB8:	case GPB9:	case GPB10:	case GPB11:
			case GPB12:	case GPB13:	case GPB14:	case GPB15:
				PORTB->CRH &=~( (GPIO_MASKED_MODE)   << ((Local_u8Iterator-GPB8)*GPA4));
				PORTB->CRH |= ( (Local_u32PinConfig) << ((Local_u8Iterator-GPB8)*GPA4));
				Local_enuErrorState =ES_OK;

				break;


			case GPC13:	case GPC14:	case GPC15:
				PORTC->CRH &=~( (GPIO_MASKED_MODE)   << ((Local_u8Iterator-GPB11)*GPA4));
				PORTC->CRH |= ( (Local_u32PinConfig) << ((Local_u8Iterator-GPB11)*GPA4));
				Local_enuErrorState =ES_OK;

				break;


			default:
				Local_enuErrorState =ES_OUT_OF_RANGE;

			}
		}
		else
		{
			Local_enuErrorState =ES_NOT_SELECTED;
		}
	}
	return Local_enuErrorState;
}
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
ERROR_STATES MGPIO_enuSetPinDirection(uint_8 Copy_u8PinID, uint_8 Copy_u8PinDirection)
{
	ERROR_STATES Local_enuErrorState =ES_NOT_OK;

	if (Copy_u8PinDirection == GPIO_PIN_INPUT_PULL_DOWN)
	{
		Copy_u8PinDirection  = GPIO_PIN_INPUT_PULL_UP;
	}



	if (Copy_u8PinID <= GPC15
			&& Copy_u8PinDirection <= GPIO_PIN_OUTPUT_AFOD_50MHZ
			&& Copy_u8PinDirection != GPIO_PIN_INPUT_PULL_DOWN)
	{
		switch(Copy_u8PinID)
		{
		case GPA0:	case GPA1:	case GPA2:	case GPA3:
		case GPA4:	case GPA5:	case GPA6:	case GPA7:
			PORTA->CRL &=~( (GPIO_MASKED_MODE)    << ((Copy_u8PinID - GPA0)*GPA4));
			PORTA->CRL |= ( (Copy_u8PinDirection) << ((Copy_u8PinID - GPA0)*GPA4));
			Local_enuErrorState =ES_OK;

			break;


		case GPA8:	case GPA9:	case GPA10:
		case GPA11: case GPA12:
			PORTA->CRH &=~( (GPIO_MASKED_MODE)    << ((Copy_u8PinID-GPA8)*GPA4));
			PORTA->CRH |= ( (Copy_u8PinDirection) << ((Copy_u8PinID-GPA8)*GPA4));
			Local_enuErrorState =ES_OK;

			break;


		case GPA15:
			PORTA->CRH &=~( (GPIO_MASKED_MODE)    << ((Copy_u8PinID-GPA6)*GPA4));
			PORTA->CRH |= ( (Copy_u8PinDirection) << ((Copy_u8PinID-GPA6)*GPA4));
			Local_enuErrorState =ES_OK;

			break;


		case GPB0:	case GPB1:
			PORTB->CRL &=~( (GPIO_MASKED_MODE)    << ((Copy_u8PinID-GPB0)*GPA4));
			PORTB->CRL |= ( (Copy_u8PinDirection) << ((Copy_u8PinID-GPB0)*GPA4));
			Local_enuErrorState =ES_OK;

			break;


		case GPB3:	case GPB4:	case GPB5:
		case GPB6:	case GPB7:
			PORTB->CRL &=~( (GPIO_MASKED_MODE)    << ((Copy_u8PinID-GPA15)*GPA4));
			PORTB->CRL |= ( (Copy_u8PinDirection) << ((Copy_u8PinID-GPA15)*GPA4));
			Local_enuErrorState =ES_OK;

			break;


		case GPB8:	case GPB9:	case GPB10:	case GPB11:
		case GPB12:	case GPB13:	case GPB14:	case GPB15:
			PORTB->CRH &=~( (GPIO_MASKED_MODE)    << ((Copy_u8PinID-GPB8)*GPA4));
			PORTB->CRH |= ( (Copy_u8PinDirection) << ((Copy_u8PinID-GPB8)*GPA4));
			Local_enuErrorState =ES_OK;

			break;


		case GPC13:	case GPC14:	case GPC15:
			PORTC->CRH &=~( (GPIO_MASKED_MODE)    << ((Copy_u8PinID-GPB11)*GPA4));
			PORTC->CRH |= ( (Copy_u8PinDirection) << ((Copy_u8PinID-GPB11)*GPA4));
			Local_enuErrorState =ES_OK;

			break;


		default:
			Local_enuErrorState =ES_OUT_OF_RANGE;

		}
	}
	else
	{
		Local_enuErrorState =ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}
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
ERROR_STATES MGPIO_enuSetPinValue(uint_8 Copy_u8PinID, uint_8 Copy_u8PinValue)
{
	ERROR_STATES Local_enuErrorState =ES_NOT_OK;

	uint_8 Local_u8PinMode=0xFF;
	uint_16 Local_Au16PinMask[16]=
			{
				(0x0001),	(0x0002),	(0x0004),	(0x0008),
				(0x0010), 	(0x0020),	(0x0040),	(0x0080),
				(0x0100), 	(0x0200),	(0x0400),	(0x0800),
				(0x1000), 	(0x2000),	(0x4000),	(0x8000)
			};

	if (Copy_u8PinID <= GPC15
		&& Copy_u8PinValue <=GPIO_PIN_HIGH)
	{
		switch(Copy_u8PinID)
		{
		case GPA0:	case GPA1:	case GPA2:	case GPA3:
		case GPA4:	case GPA5:	case GPA6:	case GPA7:

			Local_u8PinMode = ( (PORTA->CRL >> ((Copy_u8PinID-GPA0) * GPA4)) & (GPIO_MASKED_MODE) );

			if (   Local_u8PinMode >= GPIO_PIN_OUTPUT_PP_10MHZ
				&& Local_u8PinMode <= GPIO_PIN_OUTPUT_AFOD_50MHZ
				&& Local_u8PinMode != GPIO_PIN_INPUT_FLOAT
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_UP
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_DOWN
				)
			{
				if (Copy_u8PinValue == GPIO_PIN_LOW)
				{
					PORTA->BRR=Local_Au16PinMask[Copy_u8PinID];
					Local_enuErrorState =ES_OK;
				}
				else
				{
					PORTA->BSRR=Local_Au16PinMask[Copy_u8PinID];
					Local_enuErrorState =ES_OK;
				}
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTA->ODR &=~(GPIO_ONE<<Copy_u8PinID);
				Local_enuErrorState =ES_FORCE_TO_PULL_DOWN;
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && ! GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTA->ODR |= (GPIO_ONE<<Copy_u8PinID);
				Local_enuErrorState =ES_FORCE_TO_PULL_UP;
			}

			break;


		case GPA8:	case GPA9:	case GPA10:
		case GPA11: case GPA12:

			Local_u8PinMode = ( (PORTA->CRH >> ((Copy_u8PinID - GPA8)*GPA4)) & (GPIO_MASKED_MODE) );

			if (   Local_u8PinMode >= GPIO_PIN_OUTPUT_PP_10MHZ
				&& Local_u8PinMode <= GPIO_PIN_OUTPUT_AFOD_50MHZ
				&& Local_u8PinMode != GPIO_PIN_INPUT_FLOAT
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_UP
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_DOWN
				)
			{
				if (Copy_u8PinValue == GPIO_PIN_LOW)
				{
					PORTA->BRR=Local_Au16PinMask[Copy_u8PinID];
					Local_enuErrorState =ES_OK;
				}
				else
				{
					PORTA->BSRR=Local_Au16PinMask[Copy_u8PinID];
					Local_enuErrorState =ES_OK;
				}
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTA->ODR &=~(GPIO_ONE<<Copy_u8PinID);
				Local_enuErrorState =ES_FORCE_TO_PULL_DOWN;
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && ! GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTA->ODR |= (GPIO_ONE<<Copy_u8PinID);
				Local_enuErrorState =ES_FORCE_TO_PULL_UP;
			}

			break;


		case GPA15:

			Local_u8PinMode = ( (PORTA->CRH >> ((Copy_u8PinID - GPA6)*GPA4)) & (GPIO_MASKED_MODE) );

			if (   Local_u8PinMode >= GPIO_PIN_OUTPUT_PP_10MHZ
				&& Local_u8PinMode <= GPIO_PIN_OUTPUT_AFOD_50MHZ
				&& Local_u8PinMode != GPIO_PIN_INPUT_FLOAT
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_UP
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_DOWN
				)
			{
				if (Copy_u8PinValue == GPIO_PIN_LOW)
				{
					PORTA->BRR=Local_Au16PinMask[Copy_u8PinID + GPA2];
					Local_enuErrorState =ES_OK;
				}
				else
				{
					PORTA->BSRR=Local_Au16PinMask[Copy_u8PinID + GPA2];
					Local_enuErrorState =ES_OK;
				}
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTA->ODR &=~(GPIO_ONE<<(Copy_u8PinID + GPA2));
				Local_enuErrorState =ES_FORCE_TO_PULL_DOWN;
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && !GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTA->ODR |= (GPIO_ONE<<(Copy_u8PinID + GPA2));
				Local_enuErrorState =ES_FORCE_TO_PULL_UP;
			}

			break;


		case GPB0:	case GPB1:

			Local_u8PinMode = ( (PORTB->CRL >> ((Copy_u8PinID - GPB0)*GPA4)) & (GPIO_MASKED_MODE) );

			if (   Local_u8PinMode >= GPIO_PIN_OUTPUT_PP_10MHZ
				&& Local_u8PinMode <= GPIO_PIN_OUTPUT_AFOD_50MHZ
				&& Local_u8PinMode != GPIO_PIN_INPUT_FLOAT
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_UP
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_DOWN
				)
			{
				if (Copy_u8PinValue == GPIO_PIN_LOW)
				{
					PORTB->BRR=Local_Au16PinMask[Copy_u8PinID - GPB0];
					Local_enuErrorState =ES_OK;
				}
				else
				{
					PORTB->BSRR=Local_Au16PinMask[Copy_u8PinID - GPB0];
					Local_enuErrorState =ES_OK;
				}
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTB->ODR &=~(GPIO_ONE<<(Copy_u8PinID - GPB0));
				Local_enuErrorState =ES_FORCE_TO_PULL_DOWN;
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && ! GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTB->ODR |= (GPIO_ONE<<(Copy_u8PinID - GPB0));
				Local_enuErrorState =ES_FORCE_TO_PULL_UP;
			}

			break;


		case GPB3:	case GPB4:	case GPB5:
		case GPB6:	case GPB7:

			Local_u8PinMode = ( (PORTB->CRL >> ((Copy_u8PinID - GPA15)*GPA4)) & (GPIO_MASKED_MODE) );

			if (   Local_u8PinMode >= GPIO_PIN_OUTPUT_PP_10MHZ
				&& Local_u8PinMode <= GPIO_PIN_OUTPUT_AFOD_50MHZ
				&& Local_u8PinMode != GPIO_PIN_INPUT_FLOAT
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_UP
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_DOWN
				)
			{
				if (Copy_u8PinValue == GPIO_PIN_LOW)
				{
					PORTB->BRR=Local_Au16PinMask[Copy_u8PinID - GPA15];
					Local_enuErrorState =ES_OK;
				}
				else
				{
					PORTB->BSRR=Local_Au16PinMask[Copy_u8PinID - GPA15];
					Local_enuErrorState =ES_OK;
				}
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTB->ODR &=~(GPIO_ONE<<(Copy_u8PinID - GPA15));
				Local_enuErrorState =ES_FORCE_TO_PULL_DOWN;
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && ! GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTB->ODR |= (GPIO_ONE<<(Copy_u8PinID - GPA15));
				Local_enuErrorState =ES_FORCE_TO_PULL_UP;
			}

			break;


		case GPB8:	case GPB9:	case GPB10:	case GPB11:
		case GPB12:	case GPB13:	case GPB14:	case GPB15:

			Local_u8PinMode = ( (PORTB->CRH >> ((Copy_u8PinID - GPB8)*GPA4)) & (GPIO_MASKED_MODE) );

			if (   Local_u8PinMode >= GPIO_PIN_OUTPUT_PP_10MHZ
				&& Local_u8PinMode <= GPIO_PIN_OUTPUT_AFOD_50MHZ
				&& Local_u8PinMode != GPIO_PIN_INPUT_FLOAT
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_UP
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_DOWN
				)
			{
				if (Copy_u8PinValue == GPIO_PIN_LOW)
				{
					PORTB->BRR=Local_Au16PinMask[Copy_u8PinID - GPA15];
					Local_enuErrorState =ES_OK;
				}
				else
				{
					PORTB->BSRR=Local_Au16PinMask[Copy_u8PinID - GPA15];
					Local_enuErrorState =ES_OK;
				}
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTB->ODR &=~(GPIO_ONE<<(Copy_u8PinID - GPA15));
				Local_enuErrorState =ES_FORCE_TO_PULL_DOWN;
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && ! GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTB->ODR |= (GPIO_ONE<<(Copy_u8PinID - GPA15));
				Local_enuErrorState =ES_FORCE_TO_PULL_UP;
			}

			break;


		case GPC13:	case GPC14:	case GPC15:

			Local_u8PinMode = ( (PORTC->CRH >> ((Copy_u8PinID - GPB11)*GPA4)) & (GPIO_MASKED_MODE) );

			if (   Local_u8PinMode >= GPIO_PIN_OUTPUT_PP_10MHZ
				&& Local_u8PinMode <= GPIO_PIN_OUTPUT_AFOD_50MHZ
				&& Local_u8PinMode != GPIO_PIN_INPUT_FLOAT
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_UP
				&& Local_u8PinMode != GPIO_PIN_INPUT_PULL_DOWN
				)
			{
				if (Copy_u8PinValue == GPIO_PIN_LOW)
				{
					PORTC->BRR=Local_Au16PinMask[Copy_u8PinID - GPB3];
					Local_enuErrorState =ES_OK;
				}
				else
				{
					Local_enuErrorState =ES_NOT_SELECTED;
				}
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && GPIO_Au8PullDown[Copy_u8PinID] )
			{
				PORTC->ODR &=~(GPIO_ONE<<(Copy_u8PinID - GPB3));
				Local_enuErrorState =ES_FORCE_TO_PULL_DOWN;
			}
			else if (Local_u8PinMode == GPIO_PIN_INPUT_PULL_UP && ! GPIO_Au8PullDown[Copy_u8PinID] )
			{
				Local_enuErrorState =ES_NOT_SELECTED;
			}


			break;


		default:
			Local_enuErrorState =ES_OUT_OF_RANGE;

		}
	}

	return Local_enuErrorState;
}
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
ERROR_STATES MGPIO_enuTogglePinValue(uint_8 Copy_u8PinID)
{
	ERROR_STATES Local_enuErrorState =ES_NOT_OK;

	if (Copy_u8PinID <= GPB15)
	{
		switch(Copy_u8PinID)
		{
		case GPA0:	case GPA1:	case GPA2:	case GPA3:
		case GPA4:	case GPA5:	case GPA6:	case GPA7:
		case GPA8:	case GPA9:	case GPA10: case GPA11:
		case GPA12:
			PORTA->ODR ^= (GPIO_ONE<<(Copy_u8PinID - GPA0));
			Local_enuErrorState =ES_OK;

			break;


		case GPA15:
			PORTA->ODR ^= (GPIO_ONE << (Copy_u8PinID+GPA2));
			Local_enuErrorState =ES_OK;

			break;


		case GPB0:	case GPB1:
			PORTB->ODR ^= (GPIO_ONE << (Copy_u8PinID-GPB0));
			Local_enuErrorState =ES_OK;

			break;


		case GPB3:	case GPB4:	case GPB5:	case GPB6:
		case GPB7:	case GPB8:	case GPB9:	case GPB10:
		case GPB11:	case GPB12:	case GPB13:	case GPB14:
		case GPB15:
			PORTB->ODR ^= (GPIO_ONE << (Copy_u8PinID-GPA15));
			Local_enuErrorState =ES_OK;

			break;



		default:
			Local_enuErrorState =ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState =ES_NOT_SELECTED;
	}
	return Local_enuErrorState;
}
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
ERROR_STATES MGPIO_enuGetPinValue(uint_8 Copy_u8PinID, uint_8 * Copy_Pu8PinValue)
{
	ERROR_STATES Local_enuErrorState =ES_NOT_OK;

	if (Copy_u8PinID <= GPB15)
	{
		switch(Copy_u8PinID)
		{
		case GPA0:	case GPA1:	case GPA2:	case GPA3:
		case GPA4:	case GPA5:	case GPA6:	case GPA7:
		case GPA8:	case GPA9:	case GPA10: case GPA11:
		case GPA12:
			*Copy_Pu8PinValue = ( (PORTA->IDR >>(Copy_u8PinID - GPA0)) & GPIO_ONE);
			Local_enuErrorState =ES_OK;

			break;


		case GPA15:
			*Copy_Pu8PinValue = ( (PORTA->IDR >>(Copy_u8PinID+GPA2)) & GPIO_ONE);
			Local_enuErrorState =ES_OK;

			break;


		case GPB0:	case GPB1:
			*Copy_Pu8PinValue = ( (PORTB->IDR >>(Copy_u8PinID-GPB0)) & GPIO_ONE);
			Local_enuErrorState =ES_OK;

			break;


		case GPB3:	case GPB4:	case GPB5:	case GPB6:
		case GPB7:	case GPB8:	case GPB9:	case GPB10:
		case GPB11:	case GPB12:	case GPB13:	case GPB14:
		case GPB15:
			*Copy_Pu8PinValue = ( (PORTB->IDR >>(Copy_u8PinID-GPA15)) & GPIO_ONE);
			Local_enuErrorState =ES_OK;

			break;


		case GPC13:	case GPC14:	case GPC15:
			*Copy_Pu8PinValue = ( (PORTC->IDR >>(Copy_u8PinID-GPB3)) & GPIO_ONE);
			Local_enuErrorState =ES_OK;

			break;


		default:
			Local_enuErrorState =ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState =ES_NOT_SELECTED;
	}

	return Local_enuErrorState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/