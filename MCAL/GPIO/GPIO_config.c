/*
 *       GPIO_config.c
 *
 *       Created on: Jan 27, 2021
 *       Author: Ahmed El-Gaafrawy
 */
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/errorStates.h"

#include "GPIO_config.h"
#include "GPIO_priv.h"
/********************************************************************************************/
/****                                 !!!!!Attention!!!!!                                ****/
/****                                                                                    ****/
/****       You must not repeat pin written in group into another To avoid Confusion     ****/
/********************************************************************************************/


/****                                 <<<<  NOTE  >>>>                                   ****/
/****        You can choose the mode for the same group pins from the following:         ****/
/****                                                                                    ****/
/****       GPIO_PIN_INPUT_ANALOG                               GPIO_PIN_INPUT_FLOAT
	        GPIO_PIN_INPUT_PULL_UP                              GPIO_PIN_INPUT_PULL_DOWN

	  GPIO_PIN_OUTPUT_PP_10MHZ    GPIO_PIN_OUTPUT_PP_2MHZ    GPIO_PIN_OUTPUT_PP_50MHZ
	  GPIO_PIN_OUTPUT_OD_10MHZ    GPIO_PIN_OUTPUT_OD_2MHZ    GPIO_PIN_OUTPUT_OD_50MHZ

	  GPIO_PIN_OUTPUT_AFPP_10MHZ    GPIO_PIN_OUTPUT_AFPP_2MHZ    GPIO_PIN_OUTPUT_AFPP_50MHZ
	  GPIO_PIN_OUTPUT_AFOD_10MHZ    GPIO_PIN_OUTPUT_AFOD_2MHZ    GPIO_PIN_OUTPUT_AFOD_50MHZ
                                                                                         ****/
/********************************************************************************************/
/********************************************************************************************/



/********************************************************************************************/
/********************************************************************************************/
/****                            Write Here Your Pins States                             ****/
/****                             As the following Examples:                             ****/
/**** GPIO_strPins_Info GPIO_strOut_2MHZ=
          {
              GPIO_PA0  | GPIO_PB10 | ... for pins   ,
              GPIO_PIN_OUTPUT_PP_2MHZ
          }                                                                              ****/
/**** GPIO_strPins_Info GPIO_strIn_PD=
          {
              GPIO_PC13  | GPIO_PB11 | ... for pins   ,
              GPIO_PIN_INPUT_PULL_DOWN
          }    and so on                                                                          ****/
/********************************************************************************************/
/********************************************************************************************/


GPIO_strPins_Info GPIO_strPinsStates=
	{
		//configure first pins of gpio here 
	};

/********************************************************************************************/