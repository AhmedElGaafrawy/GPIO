#include "../LIBRARY/stdTypes.h"
#include "../MCAL/RCC/RCC_int.h"
#include "../MCAL/GPIO/GPIO_int.h"

void delay_one_s(void);

int
main(void)
{
	//Choose your Clock Source
	//Set your Clock Source Configuration
	
	//Enable GPIOx Clock Bus 

	GPIO_strPins_Info GPIO_strPinOut=
		{
			GPIO_PA0|GPIO_PA1|GPIO_PA2|GPIO_PA3|GPIO_PA4|GPIO_PA5  
			, PIN_OUTPUT_PP_2MHZ
		};

	MGPIO_enuInit( & GPIO_strPinOut);
	
	MGPIO_enuSetPinDirection(GPA6,PIN_OUTPUT_PP_2MHZ);
	MGPIO_enuSetPinDirection(GPA7,PIN_OUTPUT_PP_2MHZ);

	while (1)
	{
		if (RCC_GetClkSrc() == 1)
		{
			MGPIO_enuSetPinValue(PA0,PIN_HIGH);
			delay_one_s();
			MGPIO_enuSetPinValue(PA0,PIN_LOW);
			MGPIO_enuSetPinValue(PA1,PIN_HIGH);
			delay_one_s();
			MGPIO_enuSetPinValue(PA1,PIN_LOW);
			MGPIO_enuSetPinValue(PA2,PIN_HIGH);
			delay_one_s();
			MGPIO_enuSetPinValue(PA2,PIN_LOW);
			MGPIO_enuSetPinValue(PA3,PIN_HIGH);
			delay_one_s();
			MGPIO_enuSetPinValue(PA3,PIN_LOW);
			MGPIO_enuSetPinValue(PA4,PIN_HIGH);
			delay_one_s();
			MGPIO_enuSetPinValue(PA4,PIN_LOW);
			MGPIO_enuSetPinValue(PA5,PIN_HIGH);
			delay_one_s();
			MGPIO_enuSetPinValue(PA5,PIN_LOW);
			MGPIO_enuSetPinValue(PA6,PIN_HIGH);
			delay_one_s();
			MGPIO_enuSetPinValue(PA6,PIN_LOW);
			MGPIO_enuSetPinValue(PA7,PIN_HIGH);
			delay_one_s();
			MGPIO_enuSetPinValue(PA7,PIN_LOW);
			delay_one_s();
		}
	}
	return 0;
}


void delay_one_s(void)
{
	uint_16 i=0, j=0;
	for (i=0;i<660;i++)
		for(j=0;j<660;j++)
			asm("NOP");
}
