/*
 *       GPIO_priv.h
 *
 *       Created on: Jul 24, 2020
 *       Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_02_GPIO_GPIO_PRIV_H_
#define MCAL_02_GPIO_GPIO_PRIV_H_

typedef struct GPIO_CFG
{
	uint_32 GPIO_u32Pins;
	uint_32 GPIO_u32Mode_and_CNF;
}GPIO_strPins_Info;

typedef enum
{
	GPA0,         GPA1,         GPA2,         GPA3,
    GPA4,         GPA5,         GPA6,         GPA7,
	GPA8,         GPA9,         GPA10,        GPA11,
	GPA12,                                  GPA15,


	GPB0,         GPB1,                      GPB3,
	GPB4,         GPB5,         GPB6,         GPB7,
	GPB8,         GPB9,         GPB10,        GPB11,
	GPB12,        GPB13,        GPB14,        GPB15,

	GPC13,        GPC14,        GPC15,




	 GPIO_PA0 =(0x00000001),        GPIO_PB0 =(0x00004000),       GPIO_PC13=(0x20000000),
	 GPIO_PA1 =(0x00000002),        GPIO_PB1 =(0x00008000),       GPIO_PC14=(0x40000000),
	 GPIO_PA2 =(0x00000004),        /* PB2_LOCKED */              GPIO_PC15=(0x80000000),
	 GPIO_PA3 =(0x00000008),        GPIO_PB3 =(0x00010000),
	 GPIO_PA4 =(0x00000010),        GPIO_PB4 =(0x00020000),
	 GPIO_PA5 =(0x00000020),        GPIO_PB5 =(0x00040000),
	 GPIO_PA6 =(0x00000040),        GPIO_PB6 =(0x00080000),
	 GPIO_PA7 =(0x00000080),        GPIO_PB7 =(0x00100000),
	 GPIO_PA8 =(0x00000100),        GPIO_PB8 =(0x00200000),
	 GPIO_PA9 =(0x00000200),        GPIO_PB9 =(0x00400000),
	 GPIO_PA10=(0x00000400),        GPIO_PB10=(0x00800000),
	 GPIO_PA11=(0x00000800),        GPIO_PB11=(0x01000000),
	 GPIO_PA12=(0x00001000),        GPIO_PB12=(0x02000000),
	 /* PA13_LOCKED */              GPIO_PB13=(0x04000000),
	 /* PA14_LOCKED */              GPIO_PB14=(0x08000000),
	 GPIO_PA15=(0x00002000),        GPIO_PB15=(0x10000000),




	 GPIO_PIN_INPUT_ANALOG=(0x0),		GPIO_PIN_INPUT_FLOAT=(0x4),
	 GPIO_PIN_INPUT_PULL_UP=(0x8),		GPIO_PIN_INPUT_PULL_DOWN=(0x0C),

	 GPIO_PIN_OUTPUT_PP_10MHZ=(0x1),	GPIO_PIN_OUTPUT_PP_2MHZ=(0x2),	GPIO_PIN_OUTPUT_PP_50MHZ=(0x3),
	 GPIO_PIN_OUTPUT_OD_10MHZ=(0x5),	GPIO_PIN_OUTPUT_OD_2MHZ=(0x6),	GPIO_PIN_OUTPUT_OD_50MHZ=(0x7),

	 GPIO_PIN_OUTPUT_AFPP_10MHZ=(0x9),	GPIO_PIN_OUTPUT_AFPP_2MHZ=(0xA),GPIO_PIN_OUTPUT_AFPP_50MHZ=(0xB),
	 GPIO_PIN_OUTPUT_AFOD_10MHZ=(0xD),	GPIO_PIN_OUTPUT_AFOD_2MHZ=(0xE),GPIO_PIN_OUTPUT_AFOD_50MHZ=(0xF),

	 GPIO_ZERO=0,		GPIO_ONE,	GPIO_TWO,
	 GPIO_PIN_LOW=0,    GPIO_PIN_HIGH,
	 GPIO_MASKED_MODE=0x0f

}GPIO_enuPins_Info;


typedef struct
{
	uint_32 CRL;
	uint_32 CRH;
	volatile uint_32	IDR;
	uint_32 ODR;
	uint_32 BSRR;
	uint_32 BRR;
	uint_32 LCKR;
}PORT_str;

#define PORTA		((volatile PORT_str*) 0x40010800)
#define PORTB		((volatile PORT_str*) 0x40010C00)
#define PORTC		((volatile PORT_str*) 0x40011000)


#endif /* MCAL_02_GPIO_GPIO_PRIV_H_ */
