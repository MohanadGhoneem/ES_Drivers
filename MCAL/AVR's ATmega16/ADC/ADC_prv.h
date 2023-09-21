/*
 * File Name:			ADC_prv.h
 * Description:			Private Header File for ADC Driver
 * Creation Date:		30-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			30-Aug-23
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_


/****************** Macros ******************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

#define ADC_DISABLE		0
#define	ADC_ENABLE		1

#define ADC_RIGHT		0
#define ADC_LEFT		1

#define SINGLE_CONV		0xFF

/****************** Definitions ******************/
#define CHANNEL_00			0
#define CHANNEL_01			1
#define CHANNEL_02			2
#define CHANNEL_03			3
#define CHANNEL_04			4
#define CHANNEL_05			5
#define CHANNEL_06			6
#define CHANNEL_07			7

typedef enum
{
	AREF, AVCC, RESERVED, INTERNAL2_56
}ADC_ReferenceVolatge;

typedef enum
{
	PRE_1, PRE_2, PRE_4, PRE_8, PRE_16, PRE_32, PRE_64, PRE_128
}ADC_Prescaler;

typedef enum
{
	FREE_RUNNING, ANALOG_COMP, EXTI, TIMER0_COMP_MATCH, TIMER0_OF,
	TIMER_COMP_MATCH_B, TIMER1_COMP_MATCH, TIMER1_OF
}ADC_AutoTriggerMode;

typedef enum
{
	ADC_COMPLETE,
	ADC_NOT_COMPLETE
}FlagStatus_t;

/****************** Registers Addresses ******************/
#define ADMUX			*((volatile u8*) (0x27))
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define ADLAR   5
#define REFS0   6
#define REFS1   7

#define ADCSRA			*((volatile u8*) (0x26))
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define SFIOR			*((volatile u8*) (0x50))
#define PSR10   0
#define PSR2    1
#define PUD     2
#define ACME    3
#define ADTS0   5
#define ADTS1   6
#define ADTS2   7

#define ADCL			*((volatile u8*) (0x24))

#define ADCH			*((volatile u8*) (0x25))

#define ADC				*((volatile u16*) (0x24))	/* Points to Low Byte Only */


#endif /* MCAL_ADC_ADC_PRV_H_ */
