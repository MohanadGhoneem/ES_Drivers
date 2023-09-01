/*
 * File Name:			EXTI_prv.h
 * Description:			Private Header File for the External Interrupt in AVR ATmega16/32
 * Creation Date:		01-Sep-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			01-Sep-23
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

/****************** Defines ******************/
#define ENABLE		1
#define DISABLE		0


/****************** Enums ******************/
typedef enum
{
	EXTI_RISING_ID, EXTI_FALLING_ID, EXTI_ONCHANGE_ID
}EXTI_SenseControl_ID;

typedef enum
{
	EXTI0_ID, EXTI1_ID, EXTI2_ID
}EXTI_LineNo_ID;

/****************** Registers Addresses ******************/
#define GICR			*((volatile u8*) (0x5B))
#define IVCE    0
#define IVSEL   1
#define INT2    5
#define INT0    6
#define INT1    7

#define MCUCR			*((volatile u8*) (0x55))
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define SM0     4
#define SM1     5
#define SE      6
#define SM2     7

#define MCUCSR			*((volatile u8*) (0x54))
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3
#define JTRF    4
#define ISC2    6
#define JTD     7

#endif /* MCAL_EXTI_EXTI_PRV_H_ */
