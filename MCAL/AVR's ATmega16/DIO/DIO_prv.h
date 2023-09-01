/*
 * File Name:			DIO_prv.h
 * Description:			Private Header File for the DIO in AVR ATmega16/32
 * Creation Date:		01-Sep-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			01-Sep-23
 */

#ifndef MCAL_DIO_DIO_PRV_H_
#define MCAL_DIO_DIO_PRV_H_

/****************** Enums ******************/
typedef enum
{
	DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD
}DIO_PortIDs;

typedef enum
{
	DIO_PIN0, DIO_PIN1, DIO_PIN2, DIO_PIN3, DIO_PIN4, DIO_PIN5, DIO_PIN6, DIO_PIN7
}DIO_PinIDs;

typedef enum
{
	DIO_PIN_INPUT, DIO_PIN_OUTPUT
}DIO_PinDirectionType;

typedef enum
{
	DIO_PORT_INPUT, DIO_PORT_OUTPUT=0xFF
}DIO_PortDirectionType;

typedef enum
{
	DIO_PORT_LOW, DIO_PORT_HIGH=0xFF
}DIO_PortValues;

typedef enum
{
	DIO_LOW, DIO_HIGH
}DIO_LogicValues;

/****************** Registers Addresses ******************/
#define DDRA			*((volatile u8*) (0x3A))
#define DDRB			*((volatile u8*) (0x37))
#define DDRC			*((volatile u8*) (0x34))
#define DDRD			*((volatile u8*) (0x31))

#define PORTA			*((volatile u8*) (0x3B))
#define PORTB			*((volatile u8*) (0x38))
#define PORTC			*((volatile u8*) (0x35))
#define PORTD			*((volatile u8*) (0x32))

#define PINA			*((volatile u8*) (0x39))
#define PINB			*((volatile u8*) (0x36))
#define PINC			*((volatile u8*) (0x33))
#define PIND			*((volatile u8*) (0x30))


#endif /* MCAL_DIO_DIO_PRV_H_ */
