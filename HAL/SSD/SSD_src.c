/*
 * File Name:			SSD.c
 * Description:			Source File for the SSD Driver
 * Creation Date:		14-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			14-Aug-23
 */

/****************** Includes ******************/
#include "SSD_int.h"

/****************** Function Prototypes ******************/
/*
 * Function Name:	HSSD_vDisplayNum
 * Module:			SSD
 * Return Type:		void
 * Description:		Displays a specific number on SSD
 */
void HSSD_vDisplayNum(u8 A_u8Num)
{
	if(A_u8Num < 10)
	{
		MDIO_vSetPinDir(SSD_PORT, SSD_PIN0, DIO_PIN_OUTPUT);
		MDIO_vSetPinDir(SSD_PORT, SSD_PIN1, DIO_PIN_OUTPUT);
		MDIO_vSetPinDir(SSD_PORT, SSD_PIN2, DIO_PIN_OUTPUT);
		MDIO_vSetPinDir(SSD_PORT, SSD_PIN3, DIO_PIN_OUTPUT);

		MDIO_vSetPinVal(SSD_PORT, SSD_PIN0, GET_BIT(A_u8Num, 0));
		MDIO_vSetPinVal(SSD_PORT, SSD_PIN1, GET_BIT(A_u8Num, 1));
		MDIO_vSetPinVal(SSD_PORT, SSD_PIN2, GET_BIT(A_u8Num, 2));
		MDIO_vSetPinVal(SSD_PORT, SSD_PIN3, GET_BIT(A_u8Num, 3));
	}
	return;
}

/*
 * Function Name:	HSSD_vTurnOff
 * Module:			SSD
 * Return Type:		void
 * Description:		Turns the SSD Off
 */
void HSSD_vTurnOff(void)
{
	MDIO_vSetPortDir(SSD_PORT, DIO_PORT_INPUT);
	return;
}

