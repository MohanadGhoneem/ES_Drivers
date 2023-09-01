/*
 * File Name:			DIO_int.h
 * Description:			Interface Header File for DIO Driver in AVR ATmega16/32
 * Creation Date:		13-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			14-Aug-23
 */

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_


/****************** Function Prototypes ******************/
/*
 * Function Name:	MDIO_vSetPinDir
 * Module:			DIO
 * Return Type:		void
 * Description:		Set Pin Direction in a selected Port
 */
void MDIO_vSetPinDir(u8 A_u8PortNo, u8 A_u8PinNo, u8 A_u8Dir);

/*
 * Function Name:	MDIO_vSetPinVal
 * Module:			DIO
 * Return Type:		void
 * Description:		Set Pin Value in a selected Port
 */
void MDIO_vSetPinVal(u8 A_u8PortNo, u8 A_u8PinNo, u8 A_u8Val);

/*
 * Function Name:	MDIO_vTogPinVal
 * Module:			DIO
 * Return Type:		void
 * Description:		Toggles Pin Value in a selected Port
 */
void MDIO_vTogPinVal(u8 A_u8PortNo, u8 A_u8PinNo);

/*
 * Function Name:	MDIO_vGetPinVal
 * Module:			DIO
 * Return Type:		u8
 * Description:		Get Pin Value in a selected Port
 */
u8 MDIO_u8GetPinVal(u8 A_u8PortNo, u8 A_u8PinNo);

/*
 * Function Name:	MDIO_vSetPortDir
 * Module:			DIO
 * Return Type:		u8
 * Description:		Set entire Port Direction
 */
void MDIO_vSetPortDir(u8 A_u8PortNo, u8 A_u8Dir);

/*
 * Function Name:	MDIO_vSetPortVal
 * Module:			DIO
 * Return Type:		u8
 * Description:		Set entire Port Value
 */
void MDIO_vSetPortVal(u8 A_u8PortNo, u8 A_u8Val);

/*
 * Function Name:	MDIO_vGetPortVal
 * Module:			DIO
 * Return Type:		u8
 * Description:		Get entire Port Value
 */
u8 MDIO_u8GetPortVal(u8 A_u8PortNo);



#endif /* MCAL_DIO_H_ */
