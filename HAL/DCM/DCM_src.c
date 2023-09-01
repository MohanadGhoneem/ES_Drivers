/*
 * File Name:			DCM_src.c
 * Description:			Source File for DC Motor Driver
 * Creation Date:		23-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			23-Aug-23
 */
/****************** Includes ******************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/DIO/DIO_prv.h"
#include "DCM_int.h"
#include "DCM_cfg.h"
#include "DCM_prv.h"
/*
 * Function Name:	HDCM_vInit(u8 A_u8Port, u8 A_u8Pin1, u8 A_u8Pin2)
 * Module:			DC Motor
 * Return Type:		DCM_t
 * Description:		Init function for the DC Motor, takes the port and pins for the motor
 * 					and returns a configuration struct to be used in other functions
 */
DCM_t HDCM_vInit(u8 A_u8Port, u8 A_u8Pin1, u8 A_u8Pin2)
{
	DCM_t L_xMotor;

	L_xMotor.Port = A_u8Port;
	L_xMotor.Pin1 = A_u8Pin1;
	L_xMotor.Pin2 = A_u8Pin2;

	MDIO_vSetPinDir(L_xMotor.Port, L_xMotor.Pin1, DIO_PIN_OUTPUT);
	MDIO_vSetPinDir(L_xMotor.Port, L_xMotor.Pin2, DIO_PIN_OUTPUT);

	return L_xMotor;
}

/*
 * Function Name:	HDCM_vDCMRotateCW(DCM_t* A_xMotor);
 * Module:			DC Motor
 * Return Type:		void
 * Description:		Rotates the motor in Clockwise Direction
 */
void HDCM_vDCMRotateCW(DCM_t* A_xMotor)
{
	MDIO_vSetPinVal(A_xMotor->Port, A_xMotor->Pin1, DIO_HIGH);
	MDIO_vSetPinVal(A_xMotor->Port, A_xMotor->Pin2, DIO_LOW);
}

/*
 * Function Name:	HDCM_vDCMRotateCCW(DCM_t* A_xMotor);
 * Module:			DC Motor
 * Return Type:		void
 * Description:		Rotates the motor in Counter Clockwise Direction
 */
void HDCM_vDCMRotateCCW(DCM_t* A_xMotor)
{
	MDIO_vSetPinVal(A_xMotor->Port, A_xMotor->Pin1, DIO_LOW);
	MDIO_vSetPinVal(A_xMotor->Port, A_xMotor->Pin2, DIO_HIGH);
}

/*
 * Function Name:	HDCM_vDCMStop(DCM_t* A_xMotor);
 * Module:			DC Motor
 * Return Type:		void
 * Description:		Stops the motor
 */
void HDCM_vDCMStop(DCM_t* A_xMotor)
{
	MDIO_vSetPinVal(A_xMotor->Port, A_xMotor->Pin1, DIO_LOW);
	MDIO_vSetPinVal(A_xMotor->Port, A_xMotor->Pin2, DIO_LOW);
}
