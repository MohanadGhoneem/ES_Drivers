/*
 * File Name:			DCM_int.h
 * Description:			Interface Header File for DC Motor Driver
 * Creation Date:		23-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			23-Aug-23
 */

#ifndef HAL_DCM_DCM_INT_H_
#define HAL_DCM_DCM_INT_H_

/****************** Includes ******************/
#include "DCM_cfg.h"
#include "DCM_prv.h"


/****************** Function Prototypes ******************/
/*
 * Function Name:	HDCM_vInit(u8 A_u8Port, u8 A_u8Pin1, u8 A_u8Pin2)
 * Module:			DC Motor
 * Return Type:		DCM_t
 * Description:		Init function for the DC Motor, takes the port and pins for the motor
 * 					and returns a configuration struct to be used in other functions
 */
DCM_t HDCM_vInit(u8 A_u8Port, u8 A_u8Pin1, u8 A_u8Pin2);

/*
 * Function Name:	HDCM_vDCMRotateCW(DCM_t* A_xMotor);
 * Module:			DC Motor
 * Return Type:		void
 * Description:		Rotates the motor in Clockwise Direction
 */
void HDCM_vDCMRotateCW(DCM_t* A_xMotor);

/*
 * Function Name:	HDCM_vDCMRotateCCW(DCM_t* A_xMotor);
 * Module:			DC Motor
 * Return Type:		void
 * Description:		Rotates the motor in Counter Clockwise Direction
 */
void HDCM_vDCMRotateCCW(DCM_t* A_xMotor);

/*
 * Function Name:	HDCM_vDCMStop(DCM_t* A_xMotor);
 * Module:			DC Motor
 * Return Type:		void
 * Description:		Stops the motor
 */
void HDCM_vDCMStop(DCM_t* A_xMotor);

#endif /* HAL_DCM_DCM_INT_H_ */
