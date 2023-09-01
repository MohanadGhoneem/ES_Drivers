/*
 * File Name:			SSD.h
 * Description:			Interface Header File for the SSD Driver
 * Creation Date:		14-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			14-Aug-23
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

/****************** Includes ******************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/DIO/DIO_prv.h"
#include "SSD_cfg.h"

/****************** Function Prototypes ******************/
/*
 * Function Name:	HSSD_vDisplayNum
 * Module:			SSD
 * Return Type:		void
 * Description:		Displays a specific number on SSD
 */
void HSSD_vDisplayNum(u8 A_u8Num);

/*
 * Function Name:	HSSD_vTurnOff
 * Module:			SSD
 * Return Type:		void
 * Description:		Turns the SSD Off
 */
void HSSD_vTurnOff(void);

#endif /* HAL_SSD_SSD_INT_H_ */
