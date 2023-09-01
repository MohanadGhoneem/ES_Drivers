/*
 * File Name:			KPD_int.h
 * Description:			Interface Header File for Keypad Driver
 * Creation Date:		15-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			15-Aug-23
 */

#ifndef HAL_KPD_KPD_INT_H_
#define HAL_KPD_KPD_INT_H_

/****************** Includes ******************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/DIO/DIO_prv.h"
#include "KPD_cfg.h"
#include "KPD_prv.h"


/****************** Function Prototypes ******************/
/*
 * Function Name:	HKPD_u8GetPressedKey(void)
 * Module:			Keypad
 * Return Type:		u8
 * Description:		Return the pressed key of a keypad
 */
u8 HKPD_u8GetPressedKey(void);


#endif /* HAL_KPD_KPD_INT_H_ */
