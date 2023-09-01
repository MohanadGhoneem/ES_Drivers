/*
 * File Name:			GIE_int.h
 * Description:			Interface Header File for the General Interrupt in AVR ATmega16/32
 * Creation Date:		25-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			25-Aug-23
 */

#ifndef MCAL_GIE_GIE_INT_H_
#define MCAL_GIE_GIE_INT_H_

/****************** Includes ******************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_cfg.h"
#include "GIE_prv.h"



/****************** Defines ******************/


/****************** Function Prototypes ******************/
/*
 * Function Name:	MGIE_vEnableGlobalInterrupt
 * Module:			GIE
 * Return Type:		Void
 * Description:		Enable the General Interrupt Register SREG
 */
void MGIE_vEnableGlobalInterrupt(void);

/*
 * Function Name:	MGIE_vDisableGlobalInterrupt
 * Module:			GIE
 * Return Type:		Void
 * Description:		Enable the General Interrupt Register SREG
 */
void MGIE_vDisableGlobalInterrupt(void);


#endif /* MCAL_GIE_GIE_INT_H_ */
