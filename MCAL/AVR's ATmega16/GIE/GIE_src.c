/*
 * File Name:			GIE_src.c
 * Description:			Source File for the General Interrupt in AVR ATmega16/32
 * Creation Date:		25-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			25-Aug-23
 */


/****************** Includes ******************/
#include "GIE_int.h"


/****************** Functions ******************/
/*
 * Function Name:	MGIE_vEnableGlobalInterrupt
 * Module:			GIE
 * Return Type:		Void
 * Description:		Enable the General Interrupt Register SREG
 */
void MGIE_vEnableGlobalInterrupt(void)
{
	SET_BIT(SREG, SREG_I);
}

/*
 * Function Name:	MGIE_vDisableGlobalInterrupt
 * Module:			GIE
 * Return Type:		Void
 * Description:		Enable the General Interrupt Register SREG
 */
void MGIE_vDisableGlobalInterrupt(void)
{
	CLR_BIT(SREG, SREG_I);
}
