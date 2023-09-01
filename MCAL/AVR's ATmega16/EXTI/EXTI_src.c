/*
 * File Name:			EXTI_src.c
 * Description:			Source File for the External Interrupt in AVR ATmega16/32
 * Creation Date:		25-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			25-Aug-23
 */


/****************** Includes ******************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../GIE/GIE_int.h"
#include "EXTI_cfg.h"
#include "EXTI_prv.h"
#include "EXTI_int.h"

/****************** Global Variables ******************/
void (*EXTI0_callBack) (void) = NULL;
void (*EXTI1_callBack) (void) = NULL;
void (*EXTI2_callBack) (void) = NULL;


/****************** Function Prototypes ******************/
/*
 * Function Name:	MEXTI_vInit
 * Module:			EXTI
 * Return Type:		Void
 * Description:		Initialize the External Interrupt
 */
void MEXTI_vInit(void)
{
	MGIE_vEnableGlobalInterrupt();
}

/*
 * Function Name:	MEXTI_vEnableInterrupt(u8 A_u8ExtiLineNo)
 * Module:			EXTI
 * Return Type:		Void
 * Description:		Enable External Interrupt
 */
void MEXTI_vEnableInterrupt(u8 A_u8ExtiLineNo)
{
	switch(A_u8ExtiLineNo)
	{
	case EXTI0_ID:
		SET_BIT(GICR, INT0);		/* Bit No. 6 in GICR Reg. - To Enable Ex. Interrupt 0 */
		break;
	case EXTI1_ID:
		SET_BIT(GICR, INT1);		/* Bit No. 7 in GICR Reg. - To Enable Ex. Interrupt 0 */
		break;
	case EXTI2_ID:
		SET_BIT(GICR, INT2);		/* Bit No. 5 in GICR Reg. - To Enable Ex. Interrupt 0 */
		break;
	}
}

/*
 * Function Name:	MEXTI_vDisableInterrupt(u8 A_u8ExtiLineNo)
 * Module:			EXTI
 * Return Type:		Void
 * Description:		Disable External Interrupt
 */
void MEXTI_vDisableInterrupt(u8 A_u8ExtiLineNo)
{
	switch(A_u8ExtiLineNo)
	{
	case EXTI0_ID:
		CLR_BIT(GICR, INT0);		/* Bit No. 6 in GICR Reg. - To Disable Ex. Interrupt 0 */
		break;
	case EXTI1_ID:
		CLR_BIT(GICR, INT1);		/* Bit No. 7 in GICR Reg. - To Disable Ex. Interrupt 0 */
		break;
	case EXTI2_ID:
		CLR_BIT(GICR, INT2);		/* Bit No. 5 in GICR Reg. - To Disable Ex. Interrupt 0 */
		break;
	}
}

/*
 * Function Name:	MEXTI_vSetSenseControl(u8 A_u8ExtiLineNo, u8 A_u8SenseControl)
 * Module:			EXTI
 * Return Type:		Void
 * Description:		Sets the Sense Control Algorithm, i.e. Falling Edge, Rising Edge, ...
 */
void MEXTI_vSetSenseControl(u8 A_u8ExtiLineNo, u8 A_u8SenseControl)
{
	switch(A_u8ExtiLineNo)
	{
	case EXTI0_ID:
	{
		switch(A_u8SenseControl)
		{
		case EXTI_RISING_ID:
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		case EXTI_FALLING_ID:
			CLR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		case EXTI_ONCHANGE_ID:
			SET_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;
		}
	}
	break;
	case EXTI1_ID:
	{
		switch(A_u8SenseControl)
		{

		case EXTI_RISING_ID:
			SET_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			break;
		case EXTI_FALLING_ID:
			CLR_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			break;
		case EXTI_ONCHANGE_ID:
			SET_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
			break;
		}
	}
	break;
	case EXTI2_ID:
	{
		switch(A_u8SenseControl)
		{
		case EXTI_RISING_ID:
			SET_BIT(MCUCSR, ISC2);
			break;
		case EXTI_FALLING_ID:
			CLR_BIT(MCUCSR, ISC2);
			break;
		}
	}
	break;
	}
}

/*
 * Function Name:	MEXTI_vSetCallBack(void (*A_pPtr2Func) (void))
 * Module:			EXTI
 * Return Type:		Void
 * Description:		Sets the call back function
 */
void MEXTI_vSetCallBack(u8 A_u8ExtiLineNo, void (*A_pPtr2Func) (void))
{
	switch(A_u8ExtiLineNo)
	{
	case EXTI0_ID:
		EXTI0_callBack = A_pPtr2Func;
		break;
	case EXTI1_ID:
		EXTI1_callBack = A_pPtr2Func;
		break;
	case EXTI2_ID:
		EXTI2_callBack = A_pPtr2Func;
		break;
	}
}


/****************** ISRs ******************/
void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	EXTI0_callBack();
}

void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	EXTI1_callBack();
}

void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	EXTI2_callBack();
}
