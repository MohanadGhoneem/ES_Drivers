/*
 * File Name:			EXTI_int.h
 * Description:			Interface Header File for the External Interrupt in AVR ATmega16/32
 * Creation Date:		25-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			25-Aug-23
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_


/****************** Function Prototypes ******************/
/*
 * Function Name:	MEXTI_vInit
 * Module:			EXTI
 * Return Type:		Void
 * Description:		Initialize the External Interrupt
 */
void MEXTI_vInit(void);

/*
 * Function Name:	MEXTI_vEnableInterrupt(u8 A_u8ExtiLineNo)
 * Module:			EXTI
 * Return Type:		Void
 * Description:		Enable External Interrupt
 */
void MEXTI_vEnableInterrupt(u8 A_u8ExtiLineNo);

/*
 * Function Name:	MEXTI_vDisableInterrupt(u8 A_u8ExtiLineNo)
 * Module:			EXTI
 * Return Type:		Void
 * Description:		Disable External Interrupt
 */
void MEXTI_vDisableInterrupt(u8 A_u8ExtiLineNo);

/*
 * Function Name:	MEXTI_vSetSenseControl(u8 A_u8ExtiLineNo, u8 A_u8SenseControl)
 * Module:			EXTI
 * Return Type:		Void
 * Description:		Sets the Sense Control Algorithm, i.e. Falling Edge, Rising Edge, ...
 */
void MEXTI_vSetSenseControl(u8 A_u8ExtiLineNo, u8 A_u8SenseControl);

/*
 * Function Name:	MEXTI_vSetCallBack(void (*A_pPtr2Func) (void))
 * Module:			EXTI
 * Return Type:		Void
 * Description:		Sets the call back function
 */
void MEXTI_vSetCallBack(u8 A_u8ExtiLineNo, void (*A_pPtr2Func) (void));

#endif /* MCAL_EXTI_EXTI_INT_H_ */
