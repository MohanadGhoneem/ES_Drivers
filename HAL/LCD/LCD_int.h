/*
 * File Name:			LCD_int.h
 * Description:			Interface Header File for LCD Driver
 * Creation Date:		18-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			18-Aug-23
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

/****************** Includes ******************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/DIO/DIO_prv.h"
#include "LCD_cfg.h"

/****************** Function Prototypes ******************/
void HLCD_vSendCommand(u8 A_u8Cmd);
void HLCD_vSendChar(u8 A_u8Char);
void HLCD_vInit(void);
void HLCD_vClearScreen(void);
void HLCD_vSendString(u8 A_u8String[]);
void HLCD_vSendNumber(s32 A_s32Num);
void HLCD_vSetCursor(u8 A_u8LinePos, u8 A_u8LineNo);
void HLCD_vSaveCustomChar(u8 A_u8CGRAMIndex,u8 A_u8CustomCharData[]);
void HLCD_vPrintCustomChar(u8 A_u8CGRAMIndex);


#endif /* HAL_LCD_LCD_INT_H_ */
