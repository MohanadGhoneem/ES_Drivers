/*
 * File Name:			LCD_src.c
 * Description:			Soruce File for LCD Driver
 * Creation Date:		18-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			18-Aug-23
 */

/****************** Includes ******************/
#include "LCD_int.h"

/****************** Functions ******************/
/*
 * Function Name:
 * Module:
 * Return Type:
 * Description:
 */
void HLCD_vSendCommand(u8 A_u8Cmd)
{
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, 0);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, 0);
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8Cmd);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, 1);
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, 0);
	_delay_ms(1);
}
void HLCD_vSendChar(u8 A_u8Char)
{
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, 1);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, 0);
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8Char);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, 1);
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, 0);
	_delay_ms(1);
}

void HLCD_vInit(void)
{
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_EN_PIN, DIO_PIN_OUTPUT);
	MDIO_vSetPortDir(LCD_DATA_PORT, DIO_PORT_OUTPUT);

	_delay_ms(50);
	HLCD_vSendCommand(0b00111000);
	_delay_ms(1);
	HLCD_vSendCommand(0b00001100);
	_delay_ms(1);
	HLCD_vSendCommand(0b00000001);
	_delay_ms(3);
	HLCD_vSendCommand(0b00000110);
	_delay_ms(1);
}

void HLCD_vClearScreen(void)
{
	HLCD_vSendCommand(LCD_CLEAR);
}

void HLCD_vSendString(u8 A_u8String[])
{
	u8 L_u8i = 0;
	for(L_u8i = 0; A_u8String[L_u8i] != '\0'; L_u8i++)
	{
		HLCD_vSendChar(A_u8String[L_u8i]);
	}
}

void HLCD_vSendNumber(s32 A_s32Num)
{
	u8 L_u8Digits[10] = {0};
	u8 L_u8Counter = 0;
	/* TODO: IMplement negative number handling  	*/
	/* TODO: implement Zero in units corner case    */
	/* save reversed in array */
	while(A_s32Num > 0)
	{
		L_u8Digits[L_u8Counter] = A_s32Num%10 ;
		L_u8Counter++;
		A_s32Num /= 10 ;
	}

	/* print array in reverse  */
	for(s8 L_s8PrintIndex=L_u8Counter-1; L_s8PrintIndex >= 0; L_s8PrintIndex-- )
	{
		HLCD_vSendChar('0' + L_u8Digits[L_s8PrintIndex]);
	}

}

void HLCD_vSetCursor(u8 A_u8LinePos, u8 A_u8LineNo)
{
	switch(A_u8LineNo)
	{
	case LCD_LINE0:
		HLCD_vSendCommand(0x80 + A_u8LinePos + 0);
		break;
	case LCD_LINE1:
		HLCD_vSendCommand(0x80 + A_u8LinePos + 64);
		break;
	}

}
void HLCD_vSaveCustomChar(u8 A_u8CGRAMIndex,u8 A_u8CustomCharData[])
{
	/* 1-Set CGRAM Address */
	HLCD_vSendCommand(0b01000000 + (A_u8CGRAMIndex *8));
	/* 2- send custom char data */
	for(u8 L_u8Idx=0; L_u8Idx <8; L_u8Idx++)
	{
		HLCD_vSendChar(A_u8CustomCharData[L_u8Idx]);
	}
	/* 3-Set DDRAM Address */
	HLCD_vSendCommand(0x80);

}
void HLCD_vPrintCustomChar(u8 A_u8CGRAMIndex)
{
	if(A_u8CGRAMIndex < 8)
	{
		HLCD_vSendChar(A_u8CGRAMIndex);
	}

}
