/*
 * File Name:			LCD_cfg.h
 * Description:			Configuration Header File for LCD Driver
 * Creation Date:		25-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			25-Aug-23
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

/****************** Defines ******************/
#define LCD_CTRL_PORT		DIO_PORTC
#define LCD_DATA_PORT		DIO_PORTD
#define LCD_RS_PIN			DIO_PIN0
#define LCD_RW_PIN			DIO_PIN1
#define LCD_EN_PIN			DIO_PIN2

#define LCD_CLEAR			0b00000001
#define LCD_LINE0			0
#define LCD_LINE1			1

#endif /* HAL_LCD_LCD_CFG_H_ */
