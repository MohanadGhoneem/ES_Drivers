/*
 * File Name:			ADC_int.h
 * Description:			Interface Header File for ADC Driver
 * Creation Date:		25-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			25-Aug-23
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

/****************** Includes ******************/
#include "ADC_cfg.h"
#include "ADC_prv.h"

/****************** Function Prototypes ******************/
void MADC_vInit(void);
void MADC_vDisableADC(void);
u16 MADC_u16AnalogRead(u8 A_u8ChannelNo);
/* Interrupt Based APIs */
void MADC_vStartConversion(u8 A_u8ChannelNo);
u16 MADC_u16GetADCData(void);
FlagStatus_t MADC_xGetFlagStatus(void);
void MADC_vSetCallback(void(*A_ptr2func)(void));

#endif /* MCAL_ADC_ADC_INT_H_ */
