/*
 * File Name:			LM35_src.c
 * Description:			Source File for LM35 Sensor Driver
 * Creation Date:		30-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			30-Aug-23
 */
/****************** Includes ******************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "LM35_cfg.h"
#include "LM35_int.h"

/****************** Function Declaration ******************/
u8 HLM35_u8getTemperature(void)
{
	u8 L_u8Temp = 0;

	u16 L_u16ADCValue = 0;

	/* Read ADC channel where the temperature sensor is connected */
	MADC_vStartConversion(SENSOR_CHANNEL_ID);
	L_u16ADCValue = MADC_u16GetADCData();

	/* Calculate the temperature from the ADC value*/
	L_u8Temp = (u8)(((u32)L_u16ADCValue*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return L_u8Temp;
}
