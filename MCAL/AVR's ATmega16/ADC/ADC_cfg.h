/*
 * File Name:			ADC_cfg.h
 * Description:			Configuration Header File for ADC Driver
 * Creation Date:		25-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			25-Aug-23
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

/****************** Macros ******************/
#define ADC_PRESCALER		PRE_1				/* Options: PRE_1, PRE_2, PRE_4,
 	 	 	 	 	 	 	 	 	 	 	 	 * PRE_8, PRE_16, PRE_32, PRE_64, PRE_128 */
#define ADC_REFVOLT			AVCC				/* Options: AREF, AVCC, RESERVED, INTERNAL2_56 */
#define ADC_ADJ_DIR			ADC_RIGHT			/* Options: ADC_RIGHT, ADC_LEFT */
#define ADC_INT_EN			ADC_ENABLE			/* Options: ADC_ENABLE, ADC_DISABLE */
#define ADC_MODE			SINGLE_CONV			/* Options: FREE_RUNNING, ANALOG_COMP, EXTI,
 	 	 	 	 	 	 	 	 	 	 	 	 * TIMER0_COMP_MATCH, TIMER0_OF,
 	 	 	 	 	 	 	 	 	 	 	 	 * TIMER_COMP_MATCH_B, TIMER1_COMP_MATCH,
 	 	 	 	 	 	 	 	 	 	 	 	 * TIMER1_OF, SINGLE_CONV */

#endif /* MCAL_ADC_ADC_CFG_H_ */
