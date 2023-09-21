/*
 * File Name:			ADC_src.c
 * Description:			Source File for ADC Driver
 * Creation Date:		25-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			25-Aug-23
 */
/****************** Includes ******************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_int.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"

/****************** Global Variables ******************/
static void (*ADC_Callback) (void) = NULL;		/* Callback Variable*/

FlagStatus_t xAdcFlag = ADC_NOT_COMPLETE;


/****************** Functions ******************/
void MADC_vInit(void)
{
	/* 1- Reference voltage selection */
	ADMUX = (ADMUX & 0x3F) | (ADC_REFVOLT<<REFS0);

	/* 2- Data Adjustment direction  */
	ADMUX = (ADMUX & 0xDF) | (ADC_ADJ_DIR<<ADLAR);

	/* 3- Select ADC Mode */
#if ADC_MODE == SINGLE_CONV
	CLR_BIT(ADCSRA, ADATE);
#else
	SET_BIT(ADCSRA, ADATE);
	SFIOR = (SFIOR & 0x1F) | (ADC_MODE << ADTS0);
#endif

			/* 4- Interrupt Enable/disable    */
#if ADC_INT_EN == ADC_DISABLE
			CLR_BIT(ADCSRA, ADIE);
#elif ADC_INT_EN == ADC_ENABLE
	SET_BIT(ADCSRA, ADIE);
#endif

	/* 5- Select Prescaler Bits    */
	ADCSRA = (ADCSRA & 0xF8) | (ADC_PRESCALER);

	/* 6- Enable ADC Peripheral */
	SET_BIT(ADCSRA, ADEN);

}

void MADC_vDisableADC(void)
{
	CLR_BIT(ADCSRA, ADEN);
}

u16 MADC_u16AnalogRead(u8 A_u8ChannelNo)
{
	/* 1- Select Channel   */
	ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07) ;
	/* 2- Start Conversion */
	SET_BIT(ADCSRA, ADSC);
	/* 3- Poll on Flag     */
	while( GET_BIT(ADCSRA, ADIF) != 1 ){}
	/* 4- Clear Flag       */
	SET_BIT(ADCSRA, ADIF);
	/* 5- return ADC Data  */
	return ADC;
}


void MADC_vStartConversion(u8 A_u8ChannelNo)
{
	/* 1- Select Channel   */
	ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07) ;

	/* 2- Start Conversion */
	SET_BIT(ADCSRA, ADSC);
#if 0
	/* 3- Poll on Flag     */
	while( GET_BIT(ADCSRA, ADIF) != 1 ){}

	/* 4- Clear Flag       */
	SET_BIT(ADCSRA, ADIF);
#endif
}

u16 MADC_u16GetADCData(void)
{
	u16 L_u16conversionResult = 0;

#if ADC_ADJ_DIR == ADC_RIGHT
	L_u16conversionResult = ADC;

#elif ADC_ADJ_DIR == ADC_LEFT
	L_u16conversionResult = 0x03FF & (((ADCH<<2) & 0x03FC) | (ADCL & 0x03));
#endif

	return L_u16conversionResult;
}

FlagStatus_t MADC_xGetFlagStatus(void)
{
	if(GET_BIT(ADCSRA, ADIF) == 1)
	{
		xAdcFlag = ADC_COMPLETE;
	}
	return xAdcFlag;
}

void MADC_vSetCallback(void(*A_ptr2func)(void))
{
	if (A_ptr2func != NULL)
	{
		ADC_Callback = A_ptr2func;
	}
	else
	{
		/* TODO: return error state */
	}
}


/*		ADC ISR		*/
void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
	if (ADC_Callback != NULL)
	{
		ADC_Callback();
		xAdcFlag = ADC_COMPLETE;
	}
}
