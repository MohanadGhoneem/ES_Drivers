/*
 * File Name:			KPD_src.c
 * Description:			Source File for Keypad Driver
 * Creation Date:		15-Aug-23
 * Author: 				Mohanad Ghoneem
 *
 * Version:				V1.0.0
 * Last Edit:			18-Aug-23
 */

/****************** Includes ******************/
#include "KPD_int.h"

/****************** Static Function Prototypes ******************/
#if (N_COL == 3)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
static u8 HKPD_su8AdjustKeyNumber4x3(u8 A_u8EquivButton);
#elif (N_COL == 4)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x4 keypad
 */
static u8 HKPD_su8AdjustKeyNumber4x4(u8 A_u8EquivButton);

#endif

/****************** Functions ******************/
/*
 * Function Name:	HKPD_u8GetPressedKey(void)
 * Module:			Keypad
 * Return Type:		u8
 * Description:		Return the pressed key of a keypad
 */
u8 HKPD_u8GetPressedKey(void)
{
	u8 pressedKeyIndex = 0;
	u8 col = 0;
	u8 row = 0;

	while(1)
	{
		for(col=0;col<N_COL;col++) /* loop for columns */
		{
			/*
			 * Each time setup the direction for all keypad port as input pins,
			 * except this column will be output pin
			 */

			MDIO_vSetPortDir(KPD_PORT, DIO_PORT_INPUT);
			MDIO_vSetPinDir(KPD_PORT, col, DIO_PIN_OUTPUT);

			/* Clear the column output pin and set the rest pins value */
			u8 KPD_PortValue = ~(1<<(0+col));
			MDIO_vSetPortVal(KPD_PORT, KPD_PortValue);

			for(row=0;row<N_ROW;row++) /* loop for rows */
			{
				/* Check if the switch is pressed in this row */
				if((MDIO_u8GetPinVal(KPD_PORT, row+4)) == 0)
				{
					pressedKeyIndex = row + (col*N_COL) + 1;
#if (N_COL == 3)
					return HKPD_su8AdjustKeyNumber4x3(pressedKeyIndex);
#elif (N_COL == 4)
					return HKPD_su8AdjustKeyNumber4x4(pressedKeyIndex);
#endif
				}
			}
		}
	}
}

#if (N_COL == 3)

static u8 HKPD_su8AdjustKeyNumber4x3(u8 A_u8EquivButton)
{
	switch(A_u8EquivButton)
	{
	case 1: return 1;
	break;
	case 2: return 4;
	break;
	case 3: return 7;
	break;
	case 4: return '*';  /* ASCII Code of '*' */
	break;
	case 5: return 2;
	break;
	case 6: return 5;
	break;
	case 7: return 8;
	break;
	case 8: return 0;
	break;
	case 9: return 3;
	break;
	case 10: return 6;
	break;
	case 11: return 9;
	break;
	case 12: return '#'; /* ASCII Code of '#' */
	break;
	default: return A_u8EquivButton;
	}
}

#elif (N_COL == 4)

static u8 HKPD_su8AdjustKeyNumber4x4(u8 A_u8EquivButton)
{
	switch(A_u8EquivButton)
	{
	case 1: return 7;
	break;
	case 2: return 4;
	break;
	case 3: return 1;
	break;
	case 4: return 13; /* ASCII Code of Enter */
	break;
	case 5: return 8;
	break;
	case 6: return 5;
	break;
	case 7: return 2;
	break;
	case 8: return 0;
	break;
	case 9: return 9;
	break;
	case 10: return 6;
	break;
	case 11: return 3;
	break;
	case 12: return '='; /* ASCII Code of '=' */
	break;
	case 13: return '/';  /* ASCII of '/' */
	break;
	case 14: return '*'; /* ASCII Code of '*' */
	break;
	case 15: return '-'; /* ASCII Code of '-' */
	break;
	case 16: return '+'; /* ASCII Code of '+' */
	break;
	default: return A_u8EquivButton;
	}
}


#endif

