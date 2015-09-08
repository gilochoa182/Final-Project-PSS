/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         ADC.c
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Aug  29  2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 29/08/2015  |                               | Gilberto Ochoa   */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */

#include "ADC.h"

/* DEFINES */

#define PrecisionCh 0
#define StandardCh	1
#define ExternalCh	2

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 

 
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	ADCModeSelector
 *  Description          :
 *  Parameters           :  int adcmode
 *  Return               :  void
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void ADCModeSelector(T_UBYTE adcmode)
 {
 	SIU.PCR[ADC0_P0].R = 0x2000;
 	SIU.PCR[ADC0_P1].R = 0x2000;
 	SIU.PCR[ADC0_P2].R = 0x2000;
 	
 	//It must be set as "OneShot" or "Scan" Mode
	if(adcmode == OneShot)
	{
		ADC.MCR.R = 0x00000000;
		ADC.NCMR0.R = 7;      /* Initialize channel*/
		ADC.CTR0.R = 0x00008606;    /* Time conversion*/
		ADC.MCR.B.NSTART = 1;       /* Initialize conversion*/
	}
	
	else if(adcmode == Scan)
	{
		ADC.MCR.R = 0x20000000;    /* Scan Mode */
		ADC.NCMR0.R = 7;     /* Initialize channel*/
		ADC.CTR0.R = 0x00008606;   /* Time conversion*/
		ADC.MCR.B.NSTART = 1;      /* Initialize conversion*/
	}
	else
	{
		//do nothing
	}
}




 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	ADCModeSelector
 *  Description          :
 *  Parameters           :  int adcmode
 *  Return               :  void
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 T_UWORD Read_ADC(T_UBYTE channel)
 {
 	T_UWORD adc_value = 0;
 	adc_value = (T_UWORD) ADC.CDR[channel].B.CDATA;
 	
 	return adc_value;
 }
 
 
 
 T_UWORD Read_ADC_2(T_UBYTE channel)
 {
 	T_UWORD adc_value_2 = 0;
 	adc_value_2 = (T_UWORD) ADC.CDR[channel].B.CDATA;
 	
 	return adc_value_2;
 }
 
 
 
 T_UWORD Read_ADC_3(T_UBYTE channel)
 {
 	T_UWORD adc_value_3 = 0;
 	adc_value_3 = (T_UWORD) ADC.CDR[channel].B.CDATA;
 	
 	return adc_value_3;
 }