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
 void ADCModeSelector(int adcmode)
 {
 	SIU.PCR[PCR_POT].R = 0x2000;
 	
 	//It must be seted as "OneShot" or "Scan" Mode
	if(adcmode == OneShot)
	{
		ADC.MCR.R = 0x00000000;
		ADC.NCMR0.R = 1; //ANP4
		ADC.CTR0.R = 0x00008606;
		ADC.MCR.B.NSTART=1;
	}
	
	else if(adcmode == Scan)
	{
		ADC.MCR.R = 0x20000000;
		ADC.NCMR0.R = 1; //ANP4
		ADC.CTR0.R = 0x00008606;
		ADC.MCR.B.NSTART=1;
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
 int Read_ADC(void)
 {
 	int adc_value = 0;
 	adc_value = ADC.CDR[CHANNEL_0].B.CDATA;
 	
 	return adc_value;
 }