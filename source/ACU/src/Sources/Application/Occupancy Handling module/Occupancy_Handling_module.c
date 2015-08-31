/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         Occupancy_Handling_module.c
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Aug  30 2015
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
/*  1.0      | 30/08/2015  |                               | Gilberto Ochoa   */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */

#include "ADC.h" 
#include "GPIO.h"

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

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


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
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void test(void)
{
	if((Read_ADC() > 0) && (Read_ADC() < 50))
	{
		LED_OFF(LED1);
		LED_OFF(LED2);
		LED_OFF(LED3);
		LED_OFF(LED4);
	}
	
	else if((Read_ADC() > 50) && (Read_ADC() < 300))
	{
		LED_ON(LED1);
		LED_OFF(LED2);
		LED_OFF(LED3);
		LED_OFF(LED4);
	}
	
	else if((Read_ADC() > 300) && (Read_ADC() < 550))
	{
		LED_ON(LED1);
		LED_ON(LED2);
		LED_OFF(LED3);
		LED_OFF(LED4);
	}
	
	else if((Read_ADC() > 550) && (Read_ADC() < 800))
	{
		LED_ON(LED1);
		LED_ON(LED2);
		LED_ON(LED3);
		LED_OFF(LED4);
	}
	
	else if((Read_ADC() > 800) && (Read_ADC() < 1000))
	{
		LED_ON(LED1);
		LED_ON(LED2);
		LED_ON(LED3);
		LED_ON(LED4);
	}
}



void test2(void)
{
	if((Read_ADC() > 0) && (Read_ADC() < 50))
	{
		LED_OFF(LED1);
		LED_OFF(LED2);
		LED_OFF(LED3);
		LED_OFF(LED4);
	}
	
	else if((Read_ADC() > 50) && (Read_ADC() < 300))
	{
		LED_ON(LED1);
		LED_OFF(LED2);
		LED_OFF(LED3);
		LED_OFF(LED4);
	}
	
	else if((Read_ADC() > 300) && (Read_ADC() < 550))
	{
		LED_OFF(LED1);
		LED_ON(LED2);
		LED_OFF(LED3);
		LED_OFF(LED4);
	}
	
	else if((Read_ADC() > 550) && (Read_ADC() < 800))
	{
		LED_OFF(LED1);
		LED_OFF(LED2);
		LED_ON(LED3);
		LED_OFF(LED4);
	}
	
	else if((Read_ADC() > 800) && (Read_ADC() < 1000))
	{
		LED_OFF(LED1);
		LED_OFF(LED2);
		LED_OFF(LED3);
		LED_ON(LED4);
	}
}



