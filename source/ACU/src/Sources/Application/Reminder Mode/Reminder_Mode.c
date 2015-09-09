/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %template.c%
* Instance:         RPL_1
* %version:         2 %
* %created_by:      uid02495 %
* %date_created:    Fri Jan  9 14:38:03 2004 %
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
/*  1.0      | DD/MM/YYYY  |                               | Mr. Template     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */

#include "GPIO.h"

#include "Reminder_Mode.h"

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

T_UBYTE ReminderModeState = BASIC;

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
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void ReminderMode(void)
 {
 	if((BASIC_MODE == ON) && (ENHANCED_MODE == OFF) && (EURO_MODE == OFF))
 	{
 		ReminderModeState = BASIC;
 	}
 	
 	else if((BASIC_MODE == OFF) && (ENHANCED_MODE == ON) && (EURO_MODE == OFF))
 	{
 		ReminderModeState = ENHANCED;
 	}
 	
 	else if((BASIC_MODE == OFF) && (ENHANCED_MODE == OFF) && (EURO_MODE == ON))
 	{
 		ReminderModeState = EURO;
 	}
 	
 	else
 	{
 		/* Do nothing */
 	}
 }
 
 
 
  T_UBYTE GetReminderModeState(void)
 {
 	return ReminderModeState;
 }