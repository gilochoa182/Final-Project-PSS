/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         Reminder_Mode.c
* version:          1.0        
* created_by:       Gilberto Ochoa
* date_created:     Sep  9 2015
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
/*  1.0      | 09/09/2015  |                               | Gilberto Ochoa   */
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



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	ReminderMode
 *  Description          :
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  
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
 
 
 /* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	GetReminderModeState
 *  Description          :
 *  Parameters           :  void
 *  Return               :  T_UBYTE ReminderModeState
 *  Critical/explanation :  
 **************************************************************/
 T_UBYTE GetReminderModeState(void)
 {
 	return ReminderModeState;
 }