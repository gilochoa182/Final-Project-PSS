/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         Driver_SeatBelt_Reminder.c
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

#include "Driver_Seat_Belt_Sensor.h"

#include "Driver_SeatBelt_Reminder.h"

#include "Reminder_Mode.h"

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

//extern T_UBYTE ReminderModeState = DRI_BASIC;

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
 *  Name                 :	DriverBuckleState
 *  Description          :
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  NO
 **************************************************************/ 
void DriverBuckleState(void)
 {
 	switch(GetReminderModeState())
 	{
 		case BASIC:
 			switch(GetDriverSeatBeltState())
 			{
 				case DRI_BUCKLE:
 					LED_OFF(LED2);
 					break;
 		
 				case DRI_UNBUCKLE:
 					LED_ON(LED2);
 					break;
 			}
 			break;
 				
 		case ENHANCED:
 			switch(GetDriverSeatBeltState())
 			{
 				case DRI_BUCKLE:
 					LED_OFF(LED2);
 					break;
 		
 				case DRI_UNBUCKLE:
 					LED_ON(LED2);
 					break;
 			}	
 			break;
 					
 		case EURO:
 			switch(GetDriverSeatBeltState())
 			{
 				case DRI_BUCKLE:
 					LED_OFF(LED2);
 					break;
 		
 				case DRI_UNBUCKLE:
 					LED_ON(LED2);
 					break;
 			}	
 			break;
 	}
 	
 }