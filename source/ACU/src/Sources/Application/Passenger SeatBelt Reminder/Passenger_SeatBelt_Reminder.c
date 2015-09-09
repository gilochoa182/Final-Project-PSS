/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         Passenger_SeatBelt_Reminder.c
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

#include "Passenger_Seat_Belt_Sensor.h"

#include "Passenger_SeatBelt_Reminder.h"

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
 *  Name                 :	PassBuckleState
 *  Description          :
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  NO
 **************************************************************/
 void PassBuckleState(void)
 {
 	switch(GetReminderModeState())
 	{
 		case BASIC:
 		
 			switch(GetPassengerSeatBeltState())
 			{
 				case PASS_BUCKLE:
 					LED_OFF(LED1);
 					break;
 		
 				case PASS_UNBUCKLE:
 					LED_ON(LED1);
 					break;
 			}
 			break;
 				
 		case ENHANCED:
 		
 			switch(GetPassengerSeatBeltState())
 			{
 				case PASS_BUCKLE:
 					LED_OFF(LED1);
 					break;
 		
 				case PASS_UNBUCKLE:
 					LED_ON(LED1);
 					break;
 			}		
 			break;
 					
 		case EURO:
 		
 			switch(GetPassengerSeatBeltState())
 			{
 				case PASS_BUCKLE:
 					LED_OFF(LED1);
 					break;
 		
 				case PASS_UNBUCKLE:
 					LED_ON(LED1);
 					break;
 			}		
 			break;
 	}
 	
 }