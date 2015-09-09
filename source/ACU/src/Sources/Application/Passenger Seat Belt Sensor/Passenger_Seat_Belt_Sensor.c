/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         Passenger_Seat_Belt_Sensor.c
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Sep  7 2015
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
/*  1.0      | 07/09/2015  |                               | Gilberto Ochoa   */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */

#include "Passenger_Seat_Belt_Sensor.h"

#include "Passenger_Seat_Sensor.h"

#include "ADC.h" 

#include "SensorsCommon.h"


/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

static PassengerSeatSensorStateType  PassengerSeatBeltState = PASS_BUCKLE;

static PassengerSeatSensorCountType  Passcounter;

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
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void PassengerSeatBeltSensor(void)
 {	
 	if(GetSeatSensorState() ==  OCCUPIED)
 	{
 		Passcounter.time++;
		if(Passcounter.time  == PASS_TWO_HUNDRED_MS)
		{
			Passcounter.time = ZERO_MS;
		
			/***************   FAULTY   ******************************/
			if(Read_ADC_2(PASS_SEATBELT) < TWO_VOLTS)
			{
				Passcounter.unbuckle = ZERO_SAMPLES;
				Passcounter.buckle = ZERO_SAMPLES;
				Passcounter.undetermined = ZERO_SAMPLES;
			
				Passcounter.faulty++;
			
				if(Passcounter.faulty == FIVE_SAMPLES)
				{
					Passcounter.faulty = ZERO_SAMPLES;
				
					PassengerSeatBeltState = PASS_FAULTY;
				}
			
				else
				{
					/* Do nothing */
				}
			
			}
			/***********************************************************************/
		
		
		
		
		
			/***************   UNBUCKLE   ******************************/
			else if((Read_ADC_2(PASS_SEATBELT) >= TWO_VOLTS) && (Read_ADC_2(PASS_SEATBELT) < TEN_VOLTS))
			{	
				Passcounter.faulty = ZERO_SAMPLES;
				Passcounter.buckle = ZERO_SAMPLES;
				Passcounter.undetermined = ZERO_SAMPLES;
			
				Passcounter.unbuckle++;
			
				if(Passcounter.unbuckle == FIVE_SAMPLES)
				{
					Passcounter.unbuckle = ZERO_SAMPLES;
				
					PassengerSeatBeltState = PASS_UNBUCKLE;
				}
			
				else
				{
					/* Do nothing */
				}
			}
			/***********************************************************************/
		
		
		
		
		
			/***************   UNDETERMINED   ******************************/
			else if((Read_ADC_2(PASS_SEATBELT) >= TEN_VOLTS) && (Read_ADC_2(PASS_SEATBELT) < TWELVE_VOLTS))
			{	
				Passcounter.faulty = ZERO_SAMPLES;
				Passcounter.unbuckle = ZERO_SAMPLES;
				Passcounter.buckle = ZERO_SAMPLES;
			
			
				Passcounter.undetermined++;
			
				if(Passcounter.undetermined == FIVE_SAMPLES)
				{
					Passcounter.undetermined = ZERO_SAMPLES;
				
					PassengerSeatBeltState = PASS_UNDETERMINED;
				}
			
				else
				{
					/* Do nothing */
				}
			
			}
			/***********************************************************************/
		
		
		
		
		
			/***************   BUCKLE   ******************************/
			else if((Read_ADC_2(PASS_SEATBELT) >= TWELVE_VOLTS) && (Read_ADC_2(PASS_SEATBELT) < TWENTY_VOLTS))
			{	
				Passcounter.faulty = ZERO_SAMPLES;
				Passcounter.undetermined = ZERO_SAMPLES;
				Passcounter.unbuckle = ZERO_SAMPLES;
			
				Passcounter.buckle++;
			
				if(Passcounter.buckle == FIVE_SAMPLES)
				{
					Passcounter.buckle = ZERO_SAMPLES;
					
					PassengerSeatBeltState = PASS_BUCKLE;
				}
			
				else
				{
					/* Do nothing */
				}
			}
			/***********************************************************************/
		
		
		
		
		
			/***************   FAULTY   ******************************/
			else if(Read_ADC_2(PASS_SEATBELT) >= TWENTY_VOLTS)
			{	
				Passcounter.undetermined = ZERO_SAMPLES;
				Passcounter.buckle = ZERO_SAMPLES;
				Passcounter.unbuckle = ZERO_SAMPLES;
			
				Passcounter.faulty++;
			
				if(Passcounter.faulty == FIVE_SAMPLES)
				{
					Passcounter.faulty = ZERO_SAMPLES;
				
					PassengerSeatBeltState = PASS_FAULTY;
				}
			
				else
				{
					/* Do nothing */
				}
			
			}
			/***********************************************************************/	
		}   /* End Control Time */
	
		else
		{
			/* Do nothing */
		}
		
 	}  /* End if detected occupied*/
	
	else if(GetSeatSensorState() ==  UNOCCUPIED)
	{
		PassengerSeatBeltState = PASS_BUCKLE;
	}
} /* End PassengerSeatBeltSensor*/


PassengerSeatSensorStateType GetPassengerSeatBeltState(void)
{
	return PassengerSeatBeltState;
}