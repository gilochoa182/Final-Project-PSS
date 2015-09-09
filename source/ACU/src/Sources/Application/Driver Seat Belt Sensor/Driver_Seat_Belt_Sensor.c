/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         Driver_Seat_Belt_Sensor.c
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

#include "Driver_Seat_Belt_Sensor.h"

#include "ADC.h" 

#include "SensorsCommon.h"


/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

static DriverSeatSensorStateType  DriverSeatBeltState = DRI_BUCKLE;

static DriverSeatSensorCountType  Dricounter;

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
 *  Name                 :	DriverSeatBeltSensor
 *  Description          :
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  No
 **************************************************************/
 void DriverSeatBeltSensor(void)
 {	
	Dricounter.time++;
	if(Dricounter.time  == TWO_HUNDRED_MS)
	{
		Dricounter.time = ZERO_MS;
		
		/***************   FAULTY   ******************************/
		if(Read_ADC_3(DRIV_SEATBELT) < TWO_VOLTS)
		{
			Dricounter.unbuckle = ZERO_SAMPLES;
			Dricounter.buckle = ZERO_SAMPLES;
			Dricounter.undetermined = ZERO_SAMPLES;
			
			Dricounter.faulty++;
			
			if(Dricounter.faulty == FIVE_SAMPLES)
			{
				Dricounter.faulty = ZERO_SAMPLES;
				
				DriverSeatBeltState = DRI_FAULTY;
			}
			
			else
			{
				/* Do nothing */
			}
			
		}
		/***********************************************************************/
		
		
		
		
		
		/***************   UNBUCKLE   ******************************/
		else if((Read_ADC_3(DRIV_SEATBELT) >= TWO_VOLTS) && (Read_ADC_3(DRIV_SEATBELT) < TEN_VOLTS))
		{	
			Dricounter.faulty = ZERO_SAMPLES;
			Dricounter.buckle = ZERO_SAMPLES;
			Dricounter.undetermined = ZERO_SAMPLES;
			
			Dricounter.unbuckle++;
			
			if(Dricounter.unbuckle == FIVE_SAMPLES)
			{
				Dricounter.unbuckle = ZERO_SAMPLES;
				
				DriverSeatBeltState = DRI_UNBUCKLE;
				//LED_ON(LED2);
			}
			
			else
			{
				/* Do nothing */
			}
		}
		/***********************************************************************/
		
		
		
		
		
		/***************   UNDETERMINED   ******************************/
		else if((Read_ADC_3(DRIV_SEATBELT) >= TEN_VOLTS) && (Read_ADC_3(DRIV_SEATBELT) < TWELVE_VOLTS))
		{	
			Dricounter.faulty = ZERO_SAMPLES;
			Dricounter.unbuckle = ZERO_SAMPLES;
			Dricounter.buckle = ZERO_SAMPLES;
			
			
			Dricounter.undetermined++;
			
			if(Dricounter.undetermined == FIVE_SAMPLES)
			{
				Dricounter.undetermined = ZERO_SAMPLES;
				
				DriverSeatBeltState = DRI_UNDETERMINED;
			}
			
			else
			{
				/* Do nothing */
			}
			
		}
		/***********************************************************************/
		
		
		
		
		
		/***************   BUCKLE   ******************************/
		else if((Read_ADC_3(DRIV_SEATBELT) >= TWELVE_VOLTS) && (Read_ADC_3(DRIV_SEATBELT) < TWENTY_VOLTS))
		{	
			Dricounter.faulty = ZERO_SAMPLES;
			Dricounter.undetermined = ZERO_SAMPLES;
			Dricounter.unbuckle = ZERO_SAMPLES;
			
			Dricounter.buckle++;
			
			if(Dricounter.buckle == FIVE_SAMPLES)
			{
				Dricounter.buckle = ZERO_SAMPLES;
				
				DriverSeatBeltState = DRI_BUCKLE;
				//LED_OFF(LED2);
			}
			
			else
			{
				/* Do nothing */
			}
		}
		/***********************************************************************/
		
		
		
		
		
		/***************   FAULTY   ******************************/
		else if(Read_ADC_3(DRIV_SEATBELT) >= TWENTY_VOLTS)
		{	
			Dricounter.undetermined = ZERO_SAMPLES;
			Dricounter.buckle = ZERO_SAMPLES;
			Dricounter.unbuckle = ZERO_SAMPLES;
			
			Dricounter.faulty++;
			
			if(Dricounter.faulty == FIVE_SAMPLES)
			{
				Dricounter.faulty = ZERO_SAMPLES;
				
				DriverSeatBeltState = DRI_FAULTY;
			}
			
			else
			{
				/* Do nothing */
			}
			
		}
		/***********************************************************************/	
	}
	
	else      /* Else evaluation TWO_HUNDRED_MS */
	{
		/* Do nothing */
	}
		
}


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	GetDriverSeatBeltState
 *  Description          :
 *  Parameters           :  void
 *  Return               :  DriverSeatSensorStateType  DriverSeatBeltState
 *  Critical/explanation :  No
 **************************************************************/
DriverSeatSensorStateType GetDriverSeatBeltState(void)
{
	return DriverSeatBeltState;
}