/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         Passenger_Seat_Sensor.c
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
#include "Passenger_Seat_Sensor.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

SeatSensorStateType SeatSensorState = UNOCCUPIED;

SeatSensorCountType  counter;

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
 *  Name                 :	PassengerSeatSensor
 *  Description          :
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  NO
 **************************************************************/
void PassengerSeatSensor(void)
{	
	counter.time++;
	if(counter.time  == FIVE_HUNDRED_MS)
	{
		counter.time = ZERO_MS;
		
		/***************   FAULTY   ******************************/
		if((Read_ADC(PASS_SEAT_SENS) > ZERO_VOLTS) && (Read_ADC(PASS_SEAT_SENS) < TWO_VOLTS))
		{
			counter.unoccupied = ZERO_SAMPLES;
			counter.occupied = ZERO_SAMPLES;
			counter.undetermined = ZERO_SAMPLES;
			
			counter.faulty++;
			
			if(counter.faulty == SIX_SAMPLES)
			{
				counter.faulty = ZERO_SAMPLES;
				
				SeatSensorState = FAULTY;
			}
			
			else
			{
				/* Do nothing */
			}
			
		}
		/***********************************************************************/
		
		
		
		
		
		/***************   OCCUPIED   ******************************/
		else if((Read_ADC(PASS_SEAT_SENS) > TWO_VOLTS) && (Read_ADC(PASS_SEAT_SENS) < TEN_VOLTS))
		{	
			counter.faulty = ZERO_SAMPLES;
			counter.unoccupied = ZERO_SAMPLES;
			counter.undetermined = ZERO_SAMPLES;
			
			counter.occupied++;
			
			if(counter.occupied == SIX_SAMPLES)
			{
				counter.occupied = ZERO_SAMPLES;
				
				SeatSensorState = OCCUPIED;
			}
			
			else
			{
				/* Do nothing */
			}
		}
		/***********************************************************************/
		
		
		
		
		
		/***************   UNDETERMINED   ******************************/
		else if((Read_ADC(PASS_SEAT_SENS) > TEN_VOLTS) && (Read_ADC(PASS_SEAT_SENS) < TWELVE_VOLTS))
		{	
			counter.faulty = ZERO_SAMPLES;
			counter.unoccupied = ZERO_SAMPLES;
			counter.occupied = ZERO_SAMPLES;
			
			
			counter.undetermined++;
			
			if(counter.undetermined == SIX_SAMPLES)
			{
				counter.undetermined = ZERO_SAMPLES;
				
				SeatSensorState = UNDETERMINED;
			}
			
			else
			{
				/* Do nothing */
			}
			
		}
		/***********************************************************************/
		
		
		
		
		
		/***************   UNOCCUPIED   ******************************/
		else if((Read_ADC(PASS_SEAT_SENS) > TWELVE_VOLTS) && (Read_ADC(PASS_SEAT_SENS) < TWENTY_VOLTS))
		{	
			counter.faulty = ZERO_SAMPLES;
			counter.undetermined = ZERO_SAMPLES;
			counter.occupied = ZERO_SAMPLES;
			
			counter.unoccupied++;
			
			if(counter.unoccupied == SIX_SAMPLES)
			{
				counter.unoccupied = ZERO_SAMPLES;
				
				SeatSensorState = UNOCCUPIED;
			}
			
			else
			{
				/* Do nothing */
			}
		}
		/***********************************************************************/
		
		
		
		
		
		/***************   FAULTY   ******************************/
		else if(Read_ADC(PASS_SEAT_SENS) > TWENTY_VOLTS)
		{	
			counter.undetermined = ZERO_SAMPLES;
			counter.occupied = ZERO_SAMPLES;
			counter.unoccupied = ZERO_SAMPLES;
			
			counter.faulty++;
			
			if(counter.faulty == SIX_SAMPLES)
			{
				counter.faulty = ZERO_SAMPLES;
				
				SeatSensorState = FAULTY;
			}
			
			else
			{
				/* Do nothing */
			}
			
		}
		/***********************************************************************/	
	}
	
	else
	{
		/* Do nothing */
	}
		
}





/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	GetSeatSensorState
 *  Description          :
 *  Parameters           :  void
 *  Return               :	SeatSensorStateType  SeatSensorState
 *  Critical/explanation :  NO
 **************************************************************/
SeatSensorStateType GetSeatSensorState(void)
{
	return SeatSensorState;
}



void test(void)
{
	switch(GetSeatSensorState())
	{
		case FAULTY:
			LED_ON(LED1);
			LED_OFF(LED2);
			LED_OFF(LED3);
			LED_OFF(LED4);
			break;
		
		case UNOCCUPIED:
			LED_OFF(LED1);
			LED_ON(LED2);
			LED_OFF(LED3);
			LED_OFF(LED4);
			break;
		
		case UNDETERMINED:
			LED_OFF(LED1);
			LED_OFF(LED2);
			LED_ON(LED3);
			LED_OFF(LED4);
			break;
		
		case OCCUPIED:
			LED_OFF(LED1);
			LED_OFF(LED2);
			LED_OFF(LED3);
			LED_ON(LED4);
			break;
	}
}