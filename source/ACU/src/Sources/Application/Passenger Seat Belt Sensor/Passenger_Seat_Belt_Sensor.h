/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        Passenger_Seat_Belt_Sensor.h
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Sep 07 2015
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 07/09/2015  | SAR/SIF/SCN_xxx               | Gilberto Ochoa   */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef PASSENGER_SEAT_BELT_SENSOR_H                               /* To avoid double inclusion */
#define PASSENGER_SEAT_BELT_SENSOR_H

/* Includes */
/* -------- */

#include "MCU_derivative.h"

/*-- Defines -----------------------------------------------------------------*/



/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */

typedef enum
{
	DRI_FAULTY,
	BUCKLE, 
	DRI_UNDETERMINED,
	UNBUCKLE
}PassengerSeatSensorStateType;


typedef struct
{
	T_UBYTE	faulty:4;
	T_UBYTE	unbuckle :4;
	T_UBYTE	undetermined:4;
	T_UBYTE	buckle:4;
	T_UBYTE	time:4;
	T_UBYTE	:4;
}PassengerSeatSensorCountType;

/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern void PassengerSeatBeltSensor(void);
extern PassengerSeatSensorStateType GetPassengerSeatBeltState(void);

/* Functions macros */


/* Exported defines */


#endif