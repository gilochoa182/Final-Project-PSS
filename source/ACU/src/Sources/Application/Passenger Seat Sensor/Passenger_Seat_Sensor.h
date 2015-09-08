/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        Passenger_Seat_Sensor.h
* version:          1.0 
* created_by:       Gilberto Ochoa
* date_created:     Aug 30 2015
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
/*  1.0      | 30/08/2015  |                               | Gilberto Ochoa   */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef PASSENGER_SEAT_SENSOR_H                               /* To avoid double inclusion */
#define PASSENGER_SEAT_SENSOR_H

/* Includes */
/* -------- */

/*-- Defines -----------------------------------------------------------------*/

#define FIVE_HUNDRED_MS    5
#define ZERO_MS            0
#define ZERO_VOLTS         0
#define TWO_VOLTS          102
#define TEN_VOLTS          510
#define TWELVE_VOLTS       612
#define TWENTY_VOLTS       1010
#define SIX_SAMPLES        6
#define ZERO_SAMPLES       0


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */

typedef enum
{
	FAULTY,
	UNOCCUPIED, 
	UNDETERMINED,
	OCCUPIED
}SeatSensorStateType;


typedef struct
{
	T_UBYTE	faulty:3;
	T_UBYTE	unoccupied:3;
	T_UBYTE	undetermined:3;
	T_UBYTE	occupied:3;
	T_UBYTE	time:3;
}SeatSensorCountType;


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
extern void PassengerSeatSensor(void);
extern SeatSensorStateType GetSeatSensorState(void);

/* Functions macros */


/* Exported defines */


#endif