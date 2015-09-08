/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        ADC.h
* version:          1.0
* created_by:       Gilberto Ochoa
* date_created:     Aug 29 2015
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
/*  1.0      | 29/08/2015  |                               | Gilberto Ochoa   */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef ADC_H                               /* To avoid double inclusion */
#define ADC_H

/* Includes */
/* -------- */

#include "MPC5606B.h"


/****ADC****/
#define ADC ADC_0


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */


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

extern void ADCModeSelector(T_UBYTE adcmode);
extern T_UWORD Read_ADC(T_UBYTE channel);
extern T_UWORD Read_ADC_2(T_UBYTE channel);
extern T_UWORD Read_ADC_3(T_UBYTE channel);

/* Functions macros */

/* Exported defines */

#define  OneShot            0
#define  Scan               1
#define  ADC0_P0            20
#define  ADC0_P1            21
#define  ADC0_P2            22
#define  PASS_SEAT_SENS     0
#define  PASS_SEATBELT      1
#define  DRIV_SEATBELT      2
#endif