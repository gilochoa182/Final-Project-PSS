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

extern void ADCModeSelector(int adcmode);
extern int Read_ADC(void);

/* Functions macros */

/* Exported defines */

#define OneShot       0
#define Scan          1
#define PCR_POT       20
#define CHANNEL_0     0

#endif