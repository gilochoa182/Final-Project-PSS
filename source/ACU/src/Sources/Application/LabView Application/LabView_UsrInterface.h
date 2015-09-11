/*============================================================================*/
/*                        Continental Automotive                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %LabView_UsrInterface.h%
* %version:         1 %
* %created_by:      Armando Villa %
* %date_created:    Thu Sep 8 2015 %
*=============================================================================*/
/* DESCRIPTION : UART Header Driver for MPC5606B                              */
/*============================================================================*/
/* FUNCTION COMMENT : A specific driver designed to config and initialize     */
/*					  the UART module for MPC5606B.							  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 06/08/2015  | SAR/SIF/SCN_xxx               | Armando Villa    */
/* Start of the project			                                              */
/*============================================================================*/

#ifndef LABVIEW_USRINTERFACE_H                               /* To avoid double inclusion */
#define LABVIEW_USRINTERFACE_H

/* Includes */
/* -------- */
#include "MCU_derivative.h"
#include "typedefs.h"
#include "UART_Mgr.h"

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
void LabViewCmdTx(T_UBYTE lub_lvcmd);


/* Functions macros */


/* Exported defines */
#define SET_BASIC_MODE		0x42
#define SET_ENHANCED_MODE	0x65
#define SET_EURO_MODE		0x45

#define DRVR_FASTENED		0x44
#define DRVR_UNFASTENED		0x64
#define PSGR_FASTENED		0x50
#define PSGR_UNFASTENED		0x70

#define SPEED_DETECTOR		0x53



#endif