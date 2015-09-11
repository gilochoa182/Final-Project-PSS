/*============================================================================*/
/*                        Continental Automotive                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %UART.h%
* %version:         1 %
* %created_by:      Armando Villa %
* %date_created:    Thu Aug 6 2015 %
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

#ifndef UART_H                               /* To avoid double inclusion */
#define UART_H

/* Includes */
/* -------- */
#include "MCU_derivative.h"
#include "typedefs.h"

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
 void UART_Config(void);
 void UART_Init(T_ULONG lul_baudrate, T_ULONG lul_xtal);


/* Functions macros */


/* Exported defines */
#define Frec_64Mhz 64000000

#endif