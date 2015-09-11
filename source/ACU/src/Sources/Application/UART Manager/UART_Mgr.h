/*============================================================================*/
/*                        Continental Automotive                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %UART:Mgr.h%
* %version:         1 %
* %created_by:      Armando Villa %
* %date_created:    Thu Aug 6 2015 %
*=============================================================================*/
/* DESCRIPTION : UART manager for transmition and reception                   */
/*============================================================================*/
/* FUNCTION COMMENT : An especific driver designed manage the transmition and */
/*					  reception UART.										  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 06/08/2015  | 				               | Armando Villa    */
/* Start of the project			                                              */
/*============================================================================*/

#ifndef UART_MGR_H                               /* To avoid double inclusion */
#define UART_MGR_H

/* Includes */
/* -------- */
#include "UART.h"
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
void UART_TxChar(T_UBYTE lub_txchar);
//void UART_TxData(T_UBYTE *lpub_txstring);
T_UBYTE UART_RxChar(void);


/* Functions macros */


/* Exported defines */


#endif