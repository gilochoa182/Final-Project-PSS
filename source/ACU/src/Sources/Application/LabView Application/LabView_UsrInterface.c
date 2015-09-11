/*============================================================================*/
/*                        Continental Automotive                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %LabView_UsrInterface.c%
* %version:         1 %
* %created_by:      Armando Villa %
* %date_created:    Thu Sep 8 2015 %
*=============================================================================*/
/* DESCRIPTION : UART manager for transmition and reception                   */
/*============================================================================*/
/* FUNCTION COMMENT : A specific driver designed to manage the a LabView      */
/*					  interface.											  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 08/09/2015  |                               | Armando Villa    */
/* Start of the project			                                              */
/*============================================================================*/

/* Includes */
/* -------- */
#include "LabView_UsrInterface.h"


/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */


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



/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	UART_TxChar
 *  Description          :	A function to tansmit a single char
 *  Parameters           :  [Void]
 *  Return               :	[Void]
 *  Critical/explanation :  [No]
 **************************************************************/
void LabViewCmdTx(T_UBYTE lub_lvcmd){
	UART_TxChar(lub_lvcmd);
}