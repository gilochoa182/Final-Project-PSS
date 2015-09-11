/*============================================================================*/
/*                        Continental Automotive                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %UART_Mgr.c%
* %version:         1 %
* %created_by:      Armando Villa %
* %date_created:    Thu Aug 6 2015 %
*=============================================================================*/
/* DESCRIPTION : UART manager for transmition and reception                   */
/*============================================================================*/
/* FUNCTION COMMENT : A specific driver designed manage the UART transmition  */
/*					  and reception.										  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 06/08/2015  |                               | Armando Villa    */
/* Start of the project			                                              */
/*============================================================================*/

/* Includes */
/* -------- */
#include "UART_Mgr.h"


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
void UART_TxChar(T_UBYTE lub_txchar){
	LINFLEX_0.BDRL.B.DATA0 = lub_txchar;  /* write character to transmit buffer */
	while (1 != LINFLEX_0.UARTSR.B.DTF) {	/* Wait for data transmission completed flag */
	}
	LINFLEX_0.UARTSR.R = 0x0002; 
}

/**************************************************************
 *  Name                 :	UART_TxData
 *  Description          :	A function to transmit a character
 *							array.
 *  Parameters           :  [Input]
 *  Return               :	[Void]
 *  Critical/explanation :  [No]
 **************************************************************/
void UART_TxData(T_UBYTE *lpub_txstring){
	while(*lpub_txstring != '\0'){		/* Loop until array finish */
		UART_TxChar(*lpub_txstring);
		lpub_txstring++;
	}
}

/**************************************************************
 *  Name                 :	UART_TxChar
 *  Description          :	A function to recive a single char
 *  Parameters           :  [Void]
 *  Return               :	[Void]
 *  Critical/explanation :  [No]
 **************************************************************/
T_UBYTE UART_RxChar(void){
	T_UBYTE lub_rxchar;
	while (1 != LINFLEX_0.UARTSR.B.DRF){	/* Wait for data reception completed flag */
	}
	
	while (1 != LINFLEX_0.UARTSR.B.RMB){	/* Wait for Release Message Buffer */
	}
	
	/* Get the data */
	lub_rxchar = (T_UBYTE)LINFLEX_0.BDRM.B.DATA4;
	
	LINFLEX_0.UARTSR.R = 0x0204;	/* clear the DRF and RMB flags by writing 1 to them */
	
	return lub_rxchar;
}