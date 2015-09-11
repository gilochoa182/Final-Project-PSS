/*============================================================================*/
/*                        Continental Automotive                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %UART.c%
* %version:         1 %
* %created_by:      Armando Villa %
* %date_created:    Thu Aug 6 2015 %
*=============================================================================*/
/* DESCRIPTION : UART Driver for MPC5606B                                     */
/*============================================================================*/
/* FUNCTION COMMENT : A specific driver designed to config and initialize     */
/*					  the UART module for MPC5606B.							  */
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
#include "UART_Init.h"



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
 *  Name                 : inline_func	2
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
 *  Name                 :	UART_Config
 *  Description          :	A function to set the UART main 
 *							configurations.
 *  Parameters           :  [Void]
 *  Return               :	[Void]
 *  Critical/explanation :  [No]
 **************************************************************/
 void UART_Config(void){
	LINFLEX_0.LINCR1.R = 0x0081;	/* Seting the INIT mode */
	
	while (0x1000 != (LINFLEX_0.LINSR.R & 0xF000)){		/* Wait until Init mode is active */
	}
	
	SIU.PCR[18].R = 0x0400;		/* Configure pad PB2 as LIN0TX */
	SIU.PCR[19].R = 0x0103;		/* Configure pad PB3 as LIN0RX */	

	/* Configuring the UART Mode */
	LINFLEX_0.UARTCR.R = 0x0001; 	/* set the UART bit first to be able to write the other bits */
	LINFLEX_0.UARTCR.R = 0x0033; 	/* 8bit data, no parity, Tx and Rx enabled, UART mode */

}

/**************************************************************
 *  Name                 :	UART_Init
 *  Description          :	A function to initalize and set 
 *							the UART badurate.
 *  Parameters           :  [Input]
 *  Return               :	[Void]
 *  Critical/explanation :  [No]
 **************************************************************/
 void UART_Init(T_ULONG lul_baudrate, T_ULONG lul_xtal){
    T_ULONG lul_LINIBRR;
    T_ULONG lul_LINFBRR;

	/* Baudrate pareameters calcularion */
    lul_LINIBRR = ((lul_xtal)/(16*lul_baudrate));
    lul_LINFBRR = (((lul_xtal)%(16*lul_baudrate))*(lul_xtal/1000000))/((lul_xtal/1000000)*lul_baudrate);

	LINFLEX_0.LINIBRR.R = (T_UWORD)lul_LINIBRR;
	LINFLEX_0.LINFBRR.R = (T_UWORD)lul_LINFBRR;
	
	LINFLEX_0.LINCR1.R = 0x0080;	/* Configuring as a Normal mode*/
}