/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.h
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
#ifndef __CAN_MANAGER
#define __CAN_MANAGER
/*~A*/
/*~+:Imports*/
#include "Can.h"
/*~E*/
/*~A*/
extern	T_UBYTE Flag;
/*~+:Exported Interfaces*/

extern void CanManager_SendMessage_Success(void);
extern void CanManager_SendMessage_fail(void);
extern void RX_Can_Test (CAN_MessageDataType CanMessage);
extern void check(void);
extern void control(void);
/*~E*/
#endif /* __CAN_MANAGER */
