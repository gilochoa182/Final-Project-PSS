/*~A*/
/*~+:Header*/
/*******************************************************************************/
/**
\file       can.h
\author     Alicia Álvarez
\version    1.0
*/
/****************************************************************************************************/
/*~E*/
#ifndef CAN_H
#define CAN_H
/*~A*/
/*~+:Imports*/
#include "Can_Types.h"
#include "Can_Cfg.h"


/*~+:Defines*/
#define MAX_MSG_TO_DISP (10)
#define MAX_MSG_TX_TO_DISP (3)


/*~+:Public Variables*/
extern CAN_MessageDataType    received_messages[64];
extern CAN_MessageDataType    txd_messages[64];


/*~+:Public Operations*/
extern void CAN_Initialization(CAN_ConfigType *can_config);
extern void CAN_SendFrame(CAN_PduType pdu_handler);
extern void CAN_Stop(void);
/*~E*/
#endif
