/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.c
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/

/*~+:Import*/
#include "Can_Manager.h"
#include "GPIO.h"



/* Temporary CAN Messages */

uint8_t securityAccessSuccess[2] = {0x01, 0x27};
uint8_t securityAccessFail[2]    = {0x01, 0x30};


CAN_PduType   pdu_handlerSuccess = { 2, 2, securityAccessSuccess};
CAN_PduType   pdu_handlerFail    = { 2, 2, securityAccessFail};



/*~+:Can Manager Callbacks*/
CAN_MessageDataType CanMessage_PduHandler0;



/*~+:CanManager_SendMesage_25ms*/
void CanManager_SendMessage_Success(void)
{
	CAN_SendFrame(pdu_handlerSuccess);
}




void CanManager_SendMessage_fail(void)
{
	CAN_SendFrame(pdu_handlerFail);
}



void RX_Can_Test(CAN_MessageDataType CanMessage)
{
	CanMessage_PduHandler0 = CanMessage;
}



void check(void)
{
	if( (CanMessage_PduHandler0.msg_data_field[3]) == (0x67) )
	{
		LED_ON(LED1);
		LED_OFF(LED3);
		CanMessage_PduHandler0.msg_data_field[3] = 0;
	}
	
	else if((CanMessage_PduHandler0.msg_data_field[3]) == (0x7F))
	{
		LED_ON(LED3);
		LED_OFF(LED1);
		CanMessage_PduHandler0.msg_data_field[3] = 0;
	}
	
	else
	{
		LED_OFF(LED1);
		LED_OFF(LED3);
	}
	
}

/*
void stateMachine(void)
{
	static T_UBYTE i;
	switch((CanMessage_PduHandler0.msg_data_field[0]) & (0xF0))
	{
		case SF:
			for(i=1; i<=((CanMessage_PduHandler0.msg_data_field[0]) & (0x0F)))
			{
				bufferTypedetector[i-1] = CanMessage_PduHandler0.msg_data_field[i];
			}
			
			break;
			
		case FF:
			for(i=3; i<=((CanMessage_PduHandler0.msg_data_field[0]) & (0x0F)))
			{
				bufferTypedetector[i-1] = CanMessage_PduHandler0.msg_data_field[i];
			}
			break;
			
		case CF:
			break;
	}
}
*/