/*~+:Header*/
/*******************************************************************************/
/**
\file       can_cfg.c
\author     Alicia Álvarez
\version    1.0
*/
/****************************************************************************************************/


/*~+:Imports*/
#include "Can_Cfg.h"
#include "Can_Manager.h"


/*~+:Defines*/
#define MAX_NUM_RX_FILTERS  (4)
#define MAX_NUM_TX_FILTERS  (2)


/*~+:External Interfaces*/
extern uint8_t CAN_SendFrameInt(uint8_t can_eng, uint8_t can_channel, uint8_t *can_msg_buf, uint8_t len);


/*~+:Variables*/

/*~+:CAN Baudrate Configuration*/
CAN_DevBaudrateType bios_cnf_can_baudrate_options[] = {
/***********************************************************************************/
/* Propagation Segment------------------------------+                              */
/* Phase Segment 2-------------------------------+  |                              */
/* Phase Segment 1----------------------------+  |  |                              */
/* Resync Jump Width-----------------------+  |  |  |                              */
/* Baudrate Prescaler------------------+   |  |  |  |                              */
/* Clock Source ------------+          |   |  |  |  |                              */
/*                          |          |   |  |  |  |                              */
                     {CNF_CAN_OSC_CLK, 1,  2, 2, 2, 3},     /* BR 1Mbps            */
                     {CNF_CAN_OSC_CLK, 2,  2, 2, 2, 3},     /* BR 500kbps          */
                     {CNF_CAN_OSC_CLK, 4,  2, 2, 2, 3},     /* BR 250kbps          */
                     {CNF_CAN_OSC_CLK, 8,  2, 2, 2, 3}      /* BR 125kbps          */
};




/*~+:CAN Messages Configuration*/
CAN_ConfigMsgType bios_cnf_can_messages[] = {                           /*mascara para filtros*/
{ 0, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x1A0,         0xFFF,      RX_Can_Test  },
{ 1, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x17F,         0xFFF,      RX_Can_Test  },
{ 2, CNF_CAN_CH_TX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x345,         0xFFF,      NULL  },
};


CAN_ConfigDeviceType bios_cnf_can_dev[] = {
{
CANB,                                           /* CAN Device */
( sizeof(bios_cnf_can_messages)
/sizeof(bios_cnf_can_messages[0]) ),   /* Number of channels */
CNF_CAN_BOFF_DIS,                               /* Automatic Recovery OFF */
CNF_CAN_LBUF_ON,                                /* Lower buffer is transmitted first */
CNF_CAN_FIFO_DIS,                               /* FIFO Disabled */
CNF_CAN_IND_MASK,                               /* Filter mode Individual Mask */
&bios_cnf_can_baudrate_options[0],              /* CAN Baud rate Configuration */
bios_cnf_can_messages,                  /* Configured channels for this CAN Engine */
}
};


CAN_ConfigType can_driver_config = 
{
	( sizeof(bios_cnf_can_dev)/sizeof(bios_cnf_can_dev[0]) ),   /* Number of devices */
	bios_cnf_can_dev                                            /* Pointer to devices configuration */
};