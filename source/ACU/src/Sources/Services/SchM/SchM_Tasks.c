/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       SchM_Tasks.c
\brief      Application Tasks
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/

#include "SchM_Tasks.h"
#include "Can_Manager.h"
#include "ADC.h"




void SchM_3p125ms_Task(void)
{
	
}



void SchM_6p25ms_Task(void)
{	
	DriverBuckleState();
	PassBuckleState();
}



void SchM_12p5ms_Task(void)
{

}



void SchM_25ms_Task(void)
{
	DriverSeatBeltSensor();   /* Sensor to check the Driver seatbelt*/
}



void SchM_50ms_Task(void)
{
	PassengerSeatBeltSensor();   /* Sensor to check the Passenger seatbelt*/
}



void SchM_100ms_Task(void)
{
	PassengerSeatSensor();        /* Sensor to check if the passenger is present*/
}