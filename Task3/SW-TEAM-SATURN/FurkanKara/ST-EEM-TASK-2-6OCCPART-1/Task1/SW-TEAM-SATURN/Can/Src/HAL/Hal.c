#include "Hal.h"




uint8_t HAL_Move_Request;
uint8_t HAL_Object_Status;
uint8_t HAL_Grip_Status;


/*
* @brief: This function is used to check the movement request
* @param: None
*/
uint8_t HAL_Supply_Move_Request(void)
{
    return HAL_Move_Request;
}

uint8_t HAL_Supply_Object_Status(void)
{
    return HAL_Object_Status;
}

uint8_t HAL_Supply_Grip_Status(void)
{
    return HAL_Grip_Status;
}

void HAL_Open_Grip(void)
{
    //Opens grip
}

void HAL_Close_Grip(void)
{
    //Close grip
}

void HAL_Motor_Run(void)
{
    //Runs actuator
}

