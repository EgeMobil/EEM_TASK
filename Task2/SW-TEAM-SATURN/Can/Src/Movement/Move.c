#include "Move.h"
#include "Hal.h"








/*
* @brief: This function is used to initialize the movement status
* @param: None
*/
void Move_Init(void)
{
    
}


/*
* @brief: This function is used to start the movement
* @param: None
*/
void Move_Start(void)
{
    HAL_Motor_Run();
}

/*
* @brief: This function is used to stop the movement
* @param: None
*/
void Move_Stop(void)
{
    
}




/*
* @brief: This function is used to check the movement request
* @param: None
*/
uint8_t Check_Movement_Request(void)
{
    uint8_t ret_val;
    uint8_t isMoveRequested = HAL_Supply_Move_Request();

    if(isMoveRequested)
    {
        ret_val = 1;
    }
    else
    {
        ret_val = 0;
    }

    return ret_val;
}

void Open_Grip (void)
{
    uint8_t isGripOpen = HAL_Supply_Grip_Status();
    if(!isGripOpen)
    {
        HAL_Open_Grip();
    }
    else
    {
        //do nothing
    }
}

uint8_t Close_Grip(void)
{
    uint8_t ret_val;
    uint8_t isObjectGripped = HAL_Supply_Object_Status();
    if(isObjectGripped)
    {
        ret_val = 1;
    }
    else
    {
        ret_val = 0;
    }
    return ret_val;
}