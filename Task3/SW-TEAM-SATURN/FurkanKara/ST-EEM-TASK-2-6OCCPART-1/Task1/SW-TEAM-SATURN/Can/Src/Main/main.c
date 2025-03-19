#include "stdio.h"
#include "ApplicationStateMachine.h"
#include "Hal.h"






int main(void){

    HAL_Move_Request = 1;    
    HAL_Object_Status = 1;
    printf("----------Program is Started----------\n");
    while(1)
    {
        App_State_Machine();
    }


    return 0;
}