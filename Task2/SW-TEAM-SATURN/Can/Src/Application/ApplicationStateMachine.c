#include "ApplicationStateMachine.h"
#include "Move.h"

void HAL_Delay(void)
{
    uint32_t delay;
    for(delay = 0; delay < 429496729; delay++);
}

App_State_e App_State;

void App_Init(void)
{
    printf("Current state is APP_INIT_STATE\n");
    App_State = APP_WAIT_STATE;
    HAL_Delay();
}



void App_Wait_State(void)
{
    printf("Current state is APP_WAIT_STATE\n");
    uint8_t App_is_move_requested = Check_Movement_Request();
    if(App_is_move_requested)
    {
        App_State = APP_GRIP_OPEN_STATE;
    }
    else
    {
        App_State = APP_WAIT_STATE;
    }
    HAL_Delay();
}


void App_Grip_Open_State(void)
{
    printf("Current state is APP_GRIP_OPEN_STATE\n");
    Open_Grip();
    App_State = APP_GRIP_CLOSE_STATE;
    HAL_Delay();

}

void App_Grip_Close_State(void)
{
    printf("Current state is APP_GRIP_CLOSE_STATE\n");
    uint8_t App_is_object_gripped = Close_Grip();
    if(!App_is_object_gripped)
    {
        App_State = APP_GRIP_OPEN_STATE;
    }
    else
    {
        App_State = APP_GRIP_MOVE_STATE;
    }
    HAL_Delay();
}

void App_Grip_Move_State(void)
{
    printf("Current state is APP_GRIP_MOVE_STATE\n");
    Move_Start();
    App_State = APP_GRIP_RELEASE_STATE;
    HAL_Delay();

}


void App_Grip_Release_State(void)
{
    printf("Current state is APP_GRIP_RELEASE_STATE\n");
    Open_Grip();
    App_State = APP_WAIT_STATE;
    HAL_Delay();
}

void App_State_Machine(void)
{
    static const PointerFunc App_State_Machine[APP_STATE_NUMBER] = 
    {
        &App_Init,
        &App_Wait_State,
        &App_Grip_Open_State,
        &App_Grip_Close_State,
        &App_Grip_Move_State,
        &App_Grip_Release_State
    };

    App_Init();

    while(1)
    {
        App_State_Machine[App_State]();
    }

    

    

}