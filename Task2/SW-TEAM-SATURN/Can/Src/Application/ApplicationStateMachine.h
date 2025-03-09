#ifndef APPLICATION_STATE_MACHINE_H
#define APPLICATION_STATE_MACHINE_H
#include "stdint.h"
#include "stdio.h"






#define APP_STATE_NUMBER            6  

typedef void (*PointerFunc)(void); 

typedef enum
{
    APP_INIT_STATE = 0,
    APP_WAIT_STATE,
    APP_GRIP_OPEN_STATE,
    APP_GRIP_CLOSE_STATE,
    APP_GRIP_MOVE_STATE,
    APP_GRIP_RELEASE_STATE
}App_State_e;

extern App_State_e App_State;



void App_Init(void);
void App_Wait_State(void);
void App_Grip_Open_State(void);
void App_Grip_Close_State(void);
void App_Grip_Move_State(void);
void App_Grip_Release_State(void);
void App_State_Machine(void);

#endif