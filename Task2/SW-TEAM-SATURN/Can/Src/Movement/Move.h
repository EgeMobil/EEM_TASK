#ifndef MOVE_H
#define MOVE_H


#include "stdint.h"
#include "stdbool.h"



#define ACT_MOVING                  1
#define ACT_STOPPED                 0


typedef struct 
{
    /* data */
    bool isMoving;
}Move_Status_t;

typedef struct 
{
    bool is_Move_Requested;
}Move_Request_t;






void Move_Init(void);
void Move_Start(void);
void Move_Stop(void);

uint8_t Check_Movement_Request(void);
void Open_Grip(void);
uint8_t Close_Grip(void);


#endif