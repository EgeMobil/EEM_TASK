#ifndef HAL_H
#define HAL_H


#include "stdbool.h"
#include "stdint.h"


extern uint8_t HAL_Move_Request;
extern uint8_t HAL_Object_Status;

uint8_t HAL_Supply_Object_Status(void);
uint8_t HAL_Supply_Move_Request(void);


uint8_t HAL_Supply_Grip_Status(void);
void HAL_Open_Grip(void);
void HAL_Close_Grip(void);
void HAL_Motor_Run(void);


#endif
