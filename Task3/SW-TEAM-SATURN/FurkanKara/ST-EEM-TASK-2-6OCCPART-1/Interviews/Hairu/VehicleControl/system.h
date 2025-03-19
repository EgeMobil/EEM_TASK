/**
 * @file system.h
 * @author Hairu
 * @brief low level header file
 * @version 0.1
 * @date 2025-02-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef SYSTEM_H
#define SYSTEM_H

void System_Init(void);

int System_GetPot1Reading(void);

int System_GetPot2Reading(void);


void System_SetMotorSpeed(int speed);
void System_SetMotorTorque(int torque);

#endif