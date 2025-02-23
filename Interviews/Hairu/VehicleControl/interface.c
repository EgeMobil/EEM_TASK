/**
 * @file interface.c
 * @author Hairu
 * @brief 
 * @version 0.1
 * @date 2025-02-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "interface.h"
#include <stdio.h>

/**
 * @brief Initializes the interface layer
 * 
 */
void Interface_Init(void){
    // Display_Init();
    // ESC_Init();
    printf("Interface layer(ESC and Display) are initialized successfully! \n");
}

/**
 * @brief Sends the speed value to the display
 * 
 * @param speed 
 */
void Interface_SendSpeedToDisplay(int speed){
    // Display_ShowSpeed(speed);
    printf("Speed sent to display: %d \n", speed);
}

/**
 * @brief sends the motor command(speed and torque) to the motor driver
 * 
 * @param command 
 */
void Interface_SendMotorCommand(MotorCommand command){

    System_SetMotorSpeed(command.speed);
    System_SetMotorTorque(command.torque);
    printf("Motor command sent: Speed=%d, Torque=%d \n", command.speed, command.torque);
}


