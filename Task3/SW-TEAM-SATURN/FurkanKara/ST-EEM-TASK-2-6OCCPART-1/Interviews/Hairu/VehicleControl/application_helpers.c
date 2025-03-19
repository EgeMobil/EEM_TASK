/**
 * @file application_helpers.c
 * @author helper functions for the application layer
 * @brief 
 * @version 0.1
 * @date 2025-02-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "application_helpers.h"
#include <stdio.h>


/**
 * @brief caculates the speed based on the gas pedal percentage
 *        uses a linear mapping: 0% -> 0 RPM, 100% -> MAX_RPM
 * 
 * @param speed 
 * @return int 
 */
int Calculate_Speed_From_Gas(int speed)
{
    // Calculate the speed using a linear mapping
    printf("pot measurement is mapped to 0 and rpm max!  \n");
    return (speed * MAX_RPM) / 100;
}


/**
 * @brief calculates the torque based on the gas pedal percentage
 *        uses a linear mapping: 0% -> 0 Nm, 100% -> MAX_TORQUE
 * 
 * @param speed 
 * @return int 
 */
int Calculate_Torque_From_Gas(int speed)
{
    // Calculate the torque using a linear mapping
    printf("pot measurement is mapped o and torque max! \n");
    return (speed * MAX_TORQUE) / 100;
}


/**
 * @brief creates a motor command structure containing both speed and torque
 *        This command can then be sent to the motor driver.
 * 
 * @param speed 
 * @param torque 
 * @return MotorCommand 
 */
MotorCommand Create_Motor_Command(int speed, int torque)
{
    MotorCommand command;
    command.speed = speed;
    command.torque = torque;
    printf("motor command is prepared! \n");
    return command;
}
