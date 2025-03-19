/**
 * @file applicaiton.c
 * @author Application busines logic
 * @brief 
 * @version 0.1
 * @date 2025-02-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "application.h"
#include "controller.h"
#include "system.h"
#include "interface.h"
#include "application_helpers.h"
#include <stdio.h>  

static int Pot1Reading = 0;
static int Pot2Reading = 0;
static int minSpeed = 0;
static int maxSpeed = 0;
static int currentSpeed = 0;
static int currentTorque = 0;
static int averageSpeed = 0;

MotorCommand motorCommand;

void Application_Init(void)
{
    Pot1Reading = 0;
    Pot2Reading = 0;
    minSpeed = Controller_GetMinSpeed();
    maxSpeed = Controller_GetMaxSpeed();
    currentSpeed = 0;
    printf("Application initialized.\n");
    printf("\n\n");
}

/**
 * @brief 
 * 
 */
void Application_RunCycle(void)
{
    // Read the potentiometer values
    Pot1Reading = Controller_GetPot1Reading();
    Pot2Reading = Controller_GetPot2Reading();

    // Calculate the average speed
    averageSpeed = (Pot1Reading + Pot2Reading) / 2;

    /**
     * @brief set the max and min tresholds for the speed
     * 
     */
    if (averageSpeed < minSpeed)
    {
        currentSpeed = minSpeed;
    }
    else if (averageSpeed > maxSpeed)
    {
        currentSpeed = maxSpeed;
    }
    else
    {
        currentSpeed = averageSpeed;
    }

    currentSpeed = Calculate_Speed_From_Gas(currentSpeed);
    currentTorque = Calculate_Torque_From_Gas(currentTorque);

    motorCommand = Create_Motor_Command(currentSpeed, currentTorque);

    // Send the motor command to the ESC
    Interface_SendMotorCommand(motorCommand);

    // Send the speed to the display
    Interface_SendSpeedToDisplay(currentSpeed);

    printf("[Application] Current Speed=%d RPM, Torque=%d Nm\n", currentSpeed, currentTorque);
    printf("\n\n\n\n");

}
    