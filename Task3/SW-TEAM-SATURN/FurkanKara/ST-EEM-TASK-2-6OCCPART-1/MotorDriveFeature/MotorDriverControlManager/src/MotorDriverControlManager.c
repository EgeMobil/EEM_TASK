/**
 * @file MotorDriverControlManager.c
 * @brief This file contains the private implementation for the MotorDriverControlManager.
 * 
 * It includes the functionalities related to controlling the motor driver, such as setting and getting
 * the speed, brake status, direction, and raw speed status. This implementation supports various motor driver
 * controls by managing the internal state of the motor driver control manager.
 * 
 * The main functions in this file include:
 * - Setting and getting speed.
 * - Setting and getting brake status.
 * - Setting and getting direction status.
 * - Setting and getting raw speed status.
 * - A string representation of the current state of the motor driver.
 * 
 * The file defines the implementation of the `MotorDriverControlManager` functions and manages an instance of the manager.
 * 
 * @note This file is intended to be used internally and provides low-level control functionalities for the motor driver.
 */
#include "MotorDriverControlManager_private.h"

static dtMotorDriverControlManager instance;

/** 
 * @brief Sets the speed for the motor driver.
 * 
 * This function sets the speed attribute of the MotorDriverControlManager instance.
 * 
 * @param speed The speed to be set for the motor driver.
 */
static void MotorDriverControlManager_setSpeed_Impl(dtMotorDriverControlManager_Speed speed)
{
    instance.speed = speed;
}

/** 
 * @brief Gets the current speed of the motor driver.
 * 
 * This function retrieves the current speed attribute of the MotorDriverControlManager instance.
 * 
 * @return The current speed of the motor driver.
 */
static dtMotorDriverControlManager_Speed MotorDriverControlManager_getSpeed_Impl(void)
{
    return instance.speed;
}

/** 
 * @brief Sets the Bdr (Brake Driver) status for the motor driver.
 * 
 * This function sets the bdr attribute of the MotorDriverControlManager instance.
 * 
 * @param bdr The brake driver status to be set.
 */
static void MotorDriverControlManager_setBdr_Impl(dtMotorDriverControlManager_Bdr bdr)
{
    instance.bdr = bdr;
}

/** 
 * @brief Gets the current Bdr (Brake Driver) status of the motor driver.
 * 
 * This function retrieves the current bdr attribute of the MotorDriverControlManager instance.
 * 
 * @return The current brake driver status.
 */
static dtMotorDriverControlManager_Bdr MotorDriverControlManager_getBdr_Impl(void)
{
    return instance.bdr;
}

/** 
 * @brief Sets the raw speed status for the motor driver.
 * 
 * This function sets the rawSpeedStatus attribute of the MotorDriverControlManager instance.
 * 
 * @param status The raw speed status to be set.
 */
static void MotorDriverControlManager_setRawSpeedStatus_Impl(dtMotorDriverControlManager_RawSpeedStatus status)
{
    instance.rawSpeedStatus = status;
}

/** 
 * @brief Gets the current raw speed status of the motor driver.
 * 
 * This function retrieves the current rawSpeedStatus attribute of the MotorDriverControlManager instance.
 * 
 * @return The current raw speed status.
 */
static dtMotorDriverControlManager_RawSpeedStatus MotorDriverControlManager_getRawSpeedStatus_Impl(void)
{
    return instance.rawSpeedStatus;
}

/** 
 * @brief Sets the brake status for the motor driver.
 * 
 * This function sets the brakeStatus attribute of the MotorDriverControlManager instance.
 * 
 * @param status The brake status to be set.
 */
static void MotorDriverControlManager_setBrakeStatus_Impl(dtMotorDriverControlManager_BrakeStatus status)
{
    instance.brakeStatus = status;
}

/** 
 * @brief Gets the current brake status of the motor driver.
 * 
 * This function retrieves the current brakeStatus attribute of the MotorDriverControlManager instance.
 * 
 * @return The current brake status.
 */
static dtMotorDriverControlManager_BrakeStatus MotorDriverControlManager_getBrakeStatus_Impl(void)
{
    return instance.brakeStatus;
}

/** 
 * @brief Sets the direction status for the motor driver.
 * 
 * This function sets the directionStatus attribute of the MotorDriverControlManager instance.
 * 
 * @param status The direction status to be set.
 */
static void MotorDriverControlManager_setDirectionStatus_Impl(dtMotorDriverControlManager_DirectionStatus status)
{
    instance.directionStatus = status;
}

/** 
 * @brief Gets the current direction status of the motor driver.
 * 
 * This function retrieves the current directionStatus attribute of the MotorDriverControlManager instance.
 * 
 * @return The current direction status.
 */
static dtMotorDriverControlManager_DirectionStatus MotorDriverControlManager_getDirectionStatus_Impl(void)
{
    return instance.directionStatus;
}

/** 
 * @brief Converts the MotorDriverControlManager instance to a string representation.
 * 
 * This function creates a string representation of the MotorDriverControlManager instance's current state.
 * 
 * @return A string representation of the MotorDriverControlManager instance.
 */
static char* MotorDriverControlManager_toString_Impl(void)
{
    char* output = (char*)malloc(512); // Yeterli bir buffer boyutu
    if (output == NULL)
    {
        return strdup("Memory allocation failed.");
    }

    snprintf(output, 512,
             "[MotorDriverControlManager Registers]:\n"
             "Speed: %d\n"
             "Bdr: %d\n"
             "RawSpeedStatus: %d\n"
             "BrakeStatus: %d\n"
             "DirectionStatus: %d\n",
             instance.speed,
             instance.bdr,
             instance.rawSpeedStatus,
             instance.brakeStatus,
             instance.directionStatus);

    return output;
}

/** 
 * @brief Constructor for MotorDriverControlManager.
 * 
 * This function initializes the instance of MotorDriverControlManager by setting function pointers 
 * and default values for the attributes.
 */
void MotorDriverControlManager_CTOR(void)
{
    /* Initialize the Interface Pointers */
    instance.ISpeed = &SpeedInterface;
    instance.IBdr = &BdrInterface;
    instance.IRawSpeed = &RawSpeedInterface;
    instance.IBrakeAndDirection = &BrakeAndDirectionInterface;

    /* Initialize Function Pointers */
    instance.getSpeed = MotorDriverControlManager_getSpeed_Impl;
    instance.setSpeed = MotorDriverControlManager_setSpeed_Impl;

    instance.getBdr = MotorDriverControlManager_getBdr_Impl;
    instance.setBdr = MotorDriverControlManager_setBdr_Impl;

    instance.getRawSpeedStatus = MotorDriverControlManager_getRawSpeedStatus_Impl;
    instance.setRawSpeedStatus = MotorDriverControlManager_setRawSpeedStatus_Impl;

    instance.getBrakeStatus = MotorDriverControlManager_getBrakeStatus_Impl;
    instance.setBrakeStatus = MotorDriverControlManager_setBrakeStatus_Impl;

    instance.getDirectionStatus = MotorDriverControlManager_getDirectionStatus_Impl;
    instance.setDirectionStatus = MotorDriverControlManager_setDirectionStatus_Impl;

    instance.toString = MotorDriverControlManager_toString_Impl;

    /* Initialize Attributes to Default Values */
    instance.speed = 0;
    instance.bdr = 0;
    instance.rawSpeedStatus = 0;
    instance.brakeStatus = 0;
    instance.directionStatus = 0;
}

/** 
 * @brief Gets the singleton instance of MotorDriverControlManager.
 * 
 * This function returns the pointer to the singleton instance of the MotorDriverControlManager.
 * 
 * @return Pointer to the singleton instance of MotorDriverControlManager.
 */
dtMotorDriverControlManager* MotorDriverControlManager_GetInstance(void)
{
    return &instance;
}
