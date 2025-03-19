#include "MotorDriverCommProxy_private.h"

/** 
 * @file MotorDriverCommProxy.c
 * @brief This file contains the private implementation for the MotorDriverCommProxy.
 * 
 * It includes functions that set and get various attributes for motor driver communication, such as
 * brake and direction status, speed status, wheel speed, and indicator values. This implementation manages
 * a singleton instance of the MotorDriverCommProxy and provides low-level control functionalities.
 * 
 * The primary functionalities in this file are:
 * - Managing brake and direction status (IBdr).
 * - Managing speed status (ISpeed).
 * - Managing Hall wheel speed.
 * - Managing indicator values.
 * - Managing wheel speed.
 * - String representation of the current state of the motor driver communication proxy.
 * 
 * This file is intended for internal use and serves as a communication interface for controlling the motor driver.
 */
static dtMotorDriverCommProxy instance; /**< Singleton instance for MotorDriverCommProxy */

/** 
 * @brief Setter function for the brake and direction status (IBdr).
 * 
 * This function sets the brake and direction status of the MotorDriverCommProxy instance.
 * 
 * @param status The brake and direction status to be set.
 */
static void MotorDriverCommProxy_setIBdr_Impl(dtMotorDriverCommProxy_indicatorBdrStatus status)
{
    instance.iBdr = status;
}

/** 
 * @brief Getter function for the brake and direction status (IBdr).
 * 
 * This function retrieves the brake and direction status from the MotorDriverCommProxy instance.
 * 
 * @return The current brake and direction status.
 */
static dtMotorDriverCommProxy_indicatorBdrStatus MotorDriverCommProxy_getIBdr_Impl(void)
{
    return instance.iBdr;
}

/** 
 * @brief Setter function for the speed status (ISpeed).
 * 
 * This function sets the speed status of the MotorDriverCommProxy instance.
 * 
 * @param status The speed status to be set.
 */
static void MotorDriverCommProxy_setISpeed_Impl(dtMotorDriverCommProxy_indicatorSpeedStatus status)
{
    instance.iSpeed = status;
}

/** 
 * @brief Getter function for the speed status (ISpeed).
 * 
 * This function retrieves the speed status from the MotorDriverCommProxy instance.
 * 
 * @return The current speed status.
 */
static dtMotorDriverCommProxy_indicatorSpeedStatus MotorDriverCommProxy_getISpeed_Impl(void)
{
    return instance.iSpeed;
}

/** 
 * @brief Setter function for the Hall Wheel Speed.
 * 
 * This function sets the Hall wheel speed of the MotorDriverCommProxy instance.
 * 
 * @param speed The Hall wheel speed to be set.
 */
static void MotorDriverCommProxy_setHWheelSpeed_Impl(dtMotorDriverCommProxy_HALLWheelSpeed speed)
{
    instance.hWheelSpeed = speed;
}

/** 
 * @brief Getter function for the Hall Wheel Speed.
 * 
 * This function retrieves the Hall wheel speed from the MotorDriverCommProxy instance.
 * 
 * @return The current Hall wheel speed.
 */
static dtMotorDriverCommProxy_HALLWheelSpeed MotorDriverCommProxy_getHWheelSpeed_Impl(void)
{
    return instance.hWheelSpeed;
}

/** 
 * @brief Setter function for the indicator value.
 * 
 * This function sets the indicator value of the MotorDriverCommProxy instance.
 * 
 * @param indicator The indicator value to be set.
 */
static void MotorDriverCommProxy_setIndicator_Impl(dtMotorDriverCommProxy_indicator indicator)
{
    instance.indicator = indicator;
}

/** 
 * @brief Getter function for the indicator value.
 * 
 * This function retrieves the indicator value from the MotorDriverCommProxy instance.
 * 
 * @return The current indicator value.
 */
static dtMotorDriverCommProxy_indicator MotorDriverCommProxy_getIndicator_Impl(void)
{
    return instance.indicator;
}

/** 
 * @brief Setter function for the wheel speed.
 * 
 * This function sets the wheel speed of the MotorDriverCommProxy instance.
 * 
 * @param speed The wheel speed to be set.
 */
static void MotorDriverCommProxy_setWheelSpeed_Impl(dtMotorDriverCommProxy_wheelSpeed speed)
{
    instance.wheelSpeed = speed;
}

/** 
 * @brief Getter function for the wheel speed.
 * 
 * This function retrieves the wheel speed from the MotorDriverCommProxy instance.
 * 
 * @return The current wheel speed.
 */
static dtMotorDriverCommProxy_wheelSpeed MotorDriverCommProxy_getWheelSpeed_Impl(void)
{
    return instance.wheelSpeed;
}

/** 
 * @brief Converts the MotorDriverCommProxy instance to a string representation.
 * 
 * This function creates a string that represents the current state of the MotorDriverCommProxy instance,
 * including the brake, direction, speed, and wheel speed statuses.
 * 
 * @return A string containing the current state of the instance.
 */
static char* MotorDriverCommProxy_toString_Impl(void)
{
    char* output = (char*)malloc(512); // Yeterli bir buffer boyutu
    if (output == NULL)
    {
        return strdup("Memory allocation failed.");
    }

    snprintf(output, 512,
             "[MotorDriverCommProxy Registers]:\n"
             "IBdr Brake: %d\n"
             "IBdr Direction: %d\n"
             "ISpeed: %d\n"
             "HWheelSpeed: %d\n"
             "Indicator: %d\n"
             "WheelSpeed: %d\n",
             instance.iBdr.brakeStatus,
             instance.iBdr.directionStatus,
             instance.iSpeed,
             instance.hWheelSpeed,
             instance.indicator,
             instance.wheelSpeed);

    return output;
}

/** 
 * @brief Constructor for the MotorDriverCommProxy instance.
 * 
 * This function initializes the MotorDriverCommProxy instance, including setting up interface pointers,
 * function pointers, and default values for the attributes.
 */
void MotorDriverCommProxy_CTOR(void)
{
    /* Initialize the Interface Pointers */
    instance.IIndicatorBdrStatus = &IndicatorBdrStatusInterface;
    instance.IIndicatorSpeedStatus = &IndicatorSpeedStatusInterface;
    instance.IHALLWheelSpeed = &HALLWheelSpeedInterface;
    instance.IIndicator = &IndicatorInterface;
    instance.IWheelSpeed = &WheelSpeedInterface;

    /* Initialize Function Pointers */
    instance.getIBdr = MotorDriverCommProxy_getIBdr_Impl;
    instance.setIBdr = MotorDriverCommProxy_setIBdr_Impl;

    instance.getISpeed = MotorDriverCommProxy_getISpeed_Impl;
    instance.setISpeed = MotorDriverCommProxy_setISpeed_Impl;

    instance.getHWheelSpeed = MotorDriverCommProxy_getHWheelSpeed_Impl;
    instance.setHWheelSpeed = MotorDriverCommProxy_setHWheelSpeed_Impl;

    instance.getIndicator = MotorDriverCommProxy_getIndicator_Impl;
    instance.setIndicator = MotorDriverCommProxy_setIndicator_Impl;

    instance.getWheelSpeed = MotorDriverCommProxy_getWheelSpeed_Impl;
    instance.setWheelSpeed = MotorDriverCommProxy_setWheelSpeed_Impl;

    instance.toString = MotorDriverCommProxy_toString_Impl;

    /* Initialize Attributes to Default Values */
    instance.iBdr.byte = 0;
    instance.iSpeed = 0;
    instance.hWheelSpeed = 0;
    instance.indicator = 0;
    instance.wheelSpeed = 0;
}

/** 
 * @brief Retrieves the singleton instance of MotorDriverCommProxy.
 * 
 * This function returns the singleton instance of MotorDriverCommProxy.
 * 
 * @return The singleton instance of MotorDriverCommProxy.
 */
dtMotorDriverCommProxy* MotorDriverCommProxy_GetInstance(void)
{
    return &instance;
}

/** 
 * @brief Placeholder for future functional behavior implementations.
 * 
 * This section can be used to implement additional functional methods as needed for the MotorDriverCommProxy.
 */
