/**
 * @file PWMConfiguration.c
 * @brief Implementation file for the PWM Configuration.
 * 
 * This file contains the implementation of the PWM Configuration module, 
 * including methods for setting frequency, duty cycle, and handling PWM states.
 * 
 * Key functionalities include:
 * - Setting and getting frequency and duty cycle.
 * - Managing speed, direction, and brake status.
 * - Providing a string representation of the current configuration.
 * 
 * The file follows the singleton design pattern to ensure only one instance 
 * exists at runtime.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#include "PWMConfiguration_private.h"

/**
 * @brief PWM Configuration instance.
 * 
 * A static instance of the `dtPWMConfiguration` structure that holds the 
 * current state and configuration of the PWM system.
 */
static dtPWMConfiguration instance;

/**
 * @brief Starts the PWM timer.
 */
void PWMConfiguration_startTimer_Impl(void);

/**
 * @brief Stops the PWM timer.
 */
void PWMConfiguration_stopTimer_Impl(void);

/**
 * @brief Sets the timer frequency.
 * 
 * @param value Frequency value to set.
 */
void PWMConfiguration_setTimerFrequency_Impl(uint16_t value);

/**
 * @brief Sets the timer duty cycle.
 * 
 * @param value Duty cycle value to set.
 */
void PWMConfiguration_setTimerDutyCycle_Impl(uint16_t value);

/** @brief Sets the PWM frequency. */
void PWMConfiguration_setFrequency_Impl(uint16_t value) { instance.frequency = value; }

/** @brief Gets the PWM frequency. */
uint16_t PWMConfiguration_getFrequency_Impl(void) { return instance.frequency; }

/** @brief Sets the PWM duty cycle. */
void PWMConfiguration_setDutyCycle_Impl(uint16_t value) { instance.dutyCycle = value; }

/** @brief Gets the PWM duty cycle. */
uint16_t PWMConfiguration_getDutyCycle_Impl(void) { return instance.dutyCycle; }

/** @brief Sets the speed status. */
void PWMConfiguration_setSpeedStatus_Impl(dtPWMConfiguration_speedStatus value) { instance.speed = value; }

/** @brief Gets the speed status. */
dtPWMConfiguration_speedStatus PWMConfiguration_getSpeedStatus_Impl(void) { return instance.speed; }

/** @brief Sets the direction status. */
void PWMConfiguration_setDirectionStatus_Impl(dtPWMConfiguration_directionStatusType value) { instance.direction = value; }

/** @brief Gets the direction status. */
dtPWMConfiguration_directionStatusType PWMConfiguration_getDirectionStatus_Impl(void) { return instance.direction; }

/** @brief Sets the brake status. */
void PWMConfiguration_setBrakeStatus_Impl(dtPWMConfiguration_brakeStatusType value) { instance.brake = value; }

/** @brief Gets the brake status. */
dtPWMConfiguration_brakeStatusType PWMConfiguration_getBrakeStatus_Impl(void) { return instance.brake; }

/** @brief Sets the Step A configuration. */
void PWMConfiguration_setStepA_Impl(dtPWMConfiguration_pwmStep value) {
    instance.stepA = value;
}

/** @brief Gets the Step A configuration. */
dtPWMConfiguration_pwmStep PWMConfiguration_getStepA_Impl(void) {
    return instance.stepA;
}

/** @brief Sets the Step B configuration. */
void PWMConfiguration_setStepB_Impl(dtPWMConfiguration_pwmStep value) {
    instance.stepB = value;
}

/** @brief Gets the Step B configuration. */
dtPWMConfiguration_pwmStep PWMConfiguration_getStepB_Impl(void) {
    return instance.stepB;
}

/** @brief Sets the Step C configuration. */
void PWMConfiguration_setStepC_Impl(dtPWMConfiguration_pwmStep value) {
    instance.stepC = value;
}

/** @brief Gets the Step C configuration. */
dtPWMConfiguration_pwmStep PWMConfiguration_getStepC_Impl(void) {
    return instance.stepC;
}

/** @brief Converts the PWM configuration to a string representation. */
const char* PWMConfiguration_toString_Impl(void)
{
    static char buffer[512];
    snprintf(buffer, sizeof(buffer),
             "[PWMConfiguration]: Frequency: %-5u Hz, DutyCycle: %-3u%%, Speed: %-5d, Direction: %-5d, Brake: %-5d, "
             "StepA :%-5u StepB :%-5u StepC :%-5u ",
             instance.frequency, instance.dutyCycle, instance.speed, instance.direction, instance.brake,
             instance.stepA, instance.stepB, instance.stepC);
    return buffer;
}

/**
 * @brief Constructor for PWM Configuration.
 * 
 * Initializes the function pointers and assigns initial values for configuration.
 */
void PWMConfiguration_CTOR(void)
{
    instance.IBrakeStatus = &BrakeStatusInterface;
    instance.IDirectionStatus = &DirectionStatusInterface;
    instance.IGPIOStatus = &GPIOStatusInterface;
    instance.IPwmStep = &PwmStepInterface;
    instance.ISpeedStatus = &SpeedStatusInterface;

    instance.setFrequency = PWMConfiguration_setFrequency_Impl;
    instance.getFrequency = PWMConfiguration_getFrequency_Impl;
    instance.setDutyCycle = PWMConfiguration_setDutyCycle_Impl;
    instance.getDutyCycle = PWMConfiguration_getDutyCycle_Impl;
    instance.setSpeedStatus = PWMConfiguration_setSpeedStatus_Impl;
    instance.getSpeedStatus = PWMConfiguration_getSpeedStatus_Impl;
    instance.setDirectionStatus = PWMConfiguration_setDirectionStatus_Impl;
    instance.getDirectionStatus = PWMConfiguration_getDirectionStatus_Impl;
    instance.setBrakeStatus = PWMConfiguration_setBrakeStatus_Impl;
    instance.getBrakeStatus = PWMConfiguration_getBrakeStatus_Impl;
    instance.toString = PWMConfiguration_toString_Impl;

    instance.setStepA = PWMConfiguration_setStepA_Impl;
    instance.getStepA = PWMConfiguration_getStepA_Impl;
	instance.setStepB = PWMConfiguration_setStepB_Impl;
	instance.getStepB = PWMConfiguration_getStepB_Impl;
	instance.setStepC = PWMConfiguration_setStepC_Impl;
	instance.getStepC = PWMConfiguration_getStepC_Impl;

    instance.startTimer = PWMConfiguration_startTimer_Impl;
    instance.stopTimer = PWMConfiguration_stopTimer_Impl;
    instance.setTimerFrequency = PWMConfiguration_setTimerFrequency_Impl;
    instance.setTimerDutyCycle = PWMConfiguration_setTimerDutyCycle_Impl;
}

/**
 * @brief Retrieves the singleton instance of PWM Configuration.
 * 
 * @return Pointer to the static `dtPWMConfiguration` instance.
 */
dtPWMConfiguration* PWMConfiguration_GetInstance(void) { return &instance; }

/** @brief Starts the PWM timer. */
void PWMConfiguration_startTimer_Impl(void) { 
#ifndef STM32G431xx
    printf("Timer started.\n");
#else
    (void)instance.IPwmStep->startTimer();
#endif
}

/** @brief Stops the PWM timer. */
void PWMConfiguration_stopTimer_Impl(void) { 
#ifndef STM32G431xx
    printf("Timer stopped.\n");
#else
    (void)instance.IPwmStep->stopTimer();
#endif
}

/** @brief Sets the timer frequency. */
void PWMConfiguration_setTimerFrequency_Impl(uint16_t value) {
    instance.frequency = value;
#ifndef STM32G431xx
    printf("Frequency set to %u.\n", value);
#else
    (void)instance.IPwmStep->setFrequency(value);
#endif
}

/** @brief Sets the timer duty cycle. */
void PWMConfiguration_setTimerDutyCycle_Impl(uint16_t value) {
    instance.dutyCycle = value;
#ifndef STM32G431xx
    printf("Duty cycle set to %u.\n", value);
#else
    (void)instance.IPwmStep->setDutyCycle(value);
#endif
}
