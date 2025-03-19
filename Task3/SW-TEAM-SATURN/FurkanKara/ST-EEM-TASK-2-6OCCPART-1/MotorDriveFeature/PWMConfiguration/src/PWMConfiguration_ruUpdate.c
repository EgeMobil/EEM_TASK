/**
 * @file PWMConfiguration_ruUpdate.c
 * @brief Implementation file for the PWM Configuration update function.
 *
 * This file contains the implementation of the PWM Configuration update function,
 * responsible for reading PWM step values, brake status, and updating the GPIO
 * outputs accordingly. The function ensures that the brake status is checked before
 * modifying PWM outputs to maintain safety.
 *
 * Key functionalities include:
 * - Reading PWM step values from the interface.
 * - Reading and handling brake status.
 * - Writing corresponding GPIO states based on PWM step values.
 *
 * @author atakan.ertekin
 * @date 07.01.2025
 */

/* Baseclass private access include */
#include "PWMConfiguration_private.h"

/**
 * @brief Periodically updates the PWM configuration.
 *
 * This function retrieves the singleton instance of the PWM configuration manager,
 * reads the current PWM step values and brake status, and updates the GPIO pins
 * accordingly. If the brake is enabled, all PWM outputs are reset to a safe state.
 *
 * @note This function should be called periodically in the main control loop.
 */
FUNC(void, PWMConfiguration_ruUpdate)(void)
{
    /* Get Singleton Instance */
    dtPWMConfiguration* pwmc = PWMConfiguration_GetInstance();

    /* Read and set Initial PWM Step values */
    pwmc->setStepA( pwmc->IPwmStep->readPwmStepA() );
    pwmc->setStepB( pwmc->IPwmStep->readPwmStepB() );
    pwmc->setStepC( pwmc->IPwmStep->readPwmStepC() );
    
    /* Read and set initial brake status */
    pwmc->setBrakeStatus( pwmc->IBrakeStatus->readBrake() );

    /* Check Brake status */
    if (BRAKE_STATUS_ENABLE != pwmc->getBrakeStatus())
    {
        /* Send PWM Steps to gate driver */
        if (PWMSTEP_PWMSTATUS_LOW == pwmc->getStepA())
        {
            pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_RESET, HALLA_OUTPUT_PORT, HALLA_OUTPUT_PIN);
        }
        else if (PWMSTEP_PWMSTATUS_HIGH == pwmc->getStepA())
        {
            pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_SET, HALLA_OUTPUT_PORT, HALLA_OUTPUT_PIN);
        }
        else
        {
            /* Defensive Coding */
        }
    
        if (PWMSTEP_PWMSTATUS_LOW == pwmc->getStepB())
        {
            pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_RESET, HALLB_OUTPUT_PORT, HALLB_OUTPUT_PIN);
        }
        else if (PWMSTEP_PWMSTATUS_HIGH == pwmc->getStepB())
        {
            pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_SET, HALLB_OUTPUT_PORT, HALLB_OUTPUT_PIN);
        }
        else
        {
            /* Defensive Coding */
        }
    
        if (PWMSTEP_PWMSTATUS_LOW == pwmc->getStepC())
        {
            pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_RESET, HALLC_OUTPUT_PORT, HALLC_OUTPUT_PIN);
        }
        else if (PWMSTEP_PWMSTATUS_HIGH == pwmc->getStepC())
        {
            pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_SET, HALLC_OUTPUT_PORT, HALLC_OUTPUT_PIN);
        }   
        else
        {
            /* Defensive Coding */
        }
    }
    else
    {
        /* Brake status reset output */
        pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_SET, HALLA_OUTPUT_PORT, HALLA_OUTPUT_PIN);
        pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_SET, HALLB_OUTPUT_PORT, HALLB_OUTPUT_PIN);
        pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_SET, HALLC_OUTPUT_PORT, HALLC_OUTPUT_PIN);
    }
}
