/**
 * @file PWMConfiguration_ruRefresh.c
 * @brief Implementation file for the PWM Configuration refresh function.
 *
 * This file contains the implementation of the PWM Configuration refresh function,
 * responsible for reading brake, direction, and speed statuses, and updating the GPIO
 * outputs accordingly. The function ensures proper handling of motor direction changes
 * and brake logic for safe operation.
 *
 * Key functionalities include:
 * - Reading brake, direction, and speed statuses from interfaces.
 * - Handling brake logic by setting GPIO states.
 * - Ensuring safe direction changes based on speed conditions.
 *
 * @author atakan.ertekin
 * @date 07.01.2025
 */

/* Baseclass private access include */
#include "PWMConfiguration_private.h"

/**
 * @brief Refreshes the PWM configuration.
 *
 * This function retrieves the singleton instance of the PWM configuration manager,
 * reads the current brake, direction, and speed statuses, and updates the GPIO pins
 * accordingly. It ensures safe direction changes by verifying speed conditions and
 * applying brake logic.
 *
 * @note This function should be called periodically in the main control loop.
 */
FUNC(void, PWMConfiguration_ruRefresh)(void)
{
    /* Get Singleton Instance*/
    dtPWMConfiguration* pwmc = PWMConfiguration_GetInstance();

    /* Read Brake And Direction Status */
    pwmc->setBrakeStatus( pwmc->IBrakeStatus->readBrake() );
    pwmc->setDirectionStatus( pwmc->IDirectionStatus->readDirection() );

    /* Read Speed Status */
    pwmc->setSpeedStatus( pwmc->ISpeedStatus->readSpeedStatus() );

    /* Current Speed (0-1000 scaled to duty cycle) */
    uint16_t currentSpeed = pwmc->getSpeedStatus();

    /* Handle Brake Logic */
    if ( pwmc->getBrakeStatus() == BRAKE_STATUS_ENABLE)
    {
        /* Set Brake Pin Low for Full Brake */
        pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_RESET, BRAKE_OUTPUT_PORT, BRAKE_OUTPUT_PIN);
    }
    else
    {
        /* Release Brake Pin High */
        pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_SET, BRAKE_OUTPUT_PORT, BRAKE_OUTPUT_PIN);
    }

    /* Handle Direction Logic */
    static dtPWMConfiguration_directionStatusType lastDirection = DIRECTION_STATUS_FORWARD;
    
    if (pwmc->getDirectionStatus() != lastDirection)
    {
        /* Check if motor speed is zero before changing direction */
        if (currentSpeed == 0)
        {
            /* Change direction by updating GPIO state */
            if (pwmc->getDirectionStatus() == DIRECTION_STATUS_FORWARD)
            {
                pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_SET, DIRECTION_OUTPUT_PORT, DIRECTION_OUTPUT_PIN);
            }
            else
            {
                pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_RESET, DIRECTION_OUTPUT_PORT, DIRECTION_OUTPUT_PIN);
            }
    
            /* Update lastDirection to reflect the new direction */
            lastDirection = pwmc->getDirectionStatus();
        }
        else
        {
            /* Defensive Coding */
        } 
    }
    else
    {
        /* Defensive Coding */
    }
}
