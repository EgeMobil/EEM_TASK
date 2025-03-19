/**
 * @file PWMConfiguration_ruInitialisation.c
 * @brief Implementation file for the PWM Configuration functions.
 *
 * This file contains the implementation of the PWM Configuration functions,
 * including initialization and refresh functionalities. These functions manage
 * the PWM configuration by reading brake, direction, and speed statuses and
 * updating GPIO outputs accordingly. The implementation ensures safe motor
 * operation by handling direction changes and brake logic.
 *
 * Key functionalities include:
 * - Initializing PWM configuration with default settings.
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
 * @brief Initializes the PWM configuration.
 *
 * This function retrieves the singleton instance of the PWM configuration manager,
 * initializes the PWM steps, brake, and direction statuses, and sets the default
 * frequency and duty cycle. It also ensures the motor starts with zero speed and
 * begins timer operations.
 *
 * @note This function should be called once at system startup.
 */
FUNC(void, PWMConfiguration_ruInitialisation)(void)
{
    /* Get Singleton Instance*/
    dtPWMConfiguration* pwmc = PWMConfiguration_GetInstance();
    
    /* Read and set initial PwmStep */
    pwmc->setStepA( pwmc->IPwmStep->readPwmStepA() );
    pwmc->setStepB( pwmc->IPwmStep->readPwmStepB() );
    pwmc->setStepC( pwmc->IPwmStep->readPwmStepC() );
    
    /* Read and set initial direction and brake status */
    pwmc->setBrakeStatus( pwmc->IBrakeStatus->readBrake() );
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

    pwmc->setDirectionStatus( pwmc->IDirectionStatus->readDirection() );
    if (pwmc->getDirectionStatus() == DIRECTION_STATUS_FORWARD)
    {
        pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_SET, DIRECTION_OUTPUT_PORT, DIRECTION_OUTPUT_PIN);
    }
    else
    {
        pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_RESET, DIRECTION_OUTPUT_PORT, DIRECTION_OUTPUT_PIN);
    }
    
    /* Read and set initial speed status, ensuring it starts at 0 */
    pwmc->setSpeedStatus( pwmc->ISpeedStatus->readSpeedStatus() );
    if( 0U != pwmc->getSpeedStatus() )
    {
        pwmc->setSpeedStatus( 0U );
    }
    else
    {
        /* Error report here */
    }
    
    /* Set Initial Default Frequency */
    pwmc->setTimerFrequency(15000);
    /* Set Initial Duty Cycle */
    pwmc->setTimerDutyCycle(0);
    /* Start Timer */
    pwmc->startTimer();
}

