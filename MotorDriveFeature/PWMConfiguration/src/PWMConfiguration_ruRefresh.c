/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "PWMConfiguration_private.h"

FUNC(void, PWMConfiguration_ruRefresh)(void)
{
    /* Get Singelton Instance*/
    dtPWMConfiguration* pwmc = PWMConfiguration_GetInstance();

    /* Read Brake And Direction Status */
    pwmc->setBrakeStatus( pwmc->IBrakeStatus->readBrake() );
    pwmc->setDirectionStatus( pwmc->IDirectionStatus->readDirection() );

    /* Current Speed (0-1000 scaled to duty cycle) */
    uint16_t currentSpeed = pwmc->getSpeedStatus();

    /* Handle Brake Logic */
    if ( pwmc->getBrakeStatus() == BRAKE_STATUS_ENABLE)
    {
        /* Gradually reduce speed for controlled stop */
        if (currentSpeed > 0)
        {
            uint16_t newSpeed = currentSpeed > 10 ? currentSpeed - 10 : 0; // Decrease speed step by step
            pwmc->setSpeedStatus(newSpeed);

            /* Update PWM duty cycle based on new speed */
            pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_RESET, BRAKE_OUTPUT_PORT, BRAKE_OUTPUT_PIN);
            pwmc->setDutyCycle(newSpeed / 10); // Assuming 0-100% duty cycle maps to 0-1000 speed
        }
        else
        {
            /* Set Brake Pin Low for Full Brake */
            pwmc->IGPIOStatus->writePinState(GPIOSTATUS_PIN_RESET, BRAKE_OUTPUT_PORT, BRAKE_OUTPUT_PIN);
        }
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