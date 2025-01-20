/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "PWMConfiguration_private.h"

FUNC(void, PWMConfiguration_ruUpdate)(void)
{
    /* Get Singelton Instance*/
    dtPWMConfiguration* pwmc = PWMConfiguration_GetInstance();

    /* Read and set Initial PwmStep - direction and brake status */
    pwmc->setStepA( pwmc->IPwmStep->readPwmStepA() );
    pwmc->setStepB( pwmc->IPwmStep->readPwmStepB() );
    pwmc->setStepC( pwmc->IPwmStep->readPwmStepC() );
    /* Read and set initial direction and brake status */
    pwmc->setBrakeStatus( pwmc->IBrakeStatus->readBrake() );

    /* Check Brake status */
    if( BRAKE_STATUS_ENABLE != pwmc->getBrakeStatus() )
    {
        /* Send PWM Steps to gate driver */
        if( PWMSTEP_PWMSTATUS_LOW == pwmc->getStepA() )
        {
            pwmc->IGPIOStatus->writePinState( GPIOSTATUS_PIN_RESET , HALLA_OUTPUT_PORT , HALLA_OUTPUT_PIN);
        }
        else if( PWMSTEP_PWMSTATUS_HIGH == pwmc->getStepA() )
        {
            pwmc->IGPIOStatus->writePinState( GPIOSTATUS_PIN_SET , HALLA_OUTPUT_PORT , HALLA_OUTPUT_PIN);
        }
        else
        {
            /* Defensive Coding */
        }
    
        if( PWMSTEP_PWMSTATUS_LOW == pwmc->getStepB() )
        {
            pwmc->IGPIOStatus->writePinState( GPIOSTATUS_PIN_RESET , HALLB_OUTPUT_PORT , HALLB_OUTPUT_PIN);
        }
        else if( PWMSTEP_PWMSTATUS_HIGH == pwmc->getStepB() )
        {
            pwmc->IGPIOStatus->writePinState( GPIOSTATUS_PIN_SET , HALLB_OUTPUT_PORT , HALLB_OUTPUT_PIN);
        }
        else
        {
            /* Defensive Coding */
        }
    
        if( PWMSTEP_PWMSTATUS_LOW == pwmc->getStepC() )
        {
            pwmc->IGPIOStatus->writePinState( GPIOSTATUS_PIN_RESET , HALLC_OUTPUT_PORT , HALLC_OUTPUT_PIN);
        }
        else if( PWMSTEP_PWMSTATUS_HIGH == pwmc->getStepC() )
        {
            pwmc->IGPIOStatus->writePinState( GPIOSTATUS_PIN_SET , HALLC_OUTPUT_PORT , HALLC_OUTPUT_PIN);
        }   
        else
        {
            /* Defensive Coding */
        }
    }
    else
    {
        /* Brake status reset output */
        pwmc->IGPIOStatus->writePinState( GPIOSTATUS_PIN_SET , HALLA_OUTPUT_PORT , HALLA_OUTPUT_PIN);
        pwmc->IGPIOStatus->writePinState( GPIOSTATUS_PIN_SET , HALLB_OUTPUT_PORT , HALLB_OUTPUT_PIN);
        pwmc->IGPIOStatus->writePinState( GPIOSTATUS_PIN_SET , HALLC_OUTPUT_PORT , HALLC_OUTPUT_PIN);
    }

}
