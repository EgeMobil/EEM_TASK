/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "PWMConfiguration_private.h"

FUNC(void, PWMConfiguration_ruInitialisation)(void)
{
    /* Get Singelton Instance*/
    dtPWMConfiguration* pwmc = PWMConfiguration_GetInstance();
    
    /* Read and set initial PwmStep */
    pwmc->setStepA( pwmc->IPwmStep->readPwmStepA() );
    pwmc->setStepB( pwmc->IPwmStep->readPwmStepB() );
    pwmc->setStepC( pwmc->IPwmStep->readPwmStepC() );
    /* Read and set initial direction and brake status */
    pwmc->setBrakeStatus( pwmc->IBrakeStatus->readBrake() );
    pwmc->setDirectionStatus( pwmc->IDirectionStatus->readDirection() );
    
    /* Read and set initial speed status 'has to 0' */
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
