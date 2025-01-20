/* Doxygen Runable Comment */

#include "HALLSensorConfiguration_private.h"

FUNC(void, HALLSensorConfiguration_ruInitialisation)(void)
{
    
    dtHALLSensorConfiguration_PwmStep pwmStepA;
    dtHALLSensorConfiguration_PwmStep pwmStepB; 
    dtHALLSensorConfiguration_PwmStep pwmStepC;

    /* Get Singleton Instance */
    dtHALLSensorConfiguration* hsc = HALLSensorConfiguration_GetInstance();

    /* Read HALL Sensor States from InterruptHandlerManager */
    // Interrupt handler Manager ruInitialisation has to read HALL A,B,C initial status from bsw.
    hsc->getHallAConfig().setStatus( hsc->IHALLA->readStatus() );
    hsc->getHallBConfig().setStatus( hsc->IHALLB->readStatus() );
    hsc->getHallCConfig().setStatus( hsc->IHALLC->readStatus() );

    /* Send Initial conditions to Pwm Step for A */
    if( HALLA_STATUS_HIGH == hsc->getHallAConfig().getStatus())
    {
        pwmStepA = PWMSTEP_PWMSTATUS_HIGH;
      
    }
    else if( HALLA_STATUS_LOW == hsc->getHallAConfig().getStatus() )
    {
        pwmStepA = PWMSTEP_PWMSTATUS_LOW;
    }
    else
    {
        /* Defensive Coding */
    }

    /* Send Initial conditions to Pwm Step for B */
    if( HALLB_STATUS_HIGH == hsc->getHallBConfig().getStatus() )
    {
        pwmStepB = PWMSTEP_PWMSTATUS_HIGH;
    }
    else if( HALLB_STATUS_LOW == hsc->getHallBConfig().getStatus() )
    {
        pwmStepB = PWMSTEP_PWMSTATUS_LOW;
    }
    else
    {
        /* Defensive Coding */
    }
    
    /* Send Initial conditions to Pwm Step for B */
    if( HALLC_STATUS_HIGH == hsc->getHallCConfig().getStatus() )
    {
        pwmStepC = PWMSTEP_PWMSTATUS_HIGH;
    }
    else if( HALLC_STATUS_LOW == hsc->getHallCConfig().getStatus() )
    {
        pwmStepC = PWMSTEP_PWMSTATUS_LOW;
    }
    else
    {
        /* Defensive Coding */
    }

    /* Write PwmStep for HALL A,B,C */
    hsc->pwmStep->writePwmStepA(pwmStepA);
    hsc->pwmStep->writePwmStepB(pwmStepB);
    hsc->pwmStep->writePwmStepC(pwmStepC);
}
