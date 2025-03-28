/**
 * @file SpeedControlManager_ruRefresh.c
 * @brief Implementation of the SpeedControlManager refresh runable.
 *
 * This function refreshes the speed control manager by calculating and updating 
 * the current speed based on the target speed. The speed step is dynamically 
 * adjusted depending on the difference between the current and target speeds.
 * It also calls the `IIndicatorSpeedStatus_ruRefresh` function to update the 
 * indicator with the new speed values.
 * 
 * @author batu.murt
 * @date 23.01.2025
 */

#include "SpeedControlManager_private.h"


/**
 * @brief SpeedControlManager refresh runable.
 *
 * This function performs the following tasks:
 * - Calculates the dynamic speed step based on the difference between the 
 *   current and target speed.
 * - Increases or decreases the current speed towards the target speed based 
 *   on whether the target speed is greater or lesser than the current speed.
 * - Calls the `IIndicatorSpeedStatus_ruRefresh` function to update the indicator 
 *   with the current speed, target speed, and the calculated speed step.
 */
FUNC(void, SpeedControlManager_ruRefresh)(void)
{
    /* These values are normally defined in the configuration. */
    static const uint16_t minStep = 5;  // Minimum step (e.g., 5 units).
    static const uint16_t maxStep = 50; // Maximum step (e.g., 50 units).
    static const uint16_t divider = 20; // Dynamic division factor.
    
    dtSpeedControlManager* scm = SpeedControlManager_GetInstance();  
    uint16_t speedStep;

    if( BRAKE_STATUS_ENABLE == scm->getConfig().getBrake() )
    {
        /* Set Speed status 0 for brake status */
        scm->config.currentSpeed = 0U ;
    }
    else
    {
        // Calculate the dynamic step based on the difference between target and current speed
        uint16_t speedDiff = abs((int32_t)scm->config.targetSpeed - (int32_t)scm->config.currentSpeed);
        speedStep = max(minStep, min(maxStep, speedDiff / divider));

        if (scm->config.currentSpeed < scm->config.targetSpeed)
        {
            // Speed increase
            scm->config.currentSpeed += speedStep;
            if (scm->config.currentSpeed > scm->config.targetSpeed)
            {
                scm->config.currentSpeed = scm->config.targetSpeed; // Prevent overshooting target speed
            }
        }
        else if (scm->config.currentSpeed > scm->config.targetSpeed)
        {
            // Speed decrease
        	if( scm->config.currentSpeed >= speedStep)
        	{
        		scm->config.currentSpeed -= speedStep;
        	}
        	else
        	{
        		scm->config.currentSpeed = 0;
        	}

            if (scm->config.currentSpeed < scm->config.targetSpeed)
            {
                scm->config.currentSpeed = scm->config.targetSpeed; // Prevent undershooting target speed
            }
        }
        else
        {
            /* Defensive Coding */
        }
    }
    /* Update Speed status based on current speed */
    scm->getConfig().setSpeedStatus(scm->config.currentSpeed);
    /* Send Speed Status */
    scm->ISpeedStatus->writeSpeedStatus( scm->getConfig().getSpeedStatus() );
}

