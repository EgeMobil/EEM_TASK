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
 * @brief Indicator speed status refresh.
 *
 * This function displays the current speed, target speed, and the speed step 
 * on the console for the SpeedControlManager. It is primarily used for 
 * debugging and displaying speed control changes.
 *
 * @param currentSpeed Current speed of the system.
 * @param targetSpeed Target speed to be reached.
 * @param speedStep The dynamic step used for adjusting speed.
 */
void IIndicatorSpeedStatus_ruRefresh(uint16_t currentSpeed, uint16_t targetSpeed, uint16_t speedStep)
{
    printf("[IIndicatorSpeedStatus] Current speed: %u, Target speed: %u, Step: %u\n",
           currentSpeed, targetSpeed, speedStep);
}

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
        scm->config.currentSpeed -= speedStep;
        if (scm->config.currentSpeed < scm->config.targetSpeed)
        {
            scm->config.currentSpeed = scm->config.targetSpeed; // Prevent undershooting target speed
        }
    }

    // Call the indicator update function
    IIndicatorSpeedStatus_ruRefresh(scm->config.currentSpeed, scm->config.targetSpeed, speedStep);
}

