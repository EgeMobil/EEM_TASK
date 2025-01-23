/**
 * @file SpeedControlManager_ruUpdate.c
 * @brief Implementation of the SpeedControlManager update runable.
 *
 * This function updates the target speed of the SpeedControlManager based on 
 * the raw speed value obtained from the `IRawSpeed` interface. It normalizes 
 * the raw speed value to a target speed percentage based on a maximum raw 
 * value of 4095. The target speed is then updated in the SpeedControlManager 
 * configuration.
 * 
 * @author batu.murt
 * @date 23.01.2025
 */

#include "SpeedControlManager_private.h"

/**
 * @brief SpeedControlManager update runable.
 *
 * This function performs the following tasks:
 * - Retrieves the raw speed value using the `IRawSpeed` interface.
 * - Normalizes the raw speed value to a target speed (in percentage).
 * - Updates the `targetSpeed` in the SpeedControlManager configuration 
 *   based on the normalized value.
 */
FUNC(void, SpeedControlManager_ruUpdate)(void)
{
    // Get SpeedControlManager instance
    dtSpeedControlManager* scm = SpeedControlManager_GetInstance();

    // Retrieve the raw speed value and normalize it
    uint16_t rawSpeed = scm->IRawSpeed->readRawSpeed();
    uint16_t maxRawValue = 4095; // Maximum raw speed value (12-bit range)

    // Normalize the raw speed value to a target speed (in percentage)
    scm->config.targetSpeed = (rawSpeed * 1000) / maxRawValue;
}
