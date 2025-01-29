/**
 * @file SpeedControlManager_private.h
 * @brief Private header file for the Speed Control Manager.
 * 
 * This file contains the private function declarations and internal 
 * definitions for the Speed Control Manager. It provides functions 
 * for initialization, instance retrieval, and speed control operations.
 * 
 * @author batu.murt
 * @date 23.01.2025
 */

#ifndef SPEEDCONTROLMANAGER_INC_SPEEDCONTROLMANAGER_PRIVATE_H_
#define SPEEDCONTROLMANAGER_INC_SPEEDCONTROLMANAGER_PRIVATE_H_

#include "SpeedControlManager_defination.h"

/**
 * @brief Constructor for the Speed Control Manager.
 * 
 * This function initializes the Speed Control Manager and prepares it 
 * for use by setting necessary configurations and state.
 */
void SpeedControlManager_CTOR(void);

FUNC(void, SpeedControlManager_ruBrakeUpdate)(void);

/**
 * @brief Retrieves the instance of the Speed Control Manager.
 * 
 * This function provides access to the singleton instance of the 
 * Speed Control Manager. If the instance has not been created, it 
 * will initialize it.
 * 
 * @return Pointer to the Speed Control Manager instance.
 */
dtSpeedControlManager* SpeedControlManager_GetInstance(void);

/**
 * @brief Refreshes the speed control manager's status.
 * 
 * This function is called to update or refresh the current speed 
 * and other control parameters.
 */
FUNC(void, SpeedControlManager_ruRefresh)(void);

/**
 * @brief Updates the speed control manager's configuration.
 * 
 * This function updates the internal configuration of the speed 
 * control manager, adjusting settings like target speed and other 
 * parameters.
 */
FUNC(void, SpeedControlManager_ruUpdate)(void);

/**
 * @brief Initializes the speed control manager.
 * 
 * This function performs the necessary steps to initialize the 
 * Speed Control Manager, setting up the internal configurations 
 * and system interfaces.
 */
FUNC(void, SpeedControlManager_ruInitialisation)(void);

#endif /* SPEEDCONTROLMANAGER_INC_SPEEDCONTROLMANAGER_PRIVATE_H_ */
