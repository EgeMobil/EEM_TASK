/**
 * @file SpeedControlManager_public.h
 * @brief Public header file for the Speed Control Manager.
 * 
 * This file contains the public function declarations for the Speed Control Manager.
 * It includes necessary function prototypes for controlling speed, initialization, 
 * update, and refresh operations. These functions are accessible by other modules 
 * interacting with the Speed Control Manager.
 * 
 * @author batu.murt
 * @date 23.01.2025
 */

#ifndef SPEEDCONTROLMANAGER_INC_SPEEDCONTROLMANAGER_PUBLIC_H_
#define SPEEDCONTROLMANAGER_INCI_SPEEDCONTROLMANAGER_PUBLIC_H_

#include "SpeedControlManager_defination.h" 

/**
 * @brief Constructor for the Speed Control Manager.
 * 
 * Initializes the necessary structures and sets up the environment for 
 * the Speed Control Manager. This function must be called before any other 
 * Speed Control Manager operations.
 */
extern void SpeedControlManager_CTOR(void);

/**
 * @brief Get the singleton instance of the Speed Control Manager.
 * 
 * Returns a pointer to the instance of the Speed Control Manager. If the instance 
 * is not yet created, it will be initialized.
 * 
 * @return dtSpeedControlManager* Pointer to the Speed Control Manager instance.
 */
extern dtSpeedControlManager* SpeedControlManager_GetInstance(void);


extern FUNC(void, SpeedControlManager_ruBrakeUpdate)(void);

/**
 * @brief Refreshes the Speed Control Manager data.
 * 
 * This function is used to update the speed and other relevant parameters 
 * based on the current system state. It should be called periodically.
 */
extern FUNC(void, SpeedControlManager_ruRefresh)(void);

/**
 * @brief Updates the target speed in the Speed Control Manager.
 * 
 * This function updates the target speed value in the Speed Control Manager,
 * ensuring that the system is aware of the latest speed target to be achieved.
 */
extern FUNC(void, SpeedControlManager_ruUpdate)(void);

/**
 * @brief Initializes the Speed Control Manager with the required settings.
 * 
 * This function sets up the configuration for the Speed Control Manager, 
 * initializing all the necessary parameters and ensuring the manager is ready 
 * for operation.
 */
extern FUNC(void, SpeedControlManager_ruInitialisation)(void);

#endif /* SPEEDCONTROLMANAGER_INC_SPEEDCONTROLMANAGER_PUBLIC_H_ */
