/**
 * @file BrakeAndDirectionManager_private.h
 * @brief Private header file for the Brake and Direction Manager.
 * 
 * This file contains private function prototypes and definitions for the 
 * Brake and Direction Manager. It includes internal functions and 
 * runables that are not exposed to external modules.
 * 
 * This header is intended for use within the implementation of the 
 * Brake and Direction Manager only.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#ifndef BRAKEANDDIRECTIONMANAGER_INC_BRAKEANDDIRECTIONMANAGER_PRIVATE_H_
#define BRAKEANDDIRECTIONMANAGER_INC_BRAKEANDDIRECTIONMANAGER_PRIVATE_H_

#include "BrakeAndDirectionManager_definition.h"

/* Public Include */
#include "SpeedControlManager_public.h"

/**
 * @brief Constructor for the Brake and Direction Manager.
 * 
 * Initializes the Brake and Direction Manager by setting up function pointers,
 * interfaces, and initial values for attributes.
 * 
 * This function must be called before using the manager instance.
 */
void BrakeAndDirectionManager_CTOR(void);

/**
 * @brief Gets the instance of the Brake and Direction Manager.
 * 
 * Provides access to the singleton instance of the Brake and Direction Manager.
 * 
 * @return Pointer to the `dtBrakeAndDirectionManager` instance.
 */
dtBrakeAndDirectionManager* BrakeAndDirectionManager_GetInstance(void);

/* Runables */

/**
 * @brief Runnable for the initialization process.
 * 
 * This function is responsible for initializing the Brake and Direction Manager
 * during the system startup phase.
 */
FUNC(void, BrakeAndDirectionManager_ruInitialistaion)(void);

/**
 * @brief Runnable for the update process.
 * 
 * This function updates the Brake and Direction Manager by processing any changes
 * or events in the brake and direction status. It is typically called periodically.
 */
FUNC(void, BrakeAndDirectionManager_ruRefresh)(void);

#endif /* BRAKEANDDIRECTIONMANAGER_INC_BRAKEANDDIRECTIONMANAGER_PRIVATE_H_ */
