/**
 * @file ECUStateManager_public.h
 * @brief Public header file for the ECU State Manager.
 * 
 * This file contains public variable definitions and function declarations 
 * for the ECU State Manager. It provides the necessary interfaces for 
 * external modules to interact with the ECU State Manager.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#ifndef ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PUBLIC_H_
#define ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PUBLIC_H_

#include "ECUStateManager_definition.h"

/**
 * @brief Public variable for system startup state.
 */
extern dtECUStateManager_startUp systemStartUp;

/**
 * @brief Public variable for refresh state.
 */
extern dtECUStateManager_refreshState REFRESH_STATE;

/**
 * @brief Public variable for process state.
 */
extern dtECUStateManager_processState PROCESS_STATE;

/**
 * @brief Main function to manage ECU states.
 */
extern void ECUStateManager(void);

#endif /* ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PUBLIC_H_ */
