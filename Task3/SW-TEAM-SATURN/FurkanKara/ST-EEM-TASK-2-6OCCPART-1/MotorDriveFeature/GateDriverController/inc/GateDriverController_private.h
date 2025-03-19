/**
 * @file GateDriverController_private.h
 * @brief Private header file for the Gate Driver Controller.
 * 
 * This file contains private definitions, constructor prototypes, singleton 
 * getter, and runnables for the Gate Driver Controller. It should be included 
 * only within the implementation file to hide the internal details of the 
 * Gate Driver Controller.
 * 
 * @author [Your Name]
 * @date [Date]
 */

#ifndef GATEDRIVERCONTROLLER_PRIVATE_H_
#define GATEDRIVERCONTROLLER_PRIVATE_H_

/* Gate Driver definition include */
#include "GateDriverController_definition.h"

/**
 * @brief Constructor for the Gate Driver Controller.
 * 
 * This function initializes the Gate Driver Controller instance, setting 
 * up necessary configurations and internal attributes.
 */
void GateDriverController_CTOR(void);

/**
 * @brief Singleton getter for the Gate Driver Controller instance.
 * 
 * This function returns a pointer to the singleton instance of the Gate Driver 
 * Controller. If the instance does not exist, it will create and return it.
 * 
 * @return Pointer to the Gate Driver Controller instance.
 */
dtGateDriverController* GateDriverController_GetInstance(void);

/* Runables */

/**
 * @brief Initialization runnable for the Gate Driver Controller.
 * 
 * This function performs the initialization tasks required by the Gate Driver 
 * Controller, such as setting up the driver and configuring initial parameters.
 */
FUNC(void, GateDriverController_ruInitialisation)(void);

/**
 * @brief Refresh runnable for the Gate Driver Controller.
 * 
 * This function refreshes or updates the internal states or configurations 
 * of the Gate Driver Controller during runtime.
 */
FUNC(void, GateDriverController_ruRefresh)(void);

#endif /* GATEDRIVERCONTROLLER_PRIVATE_H_ */
