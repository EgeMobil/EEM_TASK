/**
 * @file GateDriverController_public.h
 * @brief Public header file for the Gate Driver Controller.
 * 
 * This file contains the public interface for the Gate Driver Controller. It includes 
 * the constructor, singleton getter, and runnables which are available for external 
 * access. The public interface allows interaction with the Gate Driver Controller 
 * functionality in a controlled manner.
 * 
 * @author [Your Name]
 * @date [Date]
 */

#ifndef GATEDRIVERCONTROLLER_PUBLIC_H_
#define GATEDRIVERCONTROLLER_PUBLIC_H_

/* Include the public definition header */
#include "GateDriverController_definition.h"

#ifdef SIL_INTEGRATION
#include "ECUStateManager_global.h"
#endif

/**
 * @brief External constructor for the Gate Driver Controller.
 * 
 * This function initializes the Gate Driver Controller instance, setting up the 
 * necessary configurations and attributes. It should be called before interacting 
 * with the Gate Driver Controller.
 */
extern void GateDriverController_CTOR(void);

/**
 * @brief External singleton getter for the Gate Driver Controller instance.
 * 
 * This function returns a pointer to the singleton instance of the Gate Driver 
 * Controller. It ensures that only one instance of the Gate Driver Controller 
 * exists and can be used throughout the application.
 * 
 * @return Pointer to the Gate Driver Controller instance.
 */
extern dtGateDriverController* GateDriverController_GetInstance(void);

/* Runable Prototypes */

/**
 * @brief External initialization runnable for the Gate Driver Controller.
 * 
 * This function is used to perform initialization tasks for the Gate Driver 
 * Controller, such as configuring driver parameters and setting up the system.
 */
extern FUNC(void, GateDriverController_ruInitialisation)(void);

/**
 * @brief External refresh runnable for the Gate Driver Controller.
 * 
 * This function is used to refresh or update the internal state of the 
 * Gate Driver Controller. It can be called periodically to ensure the controller 
 * operates correctly during runtime.
 */
extern FUNC(void, GateDriverController_ruRefresh)(void);

#endif /* GATEDRIVERCONTROLLER_PUBLIC_H_ */
