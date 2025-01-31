/** 
 * @file CompName_private.h
 * @brief Defines private functions, constructor, and the singleton instance for the MotorDriverControlManager.
 */

#ifndef COMPNAME_PRIVATE_H_
#define COMPNAME_PRIVATE_H_

/* CompName definition include */
#include "MotorDriverControlManager_definition.h"

/* Public Include */
#include "SpeedControlManager_public.h"

/* Constructor Prototype */
/** 
 * @brief Initializes the MotorDriverControlManager object.
 * This function is used to set up the instance and initialize required attributes.
 */
void MotorDriverControlManager_CTOR(void);

/* Singleton base class getter prototype */
/** 
 * @brief Retrieves the singleton instance of the MotorDriverControlManager.
 * @return Pointer to the singleton instance of the MotorDriverControlManager.
 */
dtMotorDriverControlManager* MotorDriverControlManager_GetInstance(void);

/* Runables */
/** 
 * @brief Initializes the MotorDriverControlManager system.
 * This function is used to perform initial setup or preparation tasks.
 */
FUNC(void, MotorDriverControlManager_ruInitialisation)(void);

/** 
 * @brief Refreshes the MotorDriverControlManager system.
 * This function is used to update or refresh the system's state.
 */
FUNC(void, MotorDriverControlManager_ruRefresh)(void);

#endif /* COMPNAME_PRIVATE_H_ */
