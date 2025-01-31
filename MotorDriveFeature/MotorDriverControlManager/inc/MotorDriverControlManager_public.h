/** 
 * @file CompName_public.h
 * @brief Defines the public interface for the MotorDriverControlManager, including access to the singleton instance and runnables.
 */

#ifndef COMPNAME_PUBLIC_H_
#define COMPNAME_PUBLIC_H_

/* Include the public definition header */
#include "MotorDriverControlManager_definition.h"

/* Constructor external prototype for public access*/
/** 
 * @brief Initializes the MotorDriverControlManager object.
 * This function is used to set up the instance and initialize required attributes.
 */
extern void MotorDriverControlManager_CTOR(void);

/* Singleton Base Class Getter external prototype for public access*/
/** 
 * @brief Retrieves the singleton instance of the MotorDriverControlManager.
 * @return Pointer to the singleton instance of the MotorDriverControlManager.
 */
extern dtMotorDriverControlManager* MotorDriverControlManager_GetInstance(void);

/* Runable Prototypes for public access */
/** 
 * @brief Initializes the MotorDriverControlManager system.
 * This function is used to perform initial setup or preparation tasks.
 */
extern FUNC(void, MotorDriverControlManager_ruInitialisation)(void);

/** 
 * @brief Refreshes the MotorDriverControlManager system.
 * This function is used to update or refresh the system's state.
 */
extern FUNC(void, MotorDriverControlManager_ruRefresh)(void);

#endif /* COMPNAME_PUBLIC_H_ */
