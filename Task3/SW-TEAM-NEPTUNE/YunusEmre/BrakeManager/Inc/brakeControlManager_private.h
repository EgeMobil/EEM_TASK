#ifndef PRIVATE_H
#define PRIVATE_H

#include "brakeControlManager_definition.h"

/* Constructor Prototype */
/**
 * @brief Initializes the brakeControlManager object.
 * This function is used to set up the instance and initialize required attributes.
 */
void brakeControlManager_CTOR(void);

/* Singleton base class getter prototype */
/**
 * @brief Retrieves the singleton instance of the brakeControlManager.
 * @return Pointer to the singleton instance of the brakeControlManager.
 */
BrakeControlManager_t* brakeControlManager_GetInstance(void);

/* Runables */
/**
 * @brief Initializes the brakeControlManager system.
 * This function is used to perform initial setup or preparation tasks.
 */
void brakeControlManager_ruInitialisation(void);
/**
 * @brief Refreshes the brakeControlManager system.
 * This function is used to update or refresh the system's state.
 */
void brakeControlManager_ruRefresh(void);


#endif // PRIVATE_H

