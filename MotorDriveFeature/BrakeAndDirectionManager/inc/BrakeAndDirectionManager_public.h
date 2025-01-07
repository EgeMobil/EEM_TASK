/**
 * @file BrakeAndDirectionManager_public.h
 * @brief Public header file for the Brake and Direction Manager.
 * 
 * This file provides the public interface for the Brake and Direction Manager. 
 * It declares external functions, including the constructor, instance retrieval, 
 * and runables for initialization and updates. These functions are intended to 
 * be used by other modules interacting with the Brake and Direction Manager.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#ifndef BRAKEANDDIRECTIONMANAGER_INC_BRAKEANDDIRECTIONMANAGER_PUBLIC_H_
#define BRAKEANDDIRECTIONMANAGER_INC_BRAKEANDDIRECTIONMANAGER_PUBLIC_H_

/* Include the public definition header */
#include "BrakeAndDirectionManager_definition.h"

/**
 * @brief Constructor for the Brake and Direction Manager.
 * 
 * This function initializes the Brake and Direction Manager and sets up 
 * its default configurations.
 */
extern void BrakeAndDirectionManager_CTOR(void);

/**
 * @brief Retrieves the singleton instance of the Brake and Direction Manager.
 * 
 * @return Pointer to the `dtBrakeAndDirectionManager` instance.
 */
extern dtBrakeAndDirectionManager* BrakeAndDirectionManager_GetInstance(void);

/* Runables */

/**
 * @brief Initialization runable for the Brake and Direction Manager.
 * 
 * This function sets up the initial brake and direction configurations and 
 * updates the associated interfaces.
 */
extern FUNC(void, BrakeAndDirectionManager_ruInitialistaion)(void);

/**
 * @brief Update runable for the Brake and Direction Manager.
 * 
 * This function handles the periodic update of brake and direction statuses 
 * by reading inputs, validating changes, and updating configurations.
 */
extern FUNC(void, BrakeAndDirectionManager_ruUpdate)(void);

#endif /* BRAKEANDDIRECTIONMANAGER_INC_BRAKEANDDIRECTIONMANAGER_PUBLIC_H_ */
