/**
 * @file InterruptHandlerManager_public.h
 * @brief Public header file for the Interrupt Handler Manager.
 * 
 * This file provides the public interface for the Interrupt Handler Manager. 
 * It declares external functions, including the constructor, instance retrieval, 
 * and runables for handling external and timer trigger events. These functions 
 * are intended to be used by other modules interacting with the Interrupt Handler Manager.
 * 
 * Key functionalities include:
 * - Managing external interrupt events.
 * - Managing timer interrupt events.
 * - Providing access to the singleton instance.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */
#ifndef INTERRUPTHANDLERMANAGER_INC_INTERRUPTHANDLERMANAGER_PUBLIC_H_
#define INTERRUPTHANDLERMANAGER_INC_INTERRUPTHANDLERMANAGER_PUBLIC_H_

/* Include the public definition header */
#include "InterruptHandlerManager_definition.h"

/**
 * @brief Constructor for the Interrupt Handler Manager.
 * 
 * This function initializes the Interrupt Handler Manager and sets up 
 * its default configurations.
 */
extern void InterruptHandlerManager_CTOR(void);

/**
 * @brief Retrieves the singleton instance of the Interrupt Handler Manager.
 * 
 * @return Pointer to the `dtInterruptHandlerManager` instance.
 */
extern dtInterruptHandlerManager* InterruptHandlerManager_GetInstance(void);

/**
 * @brief Runnable for handling external trigger events.
 * 
 * This function processes external interrupt events and executes the
 * necessary actions associated with the external IRQ configuration.
 */
extern FUNC(void, InterruptHandlerManager_ruExternalTrigger)(void);

/**
 * @brief Runnable for handling timer trigger events.
 * 
 * This function processes timer interrupt events and executes the
 * necessary actions associated with the timer IRQ configuration.
 */
extern FUNC(void, InterruptHandlerManager_ruTimerTrigger)(void); 

#endif /* INTERRUPTHANDLERMANAGER_INC_INTERRUPTHANDLERMANAGER_PUBLIC_H_ */