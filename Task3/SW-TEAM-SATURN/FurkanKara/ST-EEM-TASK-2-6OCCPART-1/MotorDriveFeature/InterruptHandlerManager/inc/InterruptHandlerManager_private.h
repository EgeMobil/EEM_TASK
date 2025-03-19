/**
 * @file InterruptHandlerManager_private.h
 * @brief Private header file for the Interrupt Handler Manager.
 * 
 * This file contains the private declarations and prototypes for the 
 * Interrupt Handler Manager. It is intended for internal use within the 
 * module and should not be accessed directly by external modules.
 * 
 * Key functionalities include:
 * - Singleton instance management.
 * - Internal configuration of external and timer interrupts.
 * - Definitions for runable functions specific to the module's internal behavior.
 * 
 * This file supports the implementation of the Interrupt Handler Manager 
 * and complements the public interface defined in 
 * `InterruptHandlerManager_public.h`.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#ifndef INTERRUPTHANDLERMANAGER_INC_INTERRUPTHANDLERMANAGER_PRIVATE_H_
#define INTERRUPTHANDLERMANAGER_INC_INTERRUPTHANDLERMANAGER_PRIVATE_H_

#include "InterruptHandlerManager_definition.h"

#define HALL_A_PORT ((dtInterruptHandlerManager_portName)EXTIRQ_PORTNAME_GPIOB)
#define HALL_A_PIN  ((dtInterruptHandlerManager_pinName)EXTIRQ_PINNAME_6)

#define HALL_B_PORT ((dtInterruptHandlerManager_portName)EXTIRQ_PORTNAME_GPIOB)
#define HALL_B_PIN  ((dtInterruptHandlerManager_pinName)EXTIRQ_PINNAME_7)

#define HALL_C_PORT ((dtInterruptHandlerManager_portName)EXTIRQ_PORTNAME_GPIOA)
#define HALL_C_PIN  ((dtInterruptHandlerManager_pinName)EXTIRQ_PINNAME_5)

/**
 * @brief Constructor for the Interrupt Handler Manager.
 * 
 * Initializes the Interrupt Handler Manager by setting up function pointers,
 * interfaces, and initial values for attributes. This function must be called
 * before using the manager instance.
 */
void InterruptHandlerManager_CTOR(void);

/**
 * @brief Gets the instance of the Interrupt Handler Manager.
 * 
 * Provides access to the singleton instance of the Interrupt Handler Manager.
 * 
 * @return Pointer to the `dtInterruptHandlerManager` instance.
 */
dtInterruptHandlerManager* InterruptHandlerManager_GetInstance(void);

/* Runables */

/**
 * @brief Runnable for handling external trigger events.
 * 
 * This function processes external interrupt events and executes the
 * necessary actions associated with the external IRQ configuration.
 */
FUNC(void, InterruptHandlerManager_ruExternalTrigger)(void);

/**
 * @brief Runnable for handling timer trigger events.
 * 
 * This function processes timer interrupt events and executes the
 * necessary actions associated with the timer IRQ configuration.
 */
FUNC(void, InterruptHandlerManager_ruTimerTrigger)(void);

FUNC(void, InterruptHandlerMAnager_ruInitialisation)(void);


#endif /* INTERRUPTHANDLERMANAGER_INC_INTERRUPTHANDLERMANAGER_PRIVATE_H_ */
