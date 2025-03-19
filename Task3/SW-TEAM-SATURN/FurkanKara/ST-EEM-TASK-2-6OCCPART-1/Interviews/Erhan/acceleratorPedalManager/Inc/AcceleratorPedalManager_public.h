/**
 * @file AcceleratorPedalManager_punlic.h
 * @brief Private header file for the Accelerator Pedal Manager.
 * 
 * This file contains the private function declarations and internal 
 * definitions for the Accelerator Pedal manager. 
 * 
 * @author erhan can
 * @date 20.02.2025
 */

#ifndef ACCELERATOR_PEDAL_MANAGER_PRIVATE_H_
#define ACCELERATOR_PEDAL_MANAGER_PRIVATE_H_

#include "AcceleratorPedalManager_defination.h"

/**
 * @brief Main function for executing the accelerator pedal manager process.
 *
 * This function is the main entry point for the accelerator pedal manager process.
 * It contains the state machine that handles the logic for monitoring and controlling 
 * the accelerator pedal system. The state machine ensures the proper flow of operations 
 * based on the system's current state and transitions.
 */
void AcceleratorPedalManager_ruProsses(void);

/**
 * @brief Initializes the state machine for the accelerator pedal manager.
 *
 * This function initializes the state machine that controls the accelerator pedal system. 
 * It sets up the initial state, prepares the necessary hardware or peripherals, and 
 * ensures that the system is ready for operation. It serves as the main entry point 
 * for setting up the system's state machine.
 */
void AcceleratorPedalManager_ruInitialisation(void);

/**
 * @brief Performs specific conversions and calculations for the accelerator pedal system.
 *
 * This function handles the necessary transformations and calculations related to 
 * the accelerator pedal system. 
 */
void AcceleratorPedalManager_ruConversion(void);

/**
 * @brief Performs necessary updates and sends data to other components.
 *
 * This function executes the required updates for the accelerator pedal system, 
 * ensuring that the latest information is processed and communicated to other 
 * components. 
 */
void AcceleratorPedalManager_ruUpdate(void);

/**
 * @brief Checks and verifies the correctness of the data.
 *
 * This function validates the incoming data, performing checks to ensure that 
 * the values are within acceptable ranges and meet system requirements.
 */
void AcceleratorPedalManager_ruCheck(void);

/**
 * @brief Gets the data to be sent to the dashboard.
 * 
 * This function retrieves the current value stored for the dashboard display.
 * 
 * @return uint8_t The current dashboard data value.
 */
uint8_t GetApmDashboardData(void);

/**
 * @brief Retrieves the data to be sent to the motor driver.
 *
 * This function returns the current data that will be sent to the motor driver.
 * The returned data could represent a command or control information for the motor driver.
 *
 * @return uint8_t The data that will be sent to the motor driver.
 */
uint8_t GetApmMotorDriverData(void);




#endif /* ACCELERATOR_PEDAL_MANAGER_PRIVATE_H_*/