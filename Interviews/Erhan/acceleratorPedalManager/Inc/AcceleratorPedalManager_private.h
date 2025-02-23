/**
 * @file AcceleratorPedalManager_private.h
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
 * @brief Converts an ADC reading to a voltage value.
 *
 * This function takes a raw ADC reading and converts it into a corresponding 
 * voltage value based on the system's ADC reference voltage and resolution.
 *
 * @param adc_value The raw ADC value (0 - 4096)
 * @return The converted voltage value in volts.
 */
float adcToValue(uint16_t adc_value);

/**
 * @brief Verifies the correctness of two voltage values.
 *
 * This function checks the validity of the given primary and complementary 
 * voltage values to ensure they are within an acceptable range and consistent 
 * with each other. It returns an appropriate status code based on the verification result.
 *
 * @param primary_voltage The primary voltage value to be checked.
 * @param complementary_voltage The complementary voltage value for comparison.
 * @return dtApmReturn Returns `APM_EOK` if the voltages are correct, otherwise returns `APM_ERR`.
 */
dtApmReturn checkSumVoltage(float ,float );

/**
 * @brief Checks if the vehicle's gear is in the correct position.
 *
 * This function verifies whether the vehicle's gear is in the correct 
 * position, based on the system's gear detection mechanism. It returns a 
 * success status indicating whether the gear is correctly placed.
 *
 * @return uint8_t Returns 1 if the gear is in the correct position, otherwise returns 0.
 */
uint8_t gearControl(void);

/**
 * @brief Sets the data to be sent to the motor driver.
 *
 * This function takes a value and sets it as the data to be transmitted 
 * to the motor driver. The data could represent a command or control 
 * information for the motor driver.
 *
 * @param setMotorDriverData The data to be sent to the motor driver.
 */
void SetApmMotorDriverData(uint8_t setMotorDriverData);

/**
 * @brief Retrieves the data to be sent to the motor driver.
 *
 * This function returns the current data that will be sent to the motor driver.
 * The returned data could represent a command or control information for the motor driver.
 *
 * @return uint8_t The data that will be sent to the motor driver.
 */
uint8_t GetApmMotorDriverData(void);

/**
 * @brief Determines the pedal pressure corresponding to the motor's speed.
 *
 * This function calculates and returns the pedal pressure value, 
 * which is proportional to the speed at which the motor should operate. 
 * The function converts the pedal position to a value that determines the motor's operating speed.
 *
 * @return float The value representing the pedal pressure that sets the motor's speed.
 */
float VolageToMotorValue(void);

/**
 * @brief Calculates the dashboard display value based on pedal voltage.
 * 
 * 
 * @return float The calculated dashboard value.
 */
float VolageToDashboardValue(void);

/**
 * @brief Sets the data to be sent to the dashboard.
 * 
 * 
 * @param setDashboardData The value to be set for the dashboard display.
 */
void SetApmDashboardData(uint8_t setDashboardData);

/**
 * @brief Gets the data to be sent to the dashboard.
 * 
 * This function retrieves the current value stored for the dashboard display.
 * 
 * @return uint8_t The current dashboard data value.
 */
uint8_t GetApmDashboardData(void);


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


#endif /* ACCELERATOR_PEDAL_MANAGER_PRIVATE_H_*/