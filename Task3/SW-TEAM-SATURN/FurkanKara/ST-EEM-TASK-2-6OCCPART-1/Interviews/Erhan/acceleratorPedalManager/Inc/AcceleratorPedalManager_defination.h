/**
 * @file AcceleratorPedalManager_definition.h
 * @brief Definition header file for the Accelerator Pedal Manager.
 * 
 * This file contains the definitions, enum, data types, 
 *  and structure declarations for the accelerator pedal manager. 
 *
 * @author erhan can
 * @date 20.02.2025
 */


#ifndef ACCELERATOR_PEDAL_MANAGER_DEFINITION_H_
#define ACCELERATOR_PEDAL_MANAGER_DEFINITION_H_

/* Include headers file*/
#include "main.h"
#include <stdint.h>

#define VOLTAGESUM(dataVoltagePrimary,dataVoltageComplementary)   ( (dataVoltagePrimary) + (dataVoltageComplementary) )
#define RESISTOR1           4700.0
#define RESISTOR2           10000.0
#define ADC_MAX_VALUE       4096.0
#define REFERANCE_VOLTAGE   3.3
#define GEAR_DATA_VALID     1
#define GEAR_DATA_INVALID   0

/* Return value enum */
/**
 * @enum dtApmReturn
 * @brief Return values for Accelerator Pedal manager function.
 * 
 * APM_ERR: Error state
 * APM_EOK: Successful operation
 * 
 */
typedef enum
{
    APM_ERR = 0, /** Error state */
    APM_EOK,     /** Successful operation */
}dtApmReturn;

// /**
//  * @typedef dtSpeedControlManager_scmReturn
//  * @brief Return type for Speed Control Manager functions.
//  */
// typedef dtApmReturn dtAcceleratorPedalManager_apmReturn;


/**
 * @enum dtAPMru_prosses
 * @brief Represents the different states of the system state machine.
 * 
 * APMru_Check: 
 * APMru_Conversion: 
 * APMru_Update: 
 */
typedef enum
{
    APMru_Check = 1,
    APMru_Conversion,
    APMru_Update,
}dtAPMru_prosses;

/**
 * @brief Current state of the system state machine.
 *
 * This extern variable holds the current state of the system, which is defined
 * by the `dtAPMru_prosses` enumeration. It is used to track the system's behavior
 * and control state transitions.
 *
 * @note This variable must be defined in a source file before use.
 */
extern dtAPMru_prosses APMru_prosses;


/**
 * @struct st_AcceleratorPedalManager
 * @brief Data structure for the accelerator pedal manager.
 *  
 * This structure holds the necessary data and function pointers
 * required for managing the accelerator pedal system.
 * It includes voltage readings, gear position data, and function
 * pointers for processing these values.
 * @see st_AcceleratorPedalManager
 */
typedef struct 
{
    float dataVoltagePrimary;    /**< primary voltage */
    float dataVoltageComplementary;  /**< voltage complementary */

    uint8_t gearData;    /**< appropriateness of gear position */
    uint8_t MotorDriverData;  /**< the value to be sent to the motor driver */
    uint8_t DashboardData;
    
    float (*adcToVoltagePtr)(uint16_t); /**< pointer to function that converts adc to voltage value */

    dtApmReturn (*checkSumVoltagePtr)(float, float);   /**< pointer to function that tests the correctness of two incoming voltages */

    uint8_t (*gearControlPtr)(void); /**< pointer to function that tests gear accuracy */

    void (*setApmMotorDriverDataPtr)(uint8_t); /**< sets the data to be sent to the motor driver */

    void (*setApmDashboardDataPtr)(uint8_t);

}st_AcceleratorPedalManager;

/**
 * @brief Global instance of the accelerator pedal manager.
 *
 * This extern variable is an instance of `st_AcceleratorPedalManager` 
 * and is used to store and manage accelerator pedal-related data, 
 * including voltage readings, gear position, and function pointers 
 * for processing these values.
 *
 * @note This variable must be defined in a source file before use.
 * @see st_AcceleratorPedalManager
 */
extern st_AcceleratorPedalManager  AcceleratorPedalManager;


#endif /* ACCELERATOR_PEDAL_MANAGER_DEFINITION_H_*/