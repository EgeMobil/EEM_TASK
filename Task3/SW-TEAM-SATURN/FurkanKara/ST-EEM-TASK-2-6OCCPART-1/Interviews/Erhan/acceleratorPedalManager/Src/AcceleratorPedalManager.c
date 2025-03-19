/**
 * @file AcceleratorPedalManager.c
 * @brief Contains the implementation of the Accelerator Pedal Manager system, including various 
 *        functions and structure declarations related to the accelerator pedal control logic.
 *
 * This file provides the core functionality for managing the accelerator pedal system. It includes
 * functions for voltage conversion, motor driver control, and gear validation. Additionally, the file
 * contains the state machine logic for the Accelerator Pedal Manager, managing various states such as
 * voltage checking, conversion, and update cycles.
 * The file also contains the necessary `struct` declarations that store relevant data, such as 
 * voltage values, gear information, and pointers to functions that handle specific tasks in the 
 * system.
 * @author erhan can
 * @date 20.02.2025
 */ 

#include "AcceleratorPedalManager_private.h"


/**
 * @brief The Accelerator Pedal Manager instance, containing data and function pointers for system operations.
 *
 * This global instance of the `st_AcceleratorPedalManager` struct holds the data related to the accelerator
 * pedal system, including voltage values, gear data, and function pointers to handle various tasks such as
 * voltage conversion, gear control, and motor driver data management.
 * 
 * - `dataVoltagePrimary`: Stores the primary voltage value from the accelerator pedal sensor.
 * - `dataVoltageComplementary`: Stores the complementary voltage value from the accelerator pedal sensor.
 * - `gearData`: Holds information about the gear position.
 * - `adcToVoltagePtr`: A function pointer used to convert ADC values to voltage.
 * - `checkSumVoltagePtr`: A function pointer used to check the validity of the voltage values.
 * - `gearControlPtr`: A function pointer used to control and check the gear position.
 * - `setApmMotorDriverDataPtr`: A function pointer used to send data to the motor driver.
*/ 
st_AcceleratorPedalManager  AcceleratorPedalManager ={ .dataVoltagePrimary = 1,
                                                        .dataVoltageComplementary =4,
                                                        .gearData = 1,

                                                        .adcToVoltagePtr            = adcToValue,
                                                        .checkSumVoltagePtr         = checkSumVoltage,
                                                        .gearControlPtr             = gearControl,
                                                        .setApmMotorDriverDataPtr   = SetApmMotorDriverData,
                                                        .setApmDashboardDataPtr     = SetApmDashboardData,
};


/**
 * @brief Converts an ADC value to its corresponding voltage value.
 * 
 * The formula used for the conversion is:
 * - VoltageAdc = (adc_value * REFERANCE_VOLTAGE) / ADC_MAX_VALUE
 * - VolatgeIn = VoltageAdc * ((RESISTOR1 + RESISTOR2) / RESISTOR2)
 *
 * @param adc_value The ADC value to be converted to voltage.
 * 
 * @return float The corresponding input voltage based on the ADC value.
 */
float adcToValue(uint16_t adc_value)
{
    
    float VoltageAdc = (adc_value * REFERANCE_VOLTAGE) / ADC_MAX_VALUE;
    float VolatgeIn = VoltageAdc * ((RESISTOR1 + RESISTOR2) / RESISTOR2);
    return VolatgeIn;
}


/**
 * @brief Checks the validity of two voltage values by verifying if their sum falls within a specified range.
 * 
 * This function calculates the sum of two input voltage values, `dataVoltagePrimary` and `dataVoltageComplementary`,
 * and checks if the sum is within the valid range of 4.7V to 5.2V. If the sum falls within this range, the function
 * returns `APM_EOK` indicating that the voltages are valid. Otherwise, it returns `APM_ERR` indicating an error in the 
 * voltage values.
 *
 * @param dataVoltagePrimary The primary voltage value.
 * @param dataVoltageComplementary The complementary voltage value.
 * 
 * @return dtApmReturn Returns `APM_EOK` if the voltage sum is valid, or `APM_ERR` if the sum is out of range.
 */
dtApmReturn checkSumVoltage(float dataVoltagePrimary,float dataVoltageComplementary)
{
    if ( VOLTAGESUM(dataVoltagePrimary,dataVoltageComplementary) >= 4.7 && VOLTAGESUM(dataVoltagePrimary,dataVoltageComplementary) <= 5.2 )
    {
         serial_message("volaj değeri uygun\n");
         return APM_EOK;
    }else
    {
        serial_message("voltaj değeri hatalı\n");
         return APM_ERR;
    }
    
}


/**
 * @brief Checks the validity of the gear position.
 * 
 *
 * @return uint8_t The validity of the gear data. Returns `GEAR_DATA_VALID` (1) if the gear position is valid,
 *                 and `GEAR_DATA_INVALID` (0) if the gear position is invalid.
 */
uint8_t gearControl(void)
{
    if(AcceleratorPedalManager.gearData == GEAR_DATA_VALID) 
    {
        return GEAR_DATA_VALID;
    }else
    {
        return GEAR_DATA_INVALID;
    }

}


/**
 * @brief Converts the primary voltage value to a motor control value.
 * 
 * Gives a value between 0 and 100 to the motor based on the dataVoltagePrimary value
 * 
 * @return float The calculated motor control value based on the primary voltage.
 */
float VolageToMotorValue(void)
{
    return ( 25 * AcceleratorPedalManager.dataVoltagePrimary) - 12.5 ;
}

/**
 * @brief Converts the primary voltage to a dashboard value.
 * 
 * Gives a value between 0 and 100 to the dashboard based on the dataVoltagePrimary value
 * 
 * @return float The calculated dashboard value based on the primary voltage.
 */
float VolageToDashboardValue(void)
{
    return ( 25 * AcceleratorPedalManager.dataVoltagePrimary) - 12.5 ;
}


/**
 * @brief Sets the motor driver data to the given value.
 *
 * @param setMotorDriverData The value to be set as the motor driver data.
 */
void SetApmMotorDriverData(uint8_t setMotorDriverData)
{
    AcceleratorPedalManager.MotorDriverData = setMotorDriverData;
}


/**
 * @brief Gets the motor driver data.
 * 
 * @return uint8_t The current motor driver data.
 */
uint8_t GetApmMotorDriverData(void)
{
    return AcceleratorPedalManager.MotorDriverData;
}

/**
 * @brief Sets the dashboard data to the specified value.
 * 
 * 
 * @param setDashboardData The value to be set for the dashboard data.
 */
void SetApmDashboardData(uint8_t setDashboardData)
{
    AcceleratorPedalManager.DashboardData = setDashboardData;
}

/**
 * @brief Retrieves the current dashboard data.
 * 
 * 
 * @return uint8_t The current dashboard data value.
 */
uint8_t GetApmDashboardData(void)
{
    return AcceleratorPedalManager.DashboardData;
}







