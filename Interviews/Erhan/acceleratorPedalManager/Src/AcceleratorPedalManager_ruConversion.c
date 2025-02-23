
/**
 * @file AcceleratorPedalManager_ruConversion.c
 * @brief Contains the conversion logic for ADC to voltage in the Accelerator Pedal Manager module.
 *
 * This file includes the implementation of the `AcceleratorPedalManager_ruConversion` function, 
 * which is responsible for converting ADC readings to corresponding voltage values. 
 * The function utilizes a pointer to a conversion function (`adcToVoltagePtr`) to perform 
 * the conversion for two specific ADC values: `1` and `4095`. These values are used 
 * to calculate the primary and complementary voltage values respectively.
 *
 * The results of these conversions are stored in the `dataVoltagePrimary` and 
 * `dataVoltageComplementary` variables of the `AcceleratorPedalManager` structure, 
 * which are then used by other components of the system for further processing or control.
 * @author erhan can
 * @date 20.02.2025
 */
#include "AcceleratorPedalManager_private.h"




/**
 * @brief Converts ADC values to corresponding voltage values.
 *
 * This function is responsible for converting ADC readings into their corresponding 
 * voltage values using a conversion function provided by the `adcToVoltagePtr` pointer. 
 * The function processes two specific ADC values:
 * - A fixed ADC value of `1`, which represents a low voltage input.
 * - A fixed ADC value of `4095`, which represents the maximum ADC value corresponding to the 
 *   highest measurable voltage.
 * 
 * The calculated voltage values are then stored in `dataVoltagePrimary` and `dataVoltageComplementary` 
 * respectively, which are used by the system for further processing or control.
 */
void AcceleratorPedalManager_ruConversion(void)
{
    AcceleratorPedalManager.dataVoltagePrimary          = AcceleratorPedalManager.adcToVoltagePtr(1);
    AcceleratorPedalManager.dataVoltageComplementary    = AcceleratorPedalManager.adcToVoltagePtr(4095);
    serial_message("gelen veriler voltaj değerine dönüşüm yapıldı");
}