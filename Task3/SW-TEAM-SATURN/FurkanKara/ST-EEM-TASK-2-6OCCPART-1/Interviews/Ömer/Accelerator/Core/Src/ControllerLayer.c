/*
 * ControllerLayer.c
 *
 *  Created on: Feb 20, 2025
 *      Author: omrvr
 */

#include "ControllerLayer.h"
#include "adc.h"

// Gaz pedalından veri okuma ve doğrulama
uint16_t read_gas_pedal() {
    uint16_t adc_value = HAL_ADC_GetValue(&hadc1);  // ADC'den değer okuma
    if (adc_value < 2000) {
        return 0;  // Hatalı veri durumunda 0 döndür
    }
    return adc_value;
}
