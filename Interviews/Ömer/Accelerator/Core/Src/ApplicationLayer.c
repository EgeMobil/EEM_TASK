/*
 * ApplicationLayer.c
 *
 *  Created on: Feb 20, 2025
 *      Author: omrvr
 */


#include "ApplicationLayer.h"

// Gaz pedalı verisini işleme
uint16_t process_gas_pedal_data(uint16_t adc_value) {
    return (adc_value * MAX_SPEED) / 4095;
}

// Motor hızını ayarlama (PWM ile)
void set_motor_speed(uint16_t speed) {
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, speed);  // PWM sinyali ile motor hızını ayarlama
}
