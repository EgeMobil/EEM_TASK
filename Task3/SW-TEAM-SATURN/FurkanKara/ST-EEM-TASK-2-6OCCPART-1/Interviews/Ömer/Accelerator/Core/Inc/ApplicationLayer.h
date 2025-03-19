/*
 * ApplicationLayer.h
 *
 *  Created on: Feb 20, 2025
 *      Author: omrvr
 */

#ifndef INC_APPLICATIONLAYER_H_
#define INC_APPLICATIONLAYER_H_

#include "stm32f4xx_hal.h"

#define MAX_SPEED 1000

// Gaz pedalından alınan verinin işlendiği kısım
uint16_t process_gas_pedal_data(uint16_t adc_value);

// Pwm ile motor hızını ayarla
void set_motor_speed(uint16_t speed);


#endif /* INC_APPLICATIONLAYER_H_ */
