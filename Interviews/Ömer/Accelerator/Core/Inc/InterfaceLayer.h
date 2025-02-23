/*
 * InterfaceLayer.h
 *
 *  Created on: Feb 20, 2025
 *      Author: omrvr
 */

#ifndef INC_INTERFACELAYER_H_
#define INC_INTERFACELAYER_H_


#include "stm32f4xx_hal.h"

// Motor sürücüsüne PWM sinyali gönderme
void motor_driver_interface(uint16_t speed);

#endif /* INC_INTERFACELAYER_H_ */
