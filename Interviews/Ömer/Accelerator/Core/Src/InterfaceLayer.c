/*
 * InterfaceLayer.c
 *
 *  Created on: Feb 20, 2025
 *      Author: omrvr
 */


#include "InterfaceLayer.h"
#include "ApplicationLayer.h"

// Motor sürücüsüne PWM sinyali gönderme
void motor_driver_interface(uint16_t speed) {
    set_motor_speed(speed);  // Motor hızını ayarlamak için uygulama katmanındaki fonksiyonu çağır
}
