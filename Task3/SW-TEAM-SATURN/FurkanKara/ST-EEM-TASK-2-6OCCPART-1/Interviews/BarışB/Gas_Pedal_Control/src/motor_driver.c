#include "motor_driver.h"
#include "../include/pwm_driver.h"

// Motor hızını ayarlama
void motor_driver_set_speed(float speed) {
    pwm_set_duty_cycle(speed);
}