#include "pedal_control.h"
#include "../include/adc_driver.h"
#include "../include/motor_driver.h"
#include <math.h>

#define PEDAL_TOLERANCE 0.1
#define MIN_VOLTAGE 0.5
#define MAX_VOLTAGE 4.5
#define MAX_MOTOR_SPEED 100.0

// Sensörlerden veri okuma
void read_pedal_sensors(float *sensor1, float *sensor2) {
    *sensor1 = adc_read(1);
    *sensor2 = adc_read(2);
}

// Sensör verilerini doğrulama
bool validate_pedal_data(float sensor1, float sensor2) {
    return fabs(sensor1 - sensor2) <= PEDAL_TOLERANCE;
}

// Pedal konumunu hesaplama
float calculate_pedal_position(float sensor_value) {
    return ((sensor_value - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE)) * 100.0;
}

// Pedal girişini işleme
void process_pedal_input(float sensor1, float sensor2) {
    if (!validate_pedal_data(sensor1, sensor2)) {
        return;
    }
    float pedal_position = calculate_pedal_position(sensor1);
    set_motor_speed(pedal_position);
}

// Motor hızını belirleme
void set_motor_speed(float pedal_position) {
    float motor_speed = (pedal_position / 100.0) * MAX_MOTOR_SPEED;
    motor_driver_set_speed(motor_speed);
}