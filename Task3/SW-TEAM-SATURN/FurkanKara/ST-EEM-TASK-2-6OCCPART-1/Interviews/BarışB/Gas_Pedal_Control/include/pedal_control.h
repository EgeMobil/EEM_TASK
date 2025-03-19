#ifndef PEDAL_CONTROL_H
#define PEDAL_CONTROL_H

#include <stdbool.h>

// Sensör verilerini okuma
void read_pedal_sensors(float *sensor1, float *sensor2);

// Sensör verilerini doğrulama
bool validate_pedal_data(float sensor1, float sensor2);

// Pedal konumunu hesaplama
float calculate_pedal_position(float sensor_value);

// Pedal girişini işleyerek motor hızını belirleme
void process_pedal_input(float sensor1, float sensor2);

// Motor hızını belirleme
void set_motor_speed(float pedal_position);

#endif // PEDAL_CONTROL_H