#ifndef BRAKE_CONTROL_PRIVATE_H 
#define BRAKE_CONTROL_PRIVATE_H 

#include <stdbool.h> 
#include "definition.h" 

/* External variables */
extern bool abs_active;

/* System interface functions */
void system_delay(unsigned int ms);
bool is_brake_system_ready(void);

/* Brake control functions */
void monitor_wheel_speeds(void);
float get_brake_pressure(void);
float get_wheel_speed_by_index(int wheel_index);
void update_brake_pressure(int pressure);  // Removed static
float calculate_brake_force(float pressure);  // Removed static

/* Hardware interface functions */
void set_hardware_brake_pressure(int pressure);
float read_wheel_speed_sensor(int sensor_index);

/* ABS control functions */
bool check_abs_status(void);
void abs_intervention(void);
float calculate_wheel_slip(void);
void adjust_brake_force_for_abs(float slip);

#endif /* BRAKE_CONTROL_PRIVATE_H */