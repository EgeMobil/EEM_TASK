#ifndef ABS_ALGORITHM_H
#define ABS_ALGORITHM_H 

#include <stdbool.h>

#define ABS_THRESHOLD 0.2f
#define CRITICAL_SLIP_THRESHOLD 0.3f 
#define MAX_BRAKE_REDUCTION 0.8f 

extern bool abs_active;

float calculate_wheel_slip(void);

void abs_intervention(void); 

void adjust_brake_force_for_abs(float slip); 

float get_vehicle_speed(void); 
float get_wheel_speed(void); 
float get_brake_force(void); 
void set_brake_force(float force); 




#endif 