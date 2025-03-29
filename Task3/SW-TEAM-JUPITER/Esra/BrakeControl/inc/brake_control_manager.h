#ifndef BRAKE_CONTROL_MANAGER_H
#define BRAKE_CONTROL_MANAGER_H

#include "brake_control_public.h"
#include <stdbool.h>

/* Function declarations */
bool init_brake_hardware(void);
bool init_wheel_sensors(void);
void system_delay(unsigned int ms);

#endif