#ifndef ACC_PRIVATE_H
#define ACC_PRIVATE_H

#include "definition.h"

float ACC_getVehicleSpeed(void);
float ACC_getLeadVehicleDistance(void);
float ACC_calculateSafeDistance(float speed);
float ACC_calculateAcceleration(void);
void ACC_sendAccelerationCommand(float acceleration);

#endif 
