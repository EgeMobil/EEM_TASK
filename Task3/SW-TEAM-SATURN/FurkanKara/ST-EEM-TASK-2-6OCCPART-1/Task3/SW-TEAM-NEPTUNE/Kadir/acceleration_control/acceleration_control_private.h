#ifndef ACCELERATION_CONTROL_PRIVATE_H
#define ACCELERATION_CONTROL_PRIVATE_H

#include <stdbool.h>



static float calculateAcceleration(float throttle, float power);
static float calculateFuelConsumption(float power, float throttle);
static void calculateEnginePower();
static void setPower(float power);

#endif // ACCELERATION_CONTROL_PRIVATE_H
