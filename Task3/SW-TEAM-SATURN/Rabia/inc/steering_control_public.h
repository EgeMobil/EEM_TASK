#ifndef STEERING_CONTROL_PUBLIC_H
#define STEERING_CONTROL_PUBLIC_H

#include <stdbool.h>

typedef struct SteeringControlManager SteeringControlManager;

SteeringControlManager *Steering_create();

bool Steering_setAngle(SteeringControlManager *manager, double angle);

double Steering_getAngle(const SteeringControlManager *manager);

void Steering_calibrate(SteeringControlManager *manager);

void Steering_destroy(SteeringControlManager *manager);

#endif