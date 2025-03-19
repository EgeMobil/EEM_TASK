// acceleration_control_public.h
#ifndef ACCELERATION_CONTROL_PUBLIC_H
#define ACCELERATION_CONTROL_PUBLIC_H

// Acceleration Control Structure
typedef struct {
    float throttle;
    float gasPedalSignal;
    float enginePower;
} AccelerationControlManager;

AccelerationControlManager* GetInstance();
void Acceleration_setThrottle(float value);
float Acceleration_getThrottle();
void Acceleration_limitPower();
void printState();

#endif // ACCELERATION_CONTROL_PUBLIC_H
