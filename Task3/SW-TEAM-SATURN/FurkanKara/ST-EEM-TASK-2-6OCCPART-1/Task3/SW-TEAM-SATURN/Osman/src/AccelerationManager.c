#include <stdio.h>
#include <stdint.h>
#include "AccelerationManager_Definition.h"
#include "AccelerationManager_Private.h"
#include "AccelerationManager_Public.h"

/* Instance definition */
static AccelerationManager_t instance;

/* Getter Setter Implementation */
void set_throttle(float throttle)
{
    instance.throttle = throttle;
}

float get_throttle(void)
{
    return instance.throttle;
}


void throttle_to_power(void)
{
    instance.power = (MAX_POWER * instance.throttle / 100.0f) * FUEL_EFFICIENCY * HP_TO_KW;
    printf("Throttle level to Power conversion has been done!\n");
}

void set_speed(float speed)
{
    instance.speed = speed;
}

float get_speed(void)
{
    return instance.speed;
}

void power_to_acceleration(void)
{
    instance.acceleration = ((instance.power * 1E3) / (instance.speed * 0.278f)) / VEHICLE_WEIGHT; // unit m/s^2
    printf("Power to Acc conversion has been done!\n");
}


float get_acceleration(void)
{
    return instance.acceleration;
}



void set_acceleration(float acceleration)
{
    instance.acceleration = acceleration;
}


/* toString() Implementation */
void toString(void)
{
    printf("Throttle: %f\n", instance.throttle);
    printf("Power: %f kW\n", instance.power);
    printf("Acceleration: %f m/s^2\n", instance.acceleration);
}


/* Constructor Implementation */
void AccelerationManager_Ctor(void)
{
    instance.throttle               = 0.0f;
    instance.power                  = 0.0f;
    instance.acceleration           = 0.0f;
    instance.getThrottle            = get_throttle;
    instance.setThrottle            = set_throttle;
    instance.throttleToPower        = throttle_to_power;
    instance.setSpeed               = set_speed;
    instance.getSpeed               = get_speed;
    instance.set_acceleration       = set_acceleration;
    instance.get_acceleration       = get_acceleration;
    instance.powerToAcceleration    = power_to_acceleration;
    instance.toString               = toString;

}


/* Singelton Instance Getter */
AccelerationManager_t* AccelerationManager_GetInstance(void)
{
    return &instance;
}
