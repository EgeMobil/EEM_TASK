#include "AccelerationManager_Definition.h"
#include "AccelerationManager_Private.h"
#include "AccelerationManager_Public.h"

/* Functional Behaviour Implementation */
void AccelerationManager_Update(void)
{
    AccelerationManager_t* AccM = AccelerationManager_GetInstance();

    float throttle = 60.0; // percentage
    float speed = 10.0; // actual unit in km/h


    // update private features
    AccM->setThrottle(throttle);
    AccM->setSpeed(speed);
}