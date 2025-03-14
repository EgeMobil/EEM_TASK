#ifndef ACCELERATIONMANAGER_DEFINITION_H
#define ACCELERATIONMANAGER_DEFINITION_H

#include <stdint.h>

#define FUEL_EFFICIENCY 0.5f
#define MAX_ACC_LIMIT 3.0f // the unit is m/s^2
#define MAX_POWER 90.0f // the unit is HP
#define HP_TO_KW 0.735499f 
#define VEHICLE_WEIGHT 1200.0f // kg


/* BaseClass Definition */
typedef struct 
{
    /* Interface Pointer */

    /* Attributes */
    float throttle;
    float power;
    float speed;
    float acceleration;

    /* Getter/Setter */
    float (*getThrottle)(void);
    void (*setThrottle)(float throttle);
    void (*throttleToPower)(void);

    void (*setSpeed)(float speed);
    float (*getSpeed)(void);

    float (*get_acceleration)(void);
    void (*set_acceleration)(float acc);

    void (*powerToAcceleration)(void);
    /* toString */
    void (*toString)(void);
    /* Functional Behaviours */

}AccelerationManager_t;	


#endif // ACCELERATIONMANAGER_DEFINITION_H
