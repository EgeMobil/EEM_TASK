#ifndef ACCELERATIONMANAGER_PUBLIC_H
#define ACCELERATIONMANAGER_PUBLIC_H

#include <stdint.h>

/* Include the public definition header */
#include "AccelerationManager_Definition.h"

/* Constructor external prototype for public access*/
// extern void AccelerationManager_Ctor(void);

/* Singelton Base Class Getter external prototype for public access*/
// extern AccelerationManager_t* AccelerationManager_GetInstance(void);

/* Runable Prototypes for public access */
extern void AccelerationManager_Init(void);
extern void AccelerationManager_Update(void);
extern void AccelerationManager_Control(void);


/*
* @brief Gets the current throttle level
* @return throttle level
*/
float get_throttle(void);


/*
* @brief Sets the throttle level
* @param throttle: throttle level to be set
*/
void set_throttle(float throttle);


/*
* @brief Converts throttle level to power level
*/
void throttle_to_power(void);


/*
* @brief Sets the speed
* @param speed: speed to be set
*/
void set_speed(float speed);


/*
* @brief Gets the current speed
* @return speed
*/
float get_speed(void);


/*
* @brief Gets the current acceleration
* @return acceleration 
*/
float get_acceleration(void);

/*
* @brief Sets the acceleration
* @param acceleration 
*/
void set_acceleration(float);

/*
* @brief Converts power level to acceleration
*/
void power_to_acceleration(void);


#endif // ACCELERATIONMANAGER_PUBLIC_H
