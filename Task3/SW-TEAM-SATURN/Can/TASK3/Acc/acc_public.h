#ifndef ACC_PUBLIC_H
#define ACC_PUBLIC_H


#include <stdint.h>

#define SPEED           uint32_t
#define DISTANCE        uint32_t


//Global functions
/*
* @brief Adaptive cruise control enable end disable functions
* @note This functions can be used by another modules
*/
void ACC_enable(void);
void ACC_disable(void);

/*
* @brief Adaptive cruise control speed control function
* @note This functions can be used by another modules
*/
void ACC_setSpeed(SPEED Vehicle_Speed);

/*
* @brief To get current adaptive cruise control speed value
* @note This functions can be used by another modules
*/
SPEED Speed_Get_ACC(void);


#endif // ACC_PUBLIC_H







