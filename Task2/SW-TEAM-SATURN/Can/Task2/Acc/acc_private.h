#ifndef ACC_PRIVATE_H
#define ACC_PRIVATE_H



#include "acc_public.h"

#define INLINE            static inline

typedef enum {
    ACC_OFF = 0,                             
    ACC_ACTIVE,
    ACC_SLOWING_DOWN
}ACC_State_t;

typedef struct 
{
    /* data */
    SPEED       current_Speed;      // current speed of adative cruise control
    SPEED       desired_Speed;      // desired speed of adaptive cruise control 
    DISTANCE    distance_To_Car;    // distance beetween two cars
    ACC_State_t state;
}ACC_Data_t;
ACC_Data_t Data_ACC;







#endif //ACC_PRIVATE_H