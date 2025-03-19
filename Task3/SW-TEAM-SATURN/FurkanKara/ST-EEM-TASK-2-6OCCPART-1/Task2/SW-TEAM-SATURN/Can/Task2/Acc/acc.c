#include "acc_public.h"
#include "acc_private.h"
#include "../Inc/definition.h"
#include "../Sensor/sensor.h"
#include <stdio.h>

INLINE void ACC_updateSensorData(void);
INLINE ACC_State_t ACC_getState(void);
INLINE DISTANCE ACC_getDistance(void);
INLINE SPEED ACC_getSpeed(void);


void ACC_enable(void)
{
    ACC_updateSensorData();
    if (ACC_getState() == ACC_OFF)
    {
        
        
        if (Data_ACC.current_Speed < MIN_SAFE_SPEED || Data_ACC.distance_To_Car < MAX_TRACKING_DISTANCE)
        {
            printf("Current speed is below the minimum safe speed\n");
            ACC_disable();
           
        }
        else
        {
            Data_ACC.state = ACC_ACTIVE;
            printf("ACC is activated and setted to current speed: %d \n", Data_ACC.current_Speed);
        }
    }
}

void ACC_disable(void)
{
    Data_ACC.state = ACC_OFF;
    Data_ACC.current_Speed = 0;
    Data_ACC.desired_Speed = 0;
    printf("ACC is disabled!");
}

void ACC_setSpeed(SPEED desired_Speed)
{
    ACC_updateSensorData();
    int32_t speed_diffrence = Data_ACC.current_Speed - desired_Speed;
    if(speed_diffrence < 0)
    {
        speed_diffrence = -speed_diffrence;
    }

    if(desired_Speed >= MIN_SAFE_SPEED && speed_diffrence <= SPEED_DIFFERENCE_THRESHOLD)
    {
        Data_ACC.desired_Speed = desired_Speed;
        Data_ACC.state = ACC_ACTIVE;
        printf("Target speed set to %d km/h. ACC Active.\n", desired_Speed); 
    }
    else
    {
        if(desired_Speed < MIN_SAFE_SPEED)
        {
            printf("Speed up, too low!\n");
        }
        else
        {
            printf("Your speed and desired speed is not close enough! %d \n", speed_diffrence);
        }
    }
    
}

INLINE SPEED ACC_getSpeed(void)
{
    return Get_speedRawData();    
}

INLINE DISTANCE ACC_getDistance(void)
{
    return Get_distanceRawData();
}

INLINE ACC_State_t ACC_getState(void)
{
    return Data_ACC.state;
}

INLINE void ACC_updateSensorData(void)
{
    Data_ACC.current_Speed = ACC_getSpeed();
    Data_ACC.distance_To_Car = ACC_getDistance();
    printf("Current speed: %d\n", Data_ACC.current_Speed);
    printf("Current distance: %d\n", Data_ACC.distance_To_Car);
}










