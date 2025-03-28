#ifndef BRAKE_CONTROL_PUBLIC_H 
#define BRAKE_CONTROL_PUBLIC_H 

typedef enum {
    BRAKE_OK,
    BRAKE_ERROR,
    BRAKE_ABS_ACTIVE,   // ABS intervention active
    BRAKE_INVALID_PARAM // Invalid parameter provided
}BrakeStatus; 

BrakeStatus Brake_Apply(void); 
BrakeStatus Brake_Release(void); 
BrakeStatus Brake_SetPressure(float pressure); 

#endif 