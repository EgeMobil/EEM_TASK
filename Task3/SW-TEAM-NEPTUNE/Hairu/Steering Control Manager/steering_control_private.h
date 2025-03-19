#ifndef STEERING_CONTROL_PRIVATE_H
#define STEERING_CONTROL_PRIVATE_H

#include <stdint.h>

// Private data structure for steering
struct SteeringData{
    int16_t currentAngle;     // Current steering angle
    int16_t calibrationOffset; // Calibration offset for sensor data
    int16_t rawValue;
} ;

#endif 
