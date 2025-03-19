#ifndef STEERING_CONTROL_PRIVATE_H
#define STEERING_CONTROL_PRIVATE_H

struct SteeringControlData
{
    double rawSensorValue;
    double calibrationOffset;
    double currentAngle;
};

#endif