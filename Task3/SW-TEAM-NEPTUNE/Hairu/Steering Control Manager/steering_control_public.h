#ifndef STEERING_CONTROL_PUBLIC_H
#define STEERING_CONTROL_PUBLIC_H

#include <stdint.h>

// Forward-declare the private struct pointer
// I didn't include steering_control_private.h here to keep it hidden
typedef struct SteeringData SteeringData;

// Public "object" for SteeringControl
typedef struct {
    SteeringData *data;              // Points to private data
    void (*setAngle)(void *self, int16_t angle);
    int16_t (*getAngle)(void *self);
    void (*calibrate)(void *self, int16_t offset);
} SteeringControl;

// Constructor to create and initialize a SteeringControl object
SteeringControl Steering_create(void);

#endif // STEERING_CONTROL_PUBLIC_H
