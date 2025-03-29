#include <stdlib.h>
#include "steering_control_public.h"
#include "steering_control_private.h"
#include "definition.h"

// Static (private) function prototypes
static void Steering_setAngle(void *self, int16_t angle);
static int16_t Steering_getAngle(void *self);
static void Steering_calibrate(void *self, int16_t offset);

// --------------------------
// PUBLIC CONSTRUCTOR
// --------------------------
SteeringControl Steering_create(void) {
    SteeringControl sc;
    
    // Allocate private data
    sc.data = (SteeringData*)malloc(sizeof(SteeringData));
    if (sc.data == NULL) {
        // erroe handling
    }
    
    // Initializing private fields
    sc.data->currentAngle = 0;
    sc.data->calibrationOffset = 0;
    sc.data->rawValue = 0;

    
    // Assigning function pointers
    sc.setAngle   = Steering_setAngle;
    sc.getAngle   = Steering_getAngle;
    sc.calibrate  = Steering_calibrate;
    
    return sc;
}

// --------------------------
// PRIVATE FUNCTION DEFINITIONS
// --------------------------
static void Steering_setAngle(void *self, int16_t angle) {
    SteeringControl *sc = (SteeringControl*)self;
    SteeringData *priv = sc->data;
    
    // Applying calibration offset 
    int16_t adjustedAngle = angle + priv->calibrationOffset;
    
    // making sure the steering angle is in valid range
    if (adjustedAngle < STEERING_ANGLE_MIN) {
        adjustedAngle = STEERING_ANGLE_MIN;
    } else if (adjustedAngle > STEERING_ANGLE_MAX) {
        adjustedAngle = STEERING_ANGLE_MAX;
    }
    
    priv->currentAngle = adjustedAngle;
    // steering control implementation
}

static int16_t Steering_getAngle(void *self) {
    SteeringControl *sc = (SteeringControl*)self;
    SteeringData *priv = sc->data;
    
    // Return the current angle
    return priv->currentAngle;
}

static void Steering_calibrate(void *self, int16_t offset) {
    SteeringControl *sc = (SteeringControl*)self;
    SteeringData *priv = sc->data;
    
    // Update calibration offset
    priv->calibrationOffset = offset;
    
}

