// acceleration_control.c
#include "acceleration_control_public.h"
#include "acceleration_control_private.h"
#include "definition.h"
#include <stdio.h>

static AccelerationControlManager instance = {0.0f, 0.0f, 0.0f};

AccelerationControlManager* GetInstance() {
    return &instance;
}

// Sets the throttle value
void Acceleration_setThrottle(float value) {
    if (value > 1.0f) value = 1.0f;
    if (value < 0.0f) value = 0.0f;
    instance.throttle = value;
    processGasPedalInput(value);
}

// Returns the current throttle value
float Acceleration_getThrottle() {
    return instance.throttle;
}

// Limits the engine power to the predefined safety threshold
void Acceleration_limitPower() {
    if (instance.enginePower > SAFETY_THRESHOLD) {
        setEnginePower(SAFETY_THRESHOLD);
    }
}

// Processes the gas pedal input and updates internal values
static void processGasPedalInput(float pedalValue) {
    instance.gasPedalSignal = pedalValue;
    calculateEnginePower();
}

// Calculates the engine power based on the gas pedal signal
static void calculateEnginePower() {
    float calculatedPower = instance.gasPedalSignal * MAX_ACCELERATION;
    setEnginePower(calculatedPower);
    Acceleration_limitPower();
}

// Sets engine power safely
static void setEnginePower(float power) {
    instance.enginePower = power;
}

// Prints the current state
void printState() {
    printf("Throttle: %f, Gas Pedal Signal: %f, Engine Power: %f\n", instance.throttle, instance.gasPedalSignal, instance.enginePower);
}
