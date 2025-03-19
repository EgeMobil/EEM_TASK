// acceleration_control_private.h
#ifndef ACCELERATION_CONTROL_PRIVATE_H
#define ACCELERATION_CONTROL_PRIVATE_H

#include "acceleration_control_public.h"

static void calculateEnginePower();
static void processGasPedalInput(float pedalValue);
static void setEnginePower(float power);

#endif // ACCELERATION_CONTROL_PRIVATE_H
