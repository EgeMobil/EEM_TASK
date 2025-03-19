#ifndef STEERING_CONTROL_PRIVATE_H
#define STEERING_CONTROL_PRIVATE_H

#include "steering_control_definition.h"
// Direksiyon kontrolü için gizli yapı
typedef struct
{
    double currentAngle;      // Şu anki direksiyon açısı
    double sensorValue;       // Sensör verilerinden elde edilen ham değer
    double calibrationOffset; // Kalibrasyon sonucu eklenen offset
} SteeringControl;

#endif /* STEERING_CONTROL_PRIVATE_H */
