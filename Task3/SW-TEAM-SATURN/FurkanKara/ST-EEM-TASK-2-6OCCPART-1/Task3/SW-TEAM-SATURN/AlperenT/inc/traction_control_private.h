#ifndef TRACTION_CONTROL_PRIVATE_H
#define TRACTION_CONTROL_PRIVATE_H

#include "stdint.h"
#include "stdbool.h"

// Sensör yapısı (private veri içeren)
typedef struct {
    uint16_t sensorData;
} SensorData;

// Sensör API'si (Encapsulation)
typedef struct {
    SensorData data;
    void (*read)(void* self);
    uint16_t (*getValue)(void* self);
} Sensor;

static void sensor_read(void* self);
static uint16_t sensor_getValue(void* self);
Sensor Sensor_create();

static bool detectSlip();
static void limitEnginePower();

#endif // TRACTION_CONTROL_PRIVATE_H