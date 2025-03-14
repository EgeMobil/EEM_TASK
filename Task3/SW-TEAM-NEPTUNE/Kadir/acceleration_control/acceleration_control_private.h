#ifndef ACCELERATION_CONTROL_PRIVATE_H
#define ACCELERATION_CONTROL_PRIVATE_H

#include <stdbool.h>

// Gaz pedalından gelen sinyalleri gizle
static int currentThrottle = 0; // 0 ile 100 arasında bir throttle değeri

// Motor gücünü sınırlamak için hesaplamalar
static int currentPower = 0; // Motor gücü hp

// İvmelenme hesaplama algoritması
static int calculateAcceleration(int throttle, int power);

// Yakıt karışımı hesaplaması
static int calculateFuelConsumption(int power, int throttle);

#endif // ACCELERATION_CONTROL_PRIVATE_H
