#ifndef ACCELERATION_CONTROL_PUBLIC_H
#define ACCELERATION_CONTROL_PUBLIC_H

#include <stdbool.h>

// Gaz pedalından gelen throttle sinyali (yüzde 0-100 arası bir değer girilmesi gerekir.)
void Acceleration_setThrottle(int throttle);
int Acceleration_getThrottle(void);

// Güç sınırını belirler motorgücü(hp) sınırlama
void Acceleration_limitPower(int maxPower);

// İvmelenme komutlarını uyuglama
void Acceleration_applyAcceleration(void);

#endif // ACCELERATION_CONTROL_PUBLIC_H
