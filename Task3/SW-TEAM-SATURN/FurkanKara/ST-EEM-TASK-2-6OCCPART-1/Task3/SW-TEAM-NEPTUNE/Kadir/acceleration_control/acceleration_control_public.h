#ifndef ACCELERATION_CONTROL_PUBLIC_H
#define ACCELERATION_CONTROL_PUBLIC_H

#include <stdbool.h>

typedef struct {
    float throttle;
    float power;
    float currentThrottle; // 0 ile 100 arasında bir throttle değeri
    float currentPower; // Motor gücü hp
} AccelerationControl;



AccelerationControl *GetInstance(void);

// Gaz pedalından gelen throttle sinyali (yüzde 0-100 arası bir değer girilmesi gerekir.)
void Acceleration_setThrottle(float throttle);
float Acceleration_getThrottle(void);

// Güç sınırını belirler motorgücü(hp) sınırlama
void Acceleration_limitPower();

// İvmelenme komutlarını uyuglama
void Acceleration_applyAcceleration(void);


void printfunc(void);

#endif // ACCELERATION_CONTROL_PUBLIC_H
