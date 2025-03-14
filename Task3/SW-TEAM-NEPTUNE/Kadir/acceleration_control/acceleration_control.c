#include "acceleration_control_public.h"
#include "acceleration_control_private.h"
#include "definition.h"
#include <stdio.h>

// Gaz pedalını set etme
void Acceleration_setThrottle(int throttle) {
    if (throttle >= 0 && throttle <= 100) {
        currentThrottle = throttle;
    }
}

// Gaz pedal yüzdesini al
int Acceleration_getThrottle(void) {
    return currentThrottle;
}

// Gücü sınırlama yapmalıyız
void Acceleration_limitPower(int maxPower) {
    if (maxPower <= MAX_POWER) {
        currentPower = maxPower;
    }
}

// İvmelenme hesaplama fonksiyonu
static int calculateAcceleration(int throttle, int power) {
    // Burada ivmelenme hesaplamaları yapılır
    return (throttle / 100.0) * (power / 10);     // F = m * a, m = 1 birim sabit kabul ediyoruz F = a  ----  a = throttle / 100.0) * (power / 10)
}

// Yakıt tüketimi hesaplama fonksiyonu
static int calculateFuelConsumption(int power, int throttle) {
    // Yakıt tüketimi tahmini hesaplanıyor.
    return power * throttle * FUEL_CONSUMPTION_RATE;
}

// İvmelenmeyi uygulama
void Acceleration_applyAcceleration(void) {
    // İvmelenmeyi hesapla
    int acceleration = calculateAcceleration(currentThrottle, currentPower);
    
    // Güvenlik eşiklerine göre ivmelenmeyi kısıtla
    if (acceleration > MAX_ACCELERATION) {
        acceleration = MAX_ACCELERATION;
    }
    
    // Yakıt tüketimini hesapla
    int fuelConsumption = calculateFuelConsumption(currentPower, currentThrottle);
    
    // İvmelenme ve yakıt durumu çıktısı (örnek, burada log yazılabilir)
    printf("Acceleration: %d m/s^2\n", acceleration);
    printf("Fuel Consumption: %d units\n", fuelConsumption);
}


