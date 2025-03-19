#include "acceleration_control_public.h"
#include "acceleration_control_private.h"
#include "definition.h"
#include <stdio.h>

static AccelerationControl instance = {0.0f, 0.0f,0.0f, 0.0f};

AccelerationControl *GetInstance()
{
    return &instance;
}

// Gaz pedalını set etme
void Acceleration_setThrottle(float throttle)
{
    if (throttle >= 0 && throttle <= 100)
    {
        instance.currentThrottle = throttle;
    }
}

// Gaz pedal yüzdesini al
float Acceleration_getThrottle(void)
{
    return instance.currentThrottle;
}


// Gücü sınırlama yapmalıyız
void Acceleration_limitPower()
{
    calculateEnginePower();
    if (MAX_POWER <= instance.currentPower)
    {
        instance.currentPower = MAX_POWER;
    }
}

// İvmelenme hesaplama fonksiyonu
static float calculateAcceleration(float throttle, float power)
{
    // Burada ivmelenme hesaplamaları yapılır
    return (throttle / 100.0) * (power / 10); // F = m * a, m = 1 birim sabit kabul ediyoruz F = a  ----  a = throttle / 100.0) * (power / 10)
}

// Yakıt tüketimi hesaplama fonksiyonu
static float calculateFuelConsumption(float power, float throttle)
{
    // Yakıt tüketimi tahmini hesaplanıyor.
    return power * throttle * FUEL_CONSUMPTION_RATE;
}

// İvmelenmeyi uygulama
void Acceleration_applyAcceleration(void)
{
    // İvmelenmeyi hesapla
    float acceleration = calculateAcceleration(instance.currentThrottle, instance.currentPower);

    // Güvenlik eşiklerine göre ivmelenmeyi kısıtla
    if (acceleration > MAX_ACCELERATION)
    {
        acceleration = MAX_ACCELERATION;
    }

    // Yakıt tüketimini hesapla
    float fuelConsumption = calculateFuelConsumption(instance.currentThrottle, instance.currentPower);

    // İvmelenme ve yakıt durumu çıktısı (örnek, burada log yazılabilir)
    printf("Acceleration: %f m/s^2\n", acceleration);
    printf("Fuel Consumption: %f units\n", fuelConsumption);
}

void printfunc()
{
    printf("Throttle: %f, Power: %f\n", instance.currentThrottle, instance.currentPower);
}

static void setPower(float power)
{
    instance.currentPower = power;
}

static void calculateEnginePower() {
    float calculatedPower = instance.currentThrottle * MAX_ACCELERATION;
    setPower(calculatedPower);
}