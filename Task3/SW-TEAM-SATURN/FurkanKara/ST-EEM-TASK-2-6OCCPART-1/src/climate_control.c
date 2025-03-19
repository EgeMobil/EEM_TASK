#include "climate_control_public.h"
#include "climate_control_private.h"
#include "definition.h"
#include <stdio.h>

// Mevcut sıcaklık (başlangıç değeri)
static float currentTemperature = 22.0;

// Sıcaklık sensöründen veri okuma (simüle)
float readTemperatureSensor() {
    return currentTemperature; // Gerçek bir sistemde sensörden veri okur
}

// Fan motor kontrolü (simüle)
void controlFanMotor(int speed) {
    printf("Fan hizi %d seviyesine ayarlandi.\n", speed);
}

// Kullanıcının sıcaklık ayarlaması
void Climate_setTemperature(float temp) {
    if (temp < MIN_TEMPERATURE || temp > MAX_TEMPERATURE) {
        printf("Hata: Sicaklik degeri %.1f ve %.1f arasinda olmalidir!\n", MIN_TEMPERATURE, MAX_TEMPERATURE);
        return;
    }
    currentTemperature = temp;
    printf("Sicaklik %.1f°C olarak ayarlandi.\n", temp);
}


float Climate_getCurrentTemp() {
    return readTemperatureSensor();
}

// Fan hızını ayarla
void Climate_adjustFanSpeed(int speedLevel) {
    if (speedLevel < FAN_SPEED_LOW || speedLevel > FAN_SPEED_HIGH) {
        printf("Hata: Fan hiz seviyesi gecersiz!\n");
        return;
    }
    controlFanMotor(speedLevel);
}
