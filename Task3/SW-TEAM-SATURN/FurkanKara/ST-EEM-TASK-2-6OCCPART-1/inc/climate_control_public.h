#ifndef CLIMATE_CONTROL_PUBLIC_H
#define CLIMATE_CONTROL_PUBLIC_H

// Kullanıcının sıcaklık ayarı yapması için fonksiyon
void Climate_setTemperature(float temp);

// Kullanıcının mevcut sıcaklığı alması için fonksiyon
float Climate_getCurrentTemp();

// Kullanıcının fan hızını ayarlaması için fonksiyon
void Climate_adjustFanSpeed(int speedLevel);

#endif
