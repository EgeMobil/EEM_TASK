#ifndef CLIMATE_CONTROL_PRIVATE_H
#define CLIMATE_CONTROL_PRIVATE_H

// İç sıcaklık sensöründen veri okuma fonksiyonu
float readTemperatureSensor();

// Fan motor hızını kontrol etme fonksiyonu
void controlFanMotor(int speed);

#endif
