#ifndef SPEED_CONTROL_PRIVATE_H
#define SPEED_CONTROL_PRIVATE_H

// Mevcut hız değeri (sadece bu dosya içinde erişilebilir)
static int current_speed = 20;

// Hedeflenen hız değeri (sadece bu dosya içinde erişilebilir)
static int target_speed = 0;

// Hız değişim oranı 
static const float SPEED_CHANGE_FACTOR = 0.1f;

// Hız değişimini uygulayan özel fonksiyon
static void applySpeedChange(void);

#endif // SPEED_CONTROL_PRIVATE_H