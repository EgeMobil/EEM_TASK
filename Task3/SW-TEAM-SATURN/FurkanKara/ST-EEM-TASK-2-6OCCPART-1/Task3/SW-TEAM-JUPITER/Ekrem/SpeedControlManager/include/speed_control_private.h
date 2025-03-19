#ifndef SPEED_CONTROL_PRIVATE_H
#define SPEED_CONTROL_PRIVATE_H

static int currentSpeed = 10;      // Kullanıcı başlangıç hızın
static unsigned int speedHash = 0; // Hızın hash değeri

// İç fonksiyonlar
static unsigned int generateSpeedHash(int speed);
static int validateSpeed();
static void setSpeed(int newSpeed);

#endif
