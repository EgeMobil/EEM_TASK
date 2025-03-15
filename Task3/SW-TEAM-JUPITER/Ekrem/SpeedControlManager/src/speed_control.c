#include "definition.h"
#include "speed_control_private.h"
#include "speed_control_public.h"
#include <stdio.h>
#include <stdlib.h>

static unsigned int generateSpeedHash(int speed) {
  return (speed ^ SECRET_KEY) * 31;
}

// Hızın bütünlüğünü doğrulayan fonksiyon
static int validateSpeed() {
  return (generateSpeedHash(currentSpeed) == speedHash);
}

// Hız ayarlarını değiştiren fonksiyon
static void setSpeed(int newSpeed) {
  if (abs(newSpeed - currentSpeed) > MAX_SAFE_SPEED_CHANGE) {
    printf(" Anormal hız değişimi algılandı! Hız birden bu kadar artamaz ! Güvenlik devreye giriyor...\n");
    return;
  }
  currentSpeed = newSpeed;
  speedHash = generateSpeedHash(currentSpeed);
}

// Mevcut hızı döndüren fonksiyon
int Speed_getCurrent() {
  if (!validateSpeed()) {
    printf(" Hız verisi manipüle edildi! Güvenlik kilitlendi.\n\n\n");
    exit(1);
  }
  return currentSpeed;
}

// Hız değişimini yöneten fonksiyon
void Speed_adjust(int event) {
  if (!validateSpeed()) {
    printf(" Hız verisi manipüle edildi! Güvenlik kilitlendi.\n\n\n");
    exit(1);
  }

  int newSpeed = currentSpeed;

  switch (event) {
  case 0: // Yol boş, hızlan
    newSpeed = (currentSpeed + SPEED_UP <= MAX_SPEED) ? SPEED_UP : MAX_SPEED;
    printf(" Yol boş ! Hızlan : %d km/h\n", newSpeed);
    break;
  case 1: // Trafik var, yavaşla
    newSpeed = currentSpeed - SPEED_DOWN_TRAFFIC;
    newSpeed = (newSpeed < MIN_SPEED_TRAFFIC) ? MIN_SPEED_TRAFFIC : newSpeed;
    newSpeed = (newSpeed > MAX_SPEED_TRAFFIC) ? MAX_SPEED_TRAFFIC : newSpeed;
    printf(" Trafik var! Yavaş gidiyoruz... Yeni hız: %d km/h\n", newSpeed);
    break;
  case 2: // Sağa dönüş
    newSpeed = (currentSpeed - SPEED_DOWN_RIGHT_TURN >= MIN_SPEED)
                   ? currentSpeed - SPEED_DOWN_RIGHT_TURN
                   : MIN_SPEED;
    printf(" Sağa dönüş yapılıyor... Yeni hız: %d km/h\n", newSpeed);
    break;
  case 3: // Sola dönüş
    newSpeed = (currentSpeed - SPEED_DOWN_LEFT_TURN >= MIN_SPEED)
                   ? currentSpeed - SPEED_DOWN_LEFT_TURN
                   : MIN_SPEED;
    printf(" Sola dönüş yapılıyor... Yeni hız: %d km/h\n", newSpeed);
    break;
  case 4: // Kırmızı ışık
    newSpeed = 0;
    printf(" Kırmızı ışık! Duruyoruz... Yeni hız: %d km/h\n\n", newSpeed);
    break;
  case 5: // Yayalar
    newSpeed = (currentSpeed - SPEED_DOWN_PEDESTRIAN >= MIN_SPEED)
                   ? currentSpeed - SPEED_DOWN_PEDESTRIAN
                   : MIN_SPEED;
    newSpeed =
        (newSpeed <= MAX_PEDESTRIAN_SPEED) ? newSpeed : MAX_PEDESTRIAN_SPEED;
    printf(" Yaya var! Yavaş gidiyoruz... Yeni hız: %d km/h\n", newSpeed);
    break;
  }

  setSpeed(newSpeed);
}

// Hız hedefini ayarlayan fonksiyon
void Speed_setTarget(int newSpeed) {
  if (newSpeed >= MIN_SPEED && newSpeed <= MAX_SPEED) {
    setSpeed(newSpeed);
    printf(" Hız hedefi başarıyla %d km/h olarak ayarlandı.\n", newSpeed);
  } else {
    printf(" X Hatalı hız! Hız 10 ile 60 arasında olmalı.\n\n");
    printf(" X Manipülasyon tespit edildi! Program sonlandırılıyor...\n\n");
    exit(1);
  }
}
