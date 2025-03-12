// definition.h
#ifndef DEFINITION_H
#define DEFINITION_H

// Hız sınırları
#define MAX_SPEED 60
#define MIN_SPEED 10
// Anormal hız değişimini tespit için sınır
#define MAX_SAFE_SPEED_CHANGE 44

// Hız değişim miktarları
#define SPEED_UP 35
#define SPEED_DOWN_TRAFFIC 10
#define SPEED_DOWN_RIGHT_TURN 5
#define SPEED_DOWN_LEFT_TURN 5
#define SPEED_DOWN_RED_LIGHT 20
#define SPEED_DOWN_PEDESTRIAN 10
#define MAX_PEDESTRIAN_SPEED 15
#define MIN_PEDESTRIAN_SPEED 5
#define STEADY_STATE 0
#define MAX_SPEED_TRAFFIC 30
#define MIN_SPEED_TRAFFIC 10

// Şifreleme için anahtar
#define SECRET_KEY 42

#endif // DEFINITION_H

// speed_control_private.h
#ifndef SPEED_CONTROL_PRIVATE_H
#define SPEED_CONTROL_PRIVATE_H

static int currentSpeed = 10;      // Kullanıcı başlangıç hızın
static unsigned int speedHash = 0; // Hızın hash değeri

// İç fonksiyonlar
static unsigned int generateSpeedHash(int speed);
static int validateSpeed();
static void setSpeed(int newSpeed);

#endif

// speed_control_public.h
#ifndef SPEED_CONTROL_PUBLIC_H
#define SPEED_CONTROL_PUBLIC_H

// Dışa açık fonksiyonlar
void Speed_setTarget(int newSpeed);
int Speed_getCurrent();
void Speed_adjust(int event);

#endif // SPEED_CONTROL_PUBLIC_H

// speed_control.c
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
    printf(" Kırmızı ışık! Duruyoruz... Yeni hız: %d km/h\n\n", newSpeed)
    ;
    break;
  case 5: // Yayalar
    newSpeed = (currentSpeed - SPEED_DOWN_PEDESTRIAN >= MIN_SPEED)
                   ? currentSpeed - SPEED_DOWN_PEDESTRIAN
                   : MIN_SPEED;
    newSpeed =
        (newSpeed <= MAX_PEDESTRIAN_SPEED) ? newSpeed : MAX_PEDESTRIAN_SPEED;
    printf(" Yaya var! Yavaş gidiyoruz... Yeni hız: %d km/h\n", newSpeed)
    ;
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

#include "speed_control_public.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Rastgele olay üretme fonksiyonu
int getRandomEvent(int lastEvent) {
  int event;
  do {
    event = rand() % 6;
  } while (event == lastEvent);
  return event;
}

int main() {
  srand(time(0));

  int userSpeed;
  printf("Lütfen bir hız değeri girin (10-60 km/h arasında): \n\n");
  scanf("%d", &userSpeed);

  Speed_setTarget(userSpeed);
  printf(" Başlangıç Hızı: %d km/h\n\n\n", Speed_getCurrent());

  int lastEvent = -1;
  for (int i = 0; i < 15; i++) {
    int event = getRandomEvent(lastEvent);
    lastEvent = event;
    Speed_adjust(event);
  }

  printf(" Son hız: %d km/h\n", Speed_getCurrent());
  return 0;
}