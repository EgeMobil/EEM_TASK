/*
*       speed_control.c
*
*		Created on: 13.03.25
*		Author: Ismail Gunes
*
*/

#include "speed_control_public.h"
#include "speed_control_private.h"
#include "definition.h"

static Car myCar;  // Global nesne, encapsulation için `static`

// Public fonksiyonlar struct yapısına erişerek aksiyonları gerçekleştiriyor
void SpeedControlManager_init(void) 
{
    Car_init(&myCar);
}

int Speed_getCurrent(void) 
{
    return myCar.getSpeed(&myCar);  // Hatalı çağrı düzeltildi
}

void Speed_adjust(int targetSpeed) 
{
    myCar.targetspeed = targetSpeed;
    myCar.accelerate(&myCar);  // Hızlandırma fonksiyonu çağrıldı
}

// Aracı başlatan constructor fonksiyonu
void Car_init(Car* self) 
{
    self->speed = 0;  // İlk hız 0
    self->targetspeed = 0;

    // Metotları bağla
    self->accelerate = Car_accelerate;
    self->getSpeed = Car_getSpeed;
}

// Aracı hızlandırma fonksiyonu
void Car_accelerate(Car* self) 
{
    if (self->targetspeed >= MIN_SPEED && self->targetspeed <= MAX_SPEED) 
    {
        self->speed = self->targetspeed;  // Geçerli hız aralığında ise hedef hıza ayarla
    } 
    else if (self->targetspeed > MAX_SPEED) 
    {
        self->speed = MAX_SPEED;  // Maksimum hızı aşamaz
    } 
    else 
    {
        self->speed = MIN_SPEED;  // Minimum hızın altına düşemez
    }

    printf("Araba hızlandı! Anlık hız: %d km/h\n", self->speed);
}

// Anlık hızı döndüren fonksiyon
int Car_getSpeed(Car* self) 
{
    return self->speed;
}
