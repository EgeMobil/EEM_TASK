/*
*       speed_control_private.h
*
*		Created on: 13.03.25
*		Author: Ismail Gunes
*
*/

#ifndef SPEED_CONTROL_PRIVATE_H
#define SPEED_CONTROL_PRIVATE_H

// struct
typedef struct Car 
{
    int speed;         // Anlık hız
    int targetspeed;   // Hedef hız

    void (*accelerate)(struct Car* self); // Aracı hızlandırma fonksiyonu
    int (*getSpeed)(struct Car* self);    // Anlık hızı alma fonksiyonu
} Car;

// Constructor (Aracı başlatan fonksiyon)
void Car_init(Car* self);

// Method Implementations
void Car_accelerate(Car* self);
int Car_getSpeed(Car* self);

#endif // SPEED_CONTROL_PRIVATE_H
