/*
*       speed_control_public.h
*
*		Created on: 13.03.25
*		Author: Ismail Gunes
*
*/

#ifndef SPEED_CONTROL_PUBLIC_H
#define SPEED_CONTROL_PUBLIC_H

// Public fonksiyonlar
void SpeedControlManager_init(void);  // Arabayı başlat
int  Speed_getCurrent(void);          // Mevcut hızı al
void Speed_adjust(int targetSpeed);   // Hedef hızı ayarla

#endif
