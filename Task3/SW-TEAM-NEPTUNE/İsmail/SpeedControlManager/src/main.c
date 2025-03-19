/*
*main.c
*
*		Created on: 13.03.25
*		Author: Ismail Gunes
*
*
*        araç hız uygulaması OOP yaklaşımı yapılarak struct yardımı ile yazıldı
*        ilgili değişken ve fonksiyonların 
*/
#include "speed_control_public.h"
#include <stdio.h>

int main() 
{
    SpeedControlManager_init();  // Arabayı başlat

    Speed_adjust(50);  // 50 km/h hız ver
    printf("Mevcut hız: %d km/h\n", Speed_getCurrent());

    Speed_adjust(120);  // 120 km/h hız ver
    printf("Mevcut hız: %d km/h\n", Speed_getCurrent());

    Speed_adjust(250);  // Maksimum hız sınırını test et
    printf("Mevcut hız: %d km/h\n", Speed_getCurrent());

    Speed_adjust(-10);  // Minimum hız sınırını test et
    printf("Mevcut hız: %d km/h\n", Speed_getCurrent());

    return 0;
}

/*******END OF FILE********/