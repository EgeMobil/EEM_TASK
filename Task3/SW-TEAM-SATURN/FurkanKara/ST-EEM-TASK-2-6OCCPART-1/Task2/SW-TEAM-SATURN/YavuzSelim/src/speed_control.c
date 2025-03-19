#include <stdio.h>
#include "definition.h"
#include "speed_control_private.h"
#include "speed_control_public.h"


// Kullanıcıdan gelen hedef hız değerini ayarlar
int Speed_setTarget(int speed) {
    if (speed >= MIN_SPEED && speed <= MAX_SPEED) {
        target_speed = speed;
        return target_speed; // Ayarlanan hedef hızı döndür
    }
    return -1; // Geçersiz hız durumunda hata kodu döndür
}


// Mevcut hızı döner
int Speed_getCurrent(void) {
    return current_speed;
}

// Hızın hedef hıza doğru ayarlanmasını başlatır
void Speed_adjust(void) {
    applySpeedChange();
}

// Mevcut hızın hedef hıza doğru kademeli olarak ayarlanmasını sağlar
static void applySpeedChange(void) {
    if(target_speed != -1)
    {
        printf("Hedef Hiz: %d, Mevcut Hiz: %d\n", target_speed, current_speed);  // Debug: Hedef ve mevcut hızı yazdır
        int difference = target_speed - current_speed;
        if (difference > 0) {
            current_speed += (int)((target_speed) * SPEED_CHANGE_FACTOR);
            if (current_speed > target_speed) {
                current_speed = target_speed; // Hızın hedef hızı aşmamasını sağlar
            }
        } else if (difference < 0) {
            current_speed -= (int)((target_speed) * SPEED_CHANGE_FACTOR);
            if (current_speed < target_speed) {
                current_speed = target_speed; // Hızın hedef hızın altına düşmemesini sağlar
            }
        }

    }
    else
    printf("Girilen hiz degeri yanlis\n"); 

   
}