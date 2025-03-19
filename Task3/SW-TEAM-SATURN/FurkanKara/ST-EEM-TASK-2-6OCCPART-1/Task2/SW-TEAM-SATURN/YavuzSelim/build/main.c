#include <stdio.h>

#include <windows.h>  // Windows için Sleep fonksiyonu

#include "speed_control_public.h"



int main(void) {
    // Başlangıç durumu
    printf("Baslangic Hizi: %d\n", Speed_getCurrent());
    Speed_getCurrent();
    
    // Hedef hızı belirle
    int result = Speed_setTarget(21);


    // Hızın hedefe ulaşması için ayarlama döngüsü
    if(result != -1)
    {
        printf("Hedef Hiz Ayarlandi: %d\n", result);
        while (Speed_getCurrent() != result) {
        Speed_adjust();;

        printf("Mevcut Hiz: %d\n", Speed_getCurrent());
        Sleep(1000);//programın hızını yavaşlatmak için 1s zaman farkı oluşturuyor
    }

    printf("Hedef Hiza Ulasildi: %d\n", Speed_getCurrent());
    return 0;
    }
    else
    printf("Hiz degeri yanlis ayarlandi");

}