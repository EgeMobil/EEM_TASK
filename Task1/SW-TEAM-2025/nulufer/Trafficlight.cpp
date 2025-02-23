#include <stdio.h>
#include "unistd.h"  // sleep() fonksiyonunu kullanıyoruz


typedef enum
{
    RED,
    YELLOW, 
    GREEN   
} TrafficLightState;

// Trafik ışığı durumunu burada güncelliyoruz
void updateTrafficLightState(TrafficLightState* currentState)
{
    switch (*currentState)
    {
    case RED:
        printf("Kırmızı ışık: Dur \n");
        *currentState = GREEN;  
    break;

    case GREEN:
        printf("Yeşil ışık: Geç \n");
        *currentState = YELLOW; 
    break;

    case YELLOW:
        printf("Sarı ışık: Geçişe hazırlan\n");
        *currentState = RED;  
    break;

    default:
        printf("Hatalı durum\n");
        *currentState = RED; 
    break;
    }
}

int main()
{
    TrafficLightState currentState = RED;
    int iterations = 3;

    printf("Trafik ışığı kontrol sistemi başlıyor.\n");

    for (int i = 0; i < iterations; i++)
    {
        updateTrafficLightState(&currentState); // Durumu günceller
// bekleme sürelerini burada belirtiyoruz
        switch (currentState)
        {
        case RED:
            sleep(20);
            break;

        case GREEN:
            sleep(10);
            break;

        case YELLOW:
            sleep(5);
            break;
        }
    }

    printf("Trafik ışığı kontrol sistemi tamamlandı.\n");

    return 0;
}
