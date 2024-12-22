#include <stdio.h>
#include "unistd.h"
#include <stdbool.h>      //bool için
#include <stdlib.h>       // exit için

//kontrolü kısa sürsün diye durum sürelerini 10da 1i yaptım

typedef enum
{
    çamaşır_yıkama,
    çamaşır_durulama,
    çamaşır_sıkma
    
}çamaşırState;

void updateçamaşırState(çamaşırState* currentState, int i, bool suVar)
{
    
                                                   // Su olup olmadığını kontrol et
    if (suVar) {
        printf("Su var. İşlem devam ediyor.\n");
    } else {
        printf("Su yok! İşlem durduruldu.\n");
        exit(0);                                  // Su yoksa programı iptal et
    }
    switch(*currentState)
    {
        case çamaşır_yıkama:
            printf("Çamaşırlar yıkanmaya başladı, birazdan durulanacak \n");
            *currentState = çamaşır_durulama;
            sleep(3);
        break;
        
        case çamaşır_durulama:
            printf("Çamaşırlar durulanmaya başladı, birazdan sıkma yapılacak \n");
            *currentState = çamaşır_sıkma;
            sleep(2);
        break;
        
        case çamaşır_sıkma:
            if (i == 5) {                                                           //Son durumsa farklı çıktı versin
                printf("Çamaşırlara sıkma yapılmaya başlandı, birazdan bitecek \n");  
            } else {
                printf("Çamaşırlara sıkma yapılmaya başlandı, birazdan yıkanacak \n");
                *currentState = çamaşır_yıkama;
                sleep(1.5);
                }
        break;
        
        default:
            printf("Makine bozuk olabilir \n");
        break;
        
            }
}

//mainde kullandığımız şeyleri tanımladım
int main()
{
    çamaşırState currentState = çamaşır_yıkama;
    int iterations = 6;
    bool suVar = true;
    printf("Makine çalışmaya başlıyor. \n");
    
    for(int i = 0 ; i < iterations; i++)
    {
        updateçamaşırState(&currentState, i, suVar);
        
        
    }
    
    printf("Makineyi boşaltabilirsin. \n");
    
    return 0;
}









