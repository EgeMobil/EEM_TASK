/******************************************************************************
    EMobil Meeting #3 : Intro State Machine - Durum Makinesine Giriş
*******************************************************************************/

/* State Machine 
Gömülü sistemlerde bu yöntem, özellikle karmaşık işlemleri düzenli ve kontrol edilebilir bir şekilde
yönetmek için kullanılan bir yapıdır.

KAPI SENARYOSU
1- Durumlar State'ler 
- Kapalı
- Açılıyor
- Açık
- Kapanıyor

2- Olaylar Event'ler
- Sensör bir hareket algılar. Kapı açılmaya başlar
- Zamanlayıcı tamamlanır. Kapı kapanmaya başlar

3- Geçişler Transition'lar
- Kapalı durumundayken -> Açılıyor durumuna geçmek için, sensör hareket algılamalıdır.
- Kapalı durumdan doğrudan açık durumama geçmemelidir!

4- Eylemler Action'lar
- Kapı açılıyor durumundayken, motor çalışır

NEDEN STATE MACHINE?
* Sistemi düzenli hale getirir. Ne yapılacağı net bir şekilde bellidir.
* Hataları azaltır. Her state'in, her eventin bir anlamı vardır. Kolayca tespit edilir.
* Okunabilirlik sağlar. Neyin nasıl çalıştığını anlamak daha kolay olur.

*/

#include <stdio.h>

/* 
State Machine Tasarlama süreci 
1. Problemin Analizi
2. Durumlarım Tanımlanması
3. Geçiş kurallarının belirlenmesi
*/

#include "unistd.h" // sleep() fonksiyonu için

// Durumlar için enum tanımlıyoruz
typedef enum
{
    LED_OFF,
    LED_ON
}LEDState;

// LED durumunu güncelleyen fonksiyon
void updateLEDState(LEDState* currentState)
{
    switch(*currentState)
    {
        case LED_OFF:
            printf("LED söndü. Şimdi yanacak.. \n");
            *currentState = LED_ON;
        break;
        
        case LED_ON:
            printf("LED yandı. Şimdi sönecek.. \n");
            *currentState = LED_OFF;
        break;
        
        default:
            printf("LED hatalı durumda. Şimdi sönecek.. \n");
            *currentState = LED_OFF;
        break;
    }
}


int main()
{
   LEDState currentState = LED_OFF; // başlangıç durumu led sönük
   int iterations = 10; // toplam led yanıp sönme sayısı
   
   printf("LED kontrol sistemi başlıyor. \n");
   
   for(int i = 0 ; i < iterations; i++)
   {
       updateLEDState(&currentState); // Durumu günceller
       sleep(1); // 1 saniye bekleyen zamanlayıcı simülasyonu
   }
   
   printf("LED kontrol sistemi tamamlandı. \n");
}


/* LED State Machine */
   /*
   State
   LED_ON : Led yanık.
   LED_OFF : Led sönük.
   
   Event
   Zamanlayıcı tamamlandı. ( 1 saniye geçti.)
   
   Transition
   LED_OFF -> LED_ON : Zamanlayıcı tamamlanınca
   LED_ON -> LED_OFF : Zamanlayıcı tamamlanınca
   
   Action
   LED_ON durumundayken ledi yakmak
   LED_OFF durumundayken ledi söndürmek
   
   Örnek işleyiş,
   başlangıçta led sönük LED_OFF
   zamanlayıcı başladı
   zamanlayıcı tamamlandı led yanar. LED_ON
   led yanıkken zamanlayıcı başladı.
   led yanıkken zamanlayıcı tamamlandı. led söner LED_OFF
   Bu döngü sürekli tekrar eder. ( gdb özelinde 10 iterasyonda devam etsin. )
   
   */















