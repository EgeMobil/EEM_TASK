#include "BrakeManager_Private.h"
#include "BrakeManager_Public.h"
#include <stdio.h>

float SpeedManager_Get_Vehicle_Speed(void);
float SpeedManager_Get_Wheel_Speed(void);
float SensorManager_PedalPos_Api(void);


/**
 * @brief Fren Sisteminin Kontrol Algoritmasını Uygular
 * 
 * Bu fonksiyon, fren sistemini kontrol etmek için gerekli olan temel işlemleri gerçekleştirir. 
 * - İlk olarak pedal pozisyonu, fren basıncına dönüştürülür.
 * - Ardından mevcut fren basıncı okunur ve ABS durumu kontrol edilir.
 * - Eğer fren basıncı sıfırdan büyükse, kayma tespiti yapılır ve ABS aktifse fren basıncı düzenlenir.
 * - Kayma yoksa, mevcut fren basıncı uygulanır.
 * - Eğer fren basıncı sıfırsa, fren serbest bırakılır.
 *
 * Bu algoritma, frenleme işleminin güvenli ve etkin bir şekilde yapılmasını sağlar. ABS sistemi, tekerlek kaymasını engellemek için müdahale eder, 
 * ve gerektiğinde fren basıncını optimize eder.
 *
 * @note Bu fonksiyon, gerçek zamanlı olarak sürekli çalışarak frenleme performansını izler ve gerekli ayarları yapar.
 */
void BrakeManager_ruControl(void) {

    BrakeManager_t* bm = BrakeManager_GetInstance();

    bm->pedalPosToPressure();                           // Pedal pozisyonunu fren basıncına dönüştür
    float currentPressure = bm->readCurrentPressure();  // Mevcut fren basıncını oku
    ABS_Status_t ABS_status = bm->manangmentABS();      // ABS durumunu kontrol et
    if(currentPressure > 0 ){

        if(bm->detectWheelSlip() && ABS_status == ABS_ON){
            // Kayma tespit edilirse ve ABS aktifse, fren basıncı düzenlenir
            bm->regulateBrakePressure();
        }else{
            bm->applyBrakePressure(currentPressure);
        }

    }else{
        bm->releaseBrakePressure();
    }
    
}
