#include "BrakeManager_Private.h"
#include "BrakeManager_Public.h"
#include <stdio.h>


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
    
    float currentPressure = bm->current_brake_pressure;

    if(currentPressure > 0 ){
        if(bm->manangmentABS() == ABS_ON){
            bm->absAlgorithm();  // ABS algoritmasını çalıştır
        }
        bm->applyBrakePressure(currentPressure);
    }else{
        bm->releaseBrakePressure();
    }
}
