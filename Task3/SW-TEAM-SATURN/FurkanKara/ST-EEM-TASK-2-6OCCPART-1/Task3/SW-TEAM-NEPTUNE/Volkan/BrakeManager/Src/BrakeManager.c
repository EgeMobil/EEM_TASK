#include "BrakeManager_Private.h"
#include "BrakeManager_Public.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

static BrakeManager_t instance;

/**
 * @brief BrakeManager initialization runable.
 *
 */
static void BrakeManager_CTOR(void) {

    instance.current_brake_pressure = 0.0f;
    instance.abs_active             = 0;
    instance.vehicle_speed         = 0.0f; 

    instance.applyBrakePressure    = ApplyBrakePressure_Impl;
    instance.releaseBrakePressure  = ReleaseBrakePressure_Impl;
    instance.setBrakePressure      = SetBrakePressure_Impl;
    instance.manangmentABS         = manangmentABS_Impl;
    instance.absAlgorithm          = ABSAlgorithm_Impl;  
    instance.toString              = toString_Impl;
    instance.setVehicleSpeed       = SetVehicleSpeed_Impl;
    
    printf("BrakeManager nesnesi olusturuldu.\n");
}

/**
 * @brief BrakeManager Nesnesinin adresini döndürür
 *
 * @param1 : BrakeManager türünden bir nesne oluşturur ve bu fonskiyon çağrıldığı anda bu nesne oluşturulur. Bu fonskiyon nesneden bir tane doğru şekilde oluşturulmasını sağlar.
 * 
 */
BrakeManager_t* BrakeManager_GetInstance(void){

    static uint8_t isInitialized = 0; 
    if (!isInitialized) {
        BrakeManager_CTOR();  
        isInitialized = 1;
    }
    return &instance;
}

/**
 * @brief Fren Basincini uygular.
 *
 * @param : Fren Basinci
 * 
 */
void ApplyBrakePressure_Impl(float pressure) {
    if (pressure < 0.0f) {
        printf("UYARI: Fren basinci negatif olamaz, 0.0'a ayarlaniyor!\n");
        pressure = 0.0f;
    }
    else if (pressure > 100.0f) {
        printf("UYARI: Fren basinci cok yüksek, 100.0'a ayarlaniyor!\n");
        pressure = 100.0f;
    }

    instance.current_brake_pressure = pressure;
    instance.brake_active = 1;
    instance.Status = BRAKE_ON;
    printf("Fren uygulaniyor. Basinc: %.2f\n", pressure);
}

/**
 * @brief Fren Basincini uygulamayi birakir
 *
 * 
 */
void ReleaseBrakePressure_Impl(void) {
    printf("Fren serbest birakiliyor...\n");
    instance.brake_active = 0;
    instance.current_brake_pressure = 0.0f;
    instance.Status = BRAKE_OFF;
}

/**
 * @brief Fren Basincini set eder.
 *
 * @param : Fren Basinci
 * 
 */
void SetBrakePressure_Impl(float pressure) {
    instance.current_brake_pressure = pressure;
    printf("Fren basinci set edildi: %.2f\n", pressure);
}

/**
 * @brief Hizi set eder.
 *
 * @param : Hiz
 * 
 */
void SetVehicleSpeed_Impl(float speed){
    instance.vehicle_speed = speed;
    printf("Hiz set edildi: %.2f\n", speed);
}

/**
 * @brief ABS'i aktif ve pasif eden fonskiyon
 * 
 */
ABS_Status_t manangmentABS_Impl(void){
    if(instance.vehicle_speed > 45){
        instance.abs_active = 1;
        instance.ABS_Status = ABS_ON;
    }else{
        instance.abs_active = 0;
        instance.ABS_Status = ABS_OFF;
    }
    return instance.ABS_Status;
}

/**
 * @brief ABS Algoritmasi
 * 
 * Bu fonksiyon, ABS aktif olduğunda fren basincini düzenler.
 * Tekerlek kaymasini önlemek için fren basincini artirir veya azaltir.
 */
void ABSAlgorithm_Impl(void) {
    if (instance.abs_active) {
        printf("ABS aktif, fren basinci duzenleniyor...\n");
        // Örnek bir ABS algoritmasi: Basinci %10 azalt ve tekrar uygula
        float newPressure = instance.current_brake_pressure * 0.9f;
        instance.applyBrakePressure(newPressure);
    }
}

/**
 * @brief Nesne bilgisini stringe çevirir
 * 
 */
const char* toString_Impl(void) {
    static char buffer[256];  
    memset(buffer, 0, sizeof(buffer)); 

    snprintf(buffer, sizeof(buffer),
        "BrakeManager Durumu:\n"
        "  Fren Basinci: %.2f\n"
        "  ABS Durumu: %s\n"
        "  Fren Aktif: %s\n",
        instance.current_brake_pressure,
        instance.ABS_Status == ABS_ON ? "Açik" : "Kapali",
        instance.brake_active ? "Evet" : "Hayir"
    );

    return buffer;
}