#include "BrakeManager_Private.h"
#include "BrakeManager_Public.h"
#include <stdio.h>
#include <stdlib.h>


static BrakeManager_t instance;
/**
 * @brief BrakeManager initialization runable.
 *
 */
void BrakeManager_CTOR(void) {

    instance.current_brake_pressure = 0.0f;
    instance.abs_active             = 0;
    instance.pedal_position         = 0.0f; 


    instance.applyBrakePressure    = ApplyBrakePressure_Impl;
    instance.releaseBrakePressure  = ReleaseBrakePressure_Impl;
    instance.regulateBrakePressure = RegulateBrakePressure_Impl;
    instance.detectWheelSlip       = DetectWheelSlip_Impl;
    instance.setPedalPos           = setPedalPos_Impl;
    instance.pedalPosToPressure    = pedalPosToPressure_Impl;
    instance.setVehicleSpeed       = setVehicleSpeed_Impl;
    instance.setWheelSpeed         = setWheelSpeed_Impl;
    instance.manangmentABS         = manangmentABS_Impl;
    
    printf("BrakeManager nesnesi oluşturuldu.\n");
}



/**
 * @brief BrakeManager Nesnesinin adresini döndürür
 *
 * @param1 : BrakeManager türünden bir nesne
 * 
 */
BrakeManager_t* BrakeManager_GetInstance(void){
    return &instance;
}

/**
 * @brief Fren Basıncını uygular.
 *
 * @param : Fren Basıncı
 * 
 */
 void ApplyBrakePressure_Impl(float pressure) {
    if (pressure < 0.0f) {
        printf("UYARI: Fren basıncı negatif olamaz, 0.0'a ayarlanıyor!\n");
    }
    else if (pressure > 100.0f) {
        printf("UYARI: Fren basıncı çok yüksek, 100.0'a ayarlanıyor!\n");
    }
    else if(pressure == 0 ){
        instance.brake_active = 0;
        instance.current_brake_pressure = pressure;
        instance.Status = BRAKE_OFF;
    }else{
        printf("Fren uygulanıyor.!\n");
        instance.brake_active = 1;
        instance.current_brake_pressure = pressure;
        instance.Status = BRAKE_ON;
    }
}

/**
 * @brief Fren Basıncını Anlık olarak döndürür
 * 
 */
float readCurrentPressure_Impl(void){
    
    return instance.current_brake_pressure;
}

/**
 * @brief Fren Basıncını uygulamayı bırakır
 *
 * 
 */
 void ReleaseBrakePressure_Impl(void) {
    printf("Fren serbest bırakılıyor...\n");
    instance.brake_active = 0;
    instance.current_brake_pressure = 0;
    instance.Status = BRAKE_OFF;
}
/**
 * @brief ABS aktif ise fren Yönetimi
 *
 * 
 */
 void RegulateBrakePressure_Impl(void) {

    instance.abs_active=1;
    /**
     * ABS Sistemi için özel bir fren yönetim sistemi.
     */
}

/**
 * @brief Aracın kaymaya başladığını anlayan fonskiyon
 *
 * @param1 : BrakeManager türünden bir nesne
 * 
 */
 int DetectWheelSlip_Impl(void) {

    if (instance.wheel_speed < instance.vehicle_speed * 0.8f) {
        return 1;  // Kayma tespit edildi
    }
    return 0;
}


/**
 * @brief Fren pedalının değerini set eden fonskiyon
 *
 * @param1 : BrakeManager türünden bir nesne
 * 
 */
void setPedalPos_Impl(float pedalPos) {

    instance.pedal_position = pedalPos;
}

/**
 * @brief Fren pedalının yüzdesine göre uygulanacak basıncı hesaplayan fonskiyon
 * 
 */
void pedalPosToPressure_Impl(void){

    instance.current_brake_pressure = instance.pedal_position * 10;
}


/**
 * @brief Araç hızını başka apiden alıp set eden fonksiyon
 * 
 */
void setVehicleSpeed_Impl(float speed){

    instance.vehicle_speed = speed;
}

/**
 * @brief Araç tekerlek hızını başka apiden alıp set eden fonksiyon
 * 
 */
void setWheelSpeed_Impl(float speed){
    
    instance.wheel_speed = speed;
}

/**
 * @brief ABS'i aktif ve pasif eden fonskiyon
 * 
 */
ABS_Status_t manangmentABS_Impl(void){

    if(instance.vehicle_speed > 45){
        instance.ABS_Status = ABS_ON;
    }else{
        instance.abs_active=0;
        instance.ABS_Status = ABS_OFF;
    }
    return instance.ABS_Status;
}