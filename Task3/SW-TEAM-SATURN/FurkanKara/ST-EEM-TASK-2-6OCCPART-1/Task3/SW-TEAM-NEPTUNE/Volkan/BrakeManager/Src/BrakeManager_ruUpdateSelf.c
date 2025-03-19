
#include "BrakeManager_Private.h"
#include "BrakeManager_Public.h"
#include <stdio.h>


// Deneme amaçlı koyulmuş değişkenler.
float pressure=0,speed=0;
float PressureManager_Get_Current_Pressure(){
    return pressure;
}
float SpeedManager_Get_Vehicle_Speed(){
    return speed;
}
/**
 * @brief Fren Yöneticisi Durumunu Günceller
 * 
 * Bu fonksiyon, fren sistemini güncellemek için gerekli verileri toplar ve 
 * ilgili fren yöneticisine ileterek sistemin doğru şekilde çalışmasını sağlar.
 * 
 * - Fren pedalının konumu, aracın hız bilgisi ve tekerlek hız bilgileri alınır.
 * - Alınan bu veriler, fren yöneticisine (`BrakeManager_t`) iletilir.
 * - Fren pedal konumu, araç hızı ve tekerlek hızı, fren yönetim sistemine uygun şekilde ayarlanır.
 *
 * Bu fonksiyon, frenleme sisteminin doğru ve güncel verilere dayanarak işlem yapmasını sağlar.
 */
void BrakeManager_ruUpdateSelf(void){

    BrakeManager_t* bm = BrakeManager_GetInstance();

    float pressure = PressureManager_Get_Current_Pressure();
    float speed = SpeedManager_Get_Vehicle_Speed();

    bm->setBrakePressure(pressure);
    bm->setVehicleSpeed(speed);
}