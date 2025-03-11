
#include "BrakeManager_Private.h"
#include "BrakeManager_Public.h"
#include <stdio.h>

float Brake_PedalPos_Api(){
    return 1;
}
float SpeedManager_Get_Vehicle_Speed(){
    return 2;
}
float SpeedManager_Get_Wheel_Speed(){
    return 2;
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

    float pos = Brake_PedalPos_Api();
    float speed = SpeedManager_Get_Vehicle_Speed();
    float wspeed = SpeedManager_Get_Wheel_Speed();

    bm->setPedalPos(pos);
    bm->setVehicleSpeed(speed);
    bm->setWheelSpeed(wspeed);
}