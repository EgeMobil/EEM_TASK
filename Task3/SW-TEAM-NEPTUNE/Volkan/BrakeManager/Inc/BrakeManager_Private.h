#ifndef BRAKEMANAGER_PRIVATE_H
#define BRAKEMANAGER_PRIVATE_H

#include "BrakeManager_Def.h"  


/**
 * @brief Freni uygulayan fonksiyon
 * 
 */
void ApplyBrakePressure_Impl(float pressure);

/**
 * @brief Anlık Basıncı döndürür
 * 
 */
 float readCurrentPressure_Impl(void);

/**
 * @brief Freni serbest bırakan fonskiyon
 * 
 */
 void ReleaseBrakePressure_Impl(void);


/**
 * @brief Freni regüle eden fonskiyon
 * 
 */
void RegulateBrakePressure_Impl(void);

/**
 * @brief Aracın kayıp kaymadığına karar veren fonskiyon
 * 
 */
int DetectWheelSlip_Impl(void);


/**
 * @brief Fren pedalının değerini set eden fonskiyon
 * 
 */
void setPedalPos_Impl(float pedalPos);

/**
 * @brief Fren pedalının yüzdesine göre uygulanacak basıncı hesaplayan fonskiyon
 * 
 */
void pedalPosToPressure_Impl(void);


/**
 * @brief Araç hızını başka apiden alıp set eden fonksiyon
 * 
 */
void setVehicleSpeed_Impl(float speed);

/**
 * @brief Araç tekerlek hızını başka apiden alıp set eden fonksiyon
 * 
 */
void setWheelSpeed_Impl(float speed);

/**
 * @brief ABS'i aktif ve pasif eden fonskiyon
 * 
 */
ABS_Status_t manangmentABS_Impl(void);


extern BrakeManager_t* BrakeManager_GetInstance(void);

#endif /* BRAKEMANAGER_PRIVATE_H */


