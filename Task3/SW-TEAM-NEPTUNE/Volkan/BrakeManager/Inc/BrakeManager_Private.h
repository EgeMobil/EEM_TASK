#ifndef BRAKEMANAGER_PRIVATE_H
#define BRAKEMANAGER_PRIVATE_H

#include "BrakeManager_Def.h"  

/**
 * @brief Freni uygulayan fonksiyon
 * 
 */
void ApplyBrakePressure_Impl(float pressure);

/**
 * @brief Freni serbest bırakan fonskiyon
 * 
 */
void ReleaseBrakePressure_Impl(void);

/**
 * @brief Fren basıncını set eden fonksiyon
 * 
 */
void SetBrakePressure_Impl(float pressure);

/**
 * @brief Speed set eden fonksiyon
 * 
 */
void SetVehicleSpeed_Impl(float speed);

/**
 * @brief ABS'i aktif ve pasif eden fonskiyon
 * 
 */
ABS_Status_t manangmentABS_Impl(void);

/**
 * @brief ABS Algoritması
 * 
 */
void ABSAlgorithm_Impl(void);

/**
 * @brief Nesne bilgisini stringe çevirir
 * 
 */
const char* toString_Impl(void);

BrakeManager_t* BrakeManager_GetInstance(void);


#endif /* BRAKEMANAGER_PRIVATE_H */