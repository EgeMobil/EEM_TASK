#ifndef BRAKEMANAGER_PUBLIC_H
#define BRAKEMANAGER_PUBLIC_H

#include "BrakeManager_Def.h"  

#define MAX_BRAKE_PRESSURE 100
#define MIN_BRAKE_PRESSURE


/**
 * @brief BrakeManager nesnesini başlatır.
 * 
 */
void BrakeManager_CTOR(void);

/**
 * @brief BrakeManager nesnesinin adresini döndürür
 * 
 */
BrakeManager_t* BrakeManager_GetInstance(void);


/**
 * @brief BrakeManager nesnesini public olarak kullanıma hazırlayan fonskiyon.
 * 
 */
void BrakeManager_ruInit(void);

/**
 * @brief Fren kontrol algoritmaları çalıştırılır.
 * 
 */
void BrakeManager_ruControl(void);

/**
 * @brief Fren nesnesi kendisini günceller.
 * 
 */
void BrakeManager_ruUpdateSelf(void);

#endif /* BRAKEMANAGER_PUBLIC_H */