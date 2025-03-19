#include "../Inc/BrakeManager_Def.h"
#include "../Inc/BrakeManager_Public.h"
#include "../Inc/BrakeManager_Private.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Fren yönetim modülünü başlatır.
 * 
 * Bu fonksiyon, BrakeManager modülünü başlatmak için çağrılır.
 * Singleton patternine uyum sağlamak amaçlı nesneden bir tane doğru şekilde oluşturulur.
 * 
 * 
 * @note Bu fonksiyon sistem başlatıldığında ilk çalıştırılmalıdır.
 */
void BrakeManager_ruInit(void){

        BrakeManager_GetInstance();
}