#include "../Inc/BrakeManager_Def.h"
#include "../Inc/BrakeManager_Public.h"
#include "../Inc/BrakeManager_Private.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Fren yönetim modülünü başlatır.
 * 
 * Bu fonksiyon, BrakeManager modülünü başlatmak için çağrılır.
 * İçerisinde, fren yönetim bileşeninin kurucu fonksiyonu (Constructor) olan
 * BrakeManager_CTOR() çağrılarak gerekli yapılandırmalar yapılır.
 * 
 * @note Bu fonksiyon sistem başlatıldığında ilk çalıştırılmalıdır.
 */
void BrakeManager_ruInit(void){

        BrakeManager_CTOR();
}