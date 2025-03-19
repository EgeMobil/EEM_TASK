#include "tcSpeedControlManager.h"

void tcSpeedControlManager(void)
{
    #ifndef STM32G4xx
    printf("SpeedControlManager\n");
    #endif

    // Constructor çağrısı
    SpeedControlManager_CTOR();

    // Singleton instance alma
    dtSpeedControlManager* scm = SpeedControlManager_GetInstance();
    if (scm == NULL)
    {
        #ifndef STM32G4xx
        printf("Error: SpeedControlManager_GetInstance returned NULL.\n");
        #endif
        return;
    }

    // Init öncesi toString okuma
    #ifndef STM32G4xx
    printf("[PRE-INIT] %s\n", scm->toString());
    #endif

    // Init runable çağırma
    SpeedControlManager_ruInitialisation();

    // Init sonrası toString okuma
    #ifndef STM32G4xx
    printf("[POST-INIT] %s\n", scm->toString());
    #endif

    // RawSpeed'i 2048 olarak ayarla
    RawSpeedInterface.writeRawSpeed(2048);

    // Hedef hızın normalize edildiğini kontrol et
    SpeedControlManager_ruUpdate();

    #ifndef STM32G4xx
    printf("[UPDATE] Target Speed (Normalized): %d\n", scm->config.targetSpeed);
    #endif

    // Hızlanma testleri
    #ifndef STM32G4xx
    printf("[TEST] Starting acceleration  test...\n");
    #endif

    for (uint8_t i = 0; i < 100; i++) // 100 iterasyon örnek olarak seçildi
    {
        SpeedControlManager_ruRefresh(); // Hız güncelleme işlemi
        #ifndef STM32G4xx
        printf("[Iteration %d] %s \n", i, scm->toString());
        #endif

        if(i == 30)
        {
            scm->getConfig().setBrake(BRAKE_ENABLE);
        }
        else if(i == 35)
        {
            scm->getConfig().setBrake(BRAKE_DISABLE);
        }
    }

    // Yavaşlama testi
    #ifndef STM32G4xx
    printf("[TEST] Starting  deceleration test...\n");
    #endif
    // Yeni bir test: hedef hızı düşür ve tekrar kontrol et
    #ifndef STM32G4xx
    printf("[TEST] Reducing target speed...\n");
    #endif
    scm->IRawSpeed->writeRawSpeed(1024); // Yeni hedef hız ayarla (örneğin, 1024)

    SpeedControlManager_ruUpdate();
    
    #ifndef STM32G4xx
    printf("[UPDATE] New Target Speed (Normalized): %d\n", scm->config.targetSpeed);
    #endif

    for (uint8_t i = 0; i < 100; i++)
    {
        SpeedControlManager_ruRefresh(); // Hız güncelleme işlemi
        #ifndef STM32G4xx
        printf("[Iteration %d] %s \n", i, scm->toString());
        #endif
    }
}
