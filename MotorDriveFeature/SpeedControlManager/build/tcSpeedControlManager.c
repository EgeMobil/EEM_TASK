#include "tcSpeedControlManager.h"

void tcSpeedControlManager(void)
{
    printf("SpeedControlManager\n");

    // Constructor çağrısı
    SpeedControlManager_CTOR();

    // Singleton instance alma
    dtSpeedControlManager* scm = SpeedControlManager_GetInstance();
    if (scm == NULL)
    {
        printf("Error: SpeedControlManager_GetInstance returned NULL.\n");
        return;
    }

    // Init öncesi toString okuma
    printf("[PRE-INIT] %s\n", scm->toString());

    // Init runable çağırma
    SpeedControlManager_ruInitialistaion();

    // Init sonrası toString okuma
    printf("[POST-INIT] %s\n", scm->toString());

    // RawSpeed'i 2048 olarak ayarla
    RawSpeedInterface.writeRawSpeed(2048);

    // Hedef hızın normalize edildiğini kontrol et
    SpeedControlManager_ruUpdate();
    printf("[UPDATE] Target Speed (Normalized): %d\n", scm->config.targetSpeed);

    // Hızlanma ve yavaşlama testleri
    printf("[TEST] Starting acceleration and deceleration test...\n");

    for (uint8_t i = 0; i < 100; i++) // 100 iterasyon örnek olarak seçildi
    {
        SpeedControlManager_ruRefresh(); // Hız güncelleme işlemi

        printf("[Iteration %d] Current Speed: %d, Target Speed: %d\n", 
               i, scm->config.currentSpeed, scm->config.targetSpeed);

        if (scm->config.currentSpeed == scm->config.targetSpeed)
        {
            printf("[TEST] Target speed reached at iteration %d.\n", i);
            break;
        }
    }

    // Yeni bir test: hedef hızı düşür ve tekrar kontrol et
    printf("[TEST] Reducing target speed...\n");
    scm->IRawSpeed->writeRawSpeed(1024); // Yeni hedef hız ayarla (örneğin, 1024)

    SpeedControlManager_ruUpdate();
    printf("[UPDATE] New Target Speed (Normalized): %d\n", scm->config.targetSpeed);

    for (uint8_t i = 0; i < 100; i++)
    {
        SpeedControlManager_ruRefresh();

        printf("[Iteration %d] Current Speed: %d, Target Speed: %d\n", 
               i, scm->config.currentSpeed, scm->config.targetSpeed);

        if (scm->config.currentSpeed == scm->config.targetSpeed)
        {
            printf("[TEST] Target speed reached at iteration %d.\n", i);
            break;
        }
    }
}
