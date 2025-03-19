#include "tcMotorDriverControlManager.h"

void tcMotorDriverControlManager(void)
{
    #ifndef STM32G4xx
    printf("MotorDriverControlManager \n");
    #endif

    /* CTOR */
    MotorDriverControlManager_CTOR();

    /* Get Singleton Instance For Test */
    dtMotorDriverControlManager* manager = MotorDriverControlManager_GetInstance();

    /* Read MotorDriverControlManager Status before Initialisation */
    #ifndef STM32G4xx
    printf("[PRE-INIT] %s \n", manager->toString());
    #endif

    MotorDriverControlManager_ruInitialisation();

    #ifndef STM32G4xx
    printf("[POST-INIT] %s \n", manager->toString());
    #endif

    SpeedInterface.writeSpeed(0U);
    BdrInterface.writeBdr(0x0100);

    MotorDriverControlManager_ruRefresh();

    #ifndef STM32G4xx
    printf("[REFRESH:1] %s \n", manager->toString());
    #endif

    SpeedInterface.writeSpeed(1500U);
    BdrInterface.writeBdr(0x0000);

    MotorDriverControlManager_ruRefresh();

    #ifndef STM32G4xx
    printf("[REFRESH:2] %s \n", manager->toString());
    #endif
}
