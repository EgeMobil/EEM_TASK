#include "tcMotorDriverControlManager.h"

void tcMotorDriverControlManager(void)
{
    #ifndef defined(STM32G431xx)
    printf("MotorDriverControlManager \n");
    #endif

    /* CTOR */
    MotorDriverControlManager_CTOR();

    /* Get Singleton Instance For Test */
    dtMotorDriverControlManager* manager = MotorDriverControlManager_GetInstance();

    /* Read MotorDriverControlManager Status before Initialisation */
    #ifndef defined(STM32G431xx)
    printf("[PRE-INIT] %s \n", manager->toString());
    #endif

    MotorDriverControlManager_ruInitialisation();

    #ifndef defined(STM32G431xx)
    printf("[POST-INIT] %s \n", manager->toString());
    #endif

    SpeedInterface.writeSpeed(0U);
    BdrInterface.writeBdr(0x0100);

    MotorDriverControlManager_ruRefresh();

    #ifndef defined(STM32G431xx)
    printf("[REFRESH:1] %s \n", manager->toString());
    #endif

    SpeedInterface.writeSpeed(1500U);
    BdrInterface.writeBdr(0x0000);

    MotorDriverControlManager_ruRefresh();

    #ifndef defined(STM32G431xx)
    printf("[REFRESH:2] %s \n", manager->toString());
    #endif
}
