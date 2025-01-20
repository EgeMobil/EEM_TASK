#include "tcMotorDriverControlManager.h"

void tcMotorDriverControlManager(void)
{
    printf("MotorDriverControlManager \n");

    /* CTOR */
    MotorDriverControlManager_CTOR();

    /* Get Singelton Instance For Test */
    dtMotorDriverControlManager* manager = MotorDriverControlManager_GetInstance();

    /* Read MotorDriverControlManager Status before Initialisation */
    printf("[PRE-INIT] %s \n", manager->toString() );

    MotorDriverControlManager_ruInitialisation();

    printf("[POST-INIT] %s \n", manager->toString() );

    SpeedInterface.writeSpeed(0U);
    BdrInterface.writeBdr(0x0100);

    MotorDriverControlManager_ruRefresh();

    printf("[REFRESH:1] %s \n", manager->toString() );

    SpeedInterface.writeSpeed(1500U);
    BdrInterface.writeBdr(0x0000);

    MotorDriverControlManager_ruRefresh();
    printf("[REFRESH:2] %s \n", manager->toString() );

}