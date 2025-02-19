#include "tcMotorDriverDcmProxy.h"

void tcMotorDriverDcmProxy(void)
{
    #ifndef STM32G4xx
    printf("MotorDriverDcmProxy \n");
    #endif

    /* CTOR */
    MotorDriverDcmProxy_CTOR();

    /* Get Singleton Instance For Test */
    dtMotorDriverDcmProxy* manager = MotorDriverDcmProxy_GetInstance();

    /* Read MotorDriverDcmProxy before collect errors */
    #ifndef STM32G4xx
    printf("[PRE-COLLECT] %s \n", manager->toString());
    #endif

    cmMotorDriveError testErr;
    testErr.bdr = 1;
    testErr.gdr = 0x15;
    testErr.irq = 0;
    testErr.pwm = 1;
    testErr.speed = 2;

    MotorDriveErrorInterface.writeMotorDriveError(testErr);

    MotorDriverDcmProxy_ruCollect();

    /* Read MotorDriverDcmProxy after collect errors */
    #ifndef STM32G4xx
    printf("[COLLECTED] %s \n", manager->toString());
    #endif

    /* Send to diag */
    MotorDriverDcmProxy_ruRefresh();
}
