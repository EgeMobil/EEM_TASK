#include "tcMotorDriverDcmProxy.h"

void tcMotorDriverDcmProxy(void)
{
    printf("MotorDriverDcmProxy \n");

    /* CTOR */
    MotorDriverDcmProxy_CTOR();

    /* Get Singelton Instance For Test */
    dtMotorDriverDcmProxy* manager = MotorDriverDcmProxy_GetInstance();

    /* Read MotorDriverDcmProxy before collect errors */
    printf("[PRE-COLLECT] %s \n", manager->toString() );

    cmMotorDriveError testErr;
    testErr.bdr = 1;
    testErr.gdr = 0x15;
    testErr.irq = 0;
    testErr.pwm = 1;
    testErr.speed = 2;

    MotorDriveErrorInterface.writeMotorDriveError(testErr);

    MotorDriverDcmProxy_ruCollect();

    /* Read MotorDriverDcmProxy after collect errors */
    printf("[COLLECTED] %s \n", manager->toString() );

    /* Send to diag */
    MotorDriverDcmProxy_ruRefresh();

}