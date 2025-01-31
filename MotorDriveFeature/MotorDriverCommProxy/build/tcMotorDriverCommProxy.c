#include "tcMotorDriverCommProxy.h"

void tcMotorDriverCommProxy(void)
{
    #ifndef defined(STM32G431xx)
    printf(" MotorDriverCommProxy \n");
    #endif

    /* CTOR */
    MotorDriverCommProxy_CTOR();

    /* Get Singleton Instance For Test */
    dtMotorDriverCommProxy* manager = MotorDriverCommProxy_GetInstance();

    #ifndef defined(STM32G431xx)
    printf("[BEFORE UPDATE] %s \n", manager->toString());
    #endif

    cmIndicatorBdrStatus bdrTest;
    bdrTest.brakeStatus = BRAKE_DISABLE;
    bdrTest.directionStatus = DIRECTION_FORWARD;
    cmIndicatorSpeedStatus speedTest = INDICATORSPEEDSTATUS_HIGHSPEED;

    IndicatorBdrStatusInterface.writeIndicatorBdrStatus(bdrTest);
    IndicatorSpeedStatusInterface.writeIndicatorSpeedStatus(speedTest);

    MotorDriverCommProxy_ruUpdateIndicator();

    #ifndef defined(STM32G431xx)
    printf("[INDICATOR UPDATE] %s \n", manager->toString());
    #endif

    //@LATER
    //WheelSpeedInterface.writeWheelSpeed(1500);
    //MotorDriverCommProxy_ruUpdateWheelSpeed();
    //printf("[WHEEL SPEED UPDATE] %s \n", manager->toString());

    /* Send Comm Manager Test */
    MotorDriverCommProxy_ruRefresh();

    #ifndef defined(STM32G431xx)
    printf("[AFTER UPDATE] %s \n", manager->toString());
    #endif
}
