#include "tcMotorDriverCommProxy.h"

void tcMotorDriverCommProxy(void)
{
    printf(" MotorDriverCommProxy \n");

    /* CTOR */
    MotorDriverCommProxy_CTOR();

    /* Get Singelton Instance For Test */
    dtMotorDriverCommProxy* manager = MotorDriverCommProxy_GetInstance();

    printf("[BEFORE UPDATE] %s \n", manager->toString() );

    cmIndicatorBdrStatus bdrTest;
    bdrTest.brakeStatus = BRAKE_DISABLE;
    bdrTest.directionStatus = DIRECTION_FORWARD;
    cmIndicatorSpeedStatus speedTest = INDICATORSPEEDSTATUS_HIGHSPEED;

    IndicatorBdrStatusInterface.writeIndicatorBdrStatus( bdrTest );
    IndicatorSpeedStatusInterface.writeIndicatorSpeedStatus( speedTest );

    MotorDriverCommProxy_ruUpdateIndicator();

    printf("[INDICATOR UPDATE] %s \n", manager->toString() );

    //@LATER
    //WheelSpeedInterface.writeWheelSpeed(1500);
    //MotorDriverCommProxy_ruUpdateWheelSpeed();
    //printf("[WHEEL SPEED UPDATE] %s \n", manager->toString() );

    /* Send Comm Manager Test */
    MotorDriverCommProxy_ruRefresh();

    printf("[AFTER UPDATE] %s \n", manager->toString() );
}