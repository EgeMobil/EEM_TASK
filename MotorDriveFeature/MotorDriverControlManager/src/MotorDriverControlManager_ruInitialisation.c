/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "MotorDriverControlManager_private.h"

FUNC(void, MotorDriverControlManager_ruInitialisation)(void)
{
    /* Initial values */      
    dtMotorDriverControlManager_RawSpeedStatus  initSpeed = 0U;
    dtMotorDriverControlManager_BrakeStatus     initBrake = BRAKE_DISABLE;
    dtMotorDriverControlManager_DirectionStatus initDirection = DIRECTION_FORWARD;

    /* Get Singleton Instance */
    dtMotorDriverControlManager* mdc = MotorDriverControlManager_GetInstance();

    /* Send initial values */
    mdc->setRawSpeedStatus(initSpeed);
    mdc->setBrakeStatus(initBrake);
    mdc->setDirectionStatus(initDirection);

    /* Send initial speed, brake and direction*/
    mdc->IRawSpeed->writeRawSpeed( mdc->getRawSpeedStatus() );
    mdc->IBrakeAndDirection->writeBrake( mdc->getBrakeStatus() );
    mdc->IBrakeAndDirection->writeDirection( mdc->getDirectionStatus() );

}
