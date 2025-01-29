/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "MotorDriverControlManager_private.h"

FUNC(void, MotorDriverControlManager_ruRefresh)(void)
{
    /* Get Singleton Instance */
    dtMotorDriverControlManager* mdc = MotorDriverControlManager_GetInstance();

    /* Read Speed and Bdr from Communication Network Feature */
    mdc->setSpeed( mdc->ISpeed->readSpeed() );
    mdc->setBdr( mdc->IBdr->readBdr() );

    /* [byte-direction][byte-brake] */
    uint8_t highByte = (mdc->getBdr() >> 8) & 0xFF; // Üst byte
    uint8_t lowByte = mdc->getBdr() & 0xFF;         // Alt byte

    mdc->setDirectionStatus( (dtMotorDriverControlManager_DirectionStatus)highByte );
    mdc->setBrakeStatus( (dtMotorDriverControlManager_BrakeStatus)lowByte );
    mdc->setRawSpeedStatus( (dtMotorDriverControlManager_RawSpeedStatus)mdc->getSpeed() );

    /* Send Motor Driver Values */
    mdc->IRawSpeed->writeRawSpeed( mdc->getRawSpeedStatus() );
    mdc->IBrakeAndDirection->writeDirection( mdc->getDirectionStatus() );
    mdc->IBrakeAndDirection->writeBrake( mdc->getBrakeStatus() );

    /* Call Speed Update Event */
    SpeedControlManager_ruUpdate();
    
}
