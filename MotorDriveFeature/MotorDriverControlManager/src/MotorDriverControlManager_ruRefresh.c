/** 
 * @file MotorDriverControlManager_ruRefresh.c
 * @brief Contains the private implementation of the MotorDriverControlManager, including the refresh function.
 */

/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "MotorDriverControlManager_private.h"

/** 
 * @brief Refreshes the MotorDriverControlManager system by reading updated values and sending them to the motor driver components.
 * This function updates the speed, brake, and direction values by reading them from the communication network and then writes the updated values to the motor driver components.
 */
FUNC(void, MotorDriverControlManager_ruRefresh)(void)
{
    /* Get Singleton Instance */
    dtMotorDriverControlManager* mdc = MotorDriverControlManager_GetInstance();

    /* Read Speed and Bdr from Communication Network Feature */
    mdc->setSpeed(mdc->ISpeed->readSpeed()); /**< Read speed from the ISpeed interface and set it */
    mdc->setBdr(mdc->IBdr->readBdr());       /**< Read brake and direction (Bdr) from the IBdr interface and set it */

    /* [byte-direction][byte-brake] */
    uint8_t highByte = (mdc->getBdr() >> 8) & 0xFF; /**< Extract the high byte (direction) */
    uint8_t lowByte = mdc->getBdr() & 0xFF;         /**< Extract the low byte (brake) */

    mdc->setDirectionStatus((dtMotorDriverControlManager_DirectionStatus)highByte); /**< Set direction status using the high byte */
    mdc->setBrakeStatus((dtMotorDriverControlManager_BrakeStatus)lowByte);         /**< Set brake status using the low byte */
    mdc->setRawSpeedStatus((dtMotorDriverControlManager_RawSpeedStatus)mdc->getSpeed()); /**< Set the raw speed status from the speed value */

    /* Send Motor Driver Values */
    mdc->IRawSpeed->writeRawSpeed(mdc->getRawSpeedStatus()); /**< Write the raw speed to the motor driver */
    mdc->IBrakeAndDirection->writeDirection(mdc->getDirectionStatus()); /**< Write the direction to the motor driver */
    mdc->IBrakeAndDirection->writeBrake(mdc->getBrakeStatus()); /**< Write the brake status to the motor driver */

    /* Call Speed Update Event */
    SpeedControlManager_ruUpdate(); /**< Update the speed control manager */
}

