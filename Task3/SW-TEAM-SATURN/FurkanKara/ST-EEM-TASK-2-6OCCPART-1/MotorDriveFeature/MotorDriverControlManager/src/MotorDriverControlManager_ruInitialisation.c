/** 
 * @file MotorDriverControlManager_ruInitialisation.c
 * @brief Contains the private implementation of the MotorDriverControlManager, including the initialization function.
 */

#include "MotorDriverControlManager_private.h"

/** 
 * @brief Initializes the MotorDriverControlManager system.
 * This function sets the initial values for speed, brake, and direction, then writes those values to the respective components.
 */
FUNC(void, MotorDriverControlManager_ruInitialisation)(void)
{
    /* Initial values */      
    dtMotorDriverControlManager_RawSpeedStatus  initSpeed = 0U;        /**< Initial speed value */
    dtMotorDriverControlManager_BrakeStatus     initBrake = BRAKE_DISABLE; /**< Initial brake status (disabled) */
    dtMotorDriverControlManager_DirectionStatus initDirection = DIRECTION_FORWARD; /**< Initial direction (forward) */

    /* Get Singleton Instance */
    dtMotorDriverControlManager* mdc = MotorDriverControlManager_GetInstance();

    /* Send initial values */
    mdc->setRawSpeedStatus(initSpeed); /**< Set initial speed status */
    mdc->setBrakeStatus(initBrake);    /**< Set initial brake status */
    mdc->setDirectionStatus(initDirection); /**< Set initial direction status */

    /* Send initial speed, brake and direction to respective hardware components */
    mdc->IRawSpeed->writeRawSpeed(mdc->getRawSpeedStatus()); /**< Write raw speed to hardware */
    mdc->IBrakeAndDirection->writeBrake(mdc->getBrakeStatus()); /**< Write brake status to hardware */
    mdc->IBrakeAndDirection->writeDirection(mdc->getDirectionStatus()); /**< Write direction status to hardware */
}
