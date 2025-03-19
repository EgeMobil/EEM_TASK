

#include "MotorDriverDcmProxy_private.h"
/** 
 * @file MotorDriverDcmProxy_ruCollect.c
 * @brief Collects the motor driver error data.
 * 
 * This function collects error data related to the motor driver and updates the 
 * internal error states (PWM, BDR, GDR, IRQ, Speed). Currently, the error reading 
 * functionality is commented out but it will eventually read and update errors 
 * related to the motor driver using the `IMotorDriveError` interface.
 * 
 * @note The function implementation is currently commented out and will be 
 *       finalized once the error reading logic is ready.
 */
FUNC(void, MotorDriverDcmProxy_ruCollect)(void)
{
    ///* Get Singleton Instance */
    //dtMotorDriverDcmProxy* mdp = MotorDriverDcmProxy_GetInstance();
//
    ///* Read And update Errors */
    //mdp->setPwmError( mdp->IMotorDriveError->readMotorDriveError().pwm );
    //mdp->setBdrError( mdp->IMotorDriveError->readMotorDriveError().bdr );
    //mdp->setGdrError( mdp->IMotorDriveError->readMotorDriveError().gdr );
    //mdp->setIrqError( mdp->IMotorDriveError->readMotorDriveError().irq );
    //mdp->setSpeedError( mdp->IMotorDriveError->readMotorDriveError().irq );
}
