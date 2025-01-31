#include "MotorDriverDcmProxy_private.h"

/** 
 * @file MotorDriverDcmProxy_ruRefresh.c
 * @brief Refreshes the motor driver error data and sends diagnostics.
 * 
 * This function refreshes the motor driver error data by reading error states 
 * from the motor drive interface (e.g., BDR, GDR, IRQ, PWM, Speed errors) and 
 * updating the internal error states. Afterward, it sends the diagnostic data 
 * regarding any current errors. The diagnostic feature is to be implemented later.
 * 
 * @note The error reading and diagnostic sending functionalities are currently 
 *       commented out. They will be integrated with the future diagnostic features.
 */
FUNC(void, MotorDriverDcmProxy_ruRefresh)(void)
{
    /* Get Singleton Instance */
    dtMotorDriverDcmProxy* mdp = MotorDriverDcmProxy_GetInstance();

    // /* Read Errors from IF */
    // mdp->setBdrError( mdp->IMotorDriveError->readMotorDriveError().bdr );
    // mdp->setGdrError( mdp->IMotorDriveError->readMotorDriveError().gdr );
    // mdp->setIrqError( mdp->IMotorDriveError->readMotorDriveError().irq );
    // mdp->setPwmError( mdp->IMotorDriveError->readMotorDriveError().pwm );
    // mdp->setSpeedError( mdp->IMotorDriveError->readMotorDriveError().speed );
// 
    // /* Send Diag to current Error cases */
    // //@LATER with diagnostics feature
    // printf("Error's send into diag stack \n");
}
