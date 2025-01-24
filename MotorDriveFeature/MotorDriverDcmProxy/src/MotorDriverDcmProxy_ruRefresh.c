/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "MotorDriverDcmProxy_private.h"

FUNC(void, MotorDriverDcmProxy_ruRefresh)(void)
{
    /* Get Singleton Instance */
    dtMotorDriverDcmProxy* mdp = MotorDriverDcmProxy_GetInstance();

    /* Read Erros from IF */
    mdp->setBdrError( mdp->IMotorDriveError->readMotorDriveError().bdr );
    mdp->setGdrError( mdp->IMotorDriveError->readMotorDriveError().gdr );
    mdp->setIrqError( mdp->IMotorDriveError->readMotorDriveError().irq );
    mdp->setPwmError( mdp->IMotorDriveError->readMotorDriveError().pwm );
    mdp->setSpeedError( mdp->IMotorDriveError->readMotorDriveError().speed );

    /* Send Diag to current Error cases */
    //@LATER with diagnostics feature
    printf("Error's send into diag stack \n");


    

}
