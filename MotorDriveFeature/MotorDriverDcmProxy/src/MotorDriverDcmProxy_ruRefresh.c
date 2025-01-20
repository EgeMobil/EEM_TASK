/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "MotorDriverDcmProxy_private.h"

FUNC(void, MotorDriverDcmProxy_ruRefresh)(void)
{
    /* Get Singleton Instance */
    dtMotorDriverDcmProxy* mdp = MotorDriverDcmProxy_GetInstance();

    /* Send Diag to current Error cases */
    //@LATER with diagnostics feature
    printf("Error's send into diag stack \n");

}
