/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "MotorDriverCommProxy_private.h"

FUNC(void, MotorDriverCommProxy_ruUpdateWheelSpeed)(void)
{
    /* Get Singleton Instance */
    dtMotorDriverCommProxy* mdcp = MotorDriverCommProxy_GetInstance();

    static dtMotorDriverCommProxy_HALLWheelSpeed currentSpeed = 0;

    /* Read and update wheel speed pdu variables */
    currentSpeed = mdcp->IHALLWheelSpeed->readHALLWheelSpeed();
    
    /* Calculate Real speed on vehicle */
    //@LATER

    /* Update PDU */
    mdcp->setHWheelSpeed( currentSpeed ); 


}
