/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "MotorDriverCommProxy_private.h"

FUNC(void, MotorDriverCommProxy_ruRefresh)(void)
{
    /* Get Singleton Instance */
    dtMotorDriverCommProxy* mdcp = MotorDriverCommProxy_GetInstance();

    /* Forward PDU to Comm Line */
    mdcp->IIndicator->writeIndicator( mdcp->getIndicator() );
    mdcp->IHALLWheelSpeed->writeHALLWheelSpeed( mdcp->getHWheelSpeed() ); //@LATER

}
