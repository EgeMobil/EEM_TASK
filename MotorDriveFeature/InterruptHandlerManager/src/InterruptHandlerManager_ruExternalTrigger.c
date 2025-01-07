
#include "InterruptHandlerManager_private.h"

FUNC(void, InterruptHandlerManager_ruExternalTrigger)(void)
{
    /* Read IRQ Comes from which line */

    /* Get Singleton Instance */
    dtInterruptHandlerManager* ihm = InterruptHandlerManager_GetInstance();

    /* Read port, pin and trigger type*/
    ihm->getExternalIrq().setPin( ihm->IExternalInterruptStatus->readPortName() );
    ihm->getExternalIrq().setPort( ihm->IExternalInterruptStatus->readPinName() );
    ihm->getExternalIrq().setTrigger( ihm->IExternalInterruptStatus->readTriggerType() );

}