
#include "InterruptHandlerManager_private.h"

FUNC(void, InterruptHandlerManager_ruTimerTrigger)(void)
{
    /* Get Singleton Instance */
    dtInterruptHandlerManager* ihm = InterruptHandlerManager_GetInstance();

    /* Read time */
    ihm->getTimerIrq().setMillisecond( ihm->ITimerInterruptStatus->readMillisecond() );

}