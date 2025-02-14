#include "tcGateDriverController.h"

void tcGateDriverController(void)
{
#ifndef defined(STM32G431xx)
    printf("[GateDriverController] \n");
#endif

    /* CTOR */
    GateDriverController_CTOR();

    /* Get Singleton Instance For Test */
    dtGateDriverController* manager = GateDriverController_GetInstance();

    /* Read GateDriverController Status before Initialisation */
#ifndef defined(STM32G431xx)
    printf("[PRE-INIT] %s \n", manager->toString());
#endif

    GateDriverController_ruInitialisation();

#ifndef defined(STM32G431xx)
    printf("[POST-INIT] %s \n", manager->toString());
#endif

    for(int i = 0; i < 2; i++)
    {
        GateDriverController_ruRefresh();

#ifndef defined(STM32G431xx)
        printf("[%d] %s \n", i, manager->toString());
#endif
    }
}
