#include "tcGateDriverController.h"

void tcGateDriverController(void)
{
#ifndef STM32G4xx
    printf("[GateDriverController] \n");
#endif

    /* CTOR */
    GateDriverController_CTOR();

    /* Get Singleton Instance For Test */
    dtGateDriverController* manager = GateDriverController_GetInstance();

    /* Read GateDriverController Status before Initialisation */
#ifndef STM32G4xx
    printf("[PRE-INIT] %s \n", manager->toString());
#endif

    GateDriverController_ruInitialisation();

#ifndef STM32G4xx
    printf("[POST-INIT] %s \n", manager->toString());
#endif

    for(int i = 0; i < 2; i++)
    {
        GateDriverController_ruRefresh();

#ifndef STM32G4xx
        printf("[%d] %s \n", i, manager->toString());
#endif
    }
}
