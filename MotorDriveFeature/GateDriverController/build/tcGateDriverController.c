#include "tcGateDriverController.h"

void tcGateDriverController(void)
{
    printf("[GateDriverController] \n");

    /* CTOR */
    GateDriverController_CTOR();

    /* Get Singleton Instance For Test */
    dtGateDriverController* manager = GateDriverController_GetInstance();

    /* Read GateDriverController Status before Initialisation */
    printf("[PRE-INIT] %s \n", manager->toString() );

    GateDriverController_ruInitialisation();

    printf("[POST-INIT] %s \n", manager->toString());

    for(int i=0 ; i < 2 ; i++)
    {
        GateDriverController_ruRefresh();

        printf("[%d] %s \n", i, manager->toString());
    }

}