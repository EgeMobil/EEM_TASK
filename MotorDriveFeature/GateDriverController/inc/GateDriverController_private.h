#ifndef GATEDRIVERCONTROLLER_PRIVATE_H_
#define GATEDRIVERCONTROLLER_PRIVATE_H_

/* Gate Driver definition include */
#include "GateDriverController_definition.h"

/* Constructor Prototype */
void GateDriverController_CTOR(void);

/* Singelton base class getter prototype */
dtGateDriverController* GateDriverController_GetInstance(void);

/* Runables */
FUNC(void, GateDriverController_ruInitialisation)(void);
FUNC(void, GateDriverController_ruRefresh)(void);

#endif /* GATEDRIVERCONTROLLER_PRIVATE_H_ */