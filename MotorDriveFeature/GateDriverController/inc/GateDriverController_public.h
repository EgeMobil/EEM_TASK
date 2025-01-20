#ifndef GATEDRIVERCONTROLLER_PUBLIC_H_
#define GATEDRIVERCONTROLLER_PUBLIC_H_

/* Include the public definition header */
#include "GateDriverController_definition.h"

/* Constructor external prototype for public access*/
extern void GateDriverController_CTOR(void);

/* Singelton Base Class Getter external prototype for public access*/
extern dtGateDriverController* GateDriverController_GetInstance(void);

/* Runable Prototypes for public access */
extern FUNC(void, GateDriverController_ruInitialisation)(void);
extern FUNC(void, GateDriverController_ruRefresh)(void);

#endif /* GATEDRIVERCONTROLLER_PUBLIC_H_ */