#ifndef COMPNAME_PRIVATE_H_
#define COMPNAME_PRIVATE_H_

/* CompName definition include */
#include "MotorDriverControlManager_definition.h"

/* Constructor Prototype */
void MotorDriverControlManager_CTOR(void);

/* Singelton base class getter prototype */
dtMotorDriverControlManager* MotorDriverControlManager_GetInstance(void);

/* Runables */
FUNC(void, MotorDriverControlManager_ruInitialisation)(void);
FUNC(void, MotorDriverControlManager_ruRefresh)(void);

#endif /* COMPNAME_PRIVATE_H_ */