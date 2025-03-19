#ifndef BRAKECONTROLMANAGER_PUBLIC_H
#define BRAKECONTROLMANAGER_PUBLIC_H

#include "brakeControlManager_definition.h"

extern BrakeControlManager_t* brakeControlManager_GetInstance(void);
extern void brakeControlManager_ruRefresh(void);

#endif // BRAKECONTROLMANAGER_PUBLIC_H
