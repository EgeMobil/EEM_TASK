#ifndef COMPNAME_PUBLIC_H_
#define COMPNAME_PUBLIC_H_

/* Include the public definition header */
#include "MotorDriverControlManager_definition.h"

/* Constructor external prototype for public access*/
extern void MotorDriverControlManager_CTOR(void);

/* Singelton Base Class Getter external prototype for public access*/
extern dtMotorDriverControlManager* MotorDriverControlManager_GetInstance(void);

/* Runable Prototypes for public access */
extern FUNC(void, MotorDriverControlManager_ruInitialisation)(void);
extern FUNC(void, MotorDriverControlManager_ruRefresh)(void);

#endif /* COMPNAME_PUBLIC_H_ */