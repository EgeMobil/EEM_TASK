#ifndef PWMCONFIGURATION_PUBLIC_H_
#define PWMCONFIGURATION_PUBLIC_H_

/* Include the public definition header */
#include "PWMConfiguration_definition.h"

/* Constructor external prototype for public access*/
void PWMConfiguration_CTOR(void);

/* Singelton Base Class Getter external prototype for public access*/
dtPWMConfiguration* PWMConfiguration_GetInstance(void);

/* Runable Prototypes for public access */
extern FUNC(void, PWMConfiguration_ruInitialisation)(void);
extern FUNC(void, PWMConfiguration_ruUpdate)(void);
extern FUNC(void, PWMConfiguration_ruRefresh)(void);

#endif /* PWMCONFIGURATION_PUBLIC_H_ */