#ifndef MOTORDRIVERDCMPROXY_PUBLIC_H_
#define MOTORDRIVERDCMPROXY_PUBLIC_H_

/* Include the public definition header */
#include "MotorDriverDcmProxy_definition.h"

/* Constructor Prototype */
extern dtMotorDriverDcmProxy* MotorDriverDcmProxy_GetInstance(void);

/* Singelton base class getter prototype */
extern void MotorDriverDcmProxy_CTOR(void);

/* Runable Prototypes for public access */
FUNC(void, MotorDriverDcmProxy_ruRefresh)(void);
FUNC(void, MotorDriverDcmProxy_ruCollect)(void);

#endif /* MOTORDRIVERDCMPROXY_PUBLIC_H_ */