#ifndef MOTORDRIVERDCMPROXY_PRIVATE_H_
#define MOTORDRIVERDCMPROXY_PRIVATE_H_

/* CompName definition include */
#include "MotorDriverDcmProxy_definition.h"

/* Constructor Prototype */
dtMotorDriverDcmProxy* MotorDriverDcmProxy_GetInstance(void);

/* Singelton base class getter prototype */
void MotorDriverDcmProxy_CTOR(void);

/* Runables */
FUNC(void, MotorDriverDcmProxy_ruRefresh)(void);
FUNC(void, MotorDriverDcmProxy_ruCollect)(void);

#endif /* MOTORDRIVERDCMPROXY_PRIVATE_H_ */