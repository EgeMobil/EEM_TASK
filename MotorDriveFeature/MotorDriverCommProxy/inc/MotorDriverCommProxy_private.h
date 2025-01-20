#ifndef MOTORDRIVERCOMMPROXY_PRIVATE_H_
#define MOTORDRIVERCOMMPROXY_PRIVATE_H_

/* CompName definition include */
#include "MotorDriverCommProxy_definition.h"

/* Constructor Prototype */
void MotorDriverCommProxy_CTOR(void);
/* Singelton base class getter prototype */
dtMotorDriverCommProxy* MotorDriverCommProxy_GetInstance(void);

/* Runables */
FUNC(void, MotorDriverCommProxy_ruRefresh)(void);
FUNC(void, MotorDriverCommProxy_ruUpdateIndicator)(void);
FUNC(void, MotorDriverCommProxy_ruUpdateWheelSpeed)(void);


#endif /* MOTORDRIVERCOMMPROXY_PRIVATE_H_ */