#ifndef MOTORDRIVERCOMMPROXY_PUBLIC_H_
#define MOTORDRIVERCOMMPROXY_PUBLIC_H_

/* Include the public definition header */
#include "MotorDriverCommProxy_definition.h"

/* Constructor Prototype */
extern void MotorDriverCommProxy_CTOR(void);
/* Singelton base class getter prototype */
extern dtMotorDriverCommProxy* MotorDriverCommProxy_GetInstance(void);

/* Runable Prototypes for public access */
extern FUNC(void, MotorDriverCommProxy_ruRefresh)(void);
extern FUNC(void, MotorDriverCommProxy_ruUpdateIndicator)(void);
extern FUNC(void, MotorDriverCommProxy_ruUpdateWheelSpeed)(void);

#endif /* MOTORDRIVERCOMMPROXY_PUBLIC_H_ */