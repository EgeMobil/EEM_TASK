#ifndef ACC_PUBLIC_H
#define ACC_PUBLIC_H

#include "definition.h"

ACC_Result ACC_init(void);
ACC_Result ACC_enable(void);
ACC_Result ACC_disable(void);
ACC_Result ACC_setSpeed(float speedKmh);
ACC_State ACC_getState(void);
float ACC_getSetSpeed(void);
ACC_Result ACC_update(void);

#endif 
