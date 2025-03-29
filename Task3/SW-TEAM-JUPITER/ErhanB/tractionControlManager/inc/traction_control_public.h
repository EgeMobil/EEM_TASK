#ifndef TRACTION_CONTROL_PUBLIC_H_
#define TRACTION_CONTROL_PUBLIC_H_

#include "definition.h"

extern TcsInitStatus_t traction_enable(TractionControlHandle_t *tcsHandle);
extern TcsInitStatus_t traction_disable(TractionControlHandle_t *tcsHandle);
extern TcsStatus_t traction_get_status(TractionControlHandle_t *tcsHandle);
extern void tcs_init(void);
extern void tcs_control(void);

#endif
