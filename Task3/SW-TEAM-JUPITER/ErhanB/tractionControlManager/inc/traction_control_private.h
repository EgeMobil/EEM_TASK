#ifndef TRACTION_CONTROL_PRIVATE_H_
#define TRACTION_CONTROL_PRIVATE_H_

#include "definition.h"

/*!> Reset slip for each wheel */
#define RESET_SLIP(WHEEL)           ( tcsHandle->slip_ratios[WHEEL] = 0.0f ) 

/*!> Reset speed for each wheel */
#define RESET_WHEEL_SPEED(WHEEL)    ( tcsHandle->wheel_speeds[WHEEL] = 0.0f )

/*!> Set speed for each wheel */
#define SET_WHEEL_SPEED(WHEEL, SPEED)      ( tcsHandle->wheel_speeds[WHEEL] = SPEED)

TcsInitStatus_t traction_enable(TractionControlHandle_t *tcsHandle);
TcsInitStatus_t traction_disable(TractionControlHandle_t *tcsHandle);
TcsStatus_t traction_get_status(TractionControlHandle_t *tcsHandle);
void tcs_init(TractionControlHandle_t *tcsHandle);
void tcs_control(TractionControlHandle_t *tcsHandle);
void tcs_ctor(TractionControlHandle_t *tcsHandle);

#endif
