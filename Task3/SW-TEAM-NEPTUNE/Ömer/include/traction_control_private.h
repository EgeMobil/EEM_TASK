#ifndef TRACTION_CONTROL_PRIVATE_H
#define TRACTION_CONTROL_PRIVATE_H

#include <stdint.h>
#include "traction_control_definition.h"
#include "traction_control_public.h"

void TCS_Manager_CTOR(void);


extern TCS_Manager* TCS_Manager_GetInstance();

#endif
