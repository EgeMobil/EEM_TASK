#ifndef TRACTION_CONTROL_PUBLIC_H
#define TRACTION_CONTROL_PUBLIC_H

#include <stdbool.h>

void Traction_enable();
void Traction_disable();
bool Traction_getStatus();
void TractionControl_update();

#endif // TRACTION_CONTROL_PUBLIC_H
