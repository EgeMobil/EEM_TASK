#ifndef INTERFACE_H
#define INTERFACE_H
#include "system.h"
#include "application_helpers.h"

void Interface_Init(void);

void Interface_SendSpeedToDisplay(int speed);
void Interface_SendMotorCommand(MotorCommand command);




#endif // INTERFACE_H
