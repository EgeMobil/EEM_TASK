#ifndef ELEVATOR_CONTROL_SYSTEM_H
#define ELEVATOR_CONTROL_SYSTEM_H

#include <stdio.h>


typedef enum
{
    SM_ELEVATOR_WAIT,
    SM_ELEVATOR_ENTERING_DOOR_OPENING,
    SM_ELEVATOR_FLOOR_SELECTION,
    SM_ELEVATOR_MOVEMENT,
    SM_ELEVATOR_EXITING_DOOR_OPENING,
}en_state_machine_step;

void elevatorControlSystem(void);
void elevatorControlSystem_init(void);


#endif /* ELEVATOR_CONTROL_SYSTEM_H */