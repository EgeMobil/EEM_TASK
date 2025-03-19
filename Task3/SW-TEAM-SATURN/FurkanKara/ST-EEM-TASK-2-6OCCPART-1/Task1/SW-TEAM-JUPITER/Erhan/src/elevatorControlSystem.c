#include  "elevatorControlSystem.h"


static en_state_machine_step state_machine_step;

static int floor_selection = 0;
static int Before_floor_selection = -1;

void elevatorControlSystem_init(void)
{
    state_machine_step = SM_ELEVATOR_WAIT;
}

void elevatorControlSystem(void)
{
    switch (state_machine_step)
    {
        case SM_ELEVATOR_WAIT:
            printf("The elevator is waiting. Please press the Enter key to use it.\n");
            getchar();
            while (getchar() != '\n');
            state_machine_step = SM_ELEVATOR_ENTERING_DOOR_OPENING;
        break;
    
        case SM_ELEVATOR_ENTERING_DOOR_OPENING:
            printf("The door is opening, and passengers are boarding.\n");
            state_machine_step = SM_ELEVATOR_FLOOR_SELECTION;
        break;
    
        case SM_ELEVATOR_FLOOR_SELECTION:
            printf("You can select a floor.\n");
            scanf("%d", &floor_selection);
            if (floor_selection == Before_floor_selection)
            {
                printf("You are already on this floor.\n");
                state_machine_step = SM_ELEVATOR_FLOOR_SELECTION;
                break;
            }
            Before_floor_selection = floor_selection;
            state_machine_step = SM_ELEVATOR_MOVEMENT;
            break;
    
        case SM_ELEVATOR_MOVEMENT:
            printf("The elevator is moving.\n");
            state_machine_step = SM_ELEVATOR_EXITING_DOOR_OPENING;
        break;
    
        case SM_ELEVATOR_EXITING_DOOR_OPENING:
            printf("The elevator has arrived at floor %d. The door is opening, and passengers are exiting.\n", floor_selection);
            state_machine_step = SM_ELEVATOR_WAIT;
        break;
    
        default:
            printf("An unexpected error has occurred.\n");
        break;
    }
}

