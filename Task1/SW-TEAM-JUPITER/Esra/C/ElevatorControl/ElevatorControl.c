#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define MIN_FLOOR 0
#define MAX_FLOOR 5
#define DOOR_OPERATION_TIME 2
#define MOVEMENT_TIME 3

typedef enum {
    IDLE,
    FLOOR_SELECTION,
    DOOR_OPERATION,
    MOVING,
    REACHED_DESTINATION
} ElevatorState;

bool isValidFloor(int floor);
void clearInputBuffer(void);

void handleState(ElevatorState *state, int *currentFloor, int *targetFloor) {
    switch (*state) {
        case IDLE:
            printf("Elevator is idle. Waiting for floor selection...\n");
            sleep(DOOR_OPERATION_TIME);
            *state = FLOOR_SELECTION;
            break;

        case FLOOR_SELECTION:
            printf("Current floor: %d\n", *currentFloor);
            printf("Select floor (%d-%d): ", MIN_FLOOR, MAX_FLOOR);
            
            if (scanf("%d", targetFloor) != 1) {
                printf("Invalid input!\n");
                clearInputBuffer();
                *state = IDLE;
                break;
            }

            if (!isValidFloor(*targetFloor)) {
                printf("Invalid floor selection!\n");
                *state = IDLE;
            } else if (*targetFloor == *currentFloor) {
                printf("Already on this floor!\n");
                *state = IDLE;
            } else {
                *state = DOOR_OPERATION;
            }
            break;

        case DOOR_OPERATION:
            printf("Doors opening...\n");
            sleep(DOOR_OPERATION_TIME);
            printf("Doors closing...\n");
            sleep(DOOR_OPERATION_TIME);
            *state = MOVING;
            break;

        case MOVING:
            printf("Moving from floor %d to floor %d...\n", 
                   *currentFloor, *targetFloor);
            sleep(MOVEMENT_TIME);
            *currentFloor = *targetFloor;
            *state = REACHED_DESTINATION;
            break;

        case REACHED_DESTINATION:
            printf("Arrived at floor %d!\n", *currentFloor);
            sleep(DOOR_OPERATION_TIME);
            *state = DOOR_OPERATION;
            break;
    }
}

bool isValidFloor(int floor) {
    return floor >= MIN_FLOOR && floor <= MAX_FLOOR;
}

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    ElevatorState state = IDLE;
    int currentFloor = 0, targetFloor = 0;

 

    while (true) {
        handleState(&state, &currentFloor, &targetFloor);
    }


}