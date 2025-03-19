#include <stdio.h> 
#include <string.h>
#include <unistd.h> 

typedef enum {
    WAITING,
    CARD_READING,
    VERIFICATION,
    DOOR_OPEN_CLOSE

}DoorState; 

#define VALID_CARD "12345"
#define VALID_PIN "54321"
#define MAX_INPUT_LENGTH 10

void handleDoorSte(DoorState *state) {
    char inputCard[MAX_INPUT_LENGTH];
    char inputPin[MAX_INPUT_LENGTH];

    switch (*state) {
        case WAITING:
            printf("Door is locked, waiting for card or PIN...\n");
            sleep(2);
            *state = CARD_READING;
            break;
}

case CARD_READING:
printf("Enter card number: ");
scanf("%9s", inputCard);  // Limited to 9 chars to prevent buffer overflow
printf("Enter PIN: ");
scanf("%9s", inputPin);
*state = VERIFICATION;
break;

case VERIFICATION:
if (strcmp(inputCard, VALID_CARD) == 0 && 
    strcmp(inputPin, VALID_PIN) == 0) {
    printf("Access! Door opening...\n");
    *state = DOOR_OPEN_CLOSE;
} else {
    printf("Invalid credentials! Please try again.\n");
    *state = WAITING;
}
sleep(2);
break;

case DOOR_OPEN_CLOSE:
printf("Door is open...\n");
sleep(5);
printf("Door closing...\n");
sleep(2);
*state = WAITING;
break;
}

int main() {
    DoorState state = WAITING; 

    while (1) {
        handleDoorState(&state);
    }

}