

#include <stdio.h>


/*
Problem Analysis: When a smoke is detected the system shall turn on alarm and make a call to a fire department 
 
States:
1. IDLE
2. SMOKE_DETECT
3. ALARM
4. CALL_FIRE_DEPARTEMENT

Events:
1. System Activated
2. Smoke Detected

Transitions:
1. IDLE -> SMOKE_DETECT,                            Trigger: System activation button pressed.
2. SMOKE_DETECT -> ALARM,                           Trigger: when the system detects smoke.
3. SMOKE_DETECT -> CALL_FIRE_DEPARTEMENT,           Trigger: when the system detects smoke. 


Actions:


*/


typedef enum {
    IDLE = 0,
    SMOKE_DETECT,
    ALARM,
    CALL_FIRE_DEPARTEMENT
} SystemState;


typedef enum {
    BUTTON_RELEASED = 0,
    BUTTON_PRESSED
} ButtonStatus;

void detectSmoke(){
    printf("Smoke detected! Initiating emergency response\n");
}


void updateSystemState(SystemState *state) {
    switch(*state) {
        case IDLE:
            printf("System is idle. Waiting for activation \n");
            break;
            
        case SMOKE_DETECT:
            printf("System activated! Monitoring for smoke\n");
            
            detectSmoke();
            *state = ALARM;  // Transition to ALARM state
            break;
            
        case ALARM:
            printf("Alarm activated!\n");
            *state = CALL_FIRE_DEPARTEMENT;  // Transition to calling fire department
            break;
            
        case CALL_FIRE_DEPARTEMENT:
            printf("Calling fire department...\n");
            break;
            
        default:
            printf("Fault in system state!\n");
            break;
    }
}


int main()
{
    

    
    while(1){
        ButtonStatus currentButtonStatus = BUTTON_PRESSED;
    SystemState  currentSystemState  = IDLE;
    
    char input;
    
    // Starting with IDLE state.
    updateSystemState(&currentSystemState);
    
    printf("\nPress 'a' to activate the system: ");
    input = getchar();
    while(getchar() != '\n'); 
    
    if (input == 'a' || input == 'A') {
        currentButtonStatus = BUTTON_PRESSED;
        // Transition from IDLE to SMOKE_DETECT on activation.
        currentSystemState = SMOKE_DETECT;
        updateSystemState(&currentSystemState);
    }
    
    // call updateSystemState to transition to alarm state
    updateSystemState(&currentSystemState);
    
    // calling again to transition to call fire department
    updateSystemState(&currentSystemState);
        
    
    
    }
   

    return 0;
}










