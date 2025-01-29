#include "ECUStateManager_private.h"

void ECUStateManager(void)
{
	for(int i=0; i<310 ; i++)
	{
		/* Infinite loop */
		ECU_StateMachine();
	}
}

#define TEST_HALL_A_PORT ((dtInterruptHandlerManager_portName)EXTIRQ_PORTNAME_GPIOB)
#define TEST_HALL_A_PIN  ((dtInterruptHandlerManager_pinName)EXTIRQ_PINNAME_6)

#define TEST_HALL_B_PORT ((dtInterruptHandlerManager_portName)EXTIRQ_PORTNAME_GPIOB)
#define TEST_HALL_B_PIN  ((dtInterruptHandlerManager_pinName)EXTIRQ_PINNAME_7)

#define TEST_HALL_C_PORT ((dtInterruptHandlerManager_portName)EXTIRQ_PORTNAME_GPIOA)
#define TEST_HALL_C_PIN  ((dtInterruptHandlerManager_pinName)EXTIRQ_PINNAME_5)


void ECU_StateMachine(void) 
{
    /* @DELETE : SIL TEST */
    
    /**************************************/
    if (systemStateCount == 120 ) 
    {
        BdrInterface.writeBdr(0x0101);
    }
    if (systemStateCount == 130 ) 
    {
        BdrInterface.writeBdr(0x0100);
    }

    if (systemStateCount == 10 ) 
    {
        SpeedInterface.writeSpeed(400);
    }
    else if(systemStateCount == 250 ) 
    {
        SpeedInterface.writeSpeed(0);
    }

     if (systemStateCount == 50 ) 
     {
        /* 1-0-0 changed into 1-1-0 */
        ExternalInterruptInterface.writePortName(TEST_HALL_B_PORT);
        ExternalInterruptInterface.writePinName(TEST_HALL_B_PIN);
        ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
        ECUStateManager_RunProcess(PROCESSSTATE_INTERRUPTHANDLERMANAGER_EXTERNALTRIGGER);
     }
    if (systemStateCount == 100 )
     {
        /* 1-1-0 changed into 0-1-0 */
        ExternalInterruptInterface.writePortName(TEST_HALL_A_PORT);
        ExternalInterruptInterface.writePinName(TEST_HALL_A_PIN);
        ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
        ECUStateManager_RunProcess(PROCESSSTATE_INTERRUPTHANDLERMANAGER_EXTERNALTRIGGER);
     }
    if (systemStateCount == 150 )
     {
        /* 0-1-0 changed into 0-1-1 */
        ExternalInterruptInterface.writePortName(TEST_HALL_C_PORT);
        ExternalInterruptInterface.writePinName(TEST_HALL_C_PIN);
        ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
        ECUStateManager_RunProcess(PROCESSSTATE_INTERRUPTHANDLERMANAGER_EXTERNALTRIGGER);
     }
     if (systemStateCount == 200 )
     {
        /* 0-1-1 changed into 0-0-1 */
        ExternalInterruptInterface.writePortName(TEST_HALL_B_PORT);
        ExternalInterruptInterface.writePinName(TEST_HALL_B_PIN);
        ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
        ECUStateManager_RunProcess(PROCESSSTATE_INTERRUPTHANDLERMANAGER_EXTERNALTRIGGER);
     }
     if (systemStateCount == 250 )
     {
        /* 0-0-1 changed into 1-0-1 */
        ExternalInterruptInterface.writePortName(TEST_HALL_A_PORT);
        ExternalInterruptInterface.writePinName(TEST_HALL_A_PIN);
        ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
        ECUStateManager_RunProcess(PROCESSSTATE_INTERRUPTHANDLERMANAGER_EXTERNALTRIGGER);
     }
     if (systemStateCount == 300 )
     {
        /* 1-0-1 changed into 1-0-0 Back to the start state */
        ExternalInterruptInterface.writePortName(TEST_HALL_C_PORT);
        ExternalInterruptInterface.writePinName(TEST_HALL_C_PIN);
        ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
        ECUStateManager_RunProcess(PROCESSSTATE_INTERRUPTHANDLERMANAGER_EXTERNALTRIGGER);
     }


    /**************************************/

    /* Sequence Count Increase for all step */
    systemStateCount++;

    /* Main State Machine */
    switch (ECU_STATE) 
    {
        case ECUSTATE_STARTUP:
            HandleStartupState();
            break;
        case ECUSTATE_INIT:
            HandleInitState();
            break;
        case ECUSTATE_ROUTINE:
            HandleRoutineState();
            break;
        case ECUSTATE_PROCESS:
            HandleProcessState();
            break;
        case ECUSTATE_SUSPEND:
            HandleSuspendState();
            break;
        default:
            
            ECU_STATE = ECUSTATE_ROUTINE; // Go back routine
            break;
    }

    ECUStateManager_toString();
}


#include "ECUStateManager_global.h"

// ECUStateManager_RunProcess: Tetiklenen process'i çalıştırır
void ECUStateManager_RunProcess(dtECUStateManager_processState processState)
{
    // ECU_STATE'i PROCESS durumuna ayarla
    ECU_STATE = ECUSTATE_PROCESS;
    // PROCESS_STATE'i ayarla
    PROCESS_STATE = processState;
}






