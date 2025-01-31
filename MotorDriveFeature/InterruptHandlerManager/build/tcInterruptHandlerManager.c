#include "tcInterruptHandlerManager.h"

void tcInterruptHandlerManager(void)
{
    #ifndef defined(STM32G431xx)
    printf("InterruptHandlerManager \n");
    #endif

    /* CTOR */
    InterruptHandlerManager_CTOR();

    /* Get Singleton Instance For Test */   
    dtInterruptHandlerManager* manager = InterruptHandlerManager_GetInstance();  

    /* Read InterruptHandlerManager Status before Initialisation */
    #ifndef defined(STM32G431xx)
    printf("[PRE-INIT] %s \n", manager->toString());
    #endif

    GPIOStatusInterface.writePinState(GPIOSTATUS_PIN_RESET, IGPIOSTATUS_PORT_B, IGPIOSTATUS_PIN_6);
    GPIOStatusInterface.writePinState(GPIOSTATUS_PIN_RESET, IGPIOSTATUS_PORT_B, IGPIOSTATUS_PIN_7);
    GPIOStatusInterface.writePinState(GPIOSTATUS_PIN_RESET, IGPIOSTATUS_PORT_A, IGPIOSTATUS_PIN_5);

    InterruptHandlerManager_ruInitialisation();

    #ifndef defined(STM32G431xx)
    printf("[POST-INIT] %s \n", manager->toString());
    #endif

    // Initialize Hall sensor ports and pins
    const cmExtIrqPortName HALL_A_PORT = EXTIRQ_PORTNAME_GPIOB;
    const cmExtIrqPinName HALL_A_PIN = EXTIRQ_PINNAME_6;
    const cmExtIrqPortName HALL_B_PORT = EXTIRQ_PORTNAME_GPIOB;
    const cmExtIrqPinName HALL_B_PIN = EXTIRQ_PINNAME_7;
    const cmExtIrqPortName HALL_C_PORT = EXTIRQ_PORTNAME_GPIOA;
    const cmExtIrqPinName HALL_C_PIN = EXTIRQ_PINNAME_5;

    // Simulate six-step commutation pattern
    const char* hall_codes[] = {"100", "110", "010", "011", "001", "101"};

    for (int step = 0; step < 6; step++)
    {
        #ifndef defined(STM32G431xx)
        printf("\nStep %d: Hall Code: %s\n", step + 1, hall_codes[step]);
        #endif

        // Simulate rising and falling edges for Hall sensors based on the current step
        switch (step)
        {
            case 0: // Hall code 100
                ExternalInterruptInterface.writePortName(HALL_A_PORT);
                ExternalInterruptInterface.writePinName(HALL_A_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_B_PORT);
                ExternalInterruptInterface.writePinName(HALL_B_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_C_PORT);
                ExternalInterruptInterface.writePinName(HALL_C_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();
                break;

            case 1: // Hall code 110
                ExternalInterruptInterface.writePortName(HALL_A_PORT);
                ExternalInterruptInterface.writePinName(HALL_A_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_B_PORT);
                ExternalInterruptInterface.writePinName(HALL_B_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_C_PORT);
                ExternalInterruptInterface.writePinName(HALL_C_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();
                break;

            case 2: // Hall code 010
                ExternalInterruptInterface.writePortName(HALL_A_PORT);
                ExternalInterruptInterface.writePinName(HALL_A_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_B_PORT);
                ExternalInterruptInterface.writePinName(HALL_B_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_C_PORT);
                ExternalInterruptInterface.writePinName(HALL_C_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();
                break;

            case 3: // Hall code 011
                ExternalInterruptInterface.writePortName(HALL_A_PORT);
                ExternalInterruptInterface.writePinName(HALL_A_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_B_PORT);
                ExternalInterruptInterface.writePinName(HALL_B_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_C_PORT);
                ExternalInterruptInterface.writePinName(HALL_C_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();
                break;

            case 4: // Hall code 001
                ExternalInterruptInterface.writePortName(HALL_A_PORT);
                ExternalInterruptInterface.writePinName(HALL_A_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_B_PORT);
                ExternalInterruptInterface.writePinName(HALL_B_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_C_PORT);
                ExternalInterruptInterface.writePinName(HALL_C_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();
                break;

            case 5: // Hall code 101
                ExternalInterruptInterface.writePortName(HALL_A_PORT);
                ExternalInterruptInterface.writePinName(HALL_A_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_B_PORT);
                ExternalInterruptInterface.writePinName(HALL_B_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_FALLINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();

                ExternalInterruptInterface.writePortName(HALL_C_PORT);
                ExternalInterruptInterface.writePinName(HALL_C_PIN);
                ExternalInterruptInterface.writeTriggerType(EXTIRQ_TRIGGERTYPE_RISINGEDGE);
                InterruptHandlerManager_ruExternalTrigger();
                break;
        }

        // Print state after each step
        #ifndef defined(STM32G431xx)
        printf("%s \n", manager->toString());
        #endif
    }

    #ifndef defined(STM32G431xx)
    printf("Six-Step Commutation Test Completed.\n");
    #endif

    return;
}
