#include "tcInterruptHandlerManager.h"

void tcInterruptHandlerManager(void)
{
    printf("InterruptHandlerManager \n");

    /* CTOR */
    InterruptHandlerManager_CTOR();

    /* Get Singelton Instance For Test*/   
    dtInterruptHandlerManager* manager = InterruptHandlerManager_GetInstance();  

    /* Read InterruptHandlerManager Status before Initialisation */
    printf("[PRE-INIT] %s \n", manager->toString() );

    /* Check IRQ comes from which line */
    ExternalInterruptInterface.writePortName(PORTNAME_GPIOA);
    ExternalInterruptInterface.writePinName(PINNAME_3);
    ExternalInterruptInterface.writeTriggerType(TRIGGERTYPE_RISINGEDGE);
printf("1\n");
    InterruptHandlerManager_ruExternalTrigger();
printf("2\n");
    printf("[POST-INIT] %s \n", manager->toString() );

    /* Call InterruptHandlerManager ruRefresh 10 iteration */
    for(uint8_t i = 0 ; i < 25 ; i++)
    {
        


    }

    return;
}