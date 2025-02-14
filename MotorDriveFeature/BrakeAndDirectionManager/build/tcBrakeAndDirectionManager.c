#include "tcBrakeAndDirectionManager.h"

void tcBrakeAndDirectionManager(void)
{
#ifndef defined(STM32G431xx)
    printf("BrakeAndDirectionManager \n");
#endif

    /* CTOR */
    BrakeAndDirectionManager_CTOR();

    /* Get Singelton Instance For Test*/
    dtBrakeAndDirectionManager* manager = BrakeAndDirectionManager_GetInstance();

    /* Read BrakeAndDirectionManager Status before Initialisation */
#ifndef defined(STM32G431xx)
    printf("[PRE-INIT] %s \n", manager->toString());
#endif

    /* Initalize BrakeAndDirectionManager */
    BrakeAndDirectionManager_ruInitialistaion();

    /* Read BrakeAndDirectionManager Status after Initialisation */
#ifndef defined(STM32G431xx)
    printf("[POST-INIT] %s \n", manager->toString());
#endif

    /* Call BrakeAndDirectionManager ruRefresh 5 iteration */
    for(uint8_t i = 0; i < 25; i++)
    {
#ifndef defined(STM32G431xx)
        printf("[ruRefresh iteration = %d ]\n", i);
#endif

        /* Frene basılı olmadığı için yön değişmeyecek*/
        if(i == 2)
        {
            /* İstek surekli gonderiliyor. Her iterasyonda sifirlanmiyor. */
            BrakeAndDirectionInterface.writeDirection(DIRECTION_BACKWARD);
        }

        /* Frene basıldı - */
        if(i == 5)
        {
            BrakeAndDirectionInterface.writeBrake(BRAKE_ENABLE);
        }

        if(i == 7)
        {
            BrakeAndDirectionInterface.writeDirection(DIRECTION_FORWARD);
        }

        if(i == 10)
        {
            BrakeAndDirectionInterface.writeDirection(DIRECTION_BACKWARD);
        }

        /* Frenden ayak çekildi */
        if(i == 15)
        {
            BrakeAndDirectionInterface.writeBrake(BRAKE_DISABLE);
        }

        if(i == 20)
        {
            BrakeAndDirectionInterface.writeDirection(DIRECTION_FORWARD);
        }

        BrakeAndDirectionManager_ruUpdate();
        
        /* Print BrakeAndDirectionManager After ruUpdate */
#ifndef defined(STM32G431xx)
        printf("[%d] %s \n", i, manager->toString());
#endif
    }       
}
