#include "tcBrakeAndDirectionManager.h"

void tcBrakeAndDirectionManager(void)
{
    printf("BrakeAndDirectionManager \n");

    /* CTOR */
    BrakeAndDirectionManager_CTOR();

    /* Get Singelton Instance For Test*/
    dtBrakeAndDirectionManager* manager = BrakeAndDirectionManager_GetInstance();

    /* Read BrakeAndDirectionManager Status before Initialisation */
    printf("[PRE-INIT] %s \n", manager->toString() );

    /* Initalize BrakeAndDirectionManager */
    BrakeAndDirectionManager_ruInitialistaion();

    /* Read BrakeAndDirectionManager Status after Initialisation */
    printf("[POST-INIT] %s \n", manager->toString() );

    /* Call BrakeAndDirectionManager ruRefresh 5 iteration */
    for(uint8_t i = 0 ; i < 25 ; i++)
    {
        printf("[ruRefresh iteration = %d ]\n" , i);

        /* Frene basılı olmadığı için yön değişmeyecek*/
        if( i==2 )
        {
            /* İstek surekli gonderiliyor. Her iterasyonda sifirlanmiyor.*/
            BrakeAndDirectionInterface.writeDirection(DIRECTION_BACKWARD);
        }

        /* Frene basildi - */
        if( i == 5 )
        {
            BrakeAndDirectionInterface.writeBrake(BRAKE_ENABLE);
        }

        if( i==7 )
        {
            BrakeAndDirectionInterface.writeDirection(DIRECTION_FORWARD);
        }

        if( i==10 )
        {
            BrakeAndDirectionInterface.writeDirection(DIRECTION_BACKWARD);
        }

        /* Frenden ayak çekildi */
         if( i == 15 )
        {
            BrakeAndDirectionInterface.writeBrake(BRAKE_DISABLE);
        }

        if( i==20 )
        {
            BrakeAndDirectionInterface.writeDirection(DIRECTION_FORWARD);
        }
        

        BrakeAndDirectionManager_ruUpdate();
        /* Print BrakeAndDirectionManager After ruUpdate*/
        printf("[%d] %s \n", i, manager->toString() );
    }       

}

