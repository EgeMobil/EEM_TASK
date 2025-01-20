#include "InterruptHandlerManager_private.h"

FUNC(void, InterruptHandlerMAnager_ruInitialisation)(void)
{
    dtInterruptHandlerManager_pinState currentPinState_A;
    dtInterruptHandlerManager_pinState currentPinState_B;
    dtInterruptHandlerManager_pinState currentPinState_C;

    /* Get Singleton Instance */
    dtInterruptHandlerManager* ihm = InterruptHandlerManager_GetInstance();

    /* Read GPIO Status*/
    currentPinState_A = ihm->IGPIOStatus->readPinState(HALL_A_PORT,HALL_A_PIN);
    currentPinState_B = ihm->IGPIOStatus->readPinState(HALL_B_PORT,HALL_B_PIN);
    currentPinState_C = ihm->IGPIOStatus->readPinState(HALL_C_PORT,HALL_C_PIN);

    if( GPIOSTATUS_PIN_SET == currentPinState_A )
    {
        ihm->setHallAPinState(HALLA_STATUS_HIGH);
    }
    else if( GPIOSTATUS_PIN_RESET == currentPinState_A)
    {
        ihm->setHallAPinState(HALLA_STATUS_LOW);
    }
    else
    {
        /* Defensive Coding */
    }

    if( GPIOSTATUS_PIN_SET == currentPinState_B )
    {
        ihm->setHallBPinState(HALLA_STATUS_HIGH);
    }
    else if( GPIOSTATUS_PIN_RESET == currentPinState_B)
    {
        ihm->setHallBPinState(HALLA_STATUS_LOW);
    }
    else
    {
        /* Defensive Coding */
    }

    if( GPIOSTATUS_PIN_SET == currentPinState_C )
    {
        ihm->setHallCPinState(HALLA_STATUS_HIGH);
    }
    else if( GPIOSTATUS_PIN_RESET == currentPinState_C)
    {
        ihm->setHallCPinState(HALLA_STATUS_LOW);
    }
    else
    {
        /* Defensive Coding */
    }

    /* Send Initial Pin States */
    ihm->IHALLA->writeStatus( ihm->getHallAPinState() );
    ihm->IHALLB->writeStatus( ihm->getHallBPinState() );
    ihm->IHALLC->writeStatus( ihm->getHallCPinState() );


}