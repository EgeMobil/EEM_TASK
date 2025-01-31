/**
 * @file InterruptHandlerManager_ruInitialisation.c
 * @brief Implementation of the InterruptHandlerManager initialization runable.
 *
 * This function initializes the InterruptHandlerManager by reading GPIO pin states
 * and setting the initial pin states for Hall A, B, and C. It also updates the
 * corresponding interfaces with these initial values.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#include "InterruptHandlerManager_private.h"

/**
 * @brief InterruptHandlerManager initialization runable.
 *
 * This function performs the following tasks during initialization:
 * - Retrieves the singleton instance of the InterruptHandlerManager.
 * - Reads the current pin state for Hall A, B, and C.
 * - Sets the initial pin states based on the GPIO status.
 * - Sends the initial pin states to the corresponding interfaces.
 */
FUNC(void, InterruptHandlerMAnager_ruInitialisation)(void)
{
    dtInterruptHandlerManager_pinState currentPinState_A;
    dtInterruptHandlerManager_pinState currentPinState_B;
    dtInterruptHandlerManager_pinState currentPinState_C;

    /* Get Singleton Instance */
    dtInterruptHandlerManager* ihm = InterruptHandlerManager_GetInstance();

    /* Read GPIO Status */
    currentPinState_A = ihm->IGPIOStatus->readPinState(HALL_A_PORT, HALL_A_PIN);
    currentPinState_B = ihm->IGPIOStatus->readPinState(HALL_B_PORT, HALL_B_PIN);
    currentPinState_C = ihm->IGPIOStatus->readPinState(HALL_C_PORT, HALL_C_PIN);

    /* Set Hall A Pin State */
    if (GPIOSTATUS_PIN_SET == currentPinState_A)
    {
        ihm->setHallAPinState(HALLA_STATUS_HIGH);
    }
    else if (GPIOSTATUS_PIN_RESET == currentPinState_A)
    {
        ihm->setHallAPinState(HALLA_STATUS_LOW);
    }
    else
    {
        /* Defensive Coding */
    }

    /* Set Hall B Pin State */
    if (GPIOSTATUS_PIN_SET == currentPinState_B)
    {
        ihm->setHallBPinState(HALLB_STATUS_HIGH);
    }
    else if (GPIOSTATUS_PIN_RESET == currentPinState_B)
    {
        ihm->setHallBPinState(HALLB_STATUS_LOW);
    }
    else
    {
        /* Defensive Coding */
    }

    /* Set Hall C Pin State */
    if (GPIOSTATUS_PIN_SET == currentPinState_C)
    {
        ihm->setHallCPinState(HALLC_STATUS_HIGH);
    }
    else if (GPIOSTATUS_PIN_RESET == currentPinState_C)
    {
        ihm->setHallCPinState(HALLC_STATUS_LOW);
    }
    else
    {
        /* Defensive Coding */
    }

    /* Send Initial Pin States */
    ihm->IHALLA->writeStatus(ihm->getHallAPinState());
    ihm->IHALLB->writeStatus(ihm->getHallBPinState());
    ihm->IHALLC->writeStatus(ihm->getHallCPinState());
}
