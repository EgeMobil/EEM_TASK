/**
 * @file InterruptHandlerManager_ruTimerTrigger.c
 * @brief Implementation of the InterruptHandlerManager Timer Trigger runable.
 *
 * This function handles the timer interrupt by retrieving the current millisecond
 * value from the interrupt status and updating the timer IRQ with the new value.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */
#include "InterruptHandlerManager_private.h"

/**
 * @brief InterruptHandlerManager Timer Trigger runable.
 *
 * This function performs the following tasks during a timer interrupt:
 * - Retrieves the singleton instance of the InterruptHandlerManager.
 * - Reads the current millisecond value from the timer interrupt status.
 * - Updates the timer IRQ with the new millisecond value.
 */
FUNC(void, InterruptHandlerManager_ruTimerTrigger)(void)
{
    /* Get Singleton Instance */
    dtInterruptHandlerManager* ihm = InterruptHandlerManager_GetInstance();

    /* Read time and update the timer IRQ */
    ihm->getTimerIrq().setMillisecond(ihm->ITimerInterruptStatus->readMillisecond());

    /* Time base-event management here */
}
