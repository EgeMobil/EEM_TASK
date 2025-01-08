/**
 * @file BrakeAndDirectionManager.c
 * @brief Implementation of the BrakeAndDirectionManager runable update function.
 * 
 * This function handles updates for the brake and direction statuses of the 
 * MotorDriverControlManager. It reads the current brake and direction statuses,
 * validates changes, updates configurations, and sends the status to the appropriate 
 * interfaces.
 *  
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#include "Abstract_MotorDriver.h"
#include "BrakeAndDirectionManager_private.h"

/**
 * @brief BrakeAndDirectionManager runable update function.
 * 
 * This function is responsible for managing the brake and direction statuses. It performs
 * the following tasks:
 * - Reads the brake and direction statuses from the MotorDriverControlManager.
 * - Checks and validates changes in the brake and direction statuses.
 * - Updates the configuration of the BrakeAndDirectionManager based on the new statuses.
 * - Sends the updated statuses to the corresponding interfaces.
 * - Provides error handling for unknown statuses.
 */
FUNC(void, BrakeAndDirectionManager_ruUpdate)(void)
{
    dtBrakeAndDirectionManager_bdrDirection currentDirection; /**< Current direction status. */
    dtBrakeAndDirectionManager_bdrBrake currentBrake;         /**< Current brake status. */

    /* Get Singleton Instance */
    dtBrakeAndDirectionManager* bdr = BrakeAndDirectionManager_GetInstance();

    /* Read Brake and Direction statuses from MotorDriverControlManager */
    currentBrake = bdr->IBrakeAndDirection->readBrake();
    currentDirection = bdr->IBrakeAndDirection->readDirection();

    /* Check Brake Status and apply updates */
    if (currentBrake != BRAKE_UNKNOWN)
    {
        if (bdr->getConfig().getBrake() == BRAKE_DISABLE && currentBrake == BRAKE_ENABLE)
        {
            bdr->getConfig().setBrake(BRAKE_ENABLE);
            /* Provide Backward IndicatorLamp @LATER */
        }
        else if (bdr->getConfig().getBrake() == BRAKE_ENABLE && currentBrake == BRAKE_DISABLE)
        {
            bdr->getConfig().setBrake(BRAKE_DISABLE);
            /* Provide Backward IndicatorLamp @LATER */
        }
        else
        {
            /* BrakeStatus has not changed */
            bdr->getConfig().setBrake(currentBrake);
        }

        /* Send Brake Status */
        bdr->IBrakeStatus->writeBrake(bdr->getConfig().getBrake());
    }
    else
    {
        /* Error Report Here - MotorDriverControlManager
           cannot provide unknown brake status. */

        /* Provide Error IndicatorLamp @LATER */
    }

    /* Check if Direction can change (only in stop case or reverse scenario) */
    if (currentDirection != DIRECTION_UNKNOWN && currentBrake == BRAKE_ENABLE /* Check Speed = 0 later */)
    {
        if (bdr->getConfig().getDirection() == DIRECTION_FORWARD && currentDirection == DIRECTION_BACKWARD)
        {
            bdr->getConfig().setDirection(DIRECTION_BACKWARD);
            /* Provide Backward IndicatorLamp @LATER */
        }
        else if (bdr->getConfig().getDirection() == DIRECTION_BACKWARD && currentDirection == DIRECTION_FORWARD)
        {
            bdr->getConfig().setDirection(DIRECTION_FORWARD);
            /* Provide Forward IndicatorLamp @LATER */
        }
        else
        {
            /* DirectionStatus has not changed */
            bdr->getConfig().setDirection(currentDirection);
        }

        /* Send Direction Status */
        bdr->IDirectionStatus->writeDirection(bdr->getConfig().getDirection());
    }
    else
    {
        /* Error Report Here - MotorDriverControlManager
           cannot provide unknown direction. */

        /* Provide Error IndicatorLamp @LATER */
    }
}
