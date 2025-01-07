/**
 * @file BrakeAndDirectionManager.c
 * @brief Implementation of the BrakeAndDirectionManager initialization runable.
 *
 * This function initializes the BrakeAndDirectionManager by setting the default
 * configuration values for brake and direction statuses. It also updates the 
 * corresponding interfaces with these initial values.
 */

#include "BrakeAndDirectionManager_private.h"

/**
 * @brief BrakeAndDirectionManager initialization runable.
 *
 * This function performs the following tasks during initialization:
 * - Retrieves the singleton instance of the BrakeAndDirectionManager.
 * - Sets the initial direction to `DIRECTION_FORWARD`.
 * - Sets the initial brake status to `BRAKE_DISABLE`.
 * - Updates the brake and direction statuses in the corresponding interfaces.
 */
FUNC(void, BrakeAndDirectionManager_ruInitialistaion)(void)
{
    /* Get Singleton Instance */
    dtBrakeAndDirectionManager* bdr = BrakeAndDirectionManager_GetInstance();

    /* Set Direction to Forward at startup */
    bdr->getConfig().setDirection(DIRECTION_FORWARD);

    /* Set Brake to Disable at startup */
    bdr->getConfig().setBrake(BRAKE_DISABLE);

    /* Update interface with the initial BrakeStatus */
    bdr->IBrakeStatus->writeBrake(bdr->getConfig().getBrake());

    /* Update interface with the initial DirectionStatus */
    bdr->IDirectionStatus->writeDirection(bdr->getConfig().getDirection());
}
