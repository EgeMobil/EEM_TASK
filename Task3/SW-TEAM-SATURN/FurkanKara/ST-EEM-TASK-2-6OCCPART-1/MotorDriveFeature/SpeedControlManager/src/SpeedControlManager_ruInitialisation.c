/**
 * @file SpeedControlManager_ruInitialistaion.c
 * @brief Implementation of the SpeedControlManager initialization runable.
 *
 * This function initializes the SpeedControlManager by setting the default 
 * configuration values for speed status and indicator. It also updates the 
 * corresponding interfaces with these initial values.
 * 
 * @author batu.murt
 * @date 23.01.2025
 */

#include "SpeedControlManager_private.h"

/**
 * @brief SpeedControlManager initialization runable.
 *
 * This function performs the following tasks during initialization:
 * - Retrieves the singleton instance of the SpeedControlManager.
 * - Sets the initial indicator to `INDICATORSPEEDSTATUS_IDLE`.
 * - Sets the initial speed status to `0`.
 * - Updates the indicator speed status interface with the initial value.
 * - Updates the speed status interface with the initial value.
 */
FUNC(void, SpeedControlManager_ruInitialisation)(void)
{
    /* Get Singleton Instance */
    dtSpeedControlManager* scm = SpeedControlManager_GetInstance();

    /* Set Indicator to Idle at startup */
    scm->getConfig().setIndicator(INDICATORSPEEDSTATUS_IDLE);

    /* Set Speed Status and Raw Speed to 0 at startup */
    scm->getConfig().setSpeedStatus(0);
    scm->getConfig().setRawSpeed(0);

    /* Update interface with the initial IndicatorSpeedStatus */
    scm->IIndicatorSpeedStatus->writeIndicatorSpeedStatus(scm->getConfig().getIndicator());

    /* Update interface with the initial SpeedStatus */
    scm->ISpeedStatus->writeSpeedStatus(scm->getConfig().getSpeedStatus());
}
