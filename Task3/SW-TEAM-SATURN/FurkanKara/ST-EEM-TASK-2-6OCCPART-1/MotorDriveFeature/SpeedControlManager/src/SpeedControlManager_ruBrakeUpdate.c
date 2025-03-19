#include "SpeedControlManager_private.h"

FUNC(void, SpeedControlManager_ruBrakeUpdate)(void)
{
    // Get SpeedControlManager instance
    dtSpeedControlManager* scm = SpeedControlManager_GetInstance();

    // Read Brake Status
    scm->getConfig().setBrake( scm->IBrakeStatus->readBrake() );
}