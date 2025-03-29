#include "AccelerationManager_Definition.h"
#include "AccelerationManager_Private.h"
#include "AccelerationManager_Public.h"
#include <stdio.h>

void AccelerationManager_Control(void)
{
    AccelerationManager_t* AccM = AccelerationManager_GetInstance();

    AccM->throttleToPower();
    AccM->powerToAcceleration();

    if (AccM->get_acceleration() > MAX_ACC_LIMIT)
    {
        AccM->set_acceleration(MAX_ACC_LIMIT);
    }

    else if (AccM->get_acceleration() < 0.0f)
    {
        AccM->set_acceleration(0.0f);
    }

    AccM->toString();
}


