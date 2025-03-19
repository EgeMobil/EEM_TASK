#include <stdio.h>
#include <stdint.h>
#include "AccelerationManager_Public.h"
#include "AccelerationManager_Private.h"


int main(void)
{
    AccelerationManager_Init();
    AccelerationManager_Update();
    AccelerationManager_Control();

    return 0;
}
