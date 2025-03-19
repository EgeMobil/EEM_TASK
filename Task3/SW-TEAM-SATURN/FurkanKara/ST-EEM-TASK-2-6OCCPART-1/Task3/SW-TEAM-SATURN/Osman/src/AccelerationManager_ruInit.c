#include "AccelerationManager_Definition.h"
#include "AccelerationManager_Private.h"
#include "AccelerationManager_Public.h"
#include <stdio.h>


/* Functional Behaviour Implementation */
void AccelerationManager_Init(void)
{
    printf("Acceleration Manager has been initialized\n");
    AccelerationManager_Ctor();
}

