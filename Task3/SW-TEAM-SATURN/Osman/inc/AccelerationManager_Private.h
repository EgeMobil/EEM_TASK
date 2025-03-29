#ifndef ACCELERATIONMANAGER_PRIVATE_H
#define ACCELERATIONMANAGER_PRIVATE_H


#include <stdint.h>

/* CompName definition include */
#include "AccelerationManager_Definition.h"

/* Constructor Prototype */
void AccelerationManager_Ctor(void);

/* Singelton base class getter prototype */
extern AccelerationManager_t* AccelerationManager_GetInstance(void);

/* Runables */



#endif // ACCELERATIONMANAGER_PRIVATE_H
