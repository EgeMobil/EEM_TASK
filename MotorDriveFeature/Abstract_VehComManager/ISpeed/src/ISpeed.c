#include "ISpeed.h"

ISpeed SpeedInterface = {
    .writeSpeed = ISpeed_writeSpeed_Impl,
    .readSpeed = ISpeed_readSpeed_Impl,
};

static cmSpeed currentSpeed = 0;

/**
 * @brief Implementation for writing the speed.
 * @param speed Speed to write.
 * @return Status of the operation.
 */
ISpeed_StatusType ISpeed_writeSpeed_Impl(cmSpeed speed)
{
    // Speed constraints are assumed to be globally handled in the system.
    currentSpeed = speed;
#ifndef STM32G431xx
    printf("[ISpeed] Speed written: %u\n", speed);
    #endif
    return ISPEED_OK;
}

/**
 * @brief Implementation for reading the speed.
 * @return Current speed status.
 */
cmSpeed ISpeed_readSpeed_Impl(void)
{
#ifndef STM32G431xx
    printf("[ISpeed] Speed  read: %u\n", currentSpeed);
    #endif
    return currentSpeed;
}
