#include "IRawSpeed.h"

/**
 * @brief Instance of the IRawSpeed interface.
 */
IRawSpeed RawSpeedInterface = {
    .writeRawSpeed = IRawSpeed_writeRawSpeed_Impl,
    .readRawSpeed = IRawSpeed_readRawSpeed_Impl,
};

/* Static variable for storing current raw speed status */
static cmRawSpeedStatus currentRawSpeed = 0;

/**
 * @brief Implementation for writing the raw speed status.
 * @param rawSpeed Raw speed status to write.
 * @return Status of the operation.
 */
IRawSpeed_StatusType IRawSpeed_writeRawSpeed_Impl(cmRawSpeedStatus rawSpeed)
{
    // Example: Global constraints could be checked externally before calling this function.
    currentRawSpeed = rawSpeed;
#ifndef defined(STM32G431xx)
    printf("[IRawSpeed] Raw speed written: %u\n", rawSpeed);
#endif
    return IRAWSPEED_OK;
}

/**
 * @brief Implementation for reading the raw speed status.
 * @return Current raw speed status.
 */
cmRawSpeedStatus IRawSpeed_readRawSpeed_Impl(void)
{
#ifndef defined(STM32G431xx)
    printf("[IRawSpeed] Raw speed read: %u\n", currentRawSpeed);
#endif
    return currentRawSpeed;
}
