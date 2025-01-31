#include "ISpeedStatus.h"

/**
 * @brief Instance of the ISpeedStatus interface.
 */
ISpeedStatus SpeedStatusInterface = {
    .writeSpeedStatus = ISpeedStatus_writeSpeedStatus_Impl,
    .readSpeedStatus = ISpeedStatus_readSpeedStatus_Impl,
};

/* Static variable for storing current speed status */
static cmSpeedStatus currentSpeedStatus = 0;

/**
 * @brief Implementation for writing the speed status.
 * @param speed Speed status to write.
 * @return Status of the operation.
 */
ISpeedStatus_StatusType ISpeedStatus_writeSpeedStatus_Impl(cmSpeedStatus speed)
{
    // Speed constraints are assumed to be globally handled in the system.
    currentSpeedStatus = speed;
#ifndef defined(STM32G431xx)
    printf("[ISpeedStatus] Speed status written: %u\n", speed);
#endif
    return ISPEEDSTATUS_OK;
}

/**
 * @brief Implementation for reading the speed status.
 * @return Current speed status.
 */
cmSpeedStatus ISpeedStatus_readSpeedStatus_Impl(void)
{
#ifndef defined(STM32G431xx)
    printf("[ISpeedStatus] Speed status read: %u\n", currentSpeedStatus);
#endif
    return currentSpeedStatus;
}
