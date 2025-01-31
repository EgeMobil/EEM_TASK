#include "IBrakeStatus.h"

/**
 * @brief Instance of the IBrakeStatus interface.
 */
IBrakeStatus BrakeStatusInterface = {
    .writeBrake = IBrakeStatus_writeBrake_Impl,
    .readBrake = IBrakeStatus_readBrake_Impl
};

/* Static variable for storing the current brake status */
static cmBrakeStatusType currentBrake = BRAKE_STATUS_UNKNOWN;

/**
 * @brief Implementation for writing the brake status.
 * @param brake Brake status to write.
 * @return Status of the operation.
 */
IBrakeStatus_StatusType IBrakeStatus_writeBrake_Impl(cmBrakeStatusType brake)
{
    if (brake < BRAKE_STATUS_DISABLE || brake > BRAKE_STATUS_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IBrakeStatus] Invalid brake value: %d\n", brake);
#endif
        return IBRAKESTATUS_NOT_OK;
    }

    currentBrake = brake;
#ifndef STM32G431xx
    printf("[IBrakeStatus] Brake written: %d\n", brake);
#endif
    return IBRAKESTATUS_OK;
}

/**
 * @brief Implementation for reading the brake status.
 * @return Current brake status.
 */
cmBrakeStatusType IBrakeStatus_readBrake_Impl(void)
{
#ifndef STM32G431xx
    printf("[IBrakeStatus] Brake read: %d\n", currentBrake);
#endif
    return currentBrake;
}
