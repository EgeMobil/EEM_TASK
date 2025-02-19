#include "IDirectionStatus.h"

/**
 * @brief Instance of the IDirectionStatus interface.
 */
IDirectionStatus DirectionStatusInterface = {
    .writeDirection = IDirectionStatus_writeDirection_Impl,
    .readDirection = IDirectionStatus_readDirection_Impl
};

/* Static variable for storing the current direction status */
static cmDirectionStatusType currentDirection = DIRECTION_STATUS_UNKNOWN;

/**
 * @brief Implementation for writing the direction status.
 * @param direction Direction status to write.
 * @return Status of the operation.
 */
IDirectionStatus_StatusType IDirectionStatus_writeDirection_Impl(cmDirectionStatusType direction)
{
    if (direction < DIRECTION_STATUS_BACKWARD || direction > DIRECTION_STATUS_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IDirectionStatus] Invalid direction value: %d\n", direction);
#endif
        return IDIRECTIONSTATUS_NOT_OK;
    }

    currentDirection = direction;
#ifndef STM32G431xx
    printf("[IDirectionStatus] Direction written: %d\n", direction);
#endif
    return IDIRECTIONSTATUS_OK;
}

/**
 * @brief Implementation for reading the direction status.
 * @return Current direction status.
 */
cmDirectionStatusType IDirectionStatus_readDirection_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDirectionStatus] Direction read: %d\n", currentDirection);
#endif
    return currentDirection;
}