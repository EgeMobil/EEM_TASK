#include "IBrakeAndDirection.h"

/**
 * @brief Instance of the IBrakeAndDirection interface.
 */
IBrakeAndDirection BrakeAndDirectionInterface = {
    .writeDirection = IBrakeAndDirection_writeDirection_Impl,
    .readDirection = IBrakeAndDirection_readDirection_Impl,
    .writeBrake = IBrakeAndDirection_writeBrake_Impl,
    .readBrake = IBrakeAndDirection_readBrake_Impl
};

/* Static variables for storing current states */
static cmDirectionStatus currentDirection = DIRECTION_UNKNOWN;
static cmBrakeStatus currentBrake = BRAKE_UNKNOWN;

/**
 * @brief Implementation for writing the direction status.
 * @param direction Direction status to write.
 * @return Status of the operation.
 */
IBrakeAndDirection_StatusType IBrakeAndDirection_writeDirection_Impl(cmDirectionStatus direction)
{
    if (direction < DIRECTION_BACKWARD || direction > DIRECTION_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IBrakeAndDirection] Invalid direction value: %d\n", direction);
#endif
        return IBRAKEANDDIRECTION_NOT_OK;
    }

    currentDirection = direction;
#ifndef STM32G431xx
    printf("[IBrakeAndDirection] Direction written: %d\n", direction);
#endif
    return IBRAKEANDDIRECTION_OK;
}

/**
 * @brief Implementation for reading the direction status.
 * @return Current direction status.
 */
cmDirectionStatus IBrakeAndDirection_readDirection_Impl(void)
{
#ifndef STM32G431xx
    printf("[IBrakeAndDirection] Direction read: %d\n", currentDirection);
#endif
    return currentDirection;
}

/**
 * @brief Implementation for writing the brake status.
 * @param brake Brake status to write.
 * @return Status of the operation.
 */
IBrakeAndDirection_StatusType IBrakeAndDirection_writeBrake_Impl(cmBrakeStatus brake)
{
    if (brake < BRAKE_DISABLE || brake > BRAKE_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IBrakeAndDirection] Invalid brake value: %d\n", brake);
#endif
        return IBRAKEANDDIRECTION_NOT_OK;
    }

    currentBrake = brake;
#ifndef STM32G431xx
    printf("[IBrakeAndDirection] Brake written: %d\n", brake);
#endif
    return IBRAKEANDDIRECTION_OK;
}

/**
 * @brief Implementation for reading the brake status.
 * @return Current brake status.
 */
cmBrakeStatus IBrakeAndDirection_readBrake_Impl(void)
{
#ifndef STM32G431xx
    printf("[IBrakeAndDirection] Brake read: %d\n", currentBrake);
#endif
    return currentBrake;
}
