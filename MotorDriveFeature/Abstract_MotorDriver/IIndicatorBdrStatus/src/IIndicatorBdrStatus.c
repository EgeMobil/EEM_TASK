#include "IIndicatorBdrStatus.h"

/**
 * @brief Instance of the IIndicatorBdrStatus interface.
 */
IIndicatorBdrStatus IndicatorBdrStatusInterface = {
    .writeIndicatorBdrStatus = IIndicatorBdrStatus_writeIndicatorBdrStatus_Impl,
    .readIndicatorBdrStatus = IIndicatorBdrStatus_readIndicatorBdrStatus_Impl,
};

/* Static variable for storing current indicator BDR status */
static cmIndicatorBdrStatus currentIndicatorBdrStatus = { .byte = 0x00 }; // Default to 0 (Idle, Brake Disabled)

/**
 * @brief Implementation for writing the indicator BDR status.
 * @param status Indicator BDR status to write.
 * @return Status of the operation.
 */
IIndicatorBdrStatus_StatusType IIndicatorBdrStatus_writeIndicatorBdrStatus_Impl(cmIndicatorBdrStatus status)
{
    // Validate direction status
    if (status.directionStatus > DIRECTION_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IIndicatorBdrStatus] Invalid direction status value: %d\n", status.directionStatus);
#endif
        return IINDICATORBDRSTATUS_NOT_OK;
    }

    // Validate brake status
    if (status.brakeStatus > BRAKE_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IIndicatorBdrStatus] Invalid brake status value: %d\n", status.brakeStatus);
#endif
        return IINDICATORBDRSTATUS_NOT_OK;
    }

    // Set the current status
    currentIndicatorBdrStatus = status;

#ifndef STM32G431xx
    printf("[IIndicatorBdrStatus] Indicator BDR status written: Direction = %d, Brake = %d\n",
           status.directionStatus, status.brakeStatus);
#endif

    return IINDICATORBDRSTATUS_OK;
}

/**
 * @brief Implementation for reading the indicator BDR status.
 * @return Current indicator BDR status.
 */
cmIndicatorBdrStatus IIndicatorBdrStatus_readIndicatorBdrStatus_Impl(void)
{
#ifndef STM32G431xx
    printf("[IIndicatorBdrStatus] Indicator BDR status read: Direction = %d, Brake = %d\n",
           currentIndicatorBdrStatus.directionStatus, currentIndicatorBdrStatus.brakeStatus);
#endif
    return currentIndicatorBdrStatus;
}
