#include "IIndicatorSpeedStatus.h"

/**
 * @brief Instance of the IIndicatorSpeedStatus interface.
 */
IIndicatorSpeedStatus IndicatorSpeedStatusInterface = {
    .writeIndicatorSpeedStatus = IIndicatorSpeedStatus_writeIndicatorSpeedStatus_Impl,
    .readIndicatorSpeedStatus = IIndicatorSpeedStatus_readIndicatorSpeedStatus_Impl,
};

/* Static variable for storing current indicator speed status */
static cmIndicatorSpeedStatus currentIndicatorSpeedStatus = INDICATORSPEEDSTATUS_UNKNOWN;

/**
 * @brief Implementation for writing the indicator speed status.
 * @param status Indicator speed status to write.
 * @return Status of the operation.
 */
IIndicatorSpeedStatus_StatusType IIndicatorSpeedStatus_writeIndicatorSpeedStatus_Impl(cmIndicatorSpeedStatus status)
{
    if (status < INDICATORSPEEDSTATUS_IDLE || status > INDICATORSPEEDSTATUS_UNKNOWN)
    {
        printf("[IIndicatorSpeedStatus] Invalid indicator speed status value: %d\n", status);
        return IINDICATORSPEEDSTATUS_NOT_OK;
    }

    currentIndicatorSpeedStatus = status;
    printf("[IIndicatorSpeedStatus] Indicator speed status written: %d\n", status);
    return IINDICATORSPEEDSTATUS_OK;
}

/**
 * @brief Implementation for reading the indicator speed status.
 * @return Current indicator speed status.
 */
cmIndicatorSpeedStatus IIndicatorSpeedStatus_readIndicatorSpeedStatus_Impl(void)
{
    printf("[IIndicatorSpeedStatus] Indicator speed status read: %d\n", currentIndicatorSpeedStatus);
    return currentIndicatorSpeedStatus;
}
