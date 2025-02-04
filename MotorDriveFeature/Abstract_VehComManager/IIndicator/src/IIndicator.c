#include "IIndicator.h"

/**
 * @brief Instance of the IIndicator interface.
 */
IIndicator IndicatorInterface = {
    .writeIndicator = IIndicator_writeIndicator_Impl,
    .readIndicator = IIndicator_readIndicator_Impl,
};

/* Static variable for storing current indicator value */
static cmIndicator currentIndicator = 0; // Default to 0

/**
 * @brief Implementation for writing the indicator value.
 * @param value Indicator value to write.
 * @return Status of the operation.
 */
IIndicator_StatusType IIndicator_writeIndicator_Impl(cmIndicator value)
{
    // Example validation: Ensure value is within uint16_t range
    if (value > 0xFFFE)
    {
#ifndef STM32G431xx
        printf("[IIndicator] Invalid indicator value: %u\n", value);
        #endif
        return IINDICATOR_NOT_OK;
    }

    currentIndicator = value;
#ifndef STM32G431xx
    printf("[IIndicator] Indicator value written: %u\n", value);
    #endif
    return IINDICATOR_OK;
}

/**
 * @brief Implementation for reading the indicator value.
 * @return Current indicator value.
 */
cmIndicator IIndicator_readIndicator_Impl(void)
{
#ifndef STM32G431xx
    printf("[IIndicator] Indicator value read: %u\n", currentIndicator);
    #endif
    return currentIndicator;
}
