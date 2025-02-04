#include "IHALLC.h"

/**
 * @brief Instance of the IHALLC interface.
 */
IHALLC HALLCInterface = {
    .writeStatus = IHALLC_writeStatus_Impl,
    .readStatus = IHALLC_readStatus_Impl,
    .writeRisingEdgeCFlag = IHALLC_writeRisingEdgeFlag_Impl,
    .readRisingEdgeCFlag = IHALLC_readRisingEdgeFlag_Impl,
    .writeFallingEdgeCFlag = IHALLC_writeFallingEdgeFlag_Impl,
    .readFallingEdgeCFlag = IHALLC_readFallingEdgeFlag_Impl
};

/* Static variables for storing current states */
static cmHallCStateStatus currentState = HALLC_STATUS_UNKNOWN;
static cmRisingEdgeCFlag currentRisingEdgeFlag = HALLC_RISING_EDGE_UNKNOWN;
static cmFallingEdgeCFlag currentFallingEdgeFlag = HALLC_FALLING_EDGE_UNKNOWN;

/**
 * @brief Implementation for writing the Hall sensor state.
 * @param state Hall sensor state to write.
 * @return Status of the operation.
 */
IHALLC_StatusType IHALLC_writeStatus_Impl(cmHallCStateStatus status)
{
#ifndef STM32G431xx
    printf("[IHALLC] Invalid state value: %d\n", status);
#endif
    if (status < HALLC_STATUS_LOW || status > HALLC_STATUS_UNKNOWN)
    {
        return IHALLC_NOT_OK;
    }

    currentState = status;
#ifndef STM32G431xx
    printf("[IHALLC] State written: %d\n", status);
#endif
    return IHALLC_OK;
}

/**
 * @brief Implementation for reading the Hall sensor state.
 * @return Current Hall sensor state.
 */
cmHallCStateStatus IHALLC_readStatus_Impl(void)
{
#ifndef STM32G431xx
    printf("[IHALLC] State read: %d\n", currentState);
#endif
    return currentState;
}

/**
 * @brief Implementation for writing the rising edge flag.
 * @param flag Rising edge flag to write.
 * @return Status of the operation.
 */
IHALLC_StatusType IHALLC_writeRisingEdgeFlag_Impl(cmRisingEdgeCFlag flag)
{
#ifndef STM32G431xx
    printf("[IHALLC] Invalid rising edge flag: %d\n", flag);
#endif
    if (flag < HALLC_RISING_EDGE_RESET || flag > HALLC_RISING_EDGE_UNKNOWN)
    {
        return IHALLC_NOT_OK;
    }

    currentRisingEdgeFlag = flag;
#ifndef STM32G431xx
    printf("[IHALLC] Rising edge flag written: %d\n", flag);
#endif
    return IHALLC_OK;
}

/**
 * @brief Implementation for reading the rising edge flag.
 * @return Current rising edge flag.
 */
cmRisingEdgeCFlag IHALLC_readRisingEdgeFlag_Impl(void)
{
#ifndef STM32G431xx
    printf("[IHALLC] Rising edge flag read: %d\n", currentRisingEdgeFlag);
#endif
    return currentRisingEdgeFlag;
}

/**
 * @brief Implementation for writing the falling edge flag.
 * @param flag Falling edge flag to write.
 * @return Status of the operation.
 */
IHALLC_StatusType IHALLC_writeFallingEdgeFlag_Impl(cmFallingEdgeCFlag flag)
{
#ifndef STM32G431xx
    printf("[IHALLC] Invalid falling edge flag: %d\n", flag);
#endif
    if (flag < HALLC_FALLING_EDGE_RESET || flag > HALLC_FALLING_EDGE_UNKNOWN)
    {
        return IHALLC_NOT_OK;
    }

    currentFallingEdgeFlag = flag;
#ifndef STM32G431xx
    printf("[IHALLC] Falling edge flag written: %d\n", flag);
#endif
    return IHALLC_OK;
}

/**
 * @brief Implementation for reading the falling edge flag.
 * @return Current falling edge flag.
 */
cmFallingEdgeCFlag IHALLC_readFallingEdgeFlag_Impl(void)
{
#ifndef STM32G431xx
    printf("[IHALLC] Falling edge flag read: %d\n", currentFallingEdgeFlag);
#endif
    return currentFallingEdgeFlag;
}
