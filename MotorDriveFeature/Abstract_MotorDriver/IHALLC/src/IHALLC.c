#include "IHALLC.h"

/**
 * @brief Instance of the IHALLC interface.
 */
IHALLC HALLCInterface = {
    .writeState = IHALLC_writeState_Impl,
    .readState = IHALLC_readState_Impl,
    .writeRisingEdgeFlag = IHALLC_writeRisingEdgeFlag_Impl,
    .readRisingEdgeFlag = IHALLC_readRisingEdgeFlag_Impl,
    .writeFallingEdgeFlag = IHALLC_writeFallingEdgeFlag_Impl,
    .readFallingEdgeFlag = IHALLC_readFallingEdgeFlag_Impl
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
IHALLC_StatusType IHALLC_writeState_Impl(cmHallCStateStatus state)
{
    if (state < HALLC_STATUS_ENABLE || state > HALLC_STATUS_UNKNOWN)
    {
        printf("[IHALLC] Invalid state value: %d\n", state);
        return IHALLC_NOT_OK;
    }

    currentState = state;
    printf("[IHALLC] State written: %d\n", state);
    return IHALLC_OK;
}

/**
 * @brief Implementation for reading the Hall sensor state.
 * @return Current Hall sensor state.
 */
cmHallCStateStatus IHALLC_readState_Impl(void)
{
    printf("[IHALLC] State read: %d\n", currentState);
    return currentState;
}

/**
 * @brief Implementation for writing the rising edge flag.
 * @param flag Rising edge flag to write.
 * @return Status of the operation.
 */
IHALLC_StatusType IHALLC_writeRisingEdgeFlag_Impl(cmRisingEdgeCFlag flag)
{
    if (flag < HALLC_RISING_EDGE_LOW || flag > HALLC_RISING_EDGE_UNKNOWN)
    {
        printf("[IHALLC] Invalid rising edge flag: %d\n", flag);
        return IHALLC_NOT_OK;
    }

    currentRisingEdgeFlag = flag;
    printf("[IHALLC] Rising edge flag written: %d\n", flag);
    return IHALLC_OK;
}

/**
 * @brief Implementation for reading the rising edge flag.
 * @return Current rising edge flag.
 */
cmRisingEdgeCFlag IHALLC_readRisingEdgeFlag_Impl(void)
{
    printf("[IHALLC] Rising edge flag read: %d\n", currentRisingEdgeFlag);
    return currentRisingEdgeFlag;
}

/**
 * @brief Implementation for writing the falling edge flag.
 * @param flag Falling edge flag to write.
 * @return Status of the operation.
 */
IHALLC_StatusType IHALLC_writeFallingEdgeFlag_Impl(cmFallingEdgeCFlag flag)
{
    if (flag < HALLC_FALLING_EDGE_LOW || flag > HALLC_FALLING_EDGE_UNKNOWN)
    {
        printf("[IHALLC] Invalid falling edge flag: %d\n", flag);
        return IHALLC_NOT_OK;
    }

    currentFallingEdgeFlag = flag;
    printf("[IHALLC] Falling edge flag written: %d\n", flag);
    return IHALLC_OK;
}

/**
 * @brief Implementation for reading the falling edge flag.
 * @return Current falling edge flag.
 */
cmFallingEdgeCFlag IHALLC_readFallingEdgeFlag_Impl(void)
{
    printf("[IHALLC] Falling edge flag read: %d\n", currentFallingEdgeFlag);
    return currentFallingEdgeFlag;
}
