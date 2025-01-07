#include "IHALLB.h"

/**
 * @brief Instance of the IHALLB interface.
 */
IHALLB HALLBInterface = {
    .writeState = IHALLB_writeState_Impl,
    .readState = IHALLB_readState_Impl,
    .writeRisingEdgeFlag = IHALLB_writeRisingEdgeFlag_Impl,
    .readRisingEdgeFlag = IHALLB_readRisingEdgeFlag_Impl,
    .writeFallingEdgeFlag = IHALLB_writeFallingEdgeFlag_Impl,
    .readFallingEdgeFlag = IHALLB_readFallingEdgeFlag_Impl
};

/* Static variables for storing current states */
static cmHallBStateStatus currentState = HALLB_STATUS_UNKNOWN;
static cmRisingEdgeBFlag currentRisingEdgeFlag = HALLB_RISING_EDGE_UNKNOWN;
static cmFallingEdgeBFlag currentFallingEdgeFlag = HALLB_FALLING_EDGE_UNKNOWN;

/**
 * @brief Implementation for writing the Hall sensor state.
 * @param state Hall sensor state to write.
 * @return Status of the operation.
 */
IHALLB_StatusType IHALLB_writeState_Impl(cmHallBStateStatus state)
{
    if (state < HALLB_STATUS_ENABLE || state > HALLB_STATUS_UNKNOWN)
    {
        printf("[IHALLB] Invalid state value: %d\n", state);
        return IHALLB_NOT_OK;
    }

    currentState = state;
    printf("[IHALLB] State written: %d\n", state);
    return IHALLB_OK;
}

/**
 * @brief Implementation for reading the Hall sensor state.
 * @return Current Hall sensor state.
 */
cmHallBStateStatus IHALLB_readState_Impl(void)
{
    printf("[IHALLB] State read: %d\n", currentState);
    return currentState;
}

/**
 * @brief Implementation for writing the rising edge flag.
 * @param flag Rising edge flag to write.
 * @return Status of the operation.
 */
IHALLB_StatusType IHALLB_writeRisingEdgeFlag_Impl(cmRisingEdgeBFlag flag)
{
    if (flag < HALLB_RISING_EDGE_LOW || flag > HALLB_RISING_EDGE_UNKNOWN)
    {
        printf("[IHALLB] Invalid rising edge flag: %d\n", flag);
        return IHALLB_NOT_OK;
    }

    currentRisingEdgeFlag = flag;
    printf("[IHALLB] Rising edge flag written: %d\n", flag);
    return IHALLB_OK;
}

/**
 * @brief Implementation for reading the rising edge flag.
 * @return Current rising edge flag.
 */
cmRisingEdgeBFlag IHALLB_readRisingEdgeFlag_Impl(void)
{
    printf("[IHALLB] Rising edge flag read: %d\n", currentRisingEdgeFlag);
    return currentRisingEdgeFlag;
}

/**
 * @brief Implementation for writing the falling edge flag.
 * @param flag Falling edge flag to write.
 * @return Status of the operation.
 */
IHALLB_StatusType IHALLB_writeFallingEdgeFlag_Impl(cmFallingEdgeBFlag flag)
{
    if (flag < HALLB_FALLING_EDGE_LOW || flag > HALLB_FALLING_EDGE_UNKNOWN)
    {
        printf("[IHALLB] Invalid falling edge flag: %d\n", flag);
        return IHALLB_NOT_OK;
    }

    currentFallingEdgeFlag = flag;
    printf("[IHALLB] Falling edge flag written: %d\n", flag);
    return IHALLB_OK;
}

/**
 * @brief Implementation for reading the falling edge flag.
 * @return Current falling edge flag.
 */
cmFallingEdgeBFlag IHALLB_readFallingEdgeFlag_Impl(void)
{
    printf("[IHALLB] Falling edge flag read: %d\n", currentFallingEdgeFlag);
    return currentFallingEdgeFlag;
}
