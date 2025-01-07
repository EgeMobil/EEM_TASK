#include "IHALLA.h"

/**
 * @brief Instance of the IHALLA interface.
 */
IHALLA HALLAInterface = {
    .writeState = IHALLA_writeState_Impl,
    .readState = IHALLA_readState_Impl,
    .writeRisingEdgeAFlag = IHALLA_writeRisingEdgeFlag_Impl,
    .readRisingEdgeAFlag = IHALLA_readRisingEdgeFlag_Impl,
    .writeFallingEdgeAFlag = IHALLA_writeFallingEdgeFlag_Impl,
    .readFallingEdgeAFlag = IHALLA_readFallingEdgeFlag_Impl
};

/* Static variables for storing current states */
static cmHallAStateStatus currentState = HALLA_STATUS_UNKNOWN;
static cmRisingEdgeAFlag currentRisingEdgeFlag = HALLA_RISING_EDGE_UNKNOWN;
static cmFallingEdgeAFlag currentFallingEdgeFlag = HALLA_FALLING_EDGE_UNKNOWN;

/**
 * @brief Implementation for writing the Hall sensor state.
 * @param state Hall state to write.
 * @return Status of the operation.
 */
IHALLA_StatusType IHALLA_writeState_Impl(cmHallAStateStatus state)
{
    if (state < HALLA_STATUS_ENABLE || state > HALLA_STATUS_UNKNOWN)
    {
        printf("[IHALLA] Invalid state value: %d\n", state);
        return IHALLA_NOT_OK;
    }

    currentState = state;
    printf("[IHALLA] State written: %d\n", state);
    return IHALLA_OK;
}

/**
 * @brief Implementation for reading the Hall sensor state.
 * @return Current Hall sensor state.
 */
cmHallAStateStatus IHALLA_readState_Impl(void)
{
    printf("[IHALLA] State read: %d\n", currentState);
    return currentState;
}

/**
 * @brief Implementation for writing the rising edge flag.
 * @param flag Rising edge flag to write.
 * @return Status of the operation.
 */
IHALLA_StatusType IHALLA_writeRisingEdgeFlag_Impl(cmRisingEdgeAFlag flag)
{
    if (flag < HALLA_RISING_EDGE_LOW || flag > HALLA_RISING_EDGE_UNKNOWN)
    {
        printf("[IHALLA] Invalid rising edge flag: %d\n", flag);
        return IHALLA_NOT_OK;
    }

    currentRisingEdgeFlag = flag;
    printf("[IHALLA] Rising edge flag written: %d\n", flag);
    return IHALLA_OK;
}

/**
 * @brief Implementation for reading the rising edge flag.
 * @return Current rising edge flag.
 */
cmRisingEdgeAFlag IHALLA_readRisingEdgeFlag_Impl(void)
{
    printf("[IHALLA] Rising edge flag read: %d\n", currentRisingEdgeFlag);
    return currentRisingEdgeFlag;
}

/**
 * @brief Implementation for writing the falling edge flag.
 * @param flag Falling edge flag to write.
 * @return Status of the operation.
 */
IHALLA_StatusType IHALLA_writeFallingEdgeFlag_Impl(cmFallingEdgeAFlag flag)
{
    if (flag < HALLA_FALLING_EDGE_LOW || flag > HALLA_FALLING_EDGE_UNKNOWN)
    {
        printf("[IHALLA] Invalid falling edge flag: %d\n", flag);
        return IHALLA_NOT_OK;
    }

    currentFallingEdgeFlag = flag;
    printf("[IHALLA] Falling edge flag written: %d\n", flag);
    return IHALLA_OK;
}

/**
 * @brief Implementation for reading the falling edge flag.
 * @return Current falling edge flag.
 */
cmFallingEdgeAFlag IHALLA_readFallingEdgeFlag_Impl(void)
{
    printf("[IHALLA] Falling edge flag read: %d\n", currentFallingEdgeFlag);
    return currentFallingEdgeFlag;
}
