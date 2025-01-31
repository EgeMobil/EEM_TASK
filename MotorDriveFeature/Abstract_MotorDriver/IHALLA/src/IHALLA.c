#include "IHALLA.h"

/**
 * @brief Instance of the IHALLA interface.
 */
IHALLA HALLAInterface = {
    .writeStatus = IHALLA_writeStatus_Impl,
    .readStatus = IHALLA_readStatus_Impl,
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
IHALLA_StatusType IHALLA_writeStatus_Impl(cmHallAStateStatus status)
{
    if (status < HALLA_STATUS_LOW || status > HALLA_STATUS_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IHALLA] Invalid state value: %d\n", status);
#endif
        return IHALLA_NOT_OK;
    }

    currentState = status;
#ifndef STM32G431xx
    printf("[IHALLA] State written: %d\n", status);
#endif
    return IHALLA_OK;
}

/**
 * @brief Implementation for reading the Hall sensor state.
 * @return Current Hall sensor state.
 */
cmHallAStateStatus IHALLA_readStatus_Impl(void)
{
#ifndef STM32G431xx
    printf("[IHALLA] State read: %d\n", currentState);
#endif
    return currentState;
}

/**
 * @brief Implementation for writing the rising edge flag.
 * @param flag Rising edge flag to write.
 * @return Status of the operation.
 */
IHALLA_StatusType IHALLA_writeRisingEdgeFlag_Impl(cmRisingEdgeAFlag flag)
{
    if (flag < HALLA_RISING_EDGE_RESET || flag > HALLA_RISING_EDGE_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IHALLA] Invalid rising edge flag: %d\n", flag);
#endif
        return IHALLA_NOT_OK;
    }

    currentRisingEdgeFlag = flag;
#ifndef STM32G431xx
    printf("[IHALLA] Rising edge flag written: %d\n", flag);
#endif
    return IHALLA_OK;
}

/**
 * @brief Implementation for reading the rising edge flag.
 * @return Current rising edge flag.
 */
cmRisingEdgeAFlag IHALLA_readRisingEdgeFlag_Impl(void)
{
#ifndef STM32G431xx
    printf("[IHALLA] Rising edge flag read: %d\n", currentRisingEdgeFlag);
#endif
    return currentRisingEdgeFlag;
}

/**
 * @brief Implementation for writing the falling edge flag.
 * @param flag Falling edge flag to write.
 * @return Status of the operation.
 */
IHALLA_StatusType IHALLA_writeFallingEdgeFlag_Impl(cmFallingEdgeAFlag flag)
{
    if (flag < HALLA_FALLING_EDGE_RESET || flag > HALLA_FALLING_EDGE_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IHALLA] Invalid falling edge flag: %d\n", flag);
#endif
        return IHALLA_NOT_OK;
    }

    currentFallingEdgeFlag = flag;
#ifndef STM32G431xx
    printf("[IHALLA] Falling edge flag written: %d\n", flag);
#endif
    return IHALLA_OK;
}

/**
 * @brief Implementation for reading the falling edge flag.
 * @return Current falling edge flag.
 */
cmFallingEdgeAFlag IHALLA_readFallingEdgeFlag_Impl(void)
{
#ifndef STM32G431xx
    printf("[IHALLA] Falling edge flag read: %d\n", currentFallingEdgeFlag);
#endif
    return currentFallingEdgeFlag;
}
