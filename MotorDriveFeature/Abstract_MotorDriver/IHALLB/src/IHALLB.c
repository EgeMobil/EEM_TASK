#include "IHALLB.h"

/**
 * @brief Instance of the IHALLB interface.
 */
IHALLB HALLBInterface = {
    .writeStatus = IHALLB_writeStatus_Impl,
    .readStatus = IHALLB_readStatus_Impl,
    .writeRisingEdgeBFlag = IHALLB_writeRisingEdgeFlag_Impl,
    .readRisingEdgeBFlag = IHALLB_readRisingEdgeFlag_Impl,
    .writeFallingEdgeBFlag = IHALLB_writeFallingEdgeFlag_Impl,
    .readFallingEdgeBFlag = IHALLB_readFallingEdgeFlag_Impl
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
IHALLB_StatusType IHALLB_writeStatus_Impl(cmHallBStateStatus status)
{
#ifndef defined(STM32G431xx)
    printf("[IHALLB] Invalid state value: %d\n", status);
#endif
    if (status < HALLB_STATUS_LOW || status > HALLB_STATUS_UNKNOWN)
    {
        return IHALLB_NOT_OK;
    }

    currentState = status;
#ifndef defined(STM32G431xx)
    printf("[IHALLB] State written: %d\n", status);
#endif
    return IHALLB_OK;
}

/**
 * @brief Implementation for reading the Hall sensor state.
 * @return Current Hall sensor state.
 */
cmHallBStateStatus IHALLB_readStatus_Impl(void)
{
#ifndef defined(STM32G431xx)
    printf("[IHALLB] State read: %d\n", currentState);
#endif
    return currentState;
}

/**
 * @brief Implementation for writing the rising edge flag.
 * @param flag Rising edge flag to write.
 * @return Status of the operation.
 */
IHALLB_StatusType IHALLB_writeRisingEdgeFlag_Impl(cmRisingEdgeBFlag flag)
{
#ifndef defined(STM32G431xx)
    printf("[IHALLB] Invalid rising edge flag: %d\n", flag);
#endif
    if (flag < HALLB_RISING_EDGE_RESET || flag > HALLB_RISING_EDGE_UNKNOWN)
    {
        return IHALLB_NOT_OK;
    }

    currentRisingEdgeFlag = flag;
#ifndef defined(STM32G431xx)
    printf("[IHALLB] Rising edge flag written: %d\n", flag);
#endif
    return IHALLB_OK;
}

/**
 * @brief Implementation for reading the rising edge flag.
 * @return Current rising edge flag.
 */
cmRisingEdgeBFlag IHALLB_readRisingEdgeFlag_Impl(void)
{
#ifndef defined(STM32G431xx)
    printf("[IHALLB] Rising edge flag read: %d\n", currentRisingEdgeFlag);
#endif
    return currentRisingEdgeFlag;
}

/**
 * @brief Implementation for writing the falling edge flag.
 * @param flag Falling edge flag to write.
 * @return Status of the operation.
 */
IHALLB_StatusType IHALLB_writeFallingEdgeFlag_Impl(cmFallingEdgeBFlag flag)
{
#ifndef defined(STM32G431xx)
    printf("[IHALLB] Invalid falling edge flag: %d\n", flag);
#endif
    if (flag < HALLB_FALLING_EDGE_RESET || flag > HALLB_FALLING_EDGE_UNKNOWN)
    {
        return IHALLB_NOT_OK;
    }

    currentFallingEdgeFlag = flag;
#ifndef defined(STM32G431xx)
    printf("[IHALLB] Falling edge flag written: %d\n", flag);
#endif
    return IHALLB_OK;
}

/**
 * @brief Implementation for reading the falling edge flag.
 * @return Current falling edge flag.
 */
cmFallingEdgeBFlag IHALLB_readFallingEdgeFlag_Impl(void)
{
#ifndef defined(STM32G431xx)
    printf("[IHALLB] Falling edge flag read: %d\n", currentFallingEdgeFlag);
#endif
    return currentFallingEdgeFlag;
}
