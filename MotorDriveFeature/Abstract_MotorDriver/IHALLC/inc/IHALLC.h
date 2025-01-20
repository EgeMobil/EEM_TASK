#ifndef IHALLC_H_
#define IHALLC_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IHALLC interface.
 */
typedef enum
{
    IHALLC_OK = 0,        /**< Operation completed successfully. */
    IHALLC_NOT_OK         /**< Operation failed. */
} IHALLC_StatusType;

/**
 * @brief Structure defining the function pointers for IHALLC interface.
 */
typedef struct
{
    /**
     * @brief Write the Hall sensor state.
     * @param state Hall sensor state to write.
     * @return Status of the operation.
     */
    IHALLC_StatusType (*writeStatus)(cmHallCStateStatus status);

    /**
     * @brief Read the current Hall sensor state.
     * @return Current Hall sensor state.
     */
    cmHallCStateStatus (*readStatus)(void);

    /**
     * @brief Write the rising edge flag.
     * @param flag Rising edge flag to write.
     * @return Status of the operation.
     */
    IHALLC_StatusType (*writeRisingEdgeCFlag)(cmRisingEdgeCFlag flag);

    /**
     * @brief Read the current rising edge flag.
     * @return Current rising edge flag.
     */
    cmRisingEdgeCFlag (*readRisingEdgeCFlag)(void);

    /**
     * @brief Write the falling edge flag.
     * @param flag Falling edge flag to write.
     * @return Status of the operation.
     */
    IHALLC_StatusType (*writeFallingEdgeCFlag)(cmFallingEdgeCFlag flag);

    /**
     * @brief Read the current falling edge flag.
     * @return Current falling edge flag.
     */
    cmFallingEdgeCFlag (*readFallingEdgeCFlag)(void);
} IHALLC;

/**
 * @brief Global instance of the IHALLC interface.
 */
extern IHALLC HALLCInterface;

/* Function prototypes */

/**
 * @brief Implementation for writing the Hall sensor state.
 * @param state Hall sensor state to write.
 * @return Status of the operation.
 */
IHALLC_StatusType IHALLC_writeStatus_Impl(cmHallCStateStatus status);

/**
 * @brief Implementation for reading the Hall sensor state.
 * @return Current Hall sensor state.
 */
cmHallCStateStatus IHALLC_readStatus_Impl(void);

/**
 * @brief Implementation for writing the rising edge flag.
 * @param flag Rising edge flag to write.
 * @return Status of the operation.
 */
IHALLC_StatusType IHALLC_writeRisingEdgeFlag_Impl(cmRisingEdgeCFlag flag);

/**
 * @brief Implementation for reading the rising edge flag.
 * @return Current rising edge flag.
 */
cmRisingEdgeCFlag IHALLC_readRisingEdgeFlag_Impl(void);

/**
 * @brief Implementation for writing the falling edge flag.
 * @param flag Falling edge flag to write.
 * @return Status of the operation.
 */
IHALLC_StatusType IHALLC_writeFallingEdgeFlag_Impl(cmFallingEdgeCFlag flag);

/**
 * @brief Implementation for reading the falling edge flag.
 * @return Current falling edge flag.
 */
cmFallingEdgeCFlag IHALLC_readFallingEdgeFlag_Impl(void);

#endif /* IHALLC_H_ */
