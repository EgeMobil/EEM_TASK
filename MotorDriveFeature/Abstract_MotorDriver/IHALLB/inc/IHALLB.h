#ifndef IHALLB_H_
#define IHALLB_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IHALLB interface.
 */
typedef enum
{
    IHALLB_OK = 0,        /**< Operation completed successfully. */
    IHALLB_NOT_OK         /**< Operation failed. */
} IHALLB_StatusType;

/**
 * @brief Structure defining the function pointers for IHALLB interface.
 */
typedef struct
{
    /**
     * @brief Write the Hall sensor state.
     * @param state Hall sensor state to write.
     * @return Status of the operation.
     */
    IHALLB_StatusType (*writeStatus)(cmHallBStateStatus status);

    /**
     * @brief Read the current Hall sensor state.
     * @return Current Hall sensor state.
     */
    cmHallBStateStatus (*readStatus)(void);

    /**
     * @brief Write the rising edge flag.
     * @param flag Rising edge flag to write.
     * @return Status of the operation.
     */
    IHALLB_StatusType (*writeRisingEdgeBFlag)(cmRisingEdgeBFlag flag);

    /**
     * @brief Read the current rising edge flag.
     * @return Current rising edge flag.
     */
    cmRisingEdgeBFlag (*readRisingEdgeBFlag)(void);

    /**
     * @brief Write the falling edge flag.
     * @param flag Falling edge flag to write.
     * @return Status of the operation.
     */
    IHALLB_StatusType (*writeFallingEdgeBFlag)(cmFallingEdgeBFlag flag);

    /**
     * @brief Read the current falling edge flag.
     * @return Current falling edge flag.
     */
    cmFallingEdgeBFlag (*readFallingEdgeBFlag)(void);
} IHALLB;

/**
 * @brief Global instance of the IHALLB interface.
 */
extern IHALLB HALLBInterface;

/* Function prototypes */

/**
 * @brief Implementation for writing the Hall sensor state.
 * @param state Hall sensor state to write.
 * @return Status of the operation.
 */
IHALLB_StatusType IHALLB_writeStatus_Impl(cmHallBStateStatus status);

/**
 * @brief Implementation for reading the Hall sensor state.
 * @return Current Hall sensor state.
 */
cmHallBStateStatus IHALLB_readStatus_Impl(void);

/**
 * @brief Implementation for writing the rising edge flag.
 * @param flag Rising edge flag to write.
 * @return Status of the operation.
 */
IHALLB_StatusType IHALLB_writeRisingEdgeFlag_Impl(cmRisingEdgeBFlag flag);

/**
 * @brief Implementation for reading the rising edge flag.
 * @return Current rising edge flag.
 */
cmRisingEdgeBFlag IHALLB_readRisingEdgeFlag_Impl(void);

/**
 * @brief Implementation for writing the falling edge flag.
 * @param flag Falling edge flag to write.
 * @return Status of the operation.
 */
IHALLB_StatusType IHALLB_writeFallingEdgeFlag_Impl(cmFallingEdgeBFlag flag);

/**
 * @brief Implementation for reading the falling edge flag.
 * @return Current falling edge flag.
 */
cmFallingEdgeBFlag IHALLB_readFallingEdgeFlag_Impl(void);

#endif /* IHALLB_H_ */
