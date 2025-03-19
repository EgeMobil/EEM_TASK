#ifndef IHALLA_H_
#define IHALLA_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IHALLA interface.
 */
typedef enum
{
    IHALLA_OK = 0,        /**< Operation completed successfully. */
    IHALLA_NOT_OK         /**< Operation failed. */
} IHALLA_StatusType;

/**
 * @brief Structure defining the function pointers for IHALLA interface.
 */
typedef struct
{
    /**
     * @brief Write the Hall sensor state.
     * @param state Hall state to write.
     * @return Status of the operation.
     */
    IHALLA_StatusType (*writeStatus)(cmHallAStateStatus status);

    /**
     * @brief Read the current Hall sensor state.
     * @return Current Hall sensor state.
     */
    cmHallAStateStatus (*readStatus)(void);

    /**
     * @brief Write the rising edge flag.
     * @param flag Rising edge flag to write.
     * @return Status of the operation.
     */
    IHALLA_StatusType (*writeRisingEdgeAFlag)(cmRisingEdgeAFlag flag);

    /**
     * @brief Read the current rising edge flag.
     * @return Current rising edge flag.
     */
    cmRisingEdgeAFlag (*readRisingEdgeAFlag)(void);

    /**
     * @brief Write the falling edge flag.
     * @param flag Falling edge flag to write.
     * @return Status of the operation.
     */
    IHALLA_StatusType (*writeFallingEdgeAFlag)(cmFallingEdgeAFlag flag);

    /**
     * @brief Read the current falling edge flag.
     * @return Current falling edge flag.
     */
    cmFallingEdgeAFlag (*readFallingEdgeAFlag)(void);
} IHALLA;

/**
 * @brief Global instance of the IHALLA interface.
 */
extern IHALLA HALLAInterface;

/* Function prototypes */
/**
 * @brief Writes the state status for Hall A.
 * 
 * This function sets the state status for Hall A.
 * 
 * @param state The state status to write of type `cmHallAStateStatus`.
 * @return The status of the operation:
 *         - `IHALLA_OK` if the operation was successful.
 *         - `IHALLA_NOT_OK` if the operation failed.
 */
IHALLA_StatusType IHALLA_writeStatus_Impl(cmHallAStateStatus state);

/**
 * @brief Reads the current state status for Hall A.
 * 
 * This function retrieves the current state status for Hall A.
 * 
 * @return The current state status of type `cmHallAStateStatus`.
 */
cmHallAStateStatus IHALLA_readStatus_Impl(void);

/**
 * @brief Writes the rising edge flag for Hall A.
 * 
 * This function sets the rising edge flag for Hall A.
 * 
 * @param flag The rising edge flag to write of type `cmRisingEdgeAFlag`.
 * @return The status of the operation:
 *         - `IHALLA_OK` if the operation was successful.
 *         - `IHALLA_NOT_OK` if the operation failed.
 */
IHALLA_StatusType IHALLA_writeRisingEdgeFlag_Impl(cmRisingEdgeAFlag flag);

/**
 * @brief Reads the current rising edge flag for Hall A.
 * 
 * This function retrieves the current rising edge flag for Hall A.
 * 
 * @return The current rising edge flag of type `cmRisingEdgeAFlag`.
 */
cmRisingEdgeAFlag IHALLA_readRisingEdgeFlag_Impl(void);

/**
 * @brief Writes the falling edge flag for Hall A.
 * 
 * This function sets the falling edge flag for Hall A.
 * 
 * @param flag The falling edge flag to write of type `cmFallingEdgeAFlag`.
 * @return The status of the operation:
 *         - `IHALLA_OK` if the operation was successful.
 *         - `IHALLA_NOT_OK` if the operation failed.
 */
IHALLA_StatusType IHALLA_writeFallingEdgeFlag_Impl(cmFallingEdgeAFlag flag);

/**
 * @brief Reads the current falling edge flag for Hall A.
 * 
 * This function retrieves the current falling edge flag for Hall A.
 * 
 * @return The current falling edge flag of type `cmFallingEdgeAFlag`.
 */
cmFallingEdgeAFlag IHALLA_readFallingEdgeFlag_Impl(void);

#endif /* IHALLA_H_ */
