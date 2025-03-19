#ifndef IBRAKE_AND_DIRECTION_H_
#define IBRAKE_AND_DIRECTION_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IBrakeAndDirection interface.
 */
typedef enum
{
    IBRAKEANDDIRECTION_OK = 0,       /**< Operation completed successfully. */
    IBRAKEANDDIRECTION_NOT_OK       /**< Operation failed. */
} IBrakeAndDirection_StatusType;

/**
 * @brief Structure defining the function pointers for IBrakeAndDirection interface.
 */
typedef struct
{
    /**
     * @brief Write the direction status.
     * @param direction Direction status to write.
     * @return Status of the operation.
     */
    IBrakeAndDirection_StatusType (*writeDirection)(cmDirectionStatus direction);

    /**
     * @brief Read the current direction status.
     * @return Current direction status.
     */
    cmDirectionStatus (*readDirection)(void);

    /**
     * @brief Write the brake status.
     * @param brake Brake status to write.
     * @return Status of the operation.
     */
    IBrakeAndDirection_StatusType (*writeBrake)(cmBrakeStatus brake);

    /**
     * @brief Read the current brake status.
     * @return Current brake status.
     */
    cmBrakeStatus (*readBrake)(void);
} IBrakeAndDirection;

/**
 * @brief Global instance of the IBrakeAndDirection interface.
 */
extern IBrakeAndDirection BrakeAndDirectionInterface;

/* Function prototypes */

/**
 * @brief Implementation for writing the direction status.
 * @param direction Direction status to write.
 * @return Status of the operation.
 */
IBrakeAndDirection_StatusType IBrakeAndDirection_writeDirection_Impl(cmDirectionStatus direction);

/**
 * @brief Implementation for reading the direction status.
 * @return Current direction status.
 */
cmDirectionStatus IBrakeAndDirection_readDirection_Impl(void);

/**
 * @brief Implementation for writing the brake status.
 * @param brake Brake status to write.
 * @return Status of the operation.
 */
IBrakeAndDirection_StatusType IBrakeAndDirection_writeBrake_Impl(cmBrakeStatus brake);

/**
 * @brief Implementation for reading the brake status.
 * @return Current brake status.
 */
cmBrakeStatus IBrakeAndDirection_readBrake_Impl(void);

#endif /* IBRAKE_AND_DIRECTION_H_ */
