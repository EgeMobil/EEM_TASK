#ifndef IBRAKE_STATUS_H_
#define IBRAKE_STATUS_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IBrakeStatus interface.
 */
typedef enum
{
    IBRAKESTATUS_OK = 0,       /**< Operation completed successfully. */
    IBRAKESTATUS_NOT_OK        /**< Operation failed. */
} IBrakeStatus_StatusType;

/**
 * @brief Structure defining the function pointers for IBrakeStatus interface.
 */
typedef struct
{
    /**
     * @brief Write the brake status.
     * @param brake Brake status to write.
     * @return Status of the operation.
     */
    IBrakeStatus_StatusType (*writeBrake)(cmBrakeStatusType brake);

    /**
     * @brief Read the current brake status.
     * @return Current brake status.
     */
    cmBrakeStatusType (*readBrake)(void);
} IBrakeStatus;

/**
 * @brief Global instance of the IBrakeStatus interface.
 */
extern IBrakeStatus BrakeStatusInterface;

/* Function prototypes */

/**
 * @brief Implementation for writing the brake status.
 * @param brake Brake status to write.
 * @return Status of the operation.
 */
IBrakeStatus_StatusType IBrakeStatus_writeBrake_Impl(cmBrakeStatusType brake);

/**
 * @brief Implementation for reading the brake status.
 * @return Current brake status.
 */
cmBrakeStatusType IBrakeStatus_readBrake_Impl(void);

#endif /* IBRAKE_STATUS_H_ */
