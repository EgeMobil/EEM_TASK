#ifndef IRAWSPEED_H_
#define IRAWSPEED_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IRawSpeed interface.
 */
typedef enum
{
    IRAWSPEED_OK = 0,        /**< Operation completed successfully. */
    IRAWSPEED_NOT_OK         /**< Operation failed. */
} IRawSpeed_StatusType;

/**
 * @brief Structure defining the function pointers for IRawSpeed interface.
 */
typedef struct
{
    /**
     * @brief Write the raw speed status.
     * @param rawSpeed Raw speed status to write.
     * @return Status of the operation.
     */
    IRawSpeed_StatusType (*writeRawSpeed)(cmRawSpeedStatus rawSpeed);

    /**
     * @brief Read the current raw speed status.
     * @return Current raw speed status.
     */
    cmRawSpeedStatus (*readRawSpeed)(void);
} IRawSpeed;

/**
 * @brief Global instance of the IRawSpeed interface.
 */
extern IRawSpeed RawSpeedInterface;

/* Function prototypes */
/**
 * @brief Writes the raw speed status.
 * 
 * This function sets the raw speed status.
 * 
 * @param rawSpeed The raw speed value to write of type `cmRawSpeedStatus`.
 * @return The status of the operation:
 *         - `IRAWSPEED_OK` if the operation was successful.
 *         - `IRAWSPEED_NOT_OK` if the operation failed.
 */
IRawSpeed_StatusType IRawSpeed_writeRawSpeed_Impl(cmRawSpeedStatus rawSpeed);

/**
 * @brief Reads the current raw speed status.
 * 
 * This function retrieves the current raw speed status.
 * 
 * @return The current raw speed status of type `cmRawSpeedStatus`.
 */
cmRawSpeedStatus IRawSpeed_readRawSpeed_Impl(void);

#endif /* IRAWSPEED_H_ */
