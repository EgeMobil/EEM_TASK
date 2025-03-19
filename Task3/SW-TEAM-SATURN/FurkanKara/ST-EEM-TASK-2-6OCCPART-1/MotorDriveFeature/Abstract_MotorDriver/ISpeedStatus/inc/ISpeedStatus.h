#ifndef ISPEEDSTATUS_H_
#define ISPEEDSTATUS_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the ISpeedStatus interface.
 */
typedef enum
{
    ISPEEDSTATUS_OK = 0,        /**< Operation completed successfully. */
    ISPEEDSTATUS_NOT_OK         /**< Operation failed. */
} ISpeedStatus_StatusType;

/**
 * @brief Structure defining the function pointers for ISpeedStatus interface.
 */
typedef struct
{
    /**
     * @brief Write the speed status.
     * @param speed Speed status to write.
     * @return Status of the operation.
     */
    ISpeedStatus_StatusType (*writeSpeedStatus)(cmSpeedStatus speed);

    /**
     * @brief Read the current speed status.
     * @return Current speed status.
     */
    cmSpeedStatus (*readSpeedStatus)(void);
} ISpeedStatus;

/**
 * @brief Global instance of the ISpeedStatus interface.
 */
extern ISpeedStatus SpeedStatusInterface;

/* Function prototypes */
/**
 * @brief Writes the speed status.
 * 
 * This function sets the speed status.
 * 
 * @param speed The speed value to write of type `cmSpeedStatus`.
 * @return The status of the operation:
 *         - `ISPEEDSTATUS_OK` if the operation was successful.
 *         - `ISPEEDSTATUS_NOT_OK` if the operation failed.
 */
ISpeedStatus_StatusType ISpeedStatus_writeSpeedStatus_Impl(cmSpeedStatus speed);

/**
 * @brief Reads the current speed status.
 * 
 * This function retrieves the current speed status.
 * 
 * @return The current speed status of type `cmSpeedStatus`.
 */
cmSpeedStatus ISpeedStatus_readSpeedStatus_Impl(void);

#endif /* ISPEEDSTATUS_H_ */
