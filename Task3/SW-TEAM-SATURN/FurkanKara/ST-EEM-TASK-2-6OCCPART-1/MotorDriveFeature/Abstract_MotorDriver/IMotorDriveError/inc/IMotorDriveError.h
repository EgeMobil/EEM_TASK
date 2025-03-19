#ifndef IMOTORDRIVEERROR_H_
#define IMOTORDRIVEERROR_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IMotorDriveError interface.
 */
typedef enum
{
    IMOTORDRIVEERROR_OK = 0,        /**< Operation completed successfully. */
    IMOTORDRIVEERROR_NOT_OK         /**< Operation failed. */
} IMotorDriveError_StatusType;

/**
 * @brief Structure defining the function pointers for IMotorDriveError interface.
 */
typedef struct
{
    /**
     * @brief Write the motor drive error status.
     * @param status Motor drive error status to write.
     * @return Status of the operation.
     */
    IMotorDriveError_StatusType (*writeMotorDriveError)(cmMotorDriveError status);

    /**
     * @brief Read the current motor drive error status.
     * @return Current motor drive error status.
     */
    cmMotorDriveError (*readMotorDriveError)(void);
} IMotorDriveError;

/**
 * @brief Global instance of the IMotorDriveError interface.
 */
extern IMotorDriveError MotorDriveErrorInterface;

/* Function prototypes */
/**
 * @brief Writes the motor drive error status.
 * 
 * @param status The motor drive error value to write of type `cmMotorDriveError`.
 * @return The status of the operation:
 *         - `IMOTORDRIVEERROR_OK` if the operation was successful.
 *         - `IMOTORDRIVEERROR_NOT_OK` if the operation failed.
 */
IMotorDriveError_StatusType IMotorDriveError_writeMotorDriveError_Impl(cmMotorDriveError status);

/**
 * @brief Reads the current motor drive error status.
 * 
 * @return The current motor drive error status of type `cmMotorDriveError`.
 */
cmMotorDriveError IMotorDriveError_readMotorDriveError_Impl(void);

#endif /* IMOTORDRIVEERROR_H_ */
