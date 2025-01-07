#ifndef IDIRECTION_STATUS_H_
#define IDIRECTION_STATUS_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IDirectionStatus interface.
 */
typedef enum
{
    IDIRECTIONSTATUS_OK = 0,       /**< Operation completed successfully. */
    IDIRECTIONSTATUS_NOT_OK        /**< Operation failed. */
} IDirectionStatus_StatusType;

/**
 * @brief Structure defining the function pointers for the IDirectionStatus interface.
 */
typedef struct
{
    /**
     * @brief Write the direction status.
     * @param direction Direction status to write.
     * @return Status of the operation.
     */
    IDirectionStatus_StatusType (*writeDirection)(cmDirectionStatusType direction);

    /**
     * @brief Read the current direction status.
     * @return Current direction status.
     */
    cmDirectionStatusType (*readDirection)(void);
} IDirectionStatus;

/**
 * @brief Global instance of the IDirectionStatus interface.
 */
extern IDirectionStatus DirectionStatusInterface;

/* Function prototypes */

/**
 * @brief Implementation for writing the direction status.
 * @param direction Direction status to write.
 * @return Status of the operation.
 */
IDirectionStatus_StatusType IDirectionStatus_writeDirection_Impl(cmDirectionStatusType direction);

/**
 * @brief Implementation for reading the direction status.
 * @return Current direction status.
 */
cmDirectionStatusType IDirectionStatus_readDirection_Impl(void);

#endif /* IDIRECTION_STATUS_H_ */
