#ifndef IINDICATORSPEEDSTATUS_H_
#define IINDICATORSPEEDSTATUS_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IIndicatorSpeedStatus interface.
 */
typedef enum
{
    IINDICATORSPEEDSTATUS_OK = 0,        /**< Operation completed successfully. */
    IINDICATORSPEEDSTATUS_NOT_OK         /**< Operation failed. */
} IIndicatorSpeedStatus_StatusType;

/**
 * @brief Structure defining the function pointers for IIndicatorSpeedStatus interface.
 */
typedef struct
{
    /**
     * @brief Write the indicator speed status.
     * @param status Indicator speed status to write.
     * @return Status of the operation.
     */
    IIndicatorSpeedStatus_StatusType (*writeIndicatorSpeedStatus)(cmIndicatorSpeedStatus status);

    /**
     * @brief Read the current indicator speed status.
     * @return Current indicator speed status.
     */
    cmIndicatorSpeedStatus (*readIndicatorSpeedStatus)(void);
} IIndicatorSpeedStatus;

/**
 * @brief Global instance of the IIndicatorSpeedStatus interface.
 */
extern IIndicatorSpeedStatus IndicatorSpeedStatusInterface;

/* Function prototypes */
/**
 * @brief Writes the indicator speed status.
 * 
 * This function sets the indicator speed status.
 * 
 * @param status The indicator speed value to write of type `cmIndicatorSpeedStatus`.
 * @return The status of the operation:
 *         - `IINDICATORSPEEDSTATUS_OK` if the operation was successful.
 *         - `IINDICATORSPEEDSTATUS_NOT_OK` if the operation failed.
 */
IIndicatorSpeedStatus_StatusType IIndicatorSpeedStatus_writeIndicatorSpeedStatus_Impl(cmIndicatorSpeedStatus status);

/**
 * @brief Reads the current indicator speed status.
 * 
 * This function retrieves the current indicator speed status.
 * 
 * @return The current indicator speed status of type `cmIndicatorSpeedStatus`.
 */
cmIndicatorSpeedStatus IIndicatorSpeedStatus_readIndicatorSpeedStatus_Impl(void);

#endif /* IINDICATORSPEEDSTATUS_H_ */
