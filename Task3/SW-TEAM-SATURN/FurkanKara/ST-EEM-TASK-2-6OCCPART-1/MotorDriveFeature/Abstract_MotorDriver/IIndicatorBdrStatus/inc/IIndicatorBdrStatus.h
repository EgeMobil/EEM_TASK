#ifndef IINDICATORBDRSTATUS_H_
#define IINDICATORBDRSTATUS_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IIndicatorBdrStatus interface.
 */
typedef enum
{
    IINDICATORBDRSTATUS_OK = 0,        /**< Operation completed successfully. */
    IINDICATORBDRSTATUS_NOT_OK         /**< Operation failed. */
} IIndicatorBdrStatus_StatusType;

/**
 * @brief Structure defining the function pointers for IIndicatorBdrStatus interface.
 */
typedef struct
{
    /**
     * @brief Write the indicator BDR status.
     * @param status Indicator BDR status to write.
     * @return Status of the operation.
     */
    IIndicatorBdrStatus_StatusType (*writeIndicatorBdrStatus)(cmIndicatorBdrStatus status);

    /**
     * @brief Read the current indicator BDR status.
     * @return Current indicator BDR status.
     */
    cmIndicatorBdrStatus (*readIndicatorBdrStatus)(void);
} IIndicatorBdrStatus;

/**
 * @brief Global instance of the IIndicatorBdrStatus interface.
 */
extern IIndicatorBdrStatus IndicatorBdrStatusInterface;

/* Function prototypes */
/**
 * @brief Writes the indicator BDR status.
 * 
 * This function sets the indicator BDR status.
 * 
 * @param status The indicator BDR value to write of type `cmIndicatorBdrStatus`.
 * @return The status of the operation:
 *         - `IINDICATORBDRSTATUS_OK` if the operation was successful.
 *         - `IINDICATORBDRSTATUS_NOT_OK` if the operation failed.
 */
IIndicatorBdrStatus_StatusType IIndicatorBdrStatus_writeIndicatorBdrStatus_Impl(cmIndicatorBdrStatus status);

/**
 * @brief Reads the current indicator BDR status.
 * 
 * This function retrieves the current indicator BDR status.
 * 
 * @return The current indicator BDR status of type `cmIndicatorBdrStatus`.
 */
cmIndicatorBdrStatus IIndicatorBdrStatus_readIndicatorBdrStatus_Impl(void);

#endif /* IINDICATORBDRSTATUS_H_ */
