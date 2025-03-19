#ifndef IINDICATOR_H_
#define IINDICATOR_H_

#include "Abstract_VehComManager.h"

/**
 * @brief Status type for the IIndicator interface.
 */
typedef enum
{
    IINDICATOR_OK = 0,        /**< Operation completed successfully. */
    IINDICATOR_NOT_OK         /**< Operation failed. */
} IIndicator_StatusType;

/**
 * @brief Structure defining the function pointers for IIndicator interface.
 */
typedef struct
{
    /**
     * @brief Write the indicator value.
     * @param value Indicator value to write.
     * @return Status of the operation.
     */
    IIndicator_StatusType (*writeIndicator)(cmIndicator value);

    /**
     * @brief Read the current indicator value.
     * @return Current indicator value.
     */
    cmIndicator (*readIndicator)(void);
} IIndicator;

/**
 * @brief Global instance of the IIndicator interface.
 */
extern IIndicator IndicatorInterface;

/* Function prototypes */
/**
 * @brief Writes the indicator value.
 * 
 * @param value The indicator value to write of type `cmIndicator`.
 * @return The status of the operation:
 *         - `IINDICATOR_OK` if the operation was successful.
 *         - `IINDICATOR_NOT_OK` if the operation failed.
 */
IIndicator_StatusType IIndicator_writeIndicator_Impl(cmIndicator value);

/**
 * @brief Reads the current indicator value.
 * 
 * @return The current indicator value of type `cmIndicator`.
 */
cmIndicator IIndicator_readIndicator_Impl(void);

#endif /* IINDICATOR_H_ */
