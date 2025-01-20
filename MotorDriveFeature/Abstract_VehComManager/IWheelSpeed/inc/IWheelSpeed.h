#ifndef IWHEELSPEED_H_
#define IWHEELSPEED_H_

#include "Abstract_VehComManager.h"

/**
 * @brief Status type for the IWheelSpeed interface.
 */
typedef enum
{
    IWHEELSPEED_OK = 0,        /**< Operation completed successfully. */
    IWHEELSPEED_NOT_OK         /**< Operation failed. */
} IWheelSpeed_StatusType;

/**
 * @brief Structure defining the function pointers for IWheelSpeed interface.
 */
typedef struct
{
    /**
     * @brief Write the wheel speed.
     * @param speed Wheel speed to write.
     * @return Status of the operation.
     */
    IWheelSpeed_StatusType (*writeWheelSpeed)(cmWheelSpeed speed);

    /**
     * @brief Read the current wheel speed.
     * @return Current wheel speed.
     */
    cmWheelSpeed (*readWheelSpeed)(void);
} IWheelSpeed;

/**
 * @brief Global instance of the IWheelSpeed interface.
 */
extern IWheelSpeed WheelSpeedInterface;

/* Function prototypes */
/**
 * @brief Writes the wheel speed.
 * 
 * @param speed The wheel speed value to write of type `cmWheelSpeed`.
 * @return The status of the operation:
 *         - `IWHEELSPEED_OK` if the operation was successful.
 *         - `IWHEELSPEED_NOT_OK` if the operation failed.
 */
IWheelSpeed_StatusType IWheelSpeed_writeWheelSpeed_Impl(cmWheelSpeed speed);

/**
 * @brief Reads the current wheel speed.
 * 
 * @return The current wheel speed of type `cmWheelSpeed`.
 */
cmWheelSpeed IWheelSpeed_readWheelSpeed_Impl(void);

#endif /* IWHEELSPEED_H_ */
