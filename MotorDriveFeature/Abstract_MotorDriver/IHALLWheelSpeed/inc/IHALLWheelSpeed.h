#ifndef IHALLWHEELSPEED_H_
#define IHALLWHEELSPEED_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IHALLWheelSpeed interface.
 */
typedef enum
{
    IHALLWHEELSPEED_OK = 0,        /**< Operation completed successfully. */
    IHALLWHEELSPEED_NOT_OK         /**< Operation failed. */
} IHALLWheelSpeed_StatusType;

/**
 * @brief Structure defining the function pointers for IHALLWheelSpeed interface.
 */
typedef struct
{
    /**
     * @brief Write the HALL wheel speed.
     * @param speed HALL wheel speed to write.
     * @return Status of the operation.
     */
    IHALLWheelSpeed_StatusType (*writeHALLWheelSpeed)(cmHALLWheelSpeed speed);

    /**
     * @brief Read the current HALL wheel speed.
     * @return Current HALL wheel speed.
     */
    cmHALLWheelSpeed (*readHALLWheelSpeed)(void);
} IHALLWheelSpeed;

/**
 * @brief Global instance of the IHALLWheelSpeed interface.
 */
extern IHALLWheelSpeed HALLWheelSpeedInterface;

/* Function prototypes */
/**
 * @brief Writes the HALL wheel speed.
 * 
 * @param speed The HALL wheel speed value to write of type `cmHALLWheelSpeed`.
 * @return The status of the operation:
 *         - `IHALLWHEELSPEED_OK` if the operation was successful.
 *         - `IHALLWHEELSPEED_NOT_OK` if the operation failed.
 */
IHALLWheelSpeed_StatusType IHALLWheelSpeed_writeHALLWheelSpeed_Impl(cmHALLWheelSpeed speed);

/**
 * @brief Reads the current HALL wheel speed.
 * 
 * @return The current HALL wheel speed of type `cmHALLWheelSpeed`.
 */
cmHALLWheelSpeed IHALLWheelSpeed_readHALLWheelSpeed_Impl(void);

#endif /* IHALLWHEELSPEED_H_ */
