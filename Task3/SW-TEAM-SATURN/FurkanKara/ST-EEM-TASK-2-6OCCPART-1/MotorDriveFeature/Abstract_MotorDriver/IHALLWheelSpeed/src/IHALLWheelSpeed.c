#include "IHALLWheelSpeed.h"

/**
 * @brief Instance of the IHALLWheelSpeed interface.
 */
IHALLWheelSpeed HALLWheelSpeedInterface = {
    .writeHALLWheelSpeed = IHALLWheelSpeed_writeHALLWheelSpeed_Impl,
    .readHALLWheelSpeed = IHALLWheelSpeed_readHALLWheelSpeed_Impl,
};

/* Static variable for storing current HALL wheel speed */
static cmHALLWheelSpeed currentHALLWheelSpeed = 0; // Default to 0

/**
 * @brief Implementation for writing the HALL wheel speed.
 * @param speed HALL wheel speed to write.
 * @return Status of the operation.
 */
IHALLWheelSpeed_StatusType IHALLWheelSpeed_writeHALLWheelSpeed_Impl(cmHALLWheelSpeed speed)
{
#ifndef STM32G431xx
    printf("[IHALLWheelSpeed] Invalid HALL wheel speed value: %u\n", speed);
#endif
    // Validate speed against constraints (example: max value of 65535 for uint16_t)
    if (speed > 0xFFFE)
    {
        return IHALLWHEELSPEED_NOT_OK;
    }

    currentHALLWheelSpeed = speed;

#ifndef STM32G431xx
    printf("[IHALLWheelSpeed] HALL wheel speed written: %u\n", speed);
#endif

    return IHALLWHEELSPEED_OK;
}

/**
 * @brief Implementation for reading the HALL wheel speed.
 * @return Current HALL wheel speed.
 */
cmHALLWheelSpeed IHALLWheelSpeed_readHALLWheelSpeed_Impl(void)
{
#ifndef STM32G431xx
    printf("[IHALLWheelSpeed] HALL wheel speed read: %u\n", currentHALLWheelSpeed);
#endif
    return currentHALLWheelSpeed;
}
