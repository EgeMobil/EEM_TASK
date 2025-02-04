#include "IWheelSpeed.h"

/**
 * @brief Instance of the IWheelSpeed interface.
 */
IWheelSpeed WheelSpeedInterface = {
    .writeWheelSpeed = IWheelSpeed_writeWheelSpeed_Impl,
    .readWheelSpeed = IWheelSpeed_readWheelSpeed_Impl,
};

/* Static variable for storing current wheel speed */
static cmWheelSpeed currentWheelSpeed = 0; // Default to 0

/**
 * @brief Implementation for writing the wheel speed.
 * @param speed Wheel speed to write.
 * @return Status of the operation.
 */
IWheelSpeed_StatusType IWheelSpeed_writeWheelSpeed_Impl(cmWheelSpeed speed)
{
    // Example validation: Ensure value is within uint16_t range
    if (speed > 0xFFFE)
    {
#ifndef STM32G431xx
        printf("[IWheelSpeed] Invalid wheel speed value: %u\n", speed);
        #endif
        return IWHEELSPEED_NOT_OK;
    }

    currentWheelSpeed = speed;
#ifndef STM32G431xx
    printf("[IWheelSpeed] Wheel speed written: %u\n", speed);
    #endif
    return IWHEELSPEED_OK;
}

/**
 * @brief Implementation for reading the wheel speed.
 * @return Current wheel speed.
 */
cmWheelSpeed IWheelSpeed_readWheelSpeed_Impl(void)
{    
#ifndef STM32G431xx
    printf("[IWheelSpeed] Wheel speed read: %u\n", currentWheelSpeed);
    #endif
    return currentWheelSpeed;
}
