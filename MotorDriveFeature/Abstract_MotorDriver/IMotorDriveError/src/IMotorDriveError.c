#include "IMotorDriveError.h"

/**
 * @brief Instance of the IMotorDriveError interface.
 */
IMotorDriveError MotorDriveErrorInterface = {
    .writeMotorDriveError = IMotorDriveError_writeMotorDriveError_Impl,
    .readMotorDriveError = IMotorDriveError_readMotorDriveError_Impl,
};

/* Static variable for storing current motor drive error status */
static cmMotorDriveError currentMotorDriveError = { .byte = 0x00000000 }; // Default to 0 (No errors)

/**
 * @brief Implementation for writing the motor drive error status.
 * @param status Motor drive error status to write.
 * @return Status of the operation.
 */
IMotorDriveError_StatusType IMotorDriveError_writeMotorDriveError_Impl(cmMotorDriveError status)
{
    // Basic validation for example, can be extended as needed
    if (status.byte > 0xFFFFFFFF)
    {
#ifndef STM32G431xx
        printf("[IMotorDriveError] Invalid motor drive error status value: 0x%08X\n", status.byte);
#endif
        return IMOTORDRIVEERROR_NOT_OK;
    }

    currentMotorDriveError = status;

#ifndef STM32G431xx
    printf("[IMotorDriveError] Motor drive error status written:\n");
    printf("PWM: %d, BDR: %d, IRQ: %d, SPEED: %d, GDR: 0x%04X\n",
           status.pwm, status.bdr, status.irq, status.speed, status.gdr);
#endif

    return IMOTORDRIVEERROR_OK;
}

/**
 * @brief Implementation for reading the motor drive error status.
 * @return Current motor drive error status.
 */
cmMotorDriveError IMotorDriveError_readMotorDriveError_Impl(void)
{
#ifndef STM32G431xx
    printf("[IMotorDriveError] Motor drive error status read:\n");
    printf("PWM: %d, BDR: %d, IRQ: %d, SPEED: %d, GDR: 0x%04X\n",
           currentMotorDriveError.pwm,
           currentMotorDriveError.bdr,
           currentMotorDriveError.irq,
           currentMotorDriveError.speed,
           currentMotorDriveError.gdr);
#endif

    return currentMotorDriveError;
}
