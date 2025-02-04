#include "IGPIOStatus.h"
#include <stdio.h>


/**
 * @brief Instance of the IGPIOStatus interface.
 */
IGPIOStatus GPIOStatusInterface = {
    .writePinState = IGPIOStatus_writePinState_Impl,
    .readPinState = IGPIOStatus_readPinState_Impl
};

/* Static array for storing current states of all GPIO ports and pins */
static cmGPIOpinState GPIOStateMap[IGPIOSTATUS_PORT_F + 1][IGPIOSTATUS_PIN_15 + 1] = {
    /* Port A */
    {
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN
    },
    /* Port B */
    {
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN
    },
    /* Port C */
    {
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN
    },
    /* Port D */
    {
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN
    },
    /* Port E */
    {
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN
    },
    /* Port F */
    {
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN,
        GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN, GPIOSTATUS_UNKNOWN
    }
};

/**
 * @brief Implementation for writing the GPIO pin state.
 * @param pinState State to write.
 * @param port GPIO port (enum type).
 * @param pin GPIO pin (enum type).
 * @return Status of the operation.
 */
IGPIOStatus_StatusType IGPIOStatus_writePinState_Impl(cmGPIOpinState pinState, IGPIOStatus_GPIOPort port, IGPIOStatus_GPIOPin pin)
{
    /* Validate port and pin */
    if (port < IGPIOSTATUS_PORT_A || port > IGPIOSTATUS_PORT_F || pin < IGPIOSTATUS_PIN_0 || pin > IGPIOSTATUS_PIN_15)
    {
#ifndef STM32G431xx
        printf("[IGPIOStatus] Invalid port (%d) or pin (%d).\n", port, pin);
#endif
        return IGPIOSTATUS_NOT_OK;
    }

    /* Call HAL function to actually set the pin state */
    IGPIOStatus_StatusType status = IGPIOStatus_writePinState_HAL(pinState, port, pin);

    if (status == IGPIOSTATUS_OK)
    {
        /* Cache the written state in case it's needed later */
        GPIOStateMap[port][pin] = pinState;
    }

#ifndef STM32G431xx
    printf("[IGPIOStatus] Port %d, Pin %d state written: %d\n", port, pin, pinState);
#endif

    return status;
}

/**
 * @brief Implementation for reading the GPIO pin state.
 * @param port GPIO port (enum type).
 * @param pin GPIO pin (enum type).
 * @return Current state of the GPIO pin.
 */
cmGPIOpinState IGPIOStatus_readPinState_Impl(IGPIOStatus_GPIOPort port, IGPIOStatus_GPIOPin pin)
{
    /* Validate port and pin */
    if (port < IGPIOSTATUS_PORT_A || port > IGPIOSTATUS_PORT_F || pin < IGPIOSTATUS_PIN_0 || pin > IGPIOSTATUS_PIN_15)
    {
#ifndef STM32G431xx
        printf("[IGPIOStatus] Invalid port (%d) or pin (%d).\n", port, pin);
#endif
        return GPIOSTATUS_UNKNOWN;
    }

    /* Call HAL function to get the actual pin state */
    GPIOStateMap[port][pin] = IGPIOStatus_readPinState_HAL(port, pin);

#ifndef STM32G431xx
    printf("[IGPIOStatus] Port %d, Pin %d state read: %d\n", port, pin, currentState);
#endif

    return GPIOStateMap[port][pin];
}

/**
 * @brief Initializes GPIOStateMap with current HAL GPIO states.
 * This function must be called at system startup.
 */
void IGPIOStatus_Init(void)
{
    for (IGPIOStatus_GPIOPort port = IGPIOSTATUS_PORT_A; port <= IGPIOSTATUS_PORT_F; port++)
    {
        for (IGPIOStatus_GPIOPin pin = IGPIOSTATUS_PIN_0; pin <= IGPIOSTATUS_PIN_15; pin++)
        {
            GPIOStateMap[port][pin] = IGPIOStatus_readPinState_HAL(port, pin);
        }
    }
}
