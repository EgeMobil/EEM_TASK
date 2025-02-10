#include "IGPIOStatus.h"

#ifdef STM32G4xx  // STM32 platformundaysa
#include "stm32g4xx_hal.h"
#endif

/**
 * @brief Converts IGPIOStatus_GPIOPort enum to HAL GPIO_TypeDef*.
 * @param port IGPIOStatus_GPIOPort enum value.
 * @return Corresponding GPIO_TypeDef* or NULL if invalid.
 */
static
#ifdef STM32G4xx 
 GPIO_TypeDef* 
#else
 void*
#endif
 IGPIOStatus_ConvertPort(IGPIOStatus_GPIOPort port)
{
#ifdef STM32G4xx 
    static GPIO_TypeDef* portTable[] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF};

    if (port >= IGPIOSTATUS_PORT_A && port <= IGPIOSTATUS_PORT_F)
    {
        return portTable[port];
    }
    return NULL;
#else
    printf("IGPIOStatus_ConvertPort called with port %d\n", port);
    return NULL;
#endif
}

/**
 * @brief Converts IGPIOStatus_GPIOPin enum to HAL GPIO pin mask.
 * @param pin IGPIOStatus_GPIOPin enum value.
 * @return Corresponding GPIO_Pin mask.
 */
static uint16_t IGPIOStatus_ConvertPin(IGPIOStatus_GPIOPin pin)
{
#ifdef STM32G4xx 
    if (pin >= IGPIOSTATUS_PIN_0 && pin <= IGPIOSTATUS_PIN_15)
    {
        return (1 << pin);
    }
    return 0;
#else
    printf("IGPIOStatus_ConvertPin called with pin %d\n", pin);
    return 0;
#endif
}

/**
 * @brief Writes the state of a GPIO pin.
 * @param pinState State to write (HIGH or LOW).
 * @param port GPIO port (enum type).
 * @param pin GPIO pin (enum type).
 * @return Status of the operation.
 */
IGPIOStatus_StatusType IGPIOStatus_writePinState_HAL(cmGPIOpinState pinState, IGPIOStatus_GPIOPort port, IGPIOStatus_GPIOPin pin)
{
#ifdef STM32G4xx
    GPIO_TypeDef* gpioPort = IGPIOStatus_ConvertPort(port);
    uint16_t gpioPin = IGPIOStatus_ConvertPin(pin);

    if (gpioPort == NULL || gpioPin == 0)
    {
        return IGPIOSTATUS_NOT_OK;
    }

    HAL_GPIO_WritePin(gpioPort, gpioPin, (pinState == GPIOSTATUS_PIN_SET) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    return IGPIOSTATUS_OK;
#else
    printf("IGPIOStatus_writePinState_HAL called with pinState %d, port %d, pin %d\n", pinState, port, pin);
    return IGPIOSTATUS_NOT_OK;
#endif
}

/**
 * @brief Reads the state of a GPIO pin.
 * @param port GPIO port (enum type).
 * @param pin GPIO pin (enum type).
 * @return Current state of the GPIO pin.
 */
cmGPIOpinState IGPIOStatus_readPinState_HAL(IGPIOStatus_GPIOPort port, IGPIOStatus_GPIOPin pin)
{
#ifdef STM32G4xx
    GPIO_TypeDef* gpioPort = IGPIOStatus_ConvertPort(port);
    uint16_t gpioPin = IGPIOStatus_ConvertPin(pin);

    if (gpioPort == NULL || gpioPin == 0)
    {
        return GPIOSTATUS_UNKNOWN;
    }

    GPIO_PinState halPinState = HAL_GPIO_ReadPin(gpioPort, gpioPin);
    return (halPinState == GPIO_PIN_SET) ? GPIOSTATUS_PIN_SET : GPIOSTATUS_PIN_RESET;
#else
    printf("IGPIOStatus_readPinState_HAL called with port %d, pin %d\n", port, pin);
    return GPIOSTATUS_UNKNOWN;
#endif
}
