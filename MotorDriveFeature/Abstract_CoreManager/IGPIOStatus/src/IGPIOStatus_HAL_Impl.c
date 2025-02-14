#include "IGPIOStatus.h"
#include "stm32g4xx_hal.h"

/**
 * @brief Converts IGPIOStatus_GPIOPort enum to HAL GPIO_TypeDef*.
 * @param port IGPIOStatus_GPIOPort enum value.
 * @return Corresponding GPIO_TypeDef* or NULL if invalid.
 */
static GPIO_TypeDef* IGPIOStatus_ConvertPort(IGPIOStatus_GPIOPort port)
{
    static GPIO_TypeDef* portTable[] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF};

    if (port >= IGPIOSTATUS_PORT_A && port <= IGPIOSTATUS_PORT_F)
    {
        return portTable[port];
    }
    return NULL;
}

/**
 * @brief Converts IGPIOStatus_GPIOPin enum to HAL GPIO pin mask.
 * @param pin IGPIOStatus_GPIOPin enum value.
 * @return Corresponding GPIO_Pin mask.
 */
static uint16_t IGPIOStatus_ConvertPin(IGPIOStatus_GPIOPin pin)
{
    if (pin >= IGPIOSTATUS_PIN_0 && pin <= IGPIOSTATUS_PIN_15)
    {
        return (1 << pin);
    }
    return 0;
}

/**
 * @brief Writes the state of a GPIO pin using STM32 HAL.
 * @param pinState State to write (HIGH or LOW).
 * @param port GPIO port (enum type).
 * @param pin GPIO pin (enum type).
 * @return Status of the operation.
 */
IGPIOStatus_StatusType IGPIOStatus_writePinState_HAL(cmGPIOpinState pinState, IGPIOStatus_GPIOPort port, IGPIOStatus_GPIOPin pin)
{
    GPIO_TypeDef* gpioPort = IGPIOStatus_ConvertPort(port);
    uint16_t gpioPin = IGPIOStatus_ConvertPin(pin);

    if (gpioPort == NULL || gpioPin == 0)
    {
        return IGPIOSTATUS_NOT_OK;
    }

    HAL_GPIO_WritePin(gpioPort, gpioPin, (pinState == GPIOSTATUS_PIN_SET) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    return IGPIOSTATUS_OK;
}


/**
 * @brief Reads the state of a GPIO pin using STM32 HAL.
 * @param port GPIO port (enum type).
 * @param pin GPIO pin (enum type).
 * @return Current state of the GPIO pin.
 */
cmGPIOpinState IGPIOStatus_readPinState_HAL(IGPIOStatus_GPIOPort port, IGPIOStatus_GPIOPin pin)
{
    GPIO_TypeDef* gpioPort = IGPIOStatus_ConvertPort(port);
    uint16_t gpioPin = IGPIOStatus_ConvertPin(pin);

    if (gpioPort == NULL || gpioPin == 0)
    {
        return GPIOSTATUS_UNKNOWN;
    }

    GPIO_PinState halPinState = HAL_GPIO_ReadPin(gpioPort, gpioPin);
    return (halPinState == GPIO_PIN_SET) ? GPIOSTATUS_PIN_SET : GPIOSTATUS_PIN_RESET;
}

