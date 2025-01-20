#ifndef IGPIOSTATUS_H_
#define IGPIOSTATUS_H_

#include "Abstract_CoreManager.h"

typedef enum
{
    IGPIOSTATUS_OK = 0,
    IGPIOSTATUS_NOT_OK
}IGPIOStatus_StatusType;

/**
 * @brief Enum for GPIO ports.
 */
typedef enum
{
    IGPIOSTATUS_PORT_A = 0, /**< GPIO Port A */
    IGPIOSTATUS_PORT_B,     /**< GPIO Port B */
    IGPIOSTATUS_PORT_C,     /**< GPIO Port C */
    IGPIOSTATUS_PORT_D,     /**< GPIO Port D */
    IGPIOSTATUS_PORT_E,     /**< GPIO Port E */
    IGPIOSTATUS_PORT_F      /**< GPIO Port F */
}IGPIOStatus_GPIOPort;

/**
 * @brief Enum for GPIO pins.
 */
typedef enum
{
    IGPIOSTATUS_PIN_0 = 0, /**< GPIO Pin 0 */
    IGPIOSTATUS_PIN_1,     /**< GPIO Pin 1 */
    IGPIOSTATUS_PIN_2,     /**< GPIO Pin 2 */
    IGPIOSTATUS_PIN_3,     /**< GPIO Pin 3 */
    IGPIOSTATUS_PIN_4,     /**< GPIO Pin 4 */
    IGPIOSTATUS_PIN_5,     /**< GPIO Pin 5 */
    IGPIOSTATUS_PIN_6,     /**< GPIO Pin 6 */
    IGPIOSTATUS_PIN_7,     /**< GPIO Pin 7 */
    IGPIOSTATUS_PIN_8,     /**< GPIO Pin 8 */
    IGPIOSTATUS_PIN_9,     /**< GPIO Pin 9 */
    IGPIOSTATUS_PIN_10,    /**< GPIO Pin 10 */
    IGPIOSTATUS_PIN_11,    /**< GPIO Pin 11 */
    IGPIOSTATUS_PIN_12,    /**< GPIO Pin 12 */
    IGPIOSTATUS_PIN_13,    /**< GPIO Pin 13 */
    IGPIOSTATUS_PIN_14,    /**< GPIO Pin 14 */
    IGPIOSTATUS_PIN_15     /**< GPIO Pin 15 */
}IGPIOStatus_GPIOPin;

/**
 * @brief Structure defining the function pointers for IGPIOStatus interface.
 */
typedef struct
{
    /**
     * @brief Write the state of a GPIO pin.
     * @param pinState State to write.
     * @param port GPIO port (enum type).
     * @param pin GPIO pin (enum type).
     * @return Status of the operation.
     */
    IGPIOStatus_StatusType (*writePinState)(cmGPIOpinState pinState, IGPIOStatus_GPIOPort port, IGPIOStatus_GPIOPin pin);

    /**
     * @brief Read the current state of a GPIO pin.
     * @param port GPIO port (enum type).
     * @param pin GPIO pin (enum type).
     * @return Current state of the GPIO pin.
     */
    cmGPIOpinState (*readPinState)(IGPIOStatus_GPIOPort port, IGPIOStatus_GPIOPin pin);
} IGPIOStatus;

/**
 * @brief Global instance of the IGPIOStatus interface.
 */
extern IGPIOStatus GPIOStatusInterface;

/* Function prototypes */
IGPIOStatus_StatusType IGPIOStatus_writePinState_Impl(cmGPIOpinState pinState, IGPIOStatus_GPIOPort port, IGPIOStatus_GPIOPin pin);
cmGPIOpinState IGPIOStatus_readPinState_Impl(IGPIOStatus_GPIOPort port, IGPIOStatus_GPIOPin pin);

#endif /* IGPIOSTATUS_H_ */