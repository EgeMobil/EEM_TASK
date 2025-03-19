#ifndef ABSTRACT_COREMANAGER_H_
#define ABSTRACT_COREMANAGER_H_

#include "ECUStateManager_global.h"

/*************************************************************/
/* IExternalInterruptStatus : Port Name - Compu Method */
/**
 * @brief Defines the GPIO port names for external interrupt configuration.
 */
typedef enum
{
    EXTIRQ_PORTNAME_GPIOA = 0, /**< GPIO Port A */
    EXTIRQ_PORTNAME_GPIOB,     /**< GPIO Port B */
    EXTIRQ_PORTNAME_GPIOC,     /**< GPIO Port C */
    EXTIRQ_PORTNAME_GPIOD,     /**< GPIO Port D */
    EXTIRQ_PORTNAME_GPIOE,     /**< GPIO Port E */
    EXTIRQ_PORTNAME_UNKNOWN = 0xFF /**< No valid port name */
} cmExtIrqPortName;

/* IExternalInterruptStatus : Port Name - Data Constraint */
/**
 * @brief Data constraint for GPIO port names.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for port name. */
    uint8_t upperLimit;      /**< Maximum valid value for port name. */
    MonotonyType monotony;   /**< Monotony constraint for port names. */
} dcExtIrqPortName;

/*************************************************************/
/* IExternalInterruptStatus : Pin Name - Compu Method */
/**
 * @brief Defines the GPIO pin names for external interrupt configuration.
 */
typedef enum
{
    EXTIRQ_PINNAME_0 = 0,   /**< GPIO Pin 0 */
    EXTIRQ_PINNAME_1,       /**< GPIO Pin 1 */
    EXTIRQ_PINNAME_2,       /**< GPIO Pin 2 */
    EXTIRQ_PINNAME_3,       /**< GPIO Pin 3 */
    EXTIRQ_PINNAME_4,       /**< GPIO Pin 4 */
    EXTIRQ_PINNAME_5,       /**< GPIO Pin 5 */
    EXTIRQ_PINNAME_6,       /**< GPIO Pin 6 */
    EXTIRQ_PINNAME_7,       /**< GPIO Pin 7 */
    EXTIRQ_PINNAME_8,       /**< GPIO Pin 8 */
    EXTIRQ_PINNAME_9,       /**< GPIO Pin 9 */
    EXTIRQ_PINNAME_10,      /**< GPIO Pin 10 */
    EXTIRQ_PINNAME_11,      /**< GPIO Pin 11 */
    EXTIRQ_PINNAME_12,      /**< GPIO Pin 12 */
    EXTIRQ_PINNAME_13,      /**< GPIO Pin 13 */
    EXTIRQ_PINNAME_14,      /**< GPIO Pin 14 */
    EXTIRQ_PINNAME_15,      /**< GPIO Pin 15 */
    EXTIRQ_PINNAME_UNKNOWN = 0xFF /**< No valid pin name */
} cmExtIrqPinName;

/* IExternalInterruptStatus : Pin Name - Data Constraint */
/**
 * @brief Data constraint for GPIO pin names.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for pin name. */
    uint8_t upperLimit;      /**< Maximum valid value for pin name. */
    MonotonyType monotony;   /**< Monotony constraint for pin names. */
} dcExtIrqPinName;

/*************************************************************/
/* IExternalInterruptStatus : Trigger Type - Compu Method */
/**
 * @brief Defines the trigger types for external interrupts.
 */
typedef enum
{
    EXTIRQ_TRIGGERTYPE_UNKNOWN = 0,  /**< Unknown trigger type. */
    EXTIRQ_TRIGGERTYPE_RISINGEDGE,   /**< Trigger on rising edge. */
    EXTIRQ_TRIGGERTYPE_FALLINGEDGE,  /**< Trigger on falling edge. */
} cmExtIrqTriggerType;

/* IExternalInterruptStatus : Trigger Type - Data Constraint */
/**
 * @brief Data constraint for external interrupt trigger types.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for trigger type. */
    uint8_t upperLimit;      /**< Maximum valid value for trigger type. */
    MonotonyType monotony;   /**< Monotony constraint for trigger types. */
} dcExtIrqTriggerType;
/*************************************************************/

/*************************************************************/
/* ITimerInterruptStatus : Millisecond - Compu Method */
/**
 * @brief Defines the time in milliseconds for timer interrupt configuration.
 */
typedef uint32_t cmMillisecond;

/* ITimerInterruptStatus : Millisecond - Data Constraint */
/**
 * @brief Data constraint for milliseconds.
 */
typedef struct
{
    uint32_t lowerLimit;      /**< Minimum valid value for milliseconds. */
    uint32_t upperLimit;      /**< Maximum valid value for milliseconds. */
    MonotonyType monotony;    /**< Monotony constraint for milliseconds. */
} dcMillisecond;

/*************************************************************/
/* ITimerInterruptStatus : Second - Compu Method */
/**
 * @brief Defines the time in seconds for timer interrupt configuration.
 */
typedef uint8_t cmSecond;

/* ITimerInterruptStatus : Second - Data Constraint */
/**
 * @brief Data constraint for seconds.
 */
typedef struct
{
    uint8_t lowerLimit;       /**< Minimum valid value for seconds. */
    uint8_t upperLimit;       /**< Maximum valid value for seconds. */
    MonotonyType monotony;    /**< Monotony constraint for seconds. */
} dcSecond;

/*************************************************************/
/* ITimerInterruptStatus : Minute - Compu Method */
/**
 * @brief Defines the time in minutes for timer interrupt configuration.
 */
typedef uint8_t cmMinute;

/* ITimerInterruptStatus : Minute - Data Constraint */
/**
 * @brief Data constraint for minutes.
 */
typedef struct
{
    uint8_t lowerLimit;       /**< Minimum valid value for minutes. */
    uint8_t upperLimit;       /**< Maximum valid value for minutes. */
    MonotonyType monotony;    /**< Monotony constraint for minutes. */
} dcMinute;

/*************************************************************/
/* ITimerInterruptStatus : Hour - Compu Method */
/**
 * @brief Defines the time in hours for timer interrupt configuration.
 */
typedef uint8_t cmHour;

/* ITimerInterruptStatus : Hour - Data Constraint */
/**
 * @brief Data constraint for hours.
 */
typedef struct
{
    uint8_t lowerLimit;       /**< Minimum valid value for hours. */
    uint8_t upperLimit;       /**< Maximum valid value for hours. */
    MonotonyType monotony;    /**< Monotony constraint for hours. */
} dcHour;

/*************************************************************/
/* ITimerInterruptStatus : Day - Compu Method */
/**
 * @brief Defines the time in days for timer interrupt configuration.
 */
typedef uint16_t cmDay;

/* ITimerInterruptStatus : Day - Data Constraint */
/**
 * @brief Data constraint for days.
 */
typedef struct
{
    uint16_t lowerLimit;      /**< Minimum valid value for days. */
    uint16_t upperLimit;      /**< Maximum valid value for days. */
    MonotonyType monotony;    /**< Monotony constraint for days. */
} dcDay;
/*************************************************************/

/*************************************************************/
/* IGPIOStatus : pinState - Compu Method */
typedef enum
{
    GPIOSTATUS_PIN_RESET = 0, 
    GPIOSTATUS_PIN_SET,     
    GPIOSTATUS_UNKNOWN, 
} cmGPIOpinState;

/* IGPIOStatus : pinState - Data Constraint */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for port name. */
    uint8_t upperLimit;      /**< Maximum valid value for port name. */
    MonotonyType monotony;   /**< Monotony constraint for port names. */
} dcGPIOpinState;


/*************************************************************/

#endif /* ABSTRACT_COREMANAGER_H_ */