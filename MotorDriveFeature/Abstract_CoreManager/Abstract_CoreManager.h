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
    PORTNAME_GPIOA = 0, /**< GPIO Port A */
    PORTNAME_GPIOB,     /**< GPIO Port B */
    PORTNAME_GPIOC,     /**< GPIO Port C */
    PORTNAME_GPIOD,     /**< GPIO Port D */
    PORTNAME_GPIOE,     /**< GPIO Port E */
    PORTNAME_NULL = 0xFF /**< No valid port name */
} cmPortName;

/* IExternalInterruptStatus : Port Name - Data Constraint */
/**
 * @brief Data constraint for GPIO port names.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for port name. */
    uint8_t upperLimit;      /**< Maximum valid value for port name. */
    MonotonyType monotony;   /**< Monotony constraint for port names. */
} dcPortName;

/*************************************************************/
/* IExternalInterruptStatus : Pin Name - Compu Method */
/**
 * @brief Defines the GPIO pin names for external interrupt configuration.
 */
typedef enum
{
    PINNAME_0 = 0,   /**< GPIO Pin 0 */
    PINNAME_1,       /**< GPIO Pin 1 */
    PINNAME_2,       /**< GPIO Pin 2 */
    PINNAME_3,       /**< GPIO Pin 3 */
    PINNAME_4,       /**< GPIO Pin 4 */
    PINNAME_5,       /**< GPIO Pin 5 */
    PINNAME_6,       /**< GPIO Pin 6 */
    PINNAME_7,       /**< GPIO Pin 7 */
    PINNAME_8,       /**< GPIO Pin 8 */
    PINNAME_9,       /**< GPIO Pin 9 */
    PINNAME_10,      /**< GPIO Pin 10 */
    PINNAME_11,      /**< GPIO Pin 11 */
    PINNAME_12,      /**< GPIO Pin 12 */
    PINNAME_13,      /**< GPIO Pin 13 */
    PINNAME_14,      /**< GPIO Pin 14 */
    PINNAME_15,      /**< GPIO Pin 15 */
    PINNAME_NULL = 0xFF /**< No valid pin name */
} cmPinName;

/* IExternalInterruptStatus : Pin Name - Data Constraint */
/**
 * @brief Data constraint for GPIO pin names.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for pin name. */
    uint8_t upperLimit;      /**< Maximum valid value for pin name. */
    MonotonyType monotony;   /**< Monotony constraint for pin names. */
} dcPinName;

/*************************************************************/
/* IExternalInterruptStatus : Trigger Type - Compu Method */
/**
 * @brief Defines the trigger types for external interrupts.
 */
typedef enum
{
    TRIGGERTYPE_UNKNOWN = 0,  /**< Unknown trigger type. */
    TRIGGERTYPE_RISINGEDGE,   /**< Trigger on rising edge. */
    TRIGGERTYPE_FALLINGEDGE,  /**< Trigger on falling edge. */
} cmTriggerType;

/* IExternalInterruptStatus : Trigger Type - Data Constraint */
/**
 * @brief Data constraint for external interrupt trigger types.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for trigger type. */
    uint8_t upperLimit;      /**< Maximum valid value for trigger type. */
    MonotonyType monotony;   /**< Monotony constraint for trigger types. */
} dcTriggerType;
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

#endif /* ABSTRACT_COREMANAGER_H_ */