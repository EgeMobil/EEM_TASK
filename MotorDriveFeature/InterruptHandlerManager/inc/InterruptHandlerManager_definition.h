/**
 * @file InterruptHandlerManager_definition.h
 * @brief Definition header file for the Interrupt Handler Manager.
 * 
 * This file defines the core structures, types, and aliases used by the 
 * Interrupt Handler Manager. It includes configurations for managing external 
 * interrupts, timer interrupts, and Hall sensor data. Additionally, it provides 
 * type definitions for managing states, flags, and counts associated with 
 * interrupts and sensors.
 * 
 * Key functionalities include:
 * - Type definitions for external and timer interrupts.
 * - Configuration structures for managing IRQs and Hall sensors.
 * - Integration of external interfaces such as `IExternalInterruptStatus`, 
 *   `ITimerInterruptStatus`, and Hall interfaces (`IHALLA`, `IHALLB`, `IHALLC`).
 * 
 * This file serves as the foundational definition file for the module, 
 * facilitating clear interaction between the manager and its components.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#ifndef INTERRUPTHANDLERMANAGER_INC_INTERRUPTHANDLERMANAGER_DEFINITION_H_
#define INTERRUPTHANDLERMANAGER_INC_INTERRUPTHANDLERMANAGER_DEFINITION_H_

#include "ECUStateManager_global.h"

#include "IExternalInterruptStatus.h"
#include "ITimerInterruptStatus.h"

#include "IHALLA.h"
#include "IHALLB.h"
#include "IHALLC.h"

/**
 * @brief Enum for Interrupt Handler Manager return values.
 * 
 * Represents the possible return values of the interrupt handler manager.
 */
typedef enum
{
    IHM_ERR = 0,     /**< Error occurred. */
    IHM_EOK,         /**< Operation successful. */
    IHM_UNKNOWN      /**< Unknown state. */
} dtIhmReturn;

/**
 * @brief Alias for Interrupt Handler Manager return type.
 */
typedef dtIhmReturn dtInterruptHandlerManager_ihmReturn;

/**
 * @brief Alias for port name type in Interrupt Handler Manager.
 */
typedef cmPortName dtInterruptHandlerManager_portName;

/**
 * @brief Alias for pin name type in Interrupt Handler Manager.
 */
typedef cmPinName dtInterruptHandlerManager_pinName;

/**
 * @brief Alias for trigger type in Interrupt Handler Manager.
 */
typedef cmTriggerType dtInterruptHandlerManager_triggerType;

/**
 * @brief Alias for millisecond type in Interrupt Handler Manager.
 */
typedef cmMillisecond dtInterruptHandlerManager_millisecond;

/**
 * @brief Alias for second type in Interrupt Handler Manager.
 */
typedef cmSecond dtInterruptHandlerManager_second;

/**
 * @brief Alias for minute type in Interrupt Handler Manager.
 */
typedef cmMinute dtInterruptHandlerManager_minute;

/**
 * @brief Alias for hour type in Interrupt Handler Manager.
 */
typedef cmHour dtInterruptHandlerManager_hour;

/**
 * @brief Alias for day type in Interrupt Handler Manager.
 */
typedef cmDay dtInterruptHandlerManager_day;

/**
 * @brief Alias for Hall A state status in Interrupt Handler Manager.
 */
typedef cmHallAStateStatus dtInterruptHandlerManager_HallAStateStatus;

/**
 * @brief Alias for Hall B state status in Interrupt Handler Manager.
 */
typedef cmHallBStateStatus dtInterruptHandlerManager_HallBStateStatus;

/**
 * @brief Alias for Hall C state status in Interrupt Handler Manager.
 */
typedef cmHallCStateStatus dtInterruptHandlerManager_HallCStateStatus;

/**
 * @brief Alias for Hall A falling edge flag in Interrupt Handler Manager.
 */
typedef cmFallingEdgeAFlag dtInterruptHandlerManager_FallingEdgeAFlag;

/**
 * @brief Alias for Hall B falling edge flag in Interrupt Handler Manager.
 */
typedef cmFallingEdgeBFlag dtInterruptHandlerManager_FallingEdgeBFlag;

/**
 * @brief Alias for Hall C falling edge flag in Interrupt Handler Manager.
 */
typedef cmFallingEdgeCFlag dtInterruptHandlerManager_FallingEdgeCFlag;

/**
 * @brief Alias for Hall A rising edge flag in Interrupt Handler Manager.
 */
typedef cmRisingEdgeAFlag dtInterruptHandlerManager_RisingEdgeAFlag;

/**
 * @brief Alias for Hall B rising edge flag in Interrupt Handler Manager.
 */
typedef cmRisingEdgeBFlag dtInterruptHandlerManager_RisingEdgeBFlag;

/**
 * @brief Alias for Hall C rising edge flag in Interrupt Handler Manager.
 */
typedef cmRisingEdgeCFlag dtInterruptHandlerManager_RisingEdgeCFlag;

/**
 * @brief Alias for Hall A falling edge count in Interrupt Handler Manager.
 */
typedef cmFallingEdgeACount dtInterruptHandlerManager_FallingEdgeACount;

/**
 * @brief Alias for Hall B falling edge count in Interrupt Handler Manager.
 */
typedef cmFallingEdgeBCount dtInterruptHandlerManager_FallingEdgeBCount;

/**
 * @brief Alias for Hall C falling edge count in Interrupt Handler Manager.
 */
typedef cmFallingEdgeCCount dtInterruptHandlerManager_FallingEdgeCCount;

/**
 * @brief Alias for Hall A rising edge count in Interrupt Handler Manager.
 */
typedef cmRisingEdgeACount dtInterruptHandlerManager_RisingEdgeACount;

/**
 * @brief Alias for Hall B rising edge count in Interrupt Handler Manager.
 */
typedef cmRisingEdgeBCount dtInterruptHandlerManager_RisingEdgeBCount;

/**
 * @brief Alias for Hall C rising edge count in Interrupt Handler Manager.
 */
typedef cmRisingEdgeCCount dtInterruptHandlerManager_RisingEdgeCCount;


/**
 * @brief Configuration structure for External IRQ management.
 * 
 * This structure provides configuration attributes and associated getter 
 * and setter function pointers for managing external interrupts.
 * 
 * The attributes include port, pin, and trigger type configurations. 
 * Getter and setter functions allow dynamic access and modification of 
 * these attributes during runtime.
 */
typedef struct 
{
    /* Configuration attributes */
    dtInterruptHandlerManager_portName port;     /**< Port configuration for external IRQ. */
    dtInterruptHandlerManager_pinName pin;       /**< Pin configuration for external IRQ. */
    dtInterruptHandlerManager_triggerType trigger; /**< Trigger type configuration for external IRQ. */

    /* Getter/Setter for configuration */
    /**
     * @brief Sets the port configuration.
     * @param port Port configuration to set.
     * @return void
     */
    void (*setPort)(dtInterruptHandlerManager_portName port);

    /**
     * @brief Gets the current port configuration.
     * @return Current port configuration.
     */
    dtInterruptHandlerManager_portName (*getPort)(void);

    /**
     * @brief Sets the pin configuration.
     * @param pin Pin configuration to set.
     * @return void
     */
    void (*setPin)(dtInterruptHandlerManager_pinName pin);

    /**
     * @brief Gets the current pin configuration.
     * @return Current pin configuration.
     */
    dtInterruptHandlerManager_pinName (*getPin)(void);

    /**
     * @brief Sets the trigger type configuration.
     * @param trigger Trigger type configuration to set.
     * @return void
     */
    void (*setTrigger)(dtInterruptHandlerManager_triggerType trigger);

    /**
     * @brief Gets the current trigger type configuration.
     * @return Current trigger type configuration.
     */
    dtInterruptHandlerManager_triggerType (*getTrigger)(void);

} ihmExternalIrqConfiguration;

/**
 * @brief Configuration structure for Timer IRQ management.
 * 
 * This structure provides configuration attributes and corresponding 
 * getter and setter function pointers for managing timer interrupts.
 * 
 * The attributes include millisecond, second, minute, hour, and day configurations.
 * Getter and setter functions allow dynamic access and modification of these values.
 */
typedef struct 
{
    /* Configuration attributes */
    dtInterruptHandlerManager_millisecond ms; /**< Millisecond configuration for timer IRQ. */
    dtInterruptHandlerManager_second sec;     /**< Second configuration for timer IRQ. */
    dtInterruptHandlerManager_minute min;     /**< Minute configuration for timer IRQ. */
    dtInterruptHandlerManager_hour hour;      /**< Hour configuration for timer IRQ. */
    dtInterruptHandlerManager_day day;        /**< Day configuration for timer IRQ. */

    /* Getter/Setter for configuration */

    /**
     * @brief Sets the millisecond configuration.
     * @param ms Millisecond configuration to set.
     * @return void
     */
    void (*setMillisecond)(dtInterruptHandlerManager_millisecond ms);

    /**
     * @brief Gets the current millisecond configuration.
     * @return Current millisecond configuration.
     */
    dtInterruptHandlerManager_millisecond (*getMillisecond)(void);

    /**
     * @brief Sets the second configuration.
     * @param sec Second configuration to set.
     * @return void
     */
    void (*setSecond)(dtInterruptHandlerManager_second sec);

    /**
     * @brief Gets the current second configuration.
     * @return Current second configuration.
     */
    dtInterruptHandlerManager_second (*getSecond)(void);

    /**
     * @brief Sets the minute configuration.
     * @param min Minute configuration to set.
     * @return void
     */
    void (*setMinute)(dtInterruptHandlerManager_minute min);

    /**
     * @brief Gets the current minute configuration.
     * @return Current minute configuration.
     */
    dtInterruptHandlerManager_minute (*getMinute)(void);

    /**
     * @brief Sets the hour configuration.
     * @param hour Hour configuration to set.
     * @return void
     */
    void (*setHour)(dtInterruptHandlerManager_hour hour);

    /**
     * @brief Gets the current hour configuration.
     * @return Current hour configuration.
     */
    dtInterruptHandlerManager_hour (*getHour)(void);

    /**
     * @brief Sets the day configuration.
     * @param day Day configuration to set.
     * @return void
     */
    void (*setDay)(dtInterruptHandlerManager_day day);

    /**
     * @brief Gets the current day configuration.
     * @return Current day configuration.
     */
    dtInterruptHandlerManager_day (*getDay)(void);

} ihmTimerIrqConfiguration;


/**
 * @brief Configuration structure for HALL interrupt management.
 * 
 * This structure contains attributes and function pointers for managing 
 * HALL sensor states, edge flags, and edge counts for Hall A, Hall B, and Hall C.
 */
typedef struct 
{
    /* Configuration attributes */
    dtInterruptHandlerManager_HallAStateStatus halla_state; /**< Hall A state status. */
    dtInterruptHandlerManager_HallBStateStatus hallb_state; /**< Hall B state status. */
    dtInterruptHandlerManager_HallCStateStatus hallc_state; /**< Hall C state status. */

    dtInterruptHandlerManager_FallingEdgeAFlag halla_fe_flag; /**< Hall A falling edge flag. */
    dtInterruptHandlerManager_FallingEdgeBFlag hallb_fe_flag; /**< Hall B falling edge flag. */
    dtInterruptHandlerManager_FallingEdgeCFlag hallc_fe_flag; /**< Hall C falling edge flag. */

    dtInterruptHandlerManager_RisingEdgeAFlag halla_re_flag; /**< Hall A rising edge flag. */
    dtInterruptHandlerManager_RisingEdgeBFlag hallb_re_flag; /**< Hall B rising edge flag. */
    dtInterruptHandlerManager_RisingEdgeCFlag hallc_re_flag; /**< Hall C rising edge flag. */

    dtInterruptHandlerManager_FallingEdgeACount halla_fe_count; /**< Hall A falling edge count. */
    dtInterruptHandlerManager_FallingEdgeBCount hallb_fe_count; /**< Hall B falling edge count. */
    dtInterruptHandlerManager_FallingEdgeCCount hallc_fe_count; /**< Hall C falling edge count. */

    dtInterruptHandlerManager_RisingEdgeACount halla_re_count; /**< Hall A rising edge count. */
    dtInterruptHandlerManager_RisingEdgeBCount hallb_re_count; /**< Hall B rising edge count. */
    dtInterruptHandlerManager_RisingEdgeCCount hallc_re_count; /**< Hall C rising edge count. */

    /* Getter/Setter for configuration */

    /* Hall A */
    /**
     * @brief Sets the state status for Hall A.
     * @param state State status to set.
     */
    void (*setHallAState)(dtInterruptHandlerManager_HallAStateStatus state);

    /**
     * @brief Gets the current state status for Hall A.
     * @return Current state status.
     */
    dtInterruptHandlerManager_HallAStateStatus (*getHallAState)(void);

    /**
     * @brief Sets the falling edge flag for Hall A.
     * @param flag Falling edge flag to set.
     */
    void (*setHallAFallingEdgeFlag)(dtInterruptHandlerManager_FallingEdgeAFlag flag);

    /**
     * @brief Gets the current falling edge flag for Hall A.
     * @return Current falling edge flag.
     */
    dtInterruptHandlerManager_FallingEdgeAFlag (*getHallAFallingEdgeFlag)(void);

    /**
     * @brief Sets the rising edge flag for Hall A.
     * @param flag Rising edge flag to set.
     */
    void (*setHallARisingEdgeFlag)(dtInterruptHandlerManager_RisingEdgeAFlag flag);

    /**
     * @brief Gets the current rising edge flag for Hall A.
     * @return Current rising edge flag.
     */
    dtInterruptHandlerManager_RisingEdgeAFlag (*getHallARisingEdgeFlag)(void);

    /**
     * @brief Sets the falling edge count for Hall A.
     * @param count Falling edge count to set.
     */
    void (*setHallAFallingEdgeCount)(dtInterruptHandlerManager_FallingEdgeACount count);

    /**
     * @brief Gets the current falling edge count for Hall A.
     * @return Current falling edge count.
     */
    dtInterruptHandlerManager_FallingEdgeACount (*getHallAFallingEdgeCount)(void);

    /**
     * @brief Sets the rising edge count for Hall A.
     * @param count Rising edge count to set.
     */
    void (*setHallARisingEdgeCount)(dtInterruptHandlerManager_RisingEdgeACount count);

    /**
     * @brief Gets the current rising edge count for Hall A.
     * @return Current rising edge count.
     */
    dtInterruptHandlerManager_RisingEdgeACount (*getHallARisingEdgeCount)(void);

    /* Hall B */
    /**
     * @brief Sets the state status for Hall B.
     * @param state State status to set.
     */
    void (*setHallBState)(dtInterruptHandlerManager_HallBStateStatus state);

    /**
     * @brief Gets the current state status for Hall B.
     * @return Current state status.
     */
    dtInterruptHandlerManager_HallBStateStatus (*getHallBState)(void);

    /**
     * @brief Sets the falling edge flag for Hall B.
     * @param flag Falling edge flag to set.
     */
    void (*setHallBFallingEdgeFlag)(dtInterruptHandlerManager_FallingEdgeBFlag flag);

    /**
     * @brief Gets the current falling edge flag for Hall B.
     * @return Current falling edge flag.
     */
    dtInterruptHandlerManager_FallingEdgeBFlag (*getHallBFallingEdgeFlag)(void);

    /**
     * @brief Sets the rising edge flag for Hall B.
     * @param flag Rising edge flag to set.
     */
    void (*setHallBRisingEdgeFlag)(dtInterruptHandlerManager_RisingEdgeBFlag flag);

    /**
     * @brief Gets the current rising edge flag for Hall B.
     * @return Current rising edge flag.
     */
    dtInterruptHandlerManager_RisingEdgeBFlag (*getHallBRisingEdgeFlag)(void);

    /**
     * @brief Sets the falling edge count for Hall B.
     * @param count Falling edge count to set.
     */
    void (*setHallBFallingEdgeCount)(dtInterruptHandlerManager_FallingEdgeBCount count);

    /**
     * @brief Gets the current falling edge count for Hall B.
     * @return Current falling edge count.
     */
    dtInterruptHandlerManager_FallingEdgeBCount (*getHallBFallingEdgeCount)(void);

    /**
     * @brief Sets the rising edge count for Hall B.
     * @param count Rising edge count to set.
     */
    void (*setHallBRisingEdgeCount)(dtInterruptHandlerManager_RisingEdgeBCount count);

    /**
     * @brief Gets the current rising edge count for Hall B.
     * @return Current rising edge count.
     */
    dtInterruptHandlerManager_RisingEdgeBCount (*getHallBRisingEdgeCount)(void);

    /* Hall C */
    /**
     * @brief Sets the state status for Hall C.
     * @param state State status to set.
     */
    void (*setHallCState)(dtInterruptHandlerManager_HallCStateStatus state);

    /**
     * @brief Gets the current state status for Hall C.
     * @return Current state status.
     */
    dtInterruptHandlerManager_HallCStateStatus (*getHallCState)(void);

    /**
     * @brief Sets the falling edge flag for Hall C.
     * @param flag Falling edge flag to set.
     */
    void (*setHallCFallingEdgeFlag)(dtInterruptHandlerManager_FallingEdgeCFlag flag);

    /**
     * @brief Gets the current falling edge flag for Hall C.
     * @return Current falling edge flag.
     */
    dtInterruptHandlerManager_FallingEdgeCFlag (*getHallCFallingEdgeFlag)(void);

    /**
     * @brief Sets the rising edge flag for Hall C.
     * @param flag Rising edge flag to set.
     */
    void (*setHallCRisingEdgeFlag)(dtInterruptHandlerManager_RisingEdgeCFlag flag);

    /**
     * @brief Gets the current rising edge flag for Hall C.
     * @return Current rising edge flag.
     */
    dtInterruptHandlerManager_RisingEdgeCFlag (*getHallCRisingEdgeFlag)(void);

    /**
     * @brief Sets the falling edge count for Hall C.
     * @param count Falling edge count to set.
     */
    void (*setHallCFallingEdgeCount)(dtInterruptHandlerManager_FallingEdgeCCount count);

    /**
     * @brief Gets the current falling edge count for Hall C.
     * @return Current falling edge count.
     */
    dtInterruptHandlerManager_FallingEdgeCCount (*getHallCFallingEdgeCount)(void);

    /**
     * @brief Sets the rising edge count for Hall C.
     * @param count Rising edge count to set.
     */
    void (*setHallCRisingEdgeCount)(dtInterruptHandlerManager_RisingEdgeCCount count);

    /**
     * @brief Gets the current rising edge count for Hall C.
     * @return Current rising edge count.
     */
    dtInterruptHandlerManager_RisingEdgeCCount (*getHallCRisingEdgeCount)(void);

} ihmHALLConfiguration;


/**
 * @brief Component base class for managing interrupt handlers.
 * 
 * This structure serves as a base class for managing various types of interrupt handlers,
 * including external interrupts, timer interrupts, and HALL configurations. It provides
 * attributes and function pointers for dynamic interaction and functional behaviors.
 */
typedef struct 
{
    /* Interface pointer */
    IExternalInterruptStatus* IExternalInterruptStatus; /**< Pointer to external interrupt status interface. */
    ITimerInterruptStatus* ITimerInterruptStatus;       /**< Pointer to timer interrupt status interface. */
    IHALLA* IHALLA;                                     /**< Pointer to Hall A interface. */
    IHALLB* IHALLB;                                     /**< Pointer to Hall B interface. */
    IHALLC* IHALLC;                                     /**< Pointer to Hall C interface. */

    /* Attributes */
    ihmExternalIrqConfiguration externalIrq; /**< Configuration for external interrupts. */
    ihmTimerIrqConfiguration    timerIrq;    /**< Configuration for timer interrupts. */
    ihmHALLConfiguration        HALL;        /**< Configuration for HALL sensors. */

    /* Getter Setter */

    /**
     * @brief Sets the external IRQ configuration.
     * @param config External IRQ configuration to set.
     */
    void (*setExternalIrq)(ihmExternalIrqConfiguration config);

    /**
     * @brief Gets the current external IRQ configuration.
     * @return Current external IRQ configuration.
     */
    ihmExternalIrqConfiguration (*getExternalIrq)(void);

    /**
     * @brief Sets the timer IRQ configuration.
     * @param config Timer IRQ configuration to set.
     */
    void (*setTimerIrq)(ihmTimerIrqConfiguration config);

    /**
     * @brief Gets the current timer IRQ configuration.
     * @return Current timer IRQ configuration.
     */
    ihmTimerIrqConfiguration (*getTimerIrq)(void);

    /**
     * @brief Sets the HALL configuration.
     * @param config HALL configuration to set.
     */
    void (*setHALL)(ihmHALLConfiguration config);

    /**
     * @brief Gets the current HALL configuration.
     * @return Current HALL configuration.
     */
    ihmHALLConfiguration (*getHALL)(void);

    /* toString */
    /**
     * @brief Converts the current configuration to a string representation.
     * @return A string representation of the configuration.
     */
    char* (*toString)(void);

    /* Functional Behaviours */

} dtInterruptHandlerManager;



#endif /* INTERRUPTHANDLERMANAGER_INC_INTERRUPTHANDLERMANAGER_DEFINITION_H_ */