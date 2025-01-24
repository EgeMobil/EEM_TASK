/**
 * @file HallSensorConfiguration_Definition.h
 * @brief Definition header file for the Hall Sensor Configuration component.
 * 
 * This file defines the core structures, types, and aliases used by the 
 * Hall Sensor Configuration module. It includes configurations for managing 
 * the state, rising edge, and falling edge data of Hall sensors (A, B, and C).
 * Additionally, it provides type definitions for interfacing with external 
 * components such as `IHALLA`, `IHALLB`, `IHALLC`, and `IPwmStep`.
 * 
 * Key functionalities include:
 * - Configuration structures for Hall A, B, and C sensors.
 * - Integration with external Hall and PWM step interfaces.
 * - Getter and Setter methods for managing sensor states and flags.
 * - Conversion of configuration data to a string representation for debugging.
 * 
 * This file serves as the foundational definition file for the Hall Sensor 
 * Configuration component, enabling efficient and modular sensor data management.
 * 
 * @version 1.0
 * @date 07.01.2025
 * @author atakan.ertekin
 */

#ifndef HALLSENSORCONFIGURATION_DEFINITION_H_
#define HALLSENSORCONFIGURATION_DEFINITION_H_

/* ECU StateManager Global Include */
#include "ECUStateManager_global.h"

/* Receiver Port Interface Definition Include */
#include "IHALLA.h"
#include "IHALLB.h"
#include "IHALLC.h"

/* Sender Port Interface Definition Include */
#include "IPwmStep.h"

/**
 * @enum dtHscReturn
 * @brief Base return value definitions for Hall Sensor Configuration.
 */
typedef enum
{
    HSC_ERR = 0,   /**< Error occurred. */
    HSC_EOK,       /**< Operation successful. */
    HSC_UNKNOWN    /**< Unknown state. */
} dtHscReturn;

/**
 * @typedef dtHALLSensorConfiguration_hscReturn
 * @brief Alias for return type in Hall Sensor Configuration.
 */
typedef dtHscReturn dtHALLSensorConfiguration_hscReturn;

/* Status flag aliases */

/**
 * @typedef dtHALLSensorConfiguration_HallAStateStatus
 * @brief Alias for Hall A state status.
 */
typedef cmHallAStateStatus dtHALLSensorConfiguration_HallAStateStatus;

/**
 * @typedef dtHALLSensorConfiguration_HallBStateStatus
 * @brief Alias for Hall B state status.
 */
typedef cmHallBStateStatus dtHALLSensorConfiguration_HallBStateStatus;

/**
 * @typedef dtHALLSensorConfiguration_HallCStateStatus
 * @brief Alias for Hall C state status.
 */
typedef cmHallCStateStatus dtHALLSensorConfiguration_HallCStateStatus;

/**
 * @typedef dtHALLSensorConfiguration_RisingEdgeAFlag
 * @brief Alias for Hall A rising edge flag.
 */
typedef cmRisingEdgeAFlag dtHALLSensorConfiguration_RisingEdgeAFlag;

/**
 * @typedef dtHALLSensorConfiguration_RisingEdgeBFlag
 * @brief Alias for Hall B rising edge flag.
 */
typedef cmRisingEdgeBFlag dtHALLSensorConfiguration_RisingEdgeBFlag;

/**
 * @typedef dtHALLSensorConfiguration_RisingEdgeCFlag
 * @brief Alias for Hall C rising edge flag.
 */
typedef cmRisingEdgeCFlag dtHALLSensorConfiguration_RisingEdgeCFlag;

/**
 * @typedef dtHALLSensorConfiguration_FallingEdgeAFlag
 * @brief Alias for Hall A falling edge flag.
 */
typedef cmFallingEdgeAFlag dtHALLSensorConfiguration_FallingEdgeAFlag;

/**
 * @typedef dtHALLSensorConfiguration_FallingEdgeBFlag
 * @brief Alias for Hall B falling edge flag.
 */
typedef cmFallingEdgeBFlag dtHALLSensorConfiguration_FallingEdgeBFlag;

/**
 * @typedef dtHALLSensorConfiguration_FallingEdgeCFlag
 * @brief Alias for Hall C falling edge flag.
 */
typedef cmFallingEdgeCFlag dtHALLSensorConfiguration_FallingEdgeCFlag;

typedef cmPwmStep dtHALLSensorConfiguration_PwmStep;

/**
 * @struct dtHALLAconfiguration
 * @brief Configuration structure for Hall A sensor.
 */
typedef struct 
{
    dtHALLSensorConfiguration_HallAStateStatus status; /**< Hall A state. */
    dtHALLSensorConfiguration_RisingEdgeAFlag re_flag; /**< Rising edge flag for Hall A. */
    dtHALLSensorConfiguration_FallingEdgeAFlag fe_flag; /**< Falling edge flag for Hall A. */

    /** Getter/Setter function pointers for status */
    void (*setStatus)(dtHALLSensorConfiguration_HallAStateStatus status);
    dtHALLSensorConfiguration_HallAStateStatus (*getStatus)(void);

    /** Getter/Setter function pointers for rising edge flag */
    void (*setRisingEdgeFlag)(dtHALLSensorConfiguration_RisingEdgeAFlag re_flag);
    dtHALLSensorConfiguration_RisingEdgeAFlag (*getRisingEdgeFlag)(void);

    /** Getter/Setter function pointers for falling edge flag */
    void (*setFallingEdgeFlag)(dtHALLSensorConfiguration_FallingEdgeAFlag fe_flag);
    dtHALLSensorConfiguration_FallingEdgeAFlag (*getFallingEdgeFlag)(void);

} dtHALLAconfiguration;

typedef dtHALLAconfiguration dtHALLSensorConfiguration_A;

/**
 * @struct dtHALLBconfiguration
 * @brief Configuration structure for Hall B sensor.
 */
typedef struct 
{
    dtHALLSensorConfiguration_HallBStateStatus status; /**< Hall B state. */
    dtHALLSensorConfiguration_RisingEdgeBFlag re_flag; /**< Rising edge flag for Hall B. */
    dtHALLSensorConfiguration_FallingEdgeBFlag fe_flag; /**< Falling edge flag for Hall B. */

    /** Getter/Setter function pointers for status */
    void (*setStatus)(dtHALLSensorConfiguration_HallBStateStatus status);
    dtHALLSensorConfiguration_HallBStateStatus (*getStatus)(void);

    /** Getter/Setter function pointers for rising edge flag */
    void (*setRisingEdgeFlag)(dtHALLSensorConfiguration_RisingEdgeBFlag re_flag);
    dtHALLSensorConfiguration_RisingEdgeBFlag (*getRisingEdgeFlag)(void);

    /** Getter/Setter function pointers for falling edge flag */
    void (*setFallingEdgeFlag)(dtHALLSensorConfiguration_FallingEdgeBFlag fe_flag);
    dtHALLSensorConfiguration_FallingEdgeBFlag (*getFallingEdgeFlag)(void);

} dtHALLBconfiguration;

typedef dtHALLBconfiguration dtHALLSensorConfiguration_B;

/**
 * @struct dtHALLCconfiguration
 * @brief Configuration structure for Hall C sensor.
 */
typedef struct 
{
    dtHALLSensorConfiguration_HallCStateStatus status; /**< Hall C state. */
    dtHALLSensorConfiguration_RisingEdgeCFlag re_flag; /**< Rising edge flag for Hall C. */
    dtHALLSensorConfiguration_FallingEdgeCFlag fe_flag; /**< Falling edge flag for Hall C. */

    /** Getter/Setter function pointers for status */
    void (*setStatus)(dtHALLSensorConfiguration_HallCStateStatus status);
    dtHALLSensorConfiguration_HallCStateStatus (*getStatus)(void);

    /** Getter/Setter function pointers for rising edge flag */
    void (*setRisingEdgeFlag)(dtHALLSensorConfiguration_RisingEdgeCFlag re_flag);
    dtHALLSensorConfiguration_RisingEdgeCFlag (*getRisingEdgeFlag)(void);

    /** Getter/Setter function pointers for falling edge flag */
    void (*setFallingEdgeFlag)(dtHALLSensorConfiguration_FallingEdgeCFlag fe_flag);
    dtHALLSensorConfiguration_FallingEdgeCFlag (*getFallingEdgeFlag)(void);

} dtHALLCconfiguration;

typedef dtHALLCconfiguration dtHALLSensorConfiguration_C;


/**
 * @struct dtCompName
 * @brief Base class definition for the Hall Sensor Configuration component.
 */
typedef struct 
{
    /* Interface Pointer */
    IHALLA* IHALLA; /**< Pointer to Hall A interface. */
    IHALLB* IHALLB; /**< Pointer to Hall B interface. */
    IHALLC* IHALLC; /**< Pointer to Hall C interface. */
    IPwmStep* IPwmStep; /**< Pointer to PWM Step interface. */

    /* Attributes */
    dtHALLSensorConfiguration_A hall_a; /**< Hall A configuration structure. */
    dtHALLSensorConfiguration_B hall_b; /**< Hall B configuration structure. */
    dtHALLSensorConfiguration_C hall_c; /**< Hall C configuration structure. */

    /* Getter/Setter Methods */

    /**
     * @brief Sets the configuration for Hall A.
     * @param state New configuration for Hall A.
     */
    void (*setHallAConfig)(dtHALLAconfiguration status);

    /**
     * @brief Gets the current configuration for Hall A.
     * @return Current Hall A configuration.
     */
    dtHALLAconfiguration (*getHallAConfig)(void);

    /**
     * @brief Sets the configuration for Hall B.
     * @param state New configuration for Hall B.
     */
    void (*setHallBConfig)(dtHALLBconfiguration status);

    /**
     * @brief Gets the current configuration for Hall B.
     * @return Current Hall B configuration.
     */
    dtHALLBconfiguration (*getHallBConfig)(void);

    /**
     * @brief Sets the configuration for Hall C.
     * @param state New configuration for Hall C.
     */
    void (*setHallCConfig)(dtHALLCconfiguration status);

    /**
     * @brief Gets the current configuration for Hall C.
     * @return Current Hall C configuration.
     */
    dtHALLCconfiguration (*getHallCConfig)(void);

    /* toString Method */
    /**
     * @brief Converts the current configuration to a string representation.
     * @return A string representation of the configuration.
     */
    char* (*toString)(void);

    /* Functional Behaviors */

}dtHALLSensorConfiguration;

#endif /* HALLSENSORCONFIGURATION_DEFINITION_H_ */
