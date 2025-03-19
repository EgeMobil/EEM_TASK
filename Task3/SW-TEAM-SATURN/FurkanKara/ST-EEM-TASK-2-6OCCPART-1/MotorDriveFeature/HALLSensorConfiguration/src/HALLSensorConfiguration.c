/**
 * @file HallSensorConfiguration.c
 * @brief This file contains the implementation of Hall Sensor Configuration.
 * 
 * It includes the constructor functions, toString implementations, and various helper
 * functions to handle the Hall sensor states and edge flags (rising and falling).
 * The Hall sensor configuration allows interaction with three Hall sensors (A, B, and C),
 * and manages their states, rising edge flags, and falling edge flags.
 * @author atakan.ertekin
 * @date 07.01.2025
 */
#include "HALLSensorConfiguration_private.h"

/* Static singleton instance */
static dtHALLSensorConfiguration instance;

/* Getter Setter Implementation */

/**
 * @brief Sets the configuration for Hall A.
 * 
 * This function updates the configuration for Hall A sensor. 
 * The new configuration is passed as a parameter to the function.
 * 
 * @param config New configuration for Hall A.
 */
static void HALLSensorConfiguration_setHallAConfig_Impl(dtHALLAconfiguration config)
{
    instance.hall_a = config;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall A configuration updated.\n");
#endif
}

/**
 * @brief Gets the current configuration for Hall A.
 * 
 * This function retrieves the current configuration for Hall A sensor.
 * 
 * @return Current configuration for Hall A.
 */
static dtHALLAconfiguration HALLSensorConfiguration_getHallAConfig_Impl(void)
{
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Retrieving Hall A configuration.\n");
#endif
    return instance.hall_a;
}

/**
 * @brief Sets the configuration for Hall B.
 * 
 * This function updates the configuration for Hall B sensor. 
 * The new configuration is passed as a parameter to the function.
 * 
 * @param config New configuration for Hall B.
 */
static void HALLSensorConfiguration_setHallBConfig_Impl(dtHALLBconfiguration config)
{
    instance.hall_b = config;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall B configuration updated.\n");
#endif
}

/**
 * @brief Gets the current configuration for Hall B.
 * 
 * This function retrieves the current configuration for Hall B sensor.
 * 
 * @return Current configuration for Hall B.
 */
static dtHALLBconfiguration HALLSensorConfiguration_getHallBConfig_Impl(void)
{
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Retrieving Hall B configuration.\n");
#endif
    return instance.hall_b;
}

/**
 * @brief Sets the configuration for Hall C.
 * 
 * This function updates the configuration for Hall C sensor. 
 * The new configuration is passed as a parameter to the function.
 * 
 * @param config New configuration for Hall C.
 */
static void HALLSensorConfiguration_setHallCConfig_Impl(dtHALLCconfiguration config)
{
    instance.hall_c = config;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall C configuration updated.\n");
#endif
}

/**
 * @brief Gets the current configuration for Hall C.
 * 
 * This function retrieves the current configuration for Hall C sensor.
 * 
 * @return Current configuration for Hall C.
 */
static dtHALLCconfiguration HALLSensorConfiguration_getHallCConfig_Impl(void)
{
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Retrieving Hall C configuration.\n");
#endif
    return instance.hall_c;
}

/* Getter/Setter Implementations for Hall A */

/**
 * @brief Sets the state of Hall A.
 * 
 * This function updates the state of Hall A sensor. The state is passed 
 * as a parameter to the function.
 * 
 * @param state New state for Hall A.
 */
static void HALLSensorConfiguration_setHallAState_Impl(dtHALLSensorConfiguration_HallAStateStatus state)
{
    instance.hall_a.status = state;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall A state updated: %d\n", state);
#endif
}

/**
 * @brief Gets the current state of Hall A.
 * 
 * This function retrieves the current state of Hall A sensor.
 * 
 * @return Current state for Hall A.
 */
static dtHALLSensorConfiguration_HallAStateStatus HALLSensorConfiguration_getHallAState_Impl(void)
{
    return instance.hall_a.status;
}

/**
 * @brief Sets the rising edge flag of Hall A.
 * 
 * This function updates the rising edge flag for Hall A. The flag value is passed 
 * as a parameter to the function.
 * 
 * @param flag New rising edge flag for Hall A.
 */
static void HALLSensorConfiguration_setHallARisingEdgeFlag_Impl(dtHALLSensorConfiguration_RisingEdgeAFlag flag)
{
    instance.hall_a.re_flag = flag;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall A rising edge flag updated: %d\n", flag);
#endif
}

/**
 * @brief Gets the rising edge flag of Hall A.
 * 
 * This function retrieves the rising edge flag of Hall A sensor.
 * 
 * @return Current rising edge flag for Hall A.
 */
static dtHALLSensorConfiguration_RisingEdgeAFlag HALLSensorConfiguration_getHallARisingEdgeFlag_Impl(void)
{
    return instance.hall_a.re_flag;
}

/**
 * @brief Sets the falling edge flag of Hall A.
 * 
 * This function updates the falling edge flag for Hall A. The flag value is passed 
 * as a parameter to the function.
 * 
 * @param flag New falling edge flag for Hall A.
 */
static void HALLSensorConfiguration_setHallAFallingEdgeFlag_Impl(dtHALLSensorConfiguration_FallingEdgeAFlag flag)
{
    instance.hall_a.fe_flag = flag;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall A falling edge flag updated: %d\n", flag);
#endif
}

/**
 * @brief Gets the falling edge flag of Hall A.
 * 
 * This function retrieves the falling edge flag of Hall A sensor.
 * 
 * @return Current falling edge flag for Hall A.
 */
static dtHALLSensorConfiguration_FallingEdgeAFlag HALLSensorConfiguration_getHallAFallingEdgeFlag_Impl(void)
{
    return instance.hall_a.fe_flag;
}

/* Getter/Setter Implementations for Hall B */

/**
 * @brief Sets the state of Hall B.
 * 
 * This function updates the state of Hall B sensor. The state is passed 
 * as a parameter to the function.
 * 
 * @param state New state for Hall B.
 */
static void HALLSensorConfiguration_setHallBState_Impl(dtHALLSensorConfiguration_HallBStateStatus state)
{
    instance.hall_b.status = state;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall B state updated: %d\n", state);
#endif
}

/**
 * @brief Gets the current state of Hall B.
 * 
 * This function retrieves the current state of Hall B sensor.
 * 
 * @return Current state for Hall B.
 */
static dtHALLSensorConfiguration_HallBStateStatus HALLSensorConfiguration_getHallBState_Impl(void)
{
    return instance.hall_b.status;
}

/**
 * @brief Sets the rising edge flag of Hall B.
 * 
 * This function updates the rising edge flag for Hall B. The flag value is passed 
 * as a parameter to the function.
 * 
 * @param flag New rising edge flag for Hall B.
 */
static void HALLSensorConfiguration_setHallBRisingEdgeFlag_Impl(dtHALLSensorConfiguration_RisingEdgeBFlag flag)
{
    instance.hall_b.re_flag = flag;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall B rising edge flag updated: %d\n", flag);
#endif
}

/**
 * @brief Gets the rising edge flag of Hall B.
 * 
 * This function retrieves the rising edge flag of Hall B sensor.
 * 
 * @return Current rising edge flag for Hall B.
 */
static dtHALLSensorConfiguration_RisingEdgeBFlag HALLSensorConfiguration_getHallBRisingEdgeFlag_Impl(void)
{
    return instance.hall_b.re_flag;
}

/**
 * @brief Sets the falling edge flag of Hall B.
 * 
 * This function updates the falling edge flag for Hall B. The flag value is passed 
 * as a parameter to the function.
 * 
 * @param flag New falling edge flag for Hall B.
 */
static void HALLSensorConfiguration_setHallBFallingEdgeFlag_Impl(dtHALLSensorConfiguration_FallingEdgeBFlag flag)
{
    instance.hall_b.fe_flag = flag;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall B falling edge flag updated: %d\n", flag);
#endif
}

/**
 * @brief Gets the falling edge flag of Hall B.
 * 
 * This function retrieves the falling edge flag of Hall B sensor.
 * 
 * @return Current falling edge flag for Hall B.
 */
static dtHALLSensorConfiguration_FallingEdgeBFlag HALLSensorConfiguration_getHallBFallingEdgeFlag_Impl(void)
{
    return instance.hall_b.fe_flag;
}

/* Getter/Setter Implementations for Hall C */

/**
 * @brief Sets the state of Hall C.
 * 
 * This function updates the state of Hall C sensor. The state is passed 
 * as a parameter to the function.
 * 
 * @param state New state for Hall C.
 */
static void HALLSensorConfiguration_setHallCState_Impl(dtHALLSensorConfiguration_HallCStateStatus state)
{
    instance.hall_c.status = state;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall C state updated: %d\n", state);
#endif
}

/**
 * @brief Gets the current state of Hall C.
 * 
 * This function retrieves the current state of Hall C sensor.
 * 
 * @return Current state for Hall C.
 */
static dtHALLSensorConfiguration_HallCStateStatus HALLSensorConfiguration_getHallCState_Impl(void)
{
    return instance.hall_c.status;
}

/**
 * @brief Sets the rising edge flag of Hall C.
 * 
 * This function updates the rising edge flag for Hall C. The flag value is passed 
 * as a parameter to the function.
 * 
 * @param flag New rising edge flag for Hall C.
 */
static void HALLSensorConfiguration_setHallCRisingEdgeFlag_Impl(dtHALLSensorConfiguration_RisingEdgeCFlag flag)
{
    instance.hall_c.re_flag = flag;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall C rising edge flag updated: %d\n", flag);
#endif
}

/**
 * @brief Gets the rising edge flag of Hall C.
 * 
 * This function retrieves the rising edge flag of Hall C sensor.
 * 
 * @return Current rising edge flag for Hall C.
 */
static dtHALLSensorConfiguration_RisingEdgeCFlag HALLSensorConfiguration_getHallCRisingEdgeFlag_Impl(void)
{
    return instance.hall_c.re_flag;
}

/**
 * @brief Sets the falling edge flag of Hall C.
 * 
 * This function updates the falling edge flag for Hall C. The flag value is passed 
 * as a parameter to the function.
 * 
 * @param flag New falling edge flag for Hall C.
 */
static void HALLSensorConfiguration_setHallCFallingEdgeFlag_Impl(dtHALLSensorConfiguration_FallingEdgeCFlag flag)
{
    instance.hall_c.fe_flag = flag;
#ifndef STM32G431xx
    printf("[HALLSensorConfiguration] Hall C falling edge flag updated: %d\n", flag);
#endif
}

/**
 * @brief Gets the falling edge flag of Hall C.
 * 
 * This function retrieves the falling edge flag of Hall C sensor.
 * 
 * @return Current falling edge flag for Hall C.
 */
static dtHALLSensorConfiguration_FallingEdgeCFlag HALLSensorConfiguration_getHallCFallingEdgeFlag_Impl(void)
{
    return instance.hall_c.fe_flag;
}

/* toString() Implementation */

/**
 * @brief Converts Hall A state to string representation.
 * @param state The state of Hall A sensor.
 * @return A string describing the state of Hall A sensor.
 */
static const char* HallStateToString(dtHALLSensorConfiguration_HallAStateStatus state)
{
    switch (state)
    {
        case HALLA_STATUS_LOW:
            return "Enabled";
        case HALLA_STATUS_HIGH:
            return "Disabled";
        case HALLA_STATUS_UNKNOWN:
        default:
            return "Unknown";
    }
}

/**
 * @brief Converts Hall A rising edge flag to string representation.
 * @param flag The rising edge flag for Hall A.
 * @return A string describing the rising edge flag of Hall A.
 */
static const char* RisingEdgeToString(dtHALLSensorConfiguration_RisingEdgeAFlag flag)
{
    switch (flag)
    {
        case HALLA_RISING_EDGE_RESET:
            return "Low";
        case HALLA_RISING_EDGE_SET:
            return "High";
        case HALLA_RISING_EDGE_UNKNOWN:
        default:
            return "Unknown";
    }
}

/**
 * @brief Converts Hall A falling edge flag to string representation.
 * @param flag The falling edge flag for Hall A.
 * @return A string describing the falling edge flag of Hall A.
 */
static const char* FallingEdgeToString(dtHALLSensorConfiguration_FallingEdgeAFlag flag)
{
    switch (flag)
    {
        case HALLA_FALLING_EDGE_RESET:
            return "Low";
        case HALLA_FALLING_EDGE_SET:
            return "High";
        case HALLA_FALLING_EDGE_UNKNOWN:
        default:
            return "Unknown";
    }
}

/**
 * @brief Converts the Hall Sensor Configuration to a string representation.
 * @return A string describing the complete Hall Sensor Configuration.
 */
static char* HALLSensorConfiguration_toString_Impl(void)
{
    static char buffer[1024]; // Artan bilgi için daha geniş bir buffer
    snprintf(buffer, sizeof(buffer),
             "[HALLSensorConfiguration]\n"
             "Interfaces:\n"
             "  IHALLA: %s\n"
             "  IHALLB: %s\n"
             "  IHALLC: %s\n"
             "  PwmStep: %s\n"
             "Hall A:\n"
             "  State: %s\n"
             "  Rising Edge: %s \n"
             "  Falling Edge: %s \n"
             "Hall B:\n"
             "  State: %s\n"
             "  Rising Edge: %s \n"
             "  Falling Edge: %s \n"
             "Hall C:\n"
             "  State: %s\n"
             "  Rising Edge: %s \n"
             "  Falling Edge: %s \n",
              // Interfaces connected or not
             (instance.IHALLA != NULL) ? "Connected" : "Not Connected",
             (instance.IHALLB != NULL) ? "Connected" : "Not Connected",
             (instance.IHALLC != NULL) ? "Connected" : "Not Connected",
             (instance.IPwmStep != NULL) ? "Connected" : "Not Connected",

             // Hall A information
             HallStateToString(instance.hall_a.status),
             RisingEdgeToString(instance.hall_a.re_flag),
             FallingEdgeToString(instance.hall_a.fe_flag),

             // Hall B information
             HallStateToString(instance.hall_b.status),
             RisingEdgeToString(instance.hall_b.re_flag),
             FallingEdgeToString(instance.hall_b.fe_flag),

             // Hall C information
             HallStateToString(instance.hall_c.status),
             RisingEdgeToString(instance.hall_c.re_flag),
             FallingEdgeToString(instance.hall_c.fe_flag));

    return buffer;
}

/* Constructor Implementation */

/**
 * @brief Initializes the Hall A sensor configuration.
 */
void HALLSensorConfigurationHallA_CTOR(void)
{
    instance.hall_a.status = HALLA_STATUS_UNKNOWN;
    instance.hall_a.re_flag = HALLA_RISING_EDGE_UNKNOWN;
    instance.hall_a.fe_flag = HALLA_FALLING_EDGE_UNKNOWN;

    /* Assign function pointers */
    instance.hall_a.setStatus = HALLSensorConfiguration_setHallAState_Impl;
    instance.hall_a.getStatus = HALLSensorConfiguration_getHallAState_Impl;
    instance.hall_a.setFallingEdgeFlag = HALLSensorConfiguration_setHallAFallingEdgeFlag_Impl;
    instance.hall_a.getFallingEdgeFlag = HALLSensorConfiguration_getHallAFallingEdgeFlag_Impl;
    instance.hall_a.setRisingEdgeFlag = HALLSensorConfiguration_setHallARisingEdgeFlag_Impl;
    instance.hall_a.getRisingEdgeFlag = HALLSensorConfiguration_getHallARisingEdgeFlag_Impl;
}

/**
 * @brief Initializes the Hall B sensor configuration.
 */
void HALLSensorConfigurationHallB_CTOR(void)
{
    instance.hall_b.status = HALLB_STATUS_UNKNOWN;
    instance.hall_b.re_flag = HALLB_RISING_EDGE_UNKNOWN;
    instance.hall_b.fe_flag = HALLB_FALLING_EDGE_UNKNOWN;

    /* Assign function pointers */
    instance.hall_b.setStatus = HALLSensorConfiguration_setHallBState_Impl;
    instance.hall_b.getStatus = HALLSensorConfiguration_getHallBState_Impl;
    instance.hall_b.setFallingEdgeFlag = HALLSensorConfiguration_setHallBFallingEdgeFlag_Impl;
    instance.hall_b.getFallingEdgeFlag = HALLSensorConfiguration_getHallBFallingEdgeFlag_Impl;
    instance.hall_b.setRisingEdgeFlag = HALLSensorConfiguration_setHallBRisingEdgeFlag_Impl;
    instance.hall_b.getRisingEdgeFlag = HALLSensorConfiguration_getHallBRisingEdgeFlag_Impl;
}

/**
 * @brief Initializes the Hall C sensor configuration.
 */
void HALLSensorConfigurationHallC_CTOR(void)
{
    instance.hall_c.status = HALLC_STATUS_UNKNOWN;
    instance.hall_c.re_flag = HALLC_RISING_EDGE_UNKNOWN;
    instance.hall_c.fe_flag = HALLC_FALLING_EDGE_UNKNOWN;

    /* Assign function pointers */
    instance.hall_c.setStatus = HALLSensorConfiguration_setHallCState_Impl;
    instance.hall_c.getStatus = HALLSensorConfiguration_getHallCState_Impl;
    instance.hall_c.setFallingEdgeFlag = HALLSensorConfiguration_setHallCFallingEdgeFlag_Impl;
    instance.hall_c.getFallingEdgeFlag = HALLSensorConfiguration_getHallCFallingEdgeFlag_Impl;
    instance.hall_c.setRisingEdgeFlag = HALLSensorConfiguration_setHallCRisingEdgeFlag_Impl;
    instance.hall_c.getRisingEdgeFlag = HALLSensorConfiguration_getHallCRisingEdgeFlag_Impl;
}

/**
 * @brief Initializes the Hall Sensor Configuration.
 * @details This function sets up the interfaces, attributes, and implementations for the Hall sensors.
 */
void HALLSensorConfiguration_CTOR(void)
{
    /* Initialize interfaces */
    instance.IHALLA = &HALLAInterface;
    instance.IHALLB = &HALLBInterface;
    instance.IHALLC = &HALLCInterface;
    instance.IPwmStep = &PwmStepInterface;

    /* Initialize attributes */
    HALLSensorConfigurationHallA_CTOR();
    HALLSensorConfigurationHallB_CTOR();
    HALLSensorConfigurationHallC_CTOR();

    /* Assign implementations */
    instance.setHallAConfig = HALLSensorConfiguration_setHallAConfig_Impl;
    instance.getHallAConfig = HALLSensorConfiguration_getHallAConfig_Impl;
    instance.setHallBConfig = HALLSensorConfiguration_setHallBConfig_Impl;
    instance.getHallBConfig = HALLSensorConfiguration_getHallBConfig_Impl;
    instance.setHallCConfig = HALLSensorConfiguration_setHallCConfig_Impl;
    instance.getHallCConfig = HALLSensorConfiguration_getHallCConfig_Impl;
    instance.toString = HALLSensorConfiguration_toString_Impl;
}

/* Singleton Instance Getter */

/**
 * @brief Retrieves the singleton instance of the Hall Sensor Configuration.
 * @return Pointer to the singleton instance.
 */
dtHALLSensorConfiguration* HALLSensorConfiguration_GetInstance(void)
{
    return &instance;
}
