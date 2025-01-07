/**
 * @file BrakeAndDirectionManager.c
 * @brief Implementation file for the Brake and Direction Manager.
 * 
 * This file contains the implementation of the Brake and Direction Manager, 
 * including methods for initialization, configuration management, and periodic 
 * updates. The manager interacts with various interfaces to read and write 
 * brake and direction statuses and provides functionality to handle state 
 * changes dynamically.
 * 
 * Key functionalities include:
 * - Initialization of brake and direction states.
 * - Periodic updates based on input readings.
 * - Interface communication for brake and direction statuses.
 * 
 * The file adheres to the singleton design pattern to ensure only one instance 
 * of the manager exists at runtime.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#include "BrakeAndDirectionManager_private.h"

/**
 * @brief Brake and Direction Manager Instance.
 * 
 * A static instance of the `dtBrakeAndDirectionManager` structure that holds the 
 * current state and configuration of the Brake and Direction Manager.
 */
static dtBrakeAndDirectionManager instance;

/* Getter/Setter Implementation */

/**
 * @brief Gets the current return value of the manager.
 * 
 * @return The current return value of type `dtBrakeAndDirectionManager_bdrReturn`.
 */
dtBrakeAndDirectionManager_bdrReturn getRetVal_Impl(void)
{
    return instance.retVal;
}

/**
 * @brief Sets the return value of the manager.
 * 
 * @param value The return value to set.
 */
void setRetVal_Impl(dtBrakeAndDirectionManager_bdrReturn value)
{
    instance.retVal = value;
}

/**
 * @brief Gets the current configuration of the manager.
 * 
 * @return The current configuration of type `dtBrakeAndDirectionManager_bdrConfiguration`.
 */
dtBrakeAndDirectionManager_bdrConfiguration getConfig_Impl(void)
{
    return instance.config;
}

/**
 * @brief Sets the configuration of the manager.
 * 
 * @param value The configuration to set.
 */
void setConfig_Impl(dtBrakeAndDirectionManager_bdrConfiguration value)
{
    instance.config = value;
}

/**
 * @brief Gets the current direction configuration.
 * 
 * @return The current direction of type `dtBrakeAndDirectionManager_bdrDirection`.
 */
dtBrakeAndDirectionManager_bdrDirection getDirection_Impl(void)
{
    return instance.config.direction;
}

/**
 * @brief Gets the current brake configuration.
 * 
 * @return The current brake of type `dtBrakeAndDirectionManager_bdrBrake`.
 */
dtBrakeAndDirectionManager_bdrBrake getBrake_Impl(void)
{
    return instance.config.brake;
}

/**
 * @brief Sets the direction configuration.
 * 
 * @param direction The direction to set.
 */
void setDirection_Impl(dtBrakeAndDirectionManager_bdrDirection direction)
{
    instance.config.direction = direction;
}

/**
 * @brief Sets the brake configuration.
 * 
 * @param brake The brake configuration to set.
 */
void setBrake_Impl(dtBrakeAndDirectionManager_bdrBrake brake)
{
    instance.config.brake = brake;
}

/* toString() Implementation */

/**
 * @brief Gets the string representation of `dtBdrReturn`.
 * 
 * @param value The `dtBdrReturn` value.
 * @return A string representation of the value.
 */
const char* getStringFromBdrReturn(dtBdrReturn value)
{
    switch (value)
    {
        case BDR_ERR: return "BDR_ERR";
        case BDR_EOK: return "BDR_EOK";
        case BDR_UNKNOWN: return "BDR_UNKNOWN";
        default: return "UNKNOWN";
    }
}

/**
 * @brief Gets the string representation of `dtBrakeAndDirectionManager_bdrDirection`.
 * 
 * @param value The `dtBrakeAndDirectionManager_bdrDirection` value.
 * @return A string representation of the value.
 */
const char* getStringFromBdrDirection(dtBrakeAndDirectionManager_bdrDirection value)
{
    switch (value)
    {
        case DIRECTION_BACKWARD: return "DIRECTION_BACKWARD";
        case DIRECTION_FORWARD: return  "DIRECTION_FORWARD";
        case DIRECTION_UNKNOWN: return  "DIRECTION_UNKNOWN";
        default: return "UNKNOWN";
    }
}

/**
 * @brief Gets the string representation of `dtBrakeAndDirectionManager_bdrBrake`.
 * 
 * @param value The `dtBrakeAndDirectionManager_bdrBrake` value.
 * @return A string representation of the value.
 */
const char* getStringFromBdrBrake(dtBrakeAndDirectionManager_bdrBrake value)
{
    switch (value)
    {
        case BRAKE_DISABLE: return "BRAKE_DISABLE";
        case BRAKE_ENABLE: return "BRAKE_ENABLE";
        case BRAKE_UNKNOWN: return "BRAKE_UNKNOWN";
        default: return "UNKNOWN";
    }
}

/**
 * @brief Converts the Brake and Direction Manager configuration to a string.
 * 
 * @return A dynamically allocated string representation of the current configuration.
 *         Caller is responsible for freeing the memory.
 */
char* BrakeAndDirectionManager_toString(void)
{
    dtBrakeAndDirectionManager* instance = BrakeAndDirectionManager_GetInstance();

    // Retrieve current values
    dtBrakeAndDirectionManager_bdrReturn retVal = instance->getRetVal();
    dtBrakeAndDirectionManager_bdrConfiguration config = instance->getConfig();

    // Check interface pointer status
    const char* IBrakeAndDirection = (instance->IBrakeAndDirection != NULL) ? "CONNECTED" : "DISCONNECTED";
    const char* IBrakeStatus = (instance->IBrakeStatus != NULL) ? "CONNECTED" : "DISCONNECTED";
    const char* IDirectionStatus = (instance->IDirectionStatus != NULL) ? "CONNECTED" : "DISCONNECTED";

    // Allocate memory for the output string
    char* output = (char*)malloc(256);
    if (output == NULL)
    {
        return strdup("Memory allocation failed.");
    }

    snprintf(output, 256,
             "[BrakeAndDirectionManager]: IBrakeAndDirection: %-10s, IBrakeStatus: %-10s, IDirectionStatus: %-10s, "
             "RetVal: %-10s, Direction: %-10s, Brake: %-10s",
             IBrakeAndDirection,
             IBrakeStatus,
             IDirectionStatus,
             getStringFromBdrReturn(retVal),
             getStringFromBdrDirection(config.direction),
             getStringFromBdrBrake(config.brake));

    return output;
}

/* Constructor Implementations */

/**
 * @brief Constructor for the Brake and Direction Configuration.
 * 
 * Initializes the function pointers and assigns initial values for configuration.
 */
void BdrConfiguration_CTOR(void)
{
    /* Function pointer Implementation */
    instance.config.getDirection = getDirection_Impl;
    instance.config.setDirection = setDirection_Impl;
    instance.config.getBrake = getBrake_Impl;
    instance.config.setBrake = setBrake_Impl;
    
    /* Initial value assignment */
    instance.config.setDirection(DIRECTION_UNKNOWN);
    instance.config.setBrake(BRAKE_UNKNOWN);
}

/**
 * @brief Constructor for the Brake and Direction Manager.
 * 
 * Initializes the function pointers, assigns initial values, and binds the interfaces.
 */
void BrakeAndDirectionManager_CTOR(void)
{
    /* Child class constructor */
    BdrConfiguration_CTOR();

    /* Function pointer Implementation */
    instance.getRetVal = getRetVal_Impl;
    instance.setRetVal = setRetVal_Impl;
    instance.getConfig = getConfig_Impl;
    instance.setConfig = setConfig_Impl;
    instance.toString = BrakeAndDirectionManager_toString;

    /* Initial value assignment */
    instance.setRetVal(BDR_UNKNOWN);

    /* Interface assignment */
    instance.IBrakeAndDirection = &BrakeAndDirectionInterface;
    instance.IBrakeStatus = &BrakeStatusInterface;
    instance.IDirectionStatus = &DirectionStatusInterface;
}

/**
 * @brief Public function to access the Brake and Direction Manager instance.
 * 
 * @return Pointer to the static `dtBrakeAndDirectionManager` instance.
 */
dtBrakeAndDirectionManager* BrakeAndDirectionManager_GetInstance(void)
{
    return &instance;
}

/* Functional Behaviour Implementation */

