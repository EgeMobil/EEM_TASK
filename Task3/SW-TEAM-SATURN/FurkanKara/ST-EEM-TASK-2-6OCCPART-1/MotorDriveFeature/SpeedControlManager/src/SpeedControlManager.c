/**
 * @file SpeedControlManager.c
 * @brief Implementation file for the Speed Control Manager.
 * 
 * This file contains the implementation of the Speed Control Manager, including 
 * methods for initialization, configuration management, and periodic updates. 
 * The manager interacts with various interfaces to read and write speed control 
 * statuses and provides functionality to handle state changes dynamically.
 * 
 * Key functionalities include:
 * - Initialization of speed control configurations.
 * - Interface communication for speed status and indicator.
 * - Configuration and status updates.
 * 
 * The file adheres to the singleton design pattern to ensure only one instance 
 * of the manager exists at runtime.
 * 
 * @author batu.murt
 * @date 23.01.2025
 */

#include "SpeedControlManager_private.h"

/**
 * @brief Speed Control Manager Instance.
 * 
 * A static instance of the `dtSpeedControlManager` structure that holds the 
 * current state and configuration of the Speed Control Manager.
 */
static dtSpeedControlManager instance;

/* Getter/Setter Implementation */

/**
 * @brief Gets the current return value of the manager.
 * 
 * @return The current return value of type `dtSpeedControlManager_scmReturn`.
 */
dtSpeedControlManager_scmReturn SpeedControlManager_getRetVal_Impl(void)
{
    return instance.retVal;
}

/**
 * @brief Sets the return value of the manager.
 * 
 * @param value The return value to set.
 */
void SpeedControlManager_setRetVal_Impl(dtSpeedControlManager_scmReturn value)
{
    instance.retVal = value;
}

/**
 * @brief Gets the current configuration of the manager.
 * 
 * @return The current configuration of type `dtSpeedControlManager_scmConfiguration`.
 */
dtSpeedControlManager_scmConfiguration SpeedControlManager_getConfig_Impl(void)
{
    return instance.config;
}

/**
 * @brief Sets the configuration of the manager.
 * 
 * @param value The configuration to set.
 */
void SpeedControlManager_setConfig_Impl(dtSpeedControlManager_scmConfiguration value)
{
    instance.config = value;
}

/* Getter/Setter for Raw Speed, Speed Status, and Indicator */

/**
 * @brief Gets the current minimum step configuration.
 * 
 * @return The current minimum step value.
 */
uint16_t SpeedControlManager_getMinStep_Impl(void)
{
    return instance.config.minStep;
}

/**
 * @brief Sets the minimum step configuration.
 * 
 * @param value The minimum step value to set.
 */
void SpeedControlManager_setMinStep_Impl(uint16_t value)
{
    instance.config.minStep = value;
}

/**
 * @brief Gets the current maximum step configuration.
 * 
 * @return The current maximum step value.
 */
uint16_t SpeedControlManager_getMaxStep_Impl(void)
{
    return instance.config.maxStep;
}

/**
 * @brief Sets the maximum step configuration.
 * 
 * @param value The maximum step value to set.
 */
void SpeedControlManager_setMaxStep_Impl(uint16_t value)
{
    instance.config.maxStep = value;
}

/**
 * @brief Gets the current divider step configuration.
 * 
 * @return The current divider step value.
 */
uint16_t SpeedControlManager_getDividerStep_Impl(void)
{
    return instance.config.divider;
}

/**
 * @brief Sets the divider configuration.
 * 
 * @param value The divider value to set.
 */
void SpeedControlManager_setDivider_Impl(uint16_t value)
{
    instance.config.divider = value;
}

/* Brake, Raw Speed, Speed Status, and Indicator Implementation */

dtSpeedControlManager_brakeStatus SpeedControlManager_getBrake_Impl(void)
{
    return instance.config.brake;
}

void SpeedControlManager_setBrake_Impl(dtSpeedControlManager_brakeStatus brake)
{
    instance.config.brake = brake;
}

/**
 * @brief Gets the current raw speed configuration.
 * 
 * @return The current raw speed configuration.
 */
dtSpeedControlManager_scmRawSpeed SpeedControlManager_getRawSpeed_Impl(void)
{
    return instance.config.rawSpeed;
}

/**
 * @brief Sets the raw speed configuration.
 * 
 * @param value The raw speed value to set.
 */
void SpeedControlManager_setRawSpeed_Impl(dtSpeedControlManager_scmRawSpeed value)
{
    instance.config.rawSpeed = value;
}

/**
 * @brief Gets the current speed status configuration.
 * 
 * @return The current speed status configuration.
 */
dtSpeedControlManager_scmSpeedStatus SpeedControlManager_getSpeedStatus_Impl(void)
{
    return instance.config.speedStatus;
}

/**
 * @brief Sets the speed status configuration.
 * 
 * @param value The speed status value to set.
 */
void SpeedControlManager_setSpeedStatus_Impl(dtSpeedControlManager_scmSpeedStatus value)
{
    instance.config.speedStatus = value;
}

/**
 * @brief Gets the current indicator configuration.
 * 
 * @return The current indicator configuration.
 */
dtSpeedControlManager_scmIndicator SpeedControlManager_getIndicator_Impl(void)
{
    return instance.config.indicator;
}

/**
 * @brief Sets the indicator configuration.
 * 
 * @param value The indicator value to set.
 */
void SpeedControlManager_setIndicator_Impl(dtSpeedControlManager_scmIndicator value)
{
    instance.config.indicator = value;
}

/* String Conversion Implementations */

/**
 * @brief Converts the `dtScmReturn` value to a string representation.
 * 
 * @param value The return value to convert.
 * @return A string representation of the value.
 */
const char* getStringFromScmReturn(dtScmReturn value)
{
    switch (value)
    {
        case SCM_ERR:     return "SCM_ERR";
        case SCM_EOK:     return "SCM_EOK";
        case SCM_UNKNOWN: return "SCM_UNKNOWN";
        default: return "UNKNOWN STATION";
    }
}

/**
 * @brief Converts the `dtSpeedControlManager_scmIndicator` value to a string.
 * 
 * @param value The indicator value to convert.
 * @return A string representation of the indicator value.
 */
const char* getStringFromScmIndicator(dtSpeedControlManager_scmIndicator value)
{
    switch (value)
    {
        case INDICATORSPEEDSTATUS_IDLE: return "INDICATORSPEEDSTATUS_IDLE";
        case INDICATORSPEEDSTATUS_LOWSPEED: return "INDICATORSPEEDSTATUS_LOWSPEED";
        case INDICATORSPEEDSTATUS_MIDSPEED: return "INDICATORSPEEDSTATUS_MIDSPEED";
        case INDICATORSPEEDSTATUS_HIGHSPEED: return "INDICATORSPEEDSTATUS_HIGHSPEED";
        case INDICATORSPEEDSTATUS_UNKNOWN: return "INDICATORSPEEDSTATUS_UNKNOWN";
        default: return "UNKNOWN";
    }
}

/**
 * @brief Converts the SpeedControlManager to a string representation.
 * 
 * @return A dynamically allocated string representation of the manager state.
 */
char* SpeedControlManager_toString(void)
{
    dtSpeedControlManager* instance = SpeedControlManager_GetInstance();

    // Retrieve current values
    dtSpeedControlManager_scmReturn retVal = instance->getRetVal();
    dtSpeedControlManager_scmConfiguration config = instance->getConfig();

    // Check interface pointer status
    const char* IRawSpeed = (instance->IRawSpeed != NULL) ? "CONNECTED" : "DISCONNECTED";
    const char* ISpeedStatus = (instance->ISpeedStatus != NULL) ? "CONNECTED" : "DISCONNECTED";
    const char* IIndicatorSpeedStatus = (instance->IIndicatorSpeedStatus != NULL) ? "CONNECTED" : "DISCONNECTED";

    // Allocate memory for the output string
    char* output = (char*)malloc(256);
    if (output == NULL)
    {
        return strdup("Memory allocation failed.");
    }

    snprintf(output, 256,
             "[SpeedControlManager]: IRawSpeed: %-10s, ISpeedStatus: %-10s, IIndicatorSpeedStatus: %-10s, "
             "RetVal: %-10s, Indicator: %-10s, RawSpeed: %-10d, SpeedStatus: %-10d, BrakeStatus: %-10d",
             IRawSpeed,
             ISpeedStatus,
             IIndicatorSpeedStatus,
             getStringFromScmReturn(retVal),
             getStringFromScmIndicator(config.indicator),
             instance->config.getRawSpeed(),
             instance->config.getSpeedStatus(),
             instance->config.getBrake() );

    return output;
}

/* Constructor Implementations */

/**
 * @brief Constructor for the Speed Control Manager Configuration.
 * 
 * Initializes the function pointers and assigns initial values for configuration.
 */
void ScmConfiguration_CTOR(void)
{
    instance.config.getMinStep = SpeedControlManager_getMinStep_Impl;
    instance.config.getMaxStep = SpeedControlManager_getMaxStep_Impl;
    instance.config.getDivider = SpeedControlManager_getDividerStep_Impl;

    instance.config.setMinStep = SpeedControlManager_setMinStep_Impl;
    instance.config.setMaxStep = SpeedControlManager_setMaxStep_Impl;
    instance.config.setDivider = SpeedControlManager_setDivider_Impl;

    instance.config.getBrake = SpeedControlManager_getBrake_Impl;
    instance.config.getRawSpeed = SpeedControlManager_getRawSpeed_Impl;
    instance.config.getSpeedStatus = SpeedControlManager_getSpeedStatus_Impl;
    instance.config.getIndicator = SpeedControlManager_getIndicator_Impl;

    instance.config.setBrake = SpeedControlManager_setBrake_Impl;
    instance.config.setRawSpeed = SpeedControlManager_setRawSpeed_Impl;
    instance.config.setSpeedStatus = SpeedControlManager_setSpeedStatus_Impl;
    instance.config.setIndicator = SpeedControlManager_setIndicator_Impl;

    instance.config.setIndicator(INDICATORSPEEDSTATUS_UNKNOWN);
}

/**
 * @brief Constructor for the Speed Control Manager.
 * 
 * Initializes the function pointers, assigns initial values, and binds the interfaces.
 */
void SpeedControlManager_CTOR(void)
{
    ScmConfiguration_CTOR();

    instance.getRetVal = SpeedControlManager_getRetVal_Impl;
    instance.getConfig = SpeedControlManager_getConfig_Impl;

    instance.setRetVal = SpeedControlManager_setRetVal_Impl;
    instance.setConfig = SpeedControlManager_setConfig_Impl;

    instance.toString = SpeedControlManager_toString;

    instance.setRetVal(SCM_UNKNOWN);

    // Interface assignment
    instance.IBrakeStatus = &BrakeStatusInterface;
    instance.IRawSpeed = &RawSpeedInterface;
    instance.ISpeedStatus = &SpeedStatusInterface;
    instance.IIndicatorSpeedStatus = &IndicatorSpeedStatusInterface;
}

/**
 * @brief Public function to access the Speed Control Manager instance.
 * 
 * @return Pointer to the static `dtSpeedControlManager` instance.
 */
dtSpeedControlManager* SpeedControlManager_GetInstance(void)
{
    return &instance;
}
