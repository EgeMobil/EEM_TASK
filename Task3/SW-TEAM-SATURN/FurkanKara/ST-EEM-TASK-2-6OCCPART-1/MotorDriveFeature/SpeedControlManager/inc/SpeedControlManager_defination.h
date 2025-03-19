/**
 * @file SpeedControlManager_definition.h
 * @brief Definition header file for the Speed Control Manager.
 * 
 * This file contains the definitions, data types, and structure declarations 
 * for the Speed Control Manager. It includes the necessary interfaces 
 * and dependencies for managing speed control functionalities in the 
 * MotorDriverControlManager.
 * 
 * @author batu.murt
 * @date 23.01.2025
 */

#ifndef SPEEDCONTROLMANAGER_INC_SPEEDCONTROLMANAGER_DEFINITION_H_
#define SPEEDCONTROLMANAGER_INC_SPEEDCONTROLMANAGER_DEFINITION_H_

/* Include interface headers */
#include "ECUStateManager_global.h"

#include "IRawSpeed.h"
#include "ISpeedStatus.h"
#include "IIndicatorSpeedStatus.h"
#include "IBrakeStatus.h"

/* Return value enum */
/**
 * @enum dtScmReturn
 * @brief Return values for Speed Control Manager functions.
 * 
 * SCM_ERR: Error state
 * SCM_EOK: Successful operation
 * SCM_UNKNOWN: Unknown error state
 */
typedef enum
{
    SCM_ERR = 0,    /**< Error state */
    SCM_EOK,        /**< Successful operation */
    SCM_UNKNOWN     /**< Unknown error state */
} dtScmReturn;

/**
 * @typedef dtSpeedControlManager_scmReturn
 * @brief Return type for Speed Control Manager functions.
 */
typedef dtScmReturn            dtSpeedControlManager_scmReturn;

/**
 * @typedef dtSpeedControlManager_scmRawSpeed
 * @brief Raw speed status type.
 */
typedef cmRawSpeedStatus       dtSpeedControlManager_scmRawSpeed;

/**
 * @typedef dtSpeedControlManager_scmSpeedStatus
 * @brief Speed status type.
 */
typedef cmSpeedStatus          dtSpeedControlManager_scmSpeedStatus;

/**
 * @typedef dtSpeedControlManager_scmIndicator
 * @brief Speed indicator status type.
 */
typedef cmIndicatorSpeedStatus dtSpeedControlManager_scmIndicator;

typedef cmBrakeStatusType dtSpeedControlManager_brakeStatus;

/**
 * @struct dtScmConfig
 * @brief Configuration structure for Speed Control Manager.
 * 
 * This structure holds the configuration for the speed control manager 
 * and defines the operations for managing speed status, raw speed, and 
 * speed indicators. It also includes functions for getting and setting 
 * speed parameters.
 */
typedef struct
{
    dtSpeedControlManager_scmRawSpeed    rawSpeed;      /**< Raw speed data */
    dtSpeedControlManager_scmSpeedStatus speedStatus;   /**< Speed status */
    dtSpeedControlManager_scmIndicator   indicator;     /**< Speed indicator status */

    dtSpeedControlManager_brakeStatus brake; /**< Brake Status */

    uint16_t targetSpeed;    /**< Target speed */
    uint16_t currentSpeed;   /**< Current speed */

    uint16_t minStep;        /**< Minimum speed step */
    uint16_t maxStep;        /**< Maximum speed step */
    uint16_t divider;        /**< Divider value */

    uint16_t (*getMinStep)(void);  /**< Function to get the minimum step */
    void (*setMinStep)(uint16_t minStep); /**< Function to set the minimum step */

    uint16_t (*getMaxStep)(void);  /**< Function to get the maximum step */
    void (*setMaxStep)(uint16_t maxStep); /**< Function to set the maximum step */

    uint16_t (*getDivider)(void);  /**< Function to get the divider value */
    void (*setDivider)(uint16_t divider); /**< Function to set the divider value */

    dtSpeedControlManager_brakeStatus (*getBrake)(void); /**< Function to get brake data */
    void (*setBrake)(dtSpeedControlManager_brakeStatus brake); /**< Function to set brake  data */

    dtSpeedControlManager_scmRawSpeed (*getRawSpeed)(void); /**< Function to get raw speed data */
    void (*setRawSpeed)(dtSpeedControlManager_scmRawSpeed rawSpeed); /**< Function to set raw speed data */

    dtSpeedControlManager_scmSpeedStatus(*getSpeedStatus)(void); /**< Function to get the speed status */
    void (*setSpeedStatus)(dtSpeedControlManager_scmSpeedStatus speedStatus); /**< Function to set the speed status */

    dtSpeedControlManager_scmIndicator (*getIndicator)(void); /**< Function to get the speed indicator status */
    void (*setIndicator)(dtSpeedControlManager_scmIndicator indicator); /**< Function to set the speed indicator status */
} dtScmConfig;

/**
 * @typedef dtSpeedControlManager_scmConfiguration
 * @brief Configuration type for the Speed Control Manager.
 * 
 * This type represents the configuration structure for the speed control 
 * manager, holding all parameters related to the speed control process.
 */
typedef dtScmConfig dtSpeedControlManager_scmConfiguration;

/**
 * @struct dtSpeedControlManager
 * @brief Speed Control Manager structure.
 * 
 * This structure holds the interface pointers, return value, and configuration 
 * for the speed control manager. It provides the operations for managing the 
 * speed control system, including the configuration and speed status.
 */
typedef struct
{
    /* Interface pointers */
    IRawSpeed*             IRawSpeed; /**< Raw speed interface */
    ISpeedStatus*          ISpeedStatus; /**< Speed status interface */
    IIndicatorSpeedStatus* IIndicatorSpeedStatus; /**< Speed indicator interface */
    IBrakeStatus*          IBrakeStatus; /**< Brake Status interface */

    dtSpeedControlManager_scmReturn retVal; /**< Return value */
    dtSpeedControlManager_scmConfiguration config; /**< Configuration structure */

    dtSpeedControlManager_scmReturn (*getRetVal)(void); /**< Function to get the return value */
    void (*setRetVal)(dtSpeedControlManager_scmReturn value); /**< Function to set the return value */

    dtSpeedControlManager_scmConfiguration(*getConfig)(void); /**< Function to get the configuration */
    void(*setConfig)(dtSpeedControlManager_scmConfiguration value); /**< Function to set the configuration */
    
    char* (*toString)(void); /**< Function to get a string representation of the structure */

} dtSpeedControlManager;

#endif /* SPEEDCONTROLMANAGER_INC_SPEEDCONTROLMANAGER_DEFINATION_H_ */
