/**
 * @file ECUStateManager_definition.h
 * @brief Definition header file for the ECU State Manager.
 * 
 * This file contains the definitions, data types, and structure declarations 
 * for the ECU State Manager. It includes necessary enums and function declarations 
 * for managing ECU states and processes.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#ifndef ECUSTATEMANAGER_INC_ECUSTATEMANAGER_DEFINITION_H_
#define ECUSTATEMANAGER_INC_ECUSTATEMANAGER_DEFINITION_H_

#include "stdio.h"
#include "stdint.h" 

#define SIL_INTEGRATION
//#undef SIL_INTEGRATION

/**
 * @brief Enum for ECU states.
 */
typedef enum
{
    ECUSTATE_STARTUP = 0, /**< Startup state. */
    ECUSTATE_INIT,        /**< Initialization state. */
    ECUSTATE_ROUTINE,     /**< Routine operation state. */
    ECUSTATE_PROCESS,     /**< Processing state. */
    ECUSTATE_SUSPEND,     /**< Suspended state. */
    ECUSTATE_DEFAULT      /**< Default state. */
} dtEcuState;

/**
 * @brief Alias for ECU state.
 */
typedef dtEcuState dtECUStateManager_ecuState;

/**
 * @brief Enum for startup states.
 */
typedef enum
{
    STARTUP_UNKNOWN = 0, /**< Unknown startup state. */
    STARTUP_PRE_INIT,    /**< Pre-initialization state. */
    STARTUP_INIT,        /**< Initialization state. */
    STARTUP_POST_INIT    /**< Post-initialization state. */
} dtStartUp;

/**
 * @brief Alias for startup state.
 */
typedef dtStartUp dtECUStateManager_startUp;

/**
 * @brief Enum for refresh states.
 */
typedef enum
{
    REFRESHSTATE_UNKNOWN = 0, /**< Unknown refresh state. */
    /* Motor Driver Feature */
    REFRESHSTATE_GATEDRIVERCONTROLLER,
    REFRESHSTATE_MOTORDRIVERCONTROLMANAGER,
    REFRESHSTATE_BRAKEANDDIRECTIONMANAGER,
    REFRESHSTATE_SPEEDCONTROLMANAGER,
    REFRESHSTATE_PWMCONFIGURATION,
    REFRESHSTATE_MOTORDRIVERCOMMPROXY,
    REFRESHSTATE_MOTORDRIVERDCMPROXY,
    /* Analog Configuration Feature */
    REFRESHSTATE_ANALOGREAD,
    /* Communication Feature */
    REFRESHSTATE_COMMUNICATION,
    /***********************************/
    REFRESHSTATE_SUSPEND,
    REFRESHSTATE_DEFAULT
} dtRefreshState;

/**
 * @brief Alias for refresh state.
 */
typedef dtRefreshState dtECUStateManager_refreshState;

/**
 * @brief Enum for process states.
 */
typedef enum
{
    PROCESSSTATE_UNKNOWN = 0, /**< Unknown process state. */
    /* Motor Driver Feature */
    PROCESSSTATE_INTERRUPTHANDLERMANAGER_EXTERNALTRIGGER,
    PROCESSSTATE_INTERRUPTHANDLERMANAGER_TIMERTRIGGER,
    PROCESSSTATE_HALLSENSORCONFIGURATION_UPDATE,
    PROCESSSTATE_PWMCONFIGURATION_UPDATE,
    /* Communication Feature */
    PROCESSSTATE_TXSIGNALADAPTER,
    /* Analog Configuration Feature */
    PROCESSSTATE_ANALOGDATAWRAPPER,
    /***********************************/
    PROCESSSTATE_FINISHED,
    PROCESSSTATE_DEFAULT
} dtProcessState;

/**
 * @brief Alias for process state.
 */
typedef dtProcessState dtECUStateManager_processState;

/**
 * @brief Runs the specified ECU process.
 * 
 * @param processState The process state to execute.
 */
extern void ECUStateManager_RunProcess(dtECUStateManager_processState processState);

#endif /* ECUSTATEMANAGER_INC_ECUSTATEMANAGER_DEFINITION_H_ */
