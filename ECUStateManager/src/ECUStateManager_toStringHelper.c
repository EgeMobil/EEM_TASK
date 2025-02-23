#include "ECUStateManager_private.h"

/**
 * @brief Helper function to get the string representation of the startup state.
 *
 * @param state The startup state to convert to a string.
 * @return A string representing the startup state.
 */
const char* GetStartupStateName(dtECUStateManager_startUp state)
{
    switch (state)
    {
        case STARTUP_UNKNOWN: return "UNKNOWN";
        case STARTUP_PRE_INIT: return "PRE_INIT";
        case STARTUP_INIT: return "INIT";
        case STARTUP_POST_INIT: return "POST_INIT";
        default: return "INVALID";
    }
}

/**
 * @brief Helper function to get the string representation of the ECU state.
 *
 * @param state The ECU state to convert to a string.
 * @return A string representing the ECU state.
 */
const char* GetEcuStateName(dtECUStateManager_ecuState state)
{
    switch (state)
    {
        case ECUSTATE_STARTUP: return "STARTUP";
        case ECUSTATE_INIT: return "INIT";
        case ECUSTATE_ROUTINE: return "ROUTINE";
        case ECUSTATE_PROCESS: return "PROCESS";
        case ECUSTATE_SUSPEND: return "SUSPEND";
        case ECUSTATE_DEFAULT: return "DEFAULT";
        default: return "INVALID";
    }
}

/**
 * @brief Helper function to get the string representation of the refresh state.
 *
 * @param state The refresh state to convert to a string.
 * @return A string representing the refresh state.
 */
const char* GetRefreshStateName(dtECUStateManager_refreshState state)
{
    switch (state)
    {
        case REFRESHSTATE_UNKNOWN: return "UNKNOWN";
        case REFRESHSTATE_ANALOGREAD: return "(PRIO:X)ANALOGREAD";
        case REFRESHSTATE_COMMUNICATION: return "(PRIO:X)COMMUNICATION";
        case REFRESHSTATE_GATEDRIVERCONTROLLER: return "(PRIO:1)GATEDRIVERCONTROLLER";
        case REFRESHSTATE_MOTORDRIVERCONTROLMANAGER: return "(PRIO:2)MOTORDRIVERCONTROL";
        case REFRESHSTATE_BRAKEANDDIRECTIONMANAGER: return "(PRIO:3)REFRESHSTATE_BRAKEANDDIRECTIONMANAGER";
        case REFRESHSTATE_SPEEDCONTROLMANAGER: return "(PRIO:3)SPEEDCONTROLMANAGER";
        case REFRESHSTATE_MOTORDRIVERCOMMPROXY: return "(PRIO:4)MOTORDRIVERCOMMPROXY";
        case REFRESHSTATE_MOTORDRIVERDCMPROXY: return "(PRIO:5)MOTORDRIVERDCMPROXY";
        case REFRESHSTATE_PWMCONFIGURATION: return "(PRIO:6)PWMCONFIGURATION";
        case REFRESHSTATE_SUSPEND: return "SUSPEND";
        case REFRESHSTATE_DEFAULT: return "DEFAULT";
        default: return "INVALID";
    }
}

/**
 * @brief Helper function to get the string representation of the process state.
 *
 * @param state The process state to convert to a string.
 * @return A string representing the process state.
 */
const char* GetProcessStateName(dtECUStateManager_processState state)
{
    switch (state)
    {
        case PROCESSSTATE_UNKNOWN: return "UNKNOWN";
        case PROCESSSTATE_INTERRUPTHANDLERMANAGER_EXTERNALTRIGGER: return "EXTERNALTRIGGER";
        case PROCESSSTATE_INTERRUPTHANDLERMANAGER_TIMERTRIGGER: return "TIMERTRIGGER";
        case PROCESSSTATE_HALLSENSORCONFIGURATION_UPDATE: return "HALLSENSOR_UPDATE";
        case PROCESSSTATE_PWMCONFIGURATION_UPDATE: return "PWM_UPDATE";
        case PROCESSSTATE_ANALOGDATAWRAPPER: return "ANALOGDATAWRAPPER";
        case PROCESSSTATE_TXSIGNALADAPTER: return "TXSIGNALADAPTER";
        case PROCESSSTATE_FINISHED: return "FINISHED";
        case PROCESSSTATE_DEFAULT: return "DEFAULT";
        default: return "INVALID";
    }
}

/**
 * @brief Prints the current state of the ECU system, including startup, ECU, refresh, and process states.
 */
void ECUStateManager_toString(void)
{
#ifndef STM32G431xx
    printf("SysCount: %2d | Startup: %-10s | ECU_STATE: %-8s | REFRESH_STATE: %-30s | PROCESS_STATE: %-22s | \n",
           systemStateCount,
           GetStartupStateName(systemStartUp),
           GetEcuStateName(ECU_STATE),
           GetRefreshStateName(REFRESH_STATE),
           GetProcessStateName(PROCESS_STATE) );
#endif
}
