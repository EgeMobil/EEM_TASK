/**
 * @file ECUStateManager.c
 * @brief Implementation of the ECU State Manager for managing different states of the ECU.
 * 
 * This module handles the management of various states in the ECU, including initialization,
 * routine operation, and suspend states. It coordinates the transitions between these states
 * based on the system startup and refresh requirements.
* @author atakan.ertekin
 * @date 07.01.2025
 */

#include "ECUStateManager_private.h"

/**
 * @brief Global variable that stores the current ECU state.
 * 
 * This variable holds the current state of the ECU, such as startup, initialization, or routine operation.
 */
dtECUStateManager_ecuState ECU_STATE = ECUSTATE_STARTUP;

/**
 * @brief Counter for tracking the system state count during startup.
 * 
 * This counter is used to track how many times the system has gone through different startup phases.
 */
uint32_t systemStateCount = 0;  /**< Start up count local variable */

/**
 * @brief Current system startup stage.
 * 
 * This variable keeps track of the current stage in the startup process, such as pre-initialization, initialization, or post-initialization.
 */
dtECUStateManager_startUp systemStartUp = STARTUP_PRE_INIT;

/**
 * @brief Current refresh state.
 * 
 * This variable holds the state for refreshing various components of the ECU, such as the gate driver and motor driver.
 */
dtECUStateManager_refreshState REFRESH_STATE = REFRESHSTATE_UNKNOWN;

/**
 * @brief Current process state.
 * 
 * This variable tracks the current process state, such as handling external triggers, updating configurations, or performing data processing.
 */
dtECUStateManager_processState PROCESS_STATE = PROCESSSTATE_UNKNOWN;

/**
 * @brief Handles the startup state and transitions between startup phases.
 * 
 * This function manages the different phases of the startup process:
 * - PRE_INIT: Initializes system components.
 * - INIT: Performs ECU initialization tasks.
 * - POST_INIT: Executes post-initialization routines.
 */
void HandleStartupState(void)
{
    // Handling STARTUP state
    switch (systemStartUp) {
        case STARTUP_PRE_INIT:
            // System in PRE_INIT stage
            // Constructor of class
            BrakeAndDirectionManager_CTOR();
            GateDriverController_CTOR();
            InterruptHandlerManager_CTOR();
            HALLSensorConfiguration_CTOR();
            MotorDriverCommProxy_CTOR();
            MotorDriverControlManager_CTOR();
            MotorDriverDcmProxy_CTOR();
            PWMConfiguration_CTOR();
            SpeedControlManager_CTOR();

            // Transition to the next phase
            systemStartUp = STARTUP_INIT;
            break;

        case STARTUP_INIT:
            // System in INIT stage
            // ECU initialization tasks
            ECU_STATE = ECUSTATE_INIT;
            break;

        case STARTUP_POST_INIT:
            // System in POST_INIT stage
            // Post-initialization routines
            ECU_STATE = ECUSTATE_ROUTINE;
            break;

        default:
            // Invalid STARTUP state detected
            systemStartUp = STARTUP_PRE_INIT; // Default back to PRE_INIT
            break;
    }
}

/**
 * @brief Handles the initialization state of the ECU.
 * 
 * This function performs the initialization of various system components and transitions
 * to the post-initialization stage after successful initialization.
 */
void HandleInitState(void)
{
    // Handling INIT state
    GateDriverController_ruInitialisation();
    InterruptHandlerMAnager_ruInitialisation();
    HALLSensorConfiguration_ruInitialisation();
    MotorDriverControlManager_ruInitialisation();
    BrakeAndDirectionManager_ruInitialistaion();
    SpeedControlManager_ruInitialisation();
    PWMConfiguration_ruInitialisation();

    // Successful init, transition to post-init state
    systemStartUp = STARTUP_POST_INIT;
    ECU_STATE = ECUSTATE_STARTUP;
}

/**
 * @brief Handles the routine operation state.
 * 
 * This function manages the routine operations of the ECU, including refreshing components
 * like the gate driver, motor driver, and other interfaces.
 */
void HandleRoutineState(void)
{
    // Handling ROUTINE state
    switch (REFRESH_STATE) {
        case REFRESHSTATE_GATEDRIVERCONTROLLER:
            // Refreshing Gate Driver Controller
            GateDriverController_ruRefresh();
            break;

        case REFRESHSTATE_MOTORDRIVERCONTROLMANAGER:
            // Refreshing Motor Driver Control Manager
            MotorDriverControlManager_ruRefresh();
            break;

        case REFRESHSTATE_BRAKEANDDIRECTIONMANAGER:
            // Refreshing Brake and Direction Manager
            BrakeAndDirectionManager_ruRefresh();
            break;

        case REFRESHSTATE_SPEEDCONTROLMANAGER:
            // Refreshing Speed Control Manager
            SpeedControlManager_ruRefresh();
            break;

        case REFRESHSTATE_PWMCONFIGURATION:
            // Refreshing PWM Configuration
            PWMConfiguration_ruRefresh();
            break;

        case REFRESHSTATE_MOTORDRIVERCOMMPROXY:
            // Refreshing Motor Driver Communication Proxy
            MotorDriverCommProxy_ruRefresh();
            break;

        case REFRESHSTATE_MOTORDRIVERDCMPROXY:
            // Refreshing Motor Driver DCM Proxy
            MotorDriverDcmProxy_ruRefresh();
            break;

        case REFRESHSTATE_ANALOGREAD:
            // Performing Analog Read
            break;

        case REFRESHSTATE_COMMUNICATION:
            // Performing Communication Refresh
            break;

        case REFRESHSTATE_SUSPEND:
            // System is in SUSPEND state
            // Suspend operations
            break;

        case REFRESHSTATE_DEFAULT:
            // Resetting REFRESH_STATE to REFRESHSTATE_GATEDRIVERCONTROLLER
            REFRESH_STATE = REFRESHSTATE_GATEDRIVERCONTROLLER;
            break;

        default:
            // Invalid REFRESH_STATE detected
            // Default to first routine, analog reading
            REFRESH_STATE = REFRESHSTATE_DEFAULT; 
            break;
    }

    // Move to next state
    REFRESH_STATE++;
    if (REFRESH_STATE > REFRESHSTATE_COMMUNICATION) {
        REFRESH_STATE = REFRESHSTATE_GATEDRIVERCONTROLLER; // Complete the loop and restart
    }
}

/**
 * @brief Handles the process state.
 * 
 * This function controls the execution of different processes based on the current process state,
 * including handling interrupts, updating configurations, and other tasks.
 */
void HandleProcessState(void)
{
    // Handling PROCESS state
    dtECUStateManager_processState PREV_PROCESS_STATE = PROCESS_STATE;
    dtECUStateManager_processState PREV_REFRESH_STATE = REFRESH_STATE;
    REFRESH_STATE = REFRESHSTATE_SUSPEND;

    switch (PROCESS_STATE) {
        case PROCESSSTATE_INTERRUPTHANDLERMANAGER_EXTERNALTRIGGER:
            // Handling External Interrupt Trigger
            InterruptHandlerManager_ruExternalTrigger();
            ECUStateManager_RunProcess(PROCESSSTATE_HALLSENSORCONFIGURATION_UPDATE);
            break;

        case PROCESSSTATE_INTERRUPTHANDLERMANAGER_TIMERTRIGGER:
            // Handling Timer Interrupt Trigger
            InterruptHandlerManager_ruTimerTrigger();
            break;

        case PROCESSSTATE_HALLSENSORCONFIGURATION_UPDATE:
            // Updating Hall Sensor Configuration
            HALLSensorConfiguration_ruUpdateA();
            HALLSensorConfiguration_ruUpdateB();
            HALLSensorConfiguration_ruUpdateC();
            break;

        case PROCESSSTATE_PWMCONFIGURATION_UPDATE:
            // Updating PWM Configuration
            PWMConfiguration_ruUpdate();
            break;

        case PROCESSSTATE_TXSIGNALADAPTER:
            // Handling Tx Signal Adapter
            //@LATER TxSignal Operations
            break;

        case PROCESSSTATE_ANALOGDATAWRAPPER:
            // Handling Analog Data Wrapper
            //@LATER Analog Data Operations
            ECUStateManager_RunProcess(PROCESSSTATE_TXSIGNALADAPTER);
            break;

        case PROCESSSTATE_FINISHED:
            // System is in SUSPEND state
            // Suspend operations
            PROCESS_STATE = PROCESSSTATE_DEFAULT;
            break;

        case PROCESSSTATE_DEFAULT:
            // Resetting PROCESS_STATE to UNKNOWN
            REFRESH_STATE = PREV_REFRESH_STATE + 1 ;
            ECU_STATE = ECUSTATE_ROUTINE;
            break;

        default:
            // Invalid PROCESS_STATE detected
            PROCESS_STATE = PROCESSSTATE_DEFAULT; // Default to process state
            break;
    }

    // Defensive coding to handle state transitions
    if (PREV_PROCESS_STATE == PROCESS_STATE && PROCESSSTATE_DEFAULT != PROCESS_STATE) {
        PROCESS_STATE = PROCESSSTATE_FINISHED;
    } else {
        /* Defensive Coding */
    }
}

/**
 * @brief Handles the suspend state of the ECU.
 * 
 * This function manages the ECU's operations when it is in a suspended state.
 * The ECU will be set back to a default state when this process is complete.
 */
void HandleSuspendState(void)
{
    // Handling SUSPEND state
    ECU_STATE = ECUSTATE_DEFAULT;
}
