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

#include "IGPIOStatus.h"

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
 * @brief Time variables for tracking last execution time of each routine (in ms).
 */
static uint32_t lastGateDriverUpdate = 0;
static uint32_t lastMotorDriverUpdate = 0;
static uint32_t lastBrakeDirectionUpdate = 0;
static uint32_t lastSpeedControlUpdate = 0;
static uint32_t lastPwmConfigUpdate = 0;
static uint32_t lastCommProxyUpdate = 0;
static uint32_t lastDcmProxyUpdate = 0;

/**
 * @brief Defined update periods (in milliseconds) for each routine.
 */
#define PERIOD_GATEDRIVERCONTROLLER      1000  /**< Gate driver SPI communication update */
#define PERIOD_MOTORDRIVERCONTROLMANAGER 100    /**< Motor driver speed, brake, and direction handling */
#define PERIOD_BRAKEANDDIRECTIONMANAGER  100    /**< Brake and direction handling */
#define PERIOD_SPEEDCONTROLMANAGER       100    /**< Speed control update */
#define PERIOD_PWMCONFIGURATION          100    /**< PWM duty cycle updates */
#define PERIOD_MOTORDRIVERCOMMPROXY      100  /**< Motor driver communication updates */
#define PERIOD_MOTORDRIVERDCMPROXY       500  /**< Error reporting */


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

        	/* Read and update Initial GPIOStatus for Bsw */
        	IGPIOStatus_Init();

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
uint32_t testA =0;
uint32_t testB =0;
uint32_t testC =0;
uint32_t testD =0;
uint32_t testE =0;
uint32_t testF =0;
uint32_t testG =0;
/**
 * @brief Handles routine execution based on pre-defined time intervals.
 *
 * This function ensures that each system component is updated at
 * the correct time intervals to optimize performance and reduce CPU load.
 */
void HandleRoutineState(void)
{
    uint32_t currentTime = TimerInterruptInterface.readMillisecond(); /**< Retrieve the current system time (in ms) */

    /** Update Gate Driver Controller at defined period (10ms) */
    if ((currentTime - lastGateDriverUpdate) >= PERIOD_GATEDRIVERCONTROLLER) {
    	REFRESH_STATE = REFRESHSTATE_GATEDRIVERCONTROLLER;
        GateDriverController_ruRefresh();
        lastGateDriverUpdate = currentTime;testA++;
    }

    /** Update Motor Driver Control Manager at defined period (5ms) */
    if ((currentTime - lastMotorDriverUpdate) >= PERIOD_MOTORDRIVERCONTROLMANAGER) {
    	REFRESH_STATE = REFRESHSTATE_MOTORDRIVERCONTROLMANAGER;
        MotorDriverControlManager_ruRefresh();
        lastMotorDriverUpdate = currentTime;testB++;
    }

    /** Update Brake and Direction Manager at defined period (5ms) */
    if ((currentTime - lastBrakeDirectionUpdate) >= PERIOD_BRAKEANDDIRECTIONMANAGER) {
    	REFRESH_STATE = REFRESHSTATE_BRAKEANDDIRECTIONMANAGER;
        BrakeAndDirectionManager_ruRefresh();
        lastBrakeDirectionUpdate = currentTime;testC++;
    }

    /** Update Speed Control Manager at defined period (2ms) */
    if ((currentTime - lastSpeedControlUpdate) >= PERIOD_SPEEDCONTROLMANAGER) {
    	REFRESH_STATE = REFRESHSTATE_SPEEDCONTROLMANAGER;
        SpeedControlManager_ruRefresh();
        lastSpeedControlUpdate = currentTime;testD++;
    }

    /** Update PWM Configuration at defined period (2ms) */
    if ((currentTime - lastPwmConfigUpdate) >= PERIOD_PWMCONFIGURATION) {
    	REFRESH_STATE = REFRESHSTATE_PWMCONFIGURATION;
        PWMConfiguration_ruRefresh();
        lastPwmConfigUpdate = currentTime;testE++;
    }

    /** Update Motor Driver Communication Proxy at defined period (10ms) */
    if ((currentTime - lastCommProxyUpdate) >= PERIOD_MOTORDRIVERCOMMPROXY) {
    	REFRESH_STATE = REFRESHSTATE_MOTORDRIVERCOMMPROXY;
        MotorDriverCommProxy_ruRefresh();
        lastCommProxyUpdate = currentTime;testF++;
    }

    /** Update Motor Driver DCM Proxy (Error Reporting) at defined period (20ms) */
    if ((currentTime - lastDcmProxyUpdate) >= PERIOD_MOTORDRIVERDCMPROXY) {
    	REFRESH_STATE = REFRESHSTATE_MOTORDRIVERDCMPROXY;
        MotorDriverDcmProxy_ruRefresh();
        lastDcmProxyUpdate = currentTime;testG++;
    }

    /** Handle additional system states */
    switch (REFRESH_STATE) {
        case REFRESHSTATE_ANALOGREAD:
            /** Perform analog data reading */

        	REFRESH_STATE = REFRESHSTATE_COMMUNICATION;
            break;

        case REFRESHSTATE_COMMUNICATION:
            /** Perform communication refresh */

        	/* Final system state */
        	REFRESH_STATE = REFRESHSTATE_DEFAULT;
            break;

        case REFRESHSTATE_SUSPEND:
            /** System is in SUSPEND mode */
            break;

        case REFRESHSTATE_DEFAULT:
            /** Reset REFRESH_STATE to the default state */
            REFRESH_STATE = REFRESHSTATE_ANALOGREAD;
            break;

        default:
            /** Invalid REFRESH_STATE detected, resetting to default */
            REFRESH_STATE = REFRESHSTATE_DEFAULT;
            break;
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
            ECUStateManager_RunProcess(PROCESSSTATE_PWMCONFIGURATION_UPDATE);
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
