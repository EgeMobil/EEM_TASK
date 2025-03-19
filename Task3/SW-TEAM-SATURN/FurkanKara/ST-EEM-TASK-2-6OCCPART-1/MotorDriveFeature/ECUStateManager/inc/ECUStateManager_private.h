/**
 * @file ECUStateManager_private.h
 * @brief Private header file for the ECU State Manager.
 * 
 * This file contains private function declarations, variable definitions, 
 * and helper function prototypes for the ECU State Manager. It is intended 
 * for internal use within the ECU State Manager module.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#ifndef ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PRIVATE_H_
#define ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PRIVATE_H_

#include "ECUStateManager_definition.h"

/* Public Access */
#ifdef SIL_INTEGRATION
#include "BrakeAndDirectionManager_public.h"
#include "GateDriverController_public.h"
#include "HALLSensorConfiguration_public.h"
#include "InterruptHandlerManager_public.h"
#include "MotorDriverCommProxy_public.h"
#include "MotorDriverControlManager_public.h"
#include "MotorDriverDcmProxy_public.h"
#include "PWMConfiguration_public.h"
#include "SpeedControlManager_public.h"
#endif

/**
 * @brief ECU state variable.
 */
extern dtECUStateManager_ecuState ECU_STATE;

/**
 * @brief System state counter for startup process.
 */
extern uint32_t systemStateCount;

/**
 * @brief Startup state variable.
 */
extern dtECUStateManager_startUp systemStartUp;

/**
 * @brief Refresh state variable.
 */
extern dtECUStateManager_refreshState REFRESH_STATE;

/**
 * @brief Process state variable.
 */
extern dtECUStateManager_processState PROCESS_STATE;

/* State Machine functions prototypes */
/**
 * @brief Handles the startup state.
 */
void HandleStartupState(void);

/**
 * @brief Handles the initialization state.
 */
void HandleInitState(void);

/**
 * @brief Handles the routine operation state.
 */
void HandleRoutineState(void);

/**
 * @brief Handles the processing state.
 */
void HandleProcessState(void);

/**
 * @brief Handles the suspended state.
 */
void HandleSuspendState(void);

/* toString Helper prototypes */
/**
 * @brief Converts ECU state manager data to a string representation.
 */
void ECUStateManager_toString(void);

/**
 * @brief Gets the string representation of a startup state.
 * @param state The startup state.
 * @return String representation of the startup state.
 */
const char* GetStartupStateName(dtECUStateManager_startUp state);

/**
 * @brief Gets the string representation of an ECU state.
 * @param state The ECU state.
 * @return String representation of the ECU state.
 */
const char* GetEcuStateName(dtECUStateManager_ecuState state);

/**
 * @brief Gets the string representation of a refresh state.
 * @param state The refresh state.
 * @return String representation of the refresh state.
 */
const char* GetRefreshStateName(dtECUStateManager_refreshState state);

/**
 * @brief Gets the string representation of a process state.
 * @param state The process state.
 * @return String representation of the process state.
 */
const char* GetProcessStateName(dtECUStateManager_processState state);

/* Private Method Function Implementation Definition */
/**
 * @brief Executes the ECU state machine.
 */
void ECU_StateMachine(void);

/* Private-Public Function Implementation Definition */
/**
 * @brief Main function to manage ECU states.
 */
void ECUStateManager(void);

#endif /* ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PRIVATE_H_ */
