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

/*********Private Variable Definition*****************/
extern dtECUStateManager_ecuState  ECU_STATE;
extern uint32_t systemStateCount ;  /* Start up count local variable */

/*********Private-Public Variable Definition*****************/
extern dtECUStateManager_startUp  	   systemStartUp ;
extern dtECUStateManager_refreshState  REFRESH_STATE ;
extern dtECUStateManager_processState  PROCESS_STATE ;


/* State Machine functions prototypes */
void HandleStartupState(void);
void HandleInitState(void);
void HandleRoutineState(void);
void HandleProcessState(void);
void HandleSuspendState(void);

/* toString Helper prototypes */
void ECUStateManager_toString(void);
const char* GetStartupStateName(dtECUStateManager_startUp state);
const char* GetEcuStateName(dtECUStateManager_ecuState state);
const char* GetRefreshStateName(dtECUStateManager_refreshState state);
const char* GetProcessStateName(dtECUStateManager_processState state);

/* Private Method Func Implementation Definition */
void ECU_StateMachine(void);

/* Private-Public Func Implementation Definition */
void ECUStateManager(void);

#endif /* ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PRIVATE_H_ */