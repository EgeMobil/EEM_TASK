#ifndef ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PRIVATE_H_
#define ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PRIVATE_H_

#include "ECUStateManager_definition.h"

/*********Private Variable Definition*****************/
dtECUStateManager_ecuState 		ECU_STATE 	   = ECUSTATE_UNKNOWN;

/*********Private-Public Variable Definition*****************/
dtECUStateManager_startUp  		        systemStartUp           = STARTUP_PRE_INIT;
dtECUStateManager_refreshState	        REFRESH_STATE           = REFRESHSTATE_UNKNOWN;
dtECUStateManager_processState          PROCESS_STATE           = PROCESSSTATE_UNKNOWN; 

dtECUStateManager_processState          processQueue[5]         = {PROCESSSTATE_DEFAULT,PROCESSSTATE_DEFAULT,PROCESSSTATE_DEFAULT,PROCESSSTATE_DEFAULT,PROCESSSTATE_DEFAULT};

/* Integration Process Execution Variables for Process */
dtECUStateManager_processExecutionState AnalogDataWrapper_processExecutionState   = PROCESS_EXECUTION_UNKNOWN; 

dtECUStateManager_processExecutionState TxSignalAdapter_processExecutionState     = PROCESS_EXECUTION_UNKNOWN;  
dtECUStateManager_processRunningCounter TxSignalAdapter_processRunningCounter     = 0;

/* Private Method Func Implementation Definition */
void ECU_StateMachine(void);

/* Private-Public Func Implementation Definition */
FUNC(void, ECUStateManager)(void);

#endif /* ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PRIVATE_H_ */