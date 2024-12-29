#ifndef ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PUBLIC_H_
#define ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PUBLIC_H_

#include "ECUStateManager_definition.h"

/*********Public Variable Definition*****************/
extern dtECUStateManager_startUp  		systemStartUp;
extern dtECUStateManager_refreshState	REFRESH_STATE;
extern dtECUStateManager_processState   PROCESS_STATE;

/* Integration Process Execution Variables for Process */
extern dtECUStateManager_processExecutionState AnalogDataWrapper_processExecutionState;

extern dtECUStateManager_processExecutionState TxSignalAdapter_processExecutionState;
extern dtECUStateManager_processRunningCounter TxSignalAdapter_processRunningCounter;

/* Public Func Implementation Definition */
extern FUNC(void, ECUStateManager)(void);

#endif /* ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PUBLIC_H_ */