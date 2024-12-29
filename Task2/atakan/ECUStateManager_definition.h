#ifndef ECUSTATEMANAGER_INC_ECUSTATEMANAGER_DEFINITION_H_
#define ECUSTATEMANAGER_INC_ECUSTATEMANAGER_DEFINITION_H_

/* MCU BsW - Low level layer 
-#include "stm32g4xx.h"
*/
#include "stdio.h"
#include "stdint.h"

#define FUNC(returnType, functionName) returnType functionName

typedef enum
{
	ECUSTATE_UNKNOWN = 0,
	ECUSTATE_INIT	 ,
	ECUSTATE_ROUTINE ,
	ECUSTATE_PROCESS ,
	ECUSTATE_SUSPEND ,
	ECUSTATE_DEFAULT
}dtEcuState;

typedef dtEcuState dtECUStateManager_ecuState;

typedef enum
{
	STARTUP_UNKNOWN = 0,
	STARTUP_PRE_INIT  ,
	STARTUP_INIT	  ,
	STARTUP_POST_INIT ,
}dtStartUp;

typedef dtStartUp dtECUStateManager_startUp;

typedef enum
{
	REFRESHSTATE_UNKNOWN 			 = 0,
	REFRESHSTATE_ANALOGREAD 			,
	REFRESHSTATE_COMMUNICATION  		,
	REFRESHSTATE_GATEDRIVER_FAULTREAD	,
	REFRESHSTATE_RFU01			        ,
	REFRESHSTATE_RFU02			        ,
	REFRESHSTATE_SUSPEND			    ,
	REFRESHSTATE_DEFAULT			    ,
}dtRefreshState;

typedef dtRefreshState dtECUStateManager_refreshState;

typedef enum
{
    PROCESSSTATE_UNKNOWN           = 0 ,
    PROCESSSTATE_ANALOGDATAWRAPPER     ,
    PROCESSSTATE_TXSIGNALADAPTER       ,
    PROCESSSTATE_SUSPEND		       ,
	PROCESSSTATE_DEFAULT		       ,
}dtProcessState;

typedef dtProcessState dtECUStateManager_processState;

typedef enum {
    PROCESS_EXECUTION_UNKNOWN,
    PROCESS_EXECUTION_START,   
    PROCESS_EXECUTION_RUNNING, 
    PROCESS_EXECUTION_FINISHED 
}dtProcessExecutionState;

typedef dtProcessExecutionState dtECUStateManager_processExecutionState;

typedef uint32_t dtECUStateManager_processRunningCounter;

#define TxSignalAdapter_PROCESS_RUNNING_DURATION (dtECUStateManager_processRunningCounter)(5U)


#endif /* ECUSTATEMANAGER_INC_ECUSTATEMANAGER_DEFINITION_H_ */