#ifndef ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PUBLIC_H_
#define ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PUBLIC_H_

#include "ECUStateManager_definition.h"

/*********Public Variable Definition*****************/
extern dtECUStateManager_startUp  		systemStartUp;
extern dtECUStateManager_refreshState	REFRESH_STATE;
extern dtECUStateManager_processState   PROCESS_STATE;

/* Public Func Implementation Definition */
extern void ECUStateManager(void);

#endif /* ECUSTATEMANAGER_INC_ECUSTATEMANAGER_PUBLIC_H_ */