#ifndef ECUSTATEMANAGER_INC_ECUSTATEMANAGER_GLOBAL_H_
#define ECUSTATEMANAGER_INC_ECUSTATEMANAGER_GLOBAL_H_

/**************External Driver Include****************/
/*
- Motor surucu entegresi kullanilyorsa #include "drv8353.h"
- Canbus entegresi kullaniliyorsa #include "mcp2515.h"
*/
/*****************************************************/

/********Component sinif extern tanimlamalari*********/
/*
- #include "PWMConfiguration_definition.h"
- extern dtPWMConfiguration PWMConfiguration;

- #include "AnalogConfiguration_definition.h"
- extern dtAnalogConfiguration AnalogConfiguration;
*/
/*****************************************************/

/***************External Software Layer***************/
/*
- Haberleşme Katmanı - Communication stack
#include "CommNewtork_definition.h"
#include "CommNetwork_Protocol.h"
extern dtCommNetwork CommNetwork;
extern dtProtocol    Protocol;
- Hata Yönetim Katmanı - ErrorLoggerDesc stack
...
...
...
*/

/*****************************************************/

#endif /* ECUSTATEMANAGER_INC_ECUSTATEMANAGER_GLOBAL_H_ */