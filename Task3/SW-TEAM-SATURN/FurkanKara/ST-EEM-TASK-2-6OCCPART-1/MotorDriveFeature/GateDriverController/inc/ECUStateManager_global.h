#ifndef ECUSTATEMANAGER_INC_ECUSTATEMANAGER_GLOBAL_H_
#define ECUSTATEMANAGER_INC_ECUSTATEMANAGER_GLOBAL_H_

/* MCU BsW - Low level layer 
-#include "stm32g4xx.h"
*/
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"

#define FUNC(returnType, functionName) returnType functionName

/* Monotony Type Definition */
/**
 * @brief Defines the monotony type for constraints.
 * - MONOTONY_NONE: No monotony constraint.
 * - MONOTONY_INCREASING: Values must increase.
 * - MONOTONY_DECREASING: Values must decrease.
 */
typedef enum
{
    MONOTONY_NONE,          /**< No monotony constraint. */
    MONOTONY_INCREASING,    /**< Values must increase monotonically. */
    MONOTONY_DECREASING     /**< Values must decrease monotonically. */
} MonotonyType;

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