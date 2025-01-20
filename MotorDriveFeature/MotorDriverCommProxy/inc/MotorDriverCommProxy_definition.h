#ifndef MOTORDRIVERCOMMPROXY_DEFINITION_H_
#define MOTORDRIVERCOMMPROXY_DEFINITION_H_

/* ECU StateManager Global Include*/
#include "ECUStateManager_global.h"

/* Receiver Port Interface Definition Include */
#include "IIndicatorBdrStatus.h"
#include "IIndicatorSpeedStatus.h"
#include "IHALLWheelSpeed.h"

/* Sender Port Interface Definition Include */
#include "IIndicator.h"
#include "IWheelSpeed.h"

/* Base Return Value Definition */
typedef enum
{
    MDCP_ERR = 0 ,
    MDCP_EOK ,
    MDCP_UNKNOWN
}dtMdcpReturn;

typedef enum
{
    MDCP_BRAKELAMP_OFF = 0,
    MDCP_BRAKELAMP_ON = 1,
    MDCP_BRAKELAMP_WARNING = 2,
    MDCP_BRAKELAMP_UNKNOWN = 3
}dtMdcpBrakeLamp;

typedef enum
{
    MDCP_DIRECTIONLAMP_OFF = 0,
    MDCP_DIRECTIONLAMP_ON = 1,
    MDCP_DIRECTIONLAMP_WARNING = 2,
    MDCP_DIRECTIONLAMP_UNKNOWN = 3
}dtMdcpDirectionLamp;

typedef enum
{
    MDCP_SPEEDLAMP_OFF = 0,
    MDCP_SPEEDLAMP_LOW = 1,
    MDCP_SPEEDLAMP_MID = 2,
    MDCP_SPEEDLAMP_HIGH = 3,
    MDCP_SPEEDLAMP_VERYHIGH = 4,
    MDCP_SPEEDLAMP_WARNING,
    MDCP_SPEEDLAMP_UNKNOWN = 0xF
}dtMdcpSpeedLamp;

/* Compu Method Alias Type Definitions */
typedef dtMdcpReturn            dtMotorDriverCommProxy_mdcpReturn;
typedef dtMdcpBrakeLamp         dtMotorDriverCommProxy_brakeLamp;
typedef dtMdcpDirectionLamp     dtMotorDriverCommProxy_directionLamp;
typedef dtMdcpSpeedLamp         dtMotorDriverCommProxy_speedLamp;


typedef cmIndicatorBdrStatus       dtMotorDriverCommProxy_indicatorBdrStatus;
typedef cmIndicatorSpeedStatus     dtMotorDriverCommProxy_indicatorSpeedStatus;
typedef cmHALLWheelSpeed           dtMotorDriverCommProxy_HALLWheelSpeed;
typedef cmIndicator                dtMotorDriverCommProxy_indicator;
typedef cmWheelSpeed               dtMotorDriverCommProxy_wheelSpeed;

/* BaseClass Definition */
typedef struct 
{
    /* Interface Pointer */
    IIndicatorBdrStatus* IIndicatorBdrStatus;
    IIndicatorSpeedStatus* IIndicatorSpeedStatus;
    IHALLWheelSpeed* IHALLWheelSpeed;
    IIndicator* IIndicator;
    IWheelSpeed* IWheelSpeed;

    /* Attributes */
    dtMotorDriverCommProxy_indicatorBdrStatus    iBdr;
    dtMotorDriverCommProxy_indicatorSpeedStatus  iSpeed;
    dtMotorDriverCommProxy_HALLWheelSpeed        hWheelSpeed;
    dtMotorDriverCommProxy_indicator             indicator;
    dtMotorDriverCommProxy_wheelSpeed            wheelSpeed;

    /* Getter/Setter Function Pointers */
    dtMotorDriverCommProxy_indicatorBdrStatus (*getIBdr)(void);
    void (*setIBdr)(dtMotorDriverCommProxy_indicatorBdrStatus status);

    dtMotorDriverCommProxy_indicatorSpeedStatus (*getISpeed)(void);
    void (*setISpeed)(dtMotorDriverCommProxy_indicatorSpeedStatus status);

    dtMotorDriverCommProxy_HALLWheelSpeed (*getHWheelSpeed)(void);
    void (*setHWheelSpeed)(dtMotorDriverCommProxy_HALLWheelSpeed speed);

    dtMotorDriverCommProxy_indicator (*getIndicator)(void);
    void (*setIndicator)(dtMotorDriverCommProxy_indicator indicator);

    dtMotorDriverCommProxy_wheelSpeed (*getWheelSpeed)(void);
    void (*setWheelSpeed)(dtMotorDriverCommProxy_wheelSpeed speed);

    /* toString Function Pointer */
    char* (*toString)(void);

    /* Functional Behaviours */

}dtMotorDriverCommProxy;


#endif /* MOTORDRIVERCOMMPROXY_DEFINITION_H_ */