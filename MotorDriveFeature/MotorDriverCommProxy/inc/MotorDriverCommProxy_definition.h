/** 
 * @file MotorDriverCommProxy_definition.h
 * @brief Definitions for the Motor Driver Communication Proxy (MDCP).
 * 
 * This header file contains all the necessary definitions for the motor driver communication proxy, including 
 * the ECU (Electronic Control Unit) StateManager, receiver and sender port interfaces, and basic return values.
 */
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

/** 
 * @enum dtMdcpReturn
 * @brief Return values for MDCP functions.
 * 
 * This enum specifies the basic return values for MDCP functions.
 */
typedef enum
{
    MDCP_ERR = 0 , /**< Error state */
    MDCP_EOK , /**< Success state */
    MDCP_UNKNOWN /**< Unknown state */
}dtMdcpReturn;

/** 
 * @enum dtMdcpBrakeLamp
 * @brief Brake lamp status.
 * 
 * This enum indicates the status of the brake lamp.
 */
typedef enum
{
    MDCP_BRAKELAMP_OFF = 0, /**< Brake lamp off */
    MDCP_BRAKELAMP_ON = 1, /**< Brake lamp on */
    MDCP_BRAKELAMP_WARNING = 2, /**< Brake lamp warning */
    MDCP_BRAKELAMP_UNKNOWN = 3 /**< Brake lamp status unknown */
}dtMdcpBrakeLamp;

/** 
 * @enum dtMdcpDirectionLamp
 * @brief Direction lamp status.
 * 
 * This enum indicates the status of the direction lamp.
 */
typedef enum
{
    MDCP_DIRECTIONLAMP_OFF = 0, /**< Direction lamp off */
    MDCP_DIRECTIONLAMP_ON = 1, /**< Direction lamp on */
    MDCP_DIRECTIONLAMP_WARNING = 2, /**< Direction lamp warning */
    MDCP_DIRECTIONLAMP_UNKNOWN = 3 /**< Direction lamp status unknown */
}dtMdcpDirectionLamp;

/** 
 * @enum dtMdcpSpeedLamp
 * @brief Speed lamp status.
 * 
 * This enum indicates the status of the speed lamp.
 */
typedef enum
{
    MDCP_SPEEDLAMP_OFF = 0, /**< Speed lamp off */
    MDCP_SPEEDLAMP_LOW = 1, /**< Speed lamp low */
    MDCP_SPEEDLAMP_MID = 2, /**< Speed lamp medium */
    MDCP_SPEEDLAMP_HIGH = 3, /**< Speed lamp high */
    MDCP_SPEEDLAMP_VERYHIGH = 4, /**< Speed lamp very high */
    MDCP_SPEEDLAMP_WARNING, /**< Speed lamp warning */
    MDCP_SPEEDLAMP_UNKNOWN = 0xF /**< Speed lamp status unknown */
}dtMdcpSpeedLamp;

/** 
 * @typedef dtMotorDriverCommProxy_mdcpReturn
 * @brief Alias for MDCP return type.
 * 
 * This alias is defined for the dtMdcpReturn type, to be used in MDCP functions.
 */
typedef dtMdcpReturn            dtMotorDriverCommProxy_mdcpReturn;

/** 
 * @typedef dtMotorDriverCommProxy_brakeLamp
 * @brief Alias for MDCP brake lamp type.
 */
typedef dtMdcpBrakeLamp         dtMotorDriverCommProxy_brakeLamp;

/** 
 * @typedef dtMotorDriverCommProxy_directionLamp
 * @brief Alias for MDCP direction lamp type.
 */
typedef dtMdcpDirectionLamp     dtMotorDriverCommProxy_directionLamp;

/** 
 * @typedef dtMotorDriverCommProxy_speedLamp
 * @brief Alias for MDCP speed lamp type.
 */
typedef dtMdcpSpeedLamp         dtMotorDriverCommProxy_speedLamp;

/** 
 * @typedef dtMotorDriverCommProxy_indicatorBdrStatus
 * @brief Alias for MDCP indicator brake and direction status.
 */
typedef cmIndicatorBdrStatus       dtMotorDriverCommProxy_indicatorBdrStatus;

/** 
 * @typedef dtMotorDriverCommProxy_indicatorSpeedStatus
 * @brief Alias for MDCP indicator speed status.
 */
typedef cmIndicatorSpeedStatus     dtMotorDriverCommProxy_indicatorSpeedStatus;

/** 
 * @typedef dtMotorDriverCommProxy_HALLWheelSpeed
 * @brief Alias for MDCP Hall sensor wheel speed status.
 */
typedef cmHALLWheelSpeed           dtMotorDriverCommProxy_HALLWheelSpeed;

/** 
 * @typedef dtMotorDriverCommProxy_indicator
 * @brief Alias for MDCP indicator status.
 */
typedef cmIndicator                dtMotorDriverCommProxy_indicator;

/** 
 * @typedef dtMotorDriverCommProxy_wheelSpeed
 * @brief Alias for MDCP wheel speed.
 */
typedef cmWheelSpeed               dtMotorDriverCommProxy_wheelSpeed;

/** 
 * @struct dtMotorDriverCommProxy
 * @brief Structure for the MotorDriverCommProxy class.
 * 
 * MotorDriverCommProxy is a proxy used for communication with the motor driver and manages the motor driver's data 
 * through various getter and setter functions.
 */
typedef struct 
{
    /* Interface Pointer */
    IIndicatorBdrStatus* IIndicatorBdrStatus; /**< Indicator brake and direction interface */
    IIndicatorSpeedStatus* IIndicatorSpeedStatus; /**< Indicator speed interface */
    IHALLWheelSpeed* IHALLWheelSpeed; /**< Hall sensor wheel speed interface */
    IIndicator* IIndicator; /**< Indicator interface */
    IWheelSpeed* IWheelSpeed; /**< Wheel speed interface */

    /* Attributes */
    dtMotorDriverCommProxy_indicatorBdrStatus    iBdr; /**< Indicator brake and direction status */
    dtMotorDriverCommProxy_indicatorSpeedStatus  iSpeed; /**< Indicator speed status */
    dtMotorDriverCommProxy_HALLWheelSpeed        hWheelSpeed; /**< Hall sensor wheel speed */
    dtMotorDriverCommProxy_indicator             indicator; /**< Indicator status */
    dtMotorDriverCommProxy_wheelSpeed            wheelSpeed; /**< Wheel speed */

    /* Getter/Setter Function Pointers */
    dtMotorDriverCommProxy_indicatorBdrStatus (*getIBdr)(void); /**< Getter function for IBdr */
    void (*setIBdr)(dtMotorDriverCommProxy_indicatorBdrStatus status); /**< Setter function for IBdr */

    dtMotorDriverCommProxy_indicatorSpeedStatus (*getISpeed)(void); /**< Getter function for ISpeed */
    void (*setISpeed)(dtMotorDriverCommProxy_indicatorSpeedStatus status); /**< Setter function for ISpeed */

    dtMotorDriverCommProxy_HALLWheelSpeed (*getHWheelSpeed)(void); /**< Getter function for HWheelSpeed */
    void (*setHWheelSpeed)(dtMotorDriverCommProxy_HALLWheelSpeed speed); /**< Setter function for HWheelSpeed */

    dtMotorDriverCommProxy_indicator (*getIndicator)(void); /**< Getter function for Indicator */
    void (*setIndicator)(dtMotorDriverCommProxy_indicator indicator); /**< Setter function for Indicator */

    dtMotorDriverCommProxy_wheelSpeed (*getWheelSpeed)(void); /**< Getter function for WheelSpeed */
    void (*setWheelSpeed)(dtMotorDriverCommProxy_wheelSpeed speed); /**< Setter function for WheelSpeed */

    /* toString Function Pointer */
    char* (*toString)(void); /**< Function that converts MotorDriverCommProxy instance to string */

    /* Functional Behaviours */
    // Functional methods can be added here.

}dtMotorDriverCommProxy;

#endif /* MOTORDRIVERCOMMPROXY_DEFINITION_H_ */
