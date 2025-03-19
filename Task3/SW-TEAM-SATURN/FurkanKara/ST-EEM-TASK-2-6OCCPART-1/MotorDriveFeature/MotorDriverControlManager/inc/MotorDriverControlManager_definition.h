/** 
 * @file MotorDriverControlManager_definition.h
 * @brief Defines the structure and types for the Motor Driver Control Manager, including interfaces and attributes.
 */

#ifndef MOTORDRIVERCONTROLMANAGER_DEFINITION_H_
#define MOTORDRIVERCONTROLMANAGER_DEFINITION_H_

/* ECU StateManager Global Include */
#include "ECUStateManager_global.h"

/* Receiver Port Interface Definition Include */
#include "ISpeed.h"
#include "IBdr.h"

/* Sender Port Interface Definition Include */
#include "IRawSpeed.h"
#include "IBrakeAndDirection.h"

/* Base Return Value Definition */
typedef enum
{
    MDC_ERR = 0,  /**< Error state */
    MDC_EOK,      /**< Success state */
    MDC_UNKNOWN   /**< Unknown error state */
} dtMdcReturn;

/** 
 * @brief Type alias for method return values in MotorDriverControlManager.
 */
typedef dtMdcReturn dtMotorDriverControlManager_dtMdcReturn;

/** 
 * @brief Type alias for speed-related data.
 */
typedef cmSpeed dtMotorDriverControlManager_Speed;

/** 
 * @brief Type alias for brake and direction-related data.
 */
typedef cmBdr dtMotorDriverControlManager_Bdr;

/** 
 * @brief Type alias for raw speed status data.
 */
typedef cmRawSpeedStatus dtMotorDriverControlManager_RawSpeedStatus;

/** 
 * @brief Type alias for brake status data.
 */
typedef cmBrakeStatus dtMotorDriverControlManager_BrakeStatus;

/** 
 * @brief Type alias for direction status data.
 */
typedef cmDirectionStatus dtMotorDriverControlManager_DirectionStatus;

/** 
 * @brief Structure definition for the MotorDriverControlManager class.
 * 
 * This structure defines the attributes and function pointers for accessing and controlling motor
 * speed, brake and direction states, as well as the related interfaces.
 */
typedef struct 
{
    /* Interface Pointers */
    ISpeed* ISpeed;                    /**< Interface for speed control */
    IBdr* IBdr;                         /**< Interface for brake and direction control */
    IRawSpeed* IRawSpeed;               /**< Interface for raw speed status */
    IBrakeAndDirection* IBrakeAndDirection; /**< Interface for brake and direction status */

    /* Attributes */
    dtMotorDriverControlManager_Speed           speed;          /**< Motor speed state */
    dtMotorDriverControlManager_Bdr             bdr;            /**< Brake and direction state */
    dtMotorDriverControlManager_RawSpeedStatus  rawSpeedStatus; /**< Raw speed status */
    dtMotorDriverControlManager_BrakeStatus     brakeStatus;    /**< Brake status */
    dtMotorDriverControlManager_DirectionStatus directionStatus; /**< Direction status */

    /* Getter/Setter Function Pointers */
    dtMotorDriverControlManager_Speed (*getSpeed)(void);          /**< Getter for speed */
    void (*setSpeed)(dtMotorDriverControlManager_Speed speed);    /**< Setter for speed */

    dtMotorDriverControlManager_Bdr (*getBdr)(void);              /**< Getter for brake and direction */
    void (*setBdr)(dtMotorDriverControlManager_Bdr bdr);           /**< Setter for brake and direction */

    dtMotorDriverControlManager_RawSpeedStatus (*getRawSpeedStatus)(void); /**< Getter for raw speed status */
    void (*setRawSpeedStatus)(dtMotorDriverControlManager_RawSpeedStatus status); /**< Setter for raw speed status */

    dtMotorDriverControlManager_BrakeStatus (*getBrakeStatus)(void); /**< Getter for brake status */
    void (*setBrakeStatus)(dtMotorDriverControlManager_BrakeStatus status); /**< Setter for brake status */

    dtMotorDriverControlManager_DirectionStatus (*getDirectionStatus)(void); /**< Getter for direction status */
    void (*setDirectionStatus)(dtMotorDriverControlManager_DirectionStatus status); /**< Setter for direction status */

    /* toString Function Pointer */
    char* (*toString)(void); /**< Function to convert the structure to a string representation */

    /* Functional Behaviours - Additional methods can be added for functionality */
} dtMotorDriverControlManager;

#endif /* MOTORDRIVERCONTROLMANAGER_DEFINITION_H_ */
