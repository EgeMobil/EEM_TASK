/** 
 * @file MotorDriverDcmProxy_definition.h
 * @brief Definition of the Motor Driver DCM Proxy interface and error types.
 */

#ifndef MOTORDRIVERDCMPROXY_DEFINITION_H_
#define MOTORDRIVERDCMPROXY_DEFINITION_H_

/* ECU StateManager Global Include*/
#include "ECUStateManager_global.h"

/* Receiver Port Interface Definition Include */
#include "IMotorDriveError.h"

/* Sender Port Interface Definition Include */

/** 
 * @enum dtMdpReturn
 * @brief Enum representing the possible return values for MotorDriverDcmProxy operations.
 */
typedef enum
{
    MDP_ERR = 0,       /**< General error */
    MDP_EOK,           /**< No error, operation successful */
    MDP_UNKNOWN        /**< Unknown error */
} dtMdpReturn;

/** 
 * @enum dtPwmError
 * @brief Enum representing different PWM error types.
 */
typedef enum
{
    PWM_ERR_RFU1 = 0,  /**< Reserved for future use */
    PWM_ERR_RFU2,      /**< Reserved for future use */
    PWM_ERR_RFU3,      /**< Reserved for future use */
    PWM_ERR_RFU4,      /**< Reserved for future use */
    PWM_ERR_RFU5,      /**< Reserved for future use */
    PWM_ERR_RFU6,      /**< Reserved for future use */
    PWM_ERR_UNKNOWN = 0xFF /**< Unknown PWM error */
} dtPwmError;

/** 
 * @enum dtBdrError
 * @brief Enum representing different BDR error types.
 */
typedef enum
{
    BDR_ERR_RFU1 = 0,  /**< Reserved for future use */
    BDR_ERR_RFU2,      /**< Reserved for future use */
    BDR_ERR_RFU3,      /**< Reserved for future use */
    BDR_ERR_RFU4,      /**< Reserved for future use */
    BDR_ERR_RFU5,      /**< Reserved for future use */
    BDR_ERR_RFU6,      /**< Reserved for future use */
    BDR_ERR_UNKNOWN = 0xFF /**< Unknown BDR error */
} dtBdrError;

/** 
 * @enum dtIrqError
 * @brief Enum representing different IRQ error types.
 */
typedef enum
{
    IRQ_ERR_RFU1 = 0,  /**< Reserved for future use */
    IRQ_ERR_RFU2,      /**< Reserved for future use */
    IRQ_ERR_RFU3,      /**< Reserved for future use */
    IRQ_ERR_RFU4,      /**< Reserved for future use */
    IRQ_ERR_RFU5,      /**< Reserved for future use */
    IRQ_ERR_RFU6,      /**< Reserved for future use */
    IRQ_ERR_UNKNOWN = 0xFF /**< Unknown IRQ error */
} dtIrqError;

/** 
 * @enum dtSpeedError
 * @brief Enum representing different Speed error types.
 */
typedef enum
{
    SPEED_ERR_RFU1 = 0, /**< Reserved for future use */
    SPEED_ERR_RFU2,     /**< Reserved for future use */
    SPEED_ERR_RFU3,     /**< Reserved for future use */
    SPEED_ERR_RFU4,     /**< Reserved for future use */
    SPEED_ERR_RFU5,     /**< Reserved for future use */
    SPEED_ERR_RFU6,     /**< Reserved for future use */
    SPEED_ERR_UNKNOWN = 0xFF /**< Unknown Speed error */
} dtSpeedError;

/** 
 * @enum dtGdrError
 * @brief Enum representing different GDR error types.
 */
typedef enum
{
    GDR_ERR_RFU1 = 0,   /**< Reserved for future use */
    GDR_ERR_RFU2,       /**< Reserved for future use */
    GDR_ERR_RFU3,       /**< Reserved for future use */
    GDR_ERR_RFU4,       /**< Reserved for future use */
    GDR_ERR_RFU5,       /**< Reserved for future use */
    GDR_ERR_RFU6,       /**< Reserved for future use */
    GDR_ERR_UNKNOWN = 0xFF /**< Unknown GDR error */
} dtGdrError;

/** 
 * @typedef dtMotorDriverControlManager_MdpReturn
 * @brief Alias for dtMdpReturn to be used in the MotorDriverControlManager.
 */
typedef dtMdpReturn dtMotorDriverControlManager_MdpReturn;

/** 
 * @typedef dtMotorDriverControlManager_pwmError
 * @brief Alias for dtPwmError to be used in the MotorDriverControlManager.
 */
typedef dtPwmError dtMotorDriverControlManager_pwmError;

/** 
 * @typedef dtMotorDriverControlManager_bdrError
 * @brief Alias for dtBdrError to be used in the MotorDriverControlManager.
 */
typedef dtBdrError dtMotorDriverControlManager_bdrError;

/** 
 * @typedef dtMotorDriverControlManager_irqError
 * @brief Alias for dtIrqError to be used in the MotorDriverControlManager.
 */
typedef dtIrqError dtMotorDriverControlManager_irqError;

/** 
 * @typedef dtMotorDriverControlManager_speedError
 * @brief Alias for dtSpeedError to be used in the MotorDriverControlManager.
 */
typedef dtSpeedError dtMotorDriverControlManager_speedError;

/** 
 * @typedef dtMotorDriverControlManager_gdrError
 * @brief Alias for dtGdrError to be used in the MotorDriverControlManager.
 */
typedef dtGdrError dtMotorDriverControlManager_gdrError;

/** 
 * @typedef cmMotorDriveError
 * @brief Alias for the motor drive error interface.
 */
typedef cmMotorDriveError dtMotorDriverControlManager_motorDriveError;

/** 
 * @struct dtMotorDriverDcmProxy
 * @brief The Motor Driver DCM Proxy structure containing error states and function pointers.
 * 
 * This structure manages the motor driver error states and provides functions 
 * to set and get error states, as well as a string representation of the states.
 */
typedef struct 
{
    /* Interface Pointer */
    IMotorDriveError* IMotorDriveError; /**< Pointer to the motor drive error interface */

    /* Attributes */
    dtPwmError pwmErr;  /**< PWM error state */
    dtBdrError bdrErr;  /**< BDR error state */
    dtIrqError irqErr;  /**< IRQ error state */
    dtSpeedError speedErr; /**< Speed error state */
    dtGdrError gdrErr;  /**< GDR error state */

    /* Getter/Setter Function Pointers */
    dtPwmError (*getPwmError)(void); /**< Function pointer to get the PWM error */
    void (*setPwmError)(dtPwmError error); /**< Function pointer to set the PWM error */

    dtBdrError (*getBdrError)(void); /**< Function pointer to get the BDR error */
    void (*setBdrError)(dtBdrError error); /**< Function pointer to set the BDR error */

    dtIrqError (*getIrqError)(void); /**< Function pointer to get the IRQ error */
    void (*setIrqError)(dtIrqError error); /**< Function pointer to set the IRQ error */

    dtSpeedError (*getSpeedError)(void); /**< Function pointer to get the Speed error */
    void (*setSpeedError)(dtSpeedError error); /**< Function pointer to set the Speed error */

    dtGdrError (*getGdrError)(void); /**< Function pointer to get the GDR error */
    void (*setGdrError)(dtGdrError error); /**< Function pointer to set the GDR error */

    /* toString Function Pointer */
    char* (*toString)(void); /**< Function pointer to get a string representation of the errors */

} dtMotorDriverDcmProxy;

#endif /* MOTORDRIVERDCMPROXY_DEFINITION_H_ */
