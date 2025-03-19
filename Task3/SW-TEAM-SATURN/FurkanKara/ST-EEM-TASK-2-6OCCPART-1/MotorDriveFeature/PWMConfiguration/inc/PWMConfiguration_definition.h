#ifndef PWMCONFIGURATION_DEFINITION_H_
#define PWMCONFIGURATION_DEFINITION_H_

/** 
 * @file PWMConfiguration_Definition.h
 * @brief Definition of PWM Configuration for the ECU with relevant interfaces and functionality.
 */

/* ECU StateManager Global Include*/
#include "ECUStateManager_global.h"

/* Receiver Port Interface Definition Include */
#include "IPwmStep.h"
#include "ISpeedStatus.h"
#include "IBrakeStatus.h"
#include "IDirectionStatus.h"

/* Sender Port Interface Definition Include */
#include "IGPIOStatus.h"

/** 
 * @enum dtPWMReturn
 * @brief Return values for PWM configuration functions.
 */
typedef enum
{
    PWMC_ERR = 0, /**< Error condition */
    PWMC_EOK,     /**< Success */
    PWMC_UNKNOWN  /**< Unknown return status */
} dtPWMReturn;

/** 
 * @brief Alias for PWM return type.
 */
typedef dtPWMReturn dtPWMConfiguration_pwmReturn;

/** 
 * @brief Alias for PWM step type.
 */
typedef cmPwmStep   dtPWMConfiguration_pwmStep;

/** 
 * @brief Alias for speed status type.
 */
typedef cmSpeedStatus dtPWMConfiguration_speedStatus;

/** 
 * @brief Alias for direction status type.
 */
typedef cmDirectionStatusType dtPWMConfiguration_directionStatusType;

/** 
 * @brief Alias for brake status type.
 */
typedef cmBrakeStatusType dtPWMConfiguration_brakeStatusType;

/** 
 * @struct dtPWMConfiguration
 * @brief Configuration structure for PWM, containing ports, attributes, and behaviors.
 */
typedef struct 
{
    /** @name Interface Pointers */
    /** Receiver Ports */
    IPwmStep* IPwmStep;           /**< Interface for PWM step operations */
    ISpeedStatus* ISpeedStatus;   /**< Interface for speed status */
    IBrakeStatus* IBrakeStatus;   /**< Interface for brake status */
    IDirectionStatus* IDirectionStatus; /**< Interface for direction status */
    
    /** Sender Ports */
    IGPIOStatus* IGPIOStatus;     /**< Interface for GPIO status */

    /** @name Attributes */
    uint16_t frequency;           /**< PWM frequency in Hz */
    uint16_t dutyCycle;           /**< PWM duty cycle as percentage */
    
    dtPWMConfiguration_pwmStep stepA; /**< PWM step A configuration */
    dtPWMConfiguration_pwmStep stepB; /**< PWM step B configuration */
    dtPWMConfiguration_pwmStep stepC; /**< PWM step C configuration */
    
    dtPWMConfiguration_speedStatus speed; /**< Speed status configuration */
    dtPWMConfiguration_directionStatusType direction; /**< Direction status configuration */
    dtPWMConfiguration_brakeStatusType brake; /**< Brake status configuration */

    /** @name Getter/Setter Function Pointers */
    void (*setFrequency)(uint16_t value); /**< Set the frequency of PWM */
    uint16_t (*getFrequency)(void); /**< Get the current frequency of PWM */
    void (*setDutyCycle)(uint16_t value); /**< Set the duty cycle of PWM */
    uint16_t (*getDutyCycle)(void); /**< Get the current duty cycle of PWM */
    
    void (*setStepA)(dtPWMConfiguration_pwmStep value); /**< Set step A configuration */
    dtPWMConfiguration_pwmStep (*getStepA)(void); /**< Get step A configuration */
    void (*setStepB)(dtPWMConfiguration_pwmStep value); /**< Set step B configuration */
    dtPWMConfiguration_pwmStep (*getStepB)(void); /**< Get step B configuration */
    void (*setStepC)(dtPWMConfiguration_pwmStep value); /**< Set step C configuration */
    dtPWMConfiguration_pwmStep (*getStepC)(void); /**< Get step C configuration */
    
    void (*setSpeedStatus)(dtPWMConfiguration_speedStatus value); /**< Set speed status */
    dtPWMConfiguration_speedStatus (*getSpeedStatus)(void); /**< Get speed status */
    void (*setDirectionStatus)(dtPWMConfiguration_directionStatusType value); /**< Set direction status */
    dtPWMConfiguration_directionStatusType (*getDirectionStatus)(void); /**< Get direction status */
    void (*setBrakeStatus)(dtPWMConfiguration_brakeStatusType value); /**< Set brake status */
    dtPWMConfiguration_brakeStatusType (*getBrakeStatus)(void); /**< Get brake status */

    /** @name toString Function Pointer */
    const char* (*toString)(void); /**< Get string representation of PWM configuration */

    /** @name Functional Behaviors */
    void (*startTimer)(void); /**< Start the PWM timer */
    void (*stopTimer)(void); /**< Stop the PWM timer */
    void (*setTimerFrequency)(uint16_t value); /**< Set the frequency for the timer */
    void (*setTimerDutyCycle)(uint16_t value); /**< Set the duty cycle for the timer */

} dtPWMConfiguration;

#endif /* PWMCONFIGURATION_DEFINITION_H_ */
