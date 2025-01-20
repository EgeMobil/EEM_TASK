#ifndef PWMCONFIGURATION_DEFINITION_H_
#define PWMCONFIGURATION_DEFINITION_H_

/* ECU StateManager Global Include*/
#include "ECUStateManager_global.h"

/* Receiver Port Interface Definition Include */
#include "IPwmStep.h"
#include "ISpeedStatus.h"
#include "IBrakeStatus.h"
#include "IDirectionStatus.h"

/* Sender Port Interface Definition Include */
#include "IGPIOStatus.h"

/* Base Return Value Definition */
typedef enum
{
    PWMC_ERR = 0,
    PWMC_EOK,
    PWMC_UNKNOWN
}dtPWMReturn;

/* Compu Method Alias Type Definitions */
typedef dtPWMReturn dtPWMConfiguration_pwmReturn;

typedef cmPwmStep   dtPWMConfiguration_pwmStep;

typedef cmSpeedStatus dtPWMConfiguration_speedStatus;

typedef cmDirectionStatusType dtPWMConfiguration_directionStatusType;

typedef cmBrakeStatusType dtPWMConfiguration_brakeStatusType;

/* BaseClass Definition */
typedef struct 
{
    /* Interface Pointer */
    // Receiver Ports
    IPwmStep* IPwmStep;
    ISpeedStatus* ISpeedStatus;
    IBrakeStatus* IBrakeStatus;
    IDirectionStatus* IDirectionStatus;
    // Sender Ports
    IGPIOStatus* IGPIOStatus;

    /* Attributes */
    uint16_t frequency;
    uint16_t dutyCycle;

    dtPWMConfiguration_pwmStep stepA;
    dtPWMConfiguration_pwmStep stepB;
    dtPWMConfiguration_pwmStep stepC;

    dtPWMConfiguration_speedStatus speed;
    dtPWMConfiguration_directionStatusType direction;
    dtPWMConfiguration_brakeStatusType brake;
    
    /* Getter/Setter Function Pointers */
    void (*setFrequency)(uint16_t value);
    uint16_t (*getFrequency)(void);
    void (*setDutyCycle)(uint16_t value);
    uint16_t (*getDutyCycle)(void);

    void (*setStepA)(dtPWMConfiguration_pwmStep value);
    dtPWMConfiguration_pwmStep (*getStepA)(void);
    void (*setStepB)(dtPWMConfiguration_pwmStep value);
    dtPWMConfiguration_pwmStep (*getStepB)(void);
    void (*setStepC)(dtPWMConfiguration_pwmStep value);
    dtPWMConfiguration_pwmStep (*getStepC)(void);   

    void (*setSpeedStatus)(dtPWMConfiguration_speedStatus value);
    dtPWMConfiguration_speedStatus (*getSpeedStatus)(void);
    void (*setDirectionStatus)(dtPWMConfiguration_directionStatusType value);
    dtPWMConfiguration_directionStatusType (*getDirectionStatus)(void);
    void (*setBrakeStatus)(dtPWMConfiguration_brakeStatusType value);
    dtPWMConfiguration_brakeStatusType (*getBrakeStatus)(void);

    /* toString Function Pointer */
    const char* (*toString)(void);

    /* Functional Behaviours */
    void (*startTimer)(void);
    void (*stopTimer)(void);
    void (*setTimerFrequency)(uint16_t value);
    void (*setTimerDutyCycle)(uint16_t value);

}dtPWMConfiguration;


#endif /* PWMCONFIGURATION_DEFINITION_H_ */