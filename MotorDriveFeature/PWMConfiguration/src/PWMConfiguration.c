#include "PWMConfiguration_private.h"

/* Instance definition */
static dtPWMConfiguration instance;

/* Getter Setter Implementation */

void setFrequency_Impl(uint16_t value)
{
    instance.frequency = value;
}

uint16_t getFrequency_Impl(void)
{
    return instance.frequency;
}

void setDutyCycle_Impl(uint16_t value)
{
    instance.dutyCycle = value;
}

uint16_t getDutyCycle_Impl(void)
{
    return instance.dutyCycle;
}

void setSpeedStatus_Impl(dtPWMConfiguration_speedStatus value)
{
    instance.speed = value;
}

dtPWMConfiguration_speedStatus getSpeedStatus_Impl(void)
{
    return instance.speed;
}

void setDirectionStatus_Impl(dtPWMConfiguration_directionStatusType value)
{
    instance.direction = value;
}

dtPWMConfiguration_directionStatusType getDirectionStatus_Impl(void)
{
    return instance.direction;
}

void setBrakeStatus_Impl(dtPWMConfiguration_brakeStatusType value)
{
    instance.brake = value;
}

dtPWMConfiguration_brakeStatusType getBrakeStatus_Impl(void)
{
    return instance.brake;
}

void setStepA_Impl(dtPWMConfiguration_pwmStep value)
{
    instance.stepA = value;
}

dtPWMConfiguration_pwmStep getStepA_Impl(void)
{
    return instance.stepA;
}

void setStepB_Impl(dtPWMConfiguration_pwmStep value)
{
    instance.stepB = value;
}

dtPWMConfiguration_pwmStep getStepB_Impl(void)
{
    return instance.stepB;
}

void setStepC_Impl(dtPWMConfiguration_pwmStep value)
{
    instance.stepC = value;
}

dtPWMConfiguration_pwmStep getStepC_Impl(void)
{
    return instance.stepC;
}


/* toString() Implementation */
const char* toString_Impl(void)
{
    static char buffer[512];
    snprintf(buffer, sizeof(buffer),
             "[PWMConfiguration]: Frequency: %-5u Hz, DutyCycle: %-3u%%, Speed: %-5d, Direction: %-5d, Brake: %-5d, "
             "StepA :%-5u "
             "StepB :%-5u "
             "StepC :%-5u ",
             instance.frequency,
             instance.dutyCycle,
             instance.speed,
             instance.direction,
             instance.brake,
             instance.stepA,
             instance.stepB,
             instance.stepC);
    return buffer;
}


/* Constructor Implementation */

void PWMConfiguration_CTOR(void)
{
    /* Interface Assignment */
    instance.IBrakeStatus = &BrakeStatusInterface;
    instance.IDirectionStatus = &DirectionStatusInterface;
    instance.IGPIOStatus = &GPIOStatusInterface;
    instance.IPwmStep = &PwmStepInterface;
    instance.ISpeedStatus = &SpeedStatusInterface;

    /* Existing Assignments */
    instance.setFrequency = setFrequency_Impl;
    instance.getFrequency = getFrequency_Impl;
    instance.setDutyCycle = setDutyCycle_Impl;
    instance.getDutyCycle = getDutyCycle_Impl;

    instance.setSpeedStatus = setSpeedStatus_Impl;
    instance.getSpeedStatus = getSpeedStatus_Impl;
    instance.setDirectionStatus = setDirectionStatus_Impl;
    instance.getDirectionStatus = getDirectionStatus_Impl;
    instance.setBrakeStatus = setBrakeStatus_Impl;
    instance.getBrakeStatus = getBrakeStatus_Impl;

    instance.setStepA = setStepA_Impl;
    instance.getStepA = getStepA_Impl;
    instance.setStepB = setStepB_Impl;
    instance.getStepB = getStepB_Impl;
    instance.setStepC = setStepC_Impl;
    instance.getStepC = getStepC_Impl;

    instance.toString = toString_Impl;

    /* Functional Behaviour Assignments */
    instance.startTimer = startTimer_Impl;
    instance.stopTimer = stopTimer_Impl;
    instance.setTimerFrequency = setTimerFrequency_Impl;
    instance.setTimerDutyCycle = setTimerDutyCycle_Impl;
}


/* Singelton Instance Getter */
dtPWMConfiguration* PWMConfiguration_GetInstance(void)
{
    return &instance;
}


/* Functional Behaviour Implementation */

void startTimer_Impl(void)
{
    // Timer başlatma işlemi burada tanımlanır.
    // Örneğin bir donanım zamanlayıcısını etkinleştirme kodu:
    printf("Timer started.\n");
}

void stopTimer_Impl(void)
{
    // Timer durdurma işlemi burada tanımlanır.
    // Örneğin bir donanım zamanlayıcısını devre dışı bırakma kodu:
    printf("Timer stopped.\n");
}

void setTimerFrequency_Impl(uint16_t value)
{
    // Frekans değeri ayarlanır
    instance.frequency = value;
    printf("Frequency set to %u.\n", value);
}

void setTimerDutyCycle_Impl(uint16_t value)
{
    // Duty cycle değeri ayarlanır
    instance.dutyCycle = value;
    printf("Duty cycle set to %u.\n", value);
}