#ifndef IPWMSTEP_H_
#define IPWMSTEP_H_

#include "Abstract_MotorDriver.h"

/**
 * @brief Status type for the IPwmStep interface.
 */
typedef enum
{
    IPWMSTEP_OK = 0,     /**< Operation completed successfully. */
    IPWMSTEP_NOT_OK      /**< Operation failed. */
} IPwmStep_StatusType;

/**
 * @brief Structure defining the function pointers for IPwmStep interface.
 */
typedef struct
{
    /**
     * @brief Write the pwmStepA value.
     * @param pwmStepA Value to write.
     * @return Status of the operation.
     */
    IPwmStep_StatusType (*writePwmStepA)(cmPwmStep pwmStepA);

    /**
     * @brief Read the current pwmStepA value.
     * @return Current pwmStepA value.
     */
    cmPwmStep (*readPwmStepA)(void);

    /**
     * @brief Write the pwmStepB value.
     * @param pwmStepB Value to write.
     * @return Status of the operation.
     */
    IPwmStep_StatusType (*writePwmStepB)(cmPwmStep pwmStepB);

    /**
     * @brief Read the current pwmStepB value.
     * @return Current pwmStepB value.
     */
    cmPwmStep (*readPwmStepB)(void);

    /**
     * @brief Write the pwmStepC value.
     * @param pwmStepC Value to write.
     * @return Status of the operation.
     */
    IPwmStep_StatusType (*writePwmStepC)(cmPwmStep pwmStepC);

    /**
     * @brief Read the current pwmStepC value.
     * @return Current pwmStepC value.
     */
    cmPwmStep (*readPwmStepC)(void);

    /**
     * @brief Start the PWM timer.
     * @return Status of the operation.
     */
    IPwmStep_StatusType (*startTimer)(void);

    /**
     * @brief Stop the PWM timer.
     * @return Status of the operation.
     */
    IPwmStep_StatusType (*stopTimer)(void);

    /**
     * @brief Set the PWM frequency.
     * @param frequency Desired frequency in Hz.
     * @return Status of the operation.
     */
    IPwmStep_StatusType (*setFrequency)(uint32_t frequency);

    /**
     * @brief Set the PWM duty cycle.
     * @param dutyCycle Desired duty cycle in range 0-1000.
     * @return Status of the operation.
     */
    IPwmStep_StatusType (*setDutyCycle)(uint16_t dutyCycle);

} IPwmStep;

/**
 * @brief Global instance of the IPwmStep interface.
 */
extern IPwmStep PwmStepInterface;

/* Function prototypes */
IPwmStep_StatusType IPwmStep_startTimer_Impl(void);
IPwmStep_StatusType IPwmStep_stopTimer_Impl(void);
IPwmStep_StatusType IPwmStep_setFrequency_Impl(uint32_t frequency);
IPwmStep_StatusType IPwmStep_setDutyCycle_Impl(uint16_t dutyCycle);
/* Prototypes for pwmStepA */
IPwmStep_StatusType IPwmStep_writePwmStepA_Impl(cmPwmStep pwmStepA);
cmPwmStep IPwmStep_readPwmStepA_Impl(void);
/* Prototypes for pwmStepB */
IPwmStep_StatusType IPwmStep_writePwmStepB_Impl(cmPwmStep pwmStepB);
cmPwmStep IPwmStep_readPwmStepB_Impl(void);
/* Prototypes for pwmStepC */
IPwmStep_StatusType IPwmStep_writePwmStepC_Impl(cmPwmStep pwmStepC);
cmPwmStep IPwmStep_readPwmStepC_Impl(void);

#ifndef STM32G431xx
/* HAL Prototypes */
IPwmStep_StatusType IPwmStep_writePwmStepA_HAL(cmPwmStep pwmStepA);
IPwmStep_StatusType IPwmStep_writePwmStepB_HAL(cmPwmStep pwmStepB);
IPwmStep_StatusType IPwmStep_writePwmStepC_HAL(cmPwmStep pwmStepC);
IPwmStep_StatusType IPwmStep_startTimer_HAL(void);
IPwmStep_StatusType IPwmStep_stopTimer_HAL(void);
IPwmStep_StatusType IPwmStep_setFrequency_HAL(uint32_t frequency);
IPwmStep_StatusType IPwmStep_setDutyCycle_HAL(uint16_t dutyCycle);
#endif

#endif /* IPWMSTEP_H_ */
