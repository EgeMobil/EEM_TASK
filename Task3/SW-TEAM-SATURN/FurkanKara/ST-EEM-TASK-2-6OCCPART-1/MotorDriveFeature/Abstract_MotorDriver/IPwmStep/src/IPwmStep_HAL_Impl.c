
#include "IPwmStep.h"
#include "stm32g4xx_hal.h"

/* GPIO Pin Definitions */
#define PWM_STEP_STATE0_PORT GPIOB
#define PWM_STEP_STATE0_PIN  GPIO_PIN_15

#define PWM_STEP_STATE1_PORT GPIOA
#define PWM_STEP_STATE1_PIN  GPIO_PIN_9

#define PWM_STEP_STATE2_PORT GPIOB
#define PWM_STEP_STATE2_PIN  GPIO_PIN_14

/* TIM1 PWM Configuration */
extern 	TIM_HandleTypeDef htim1;  /**< TIM1 handle from CubeMX */
#define PWM_TIMER_INSTANCE    TIM1
#define PWM_TIMER_CHANNEL     TIM_CHANNEL_3  /**< TIM1 Channel 3 (PA10) */

/* Default Frequency and Duty Cycle */
#define DEFAULT_PWM_FREQUENCY  15000  /**< Default PWM frequency in Hz */
#define DEFAULT_DUTY_CYCLE     0    /**< Default duty cycle in % */

/* Variables to store frequency and duty cycle */
static uint32_t pwmFrequency = DEFAULT_PWM_FREQUENCY;
static uint8_t pwmDutyCycle = DEFAULT_DUTY_CYCLE;

/**
 * @brief Converts the given pwmStep value to a GPIO pin state.
 * @param pwmStep The pwm step value to convert.
 * @return GPIO_PIN_SET if HIGH, GPIO_PIN_RESET otherwise.
 */
static GPIO_PinState IPwmStep_ConvertToGPIOState(cmPwmStep pwmStep)
{
    return (pwmStep == PWMSTEP_PWMSTATUS_HIGH) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}

/**
 * @brief Writes the pwmStepA (STATE0) value to the corresponding GPIO pin.
 * @param pwmStepA The value to write.
 * @return Status of the operation.
 */
IPwmStep_StatusType IPwmStep_writePwmStepA_HAL(cmPwmStep pwmStepA)
{
    if (pwmStepA < PWMSTEP_PWMSTATUS_LOW || pwmStepA > PWMSTEP_PWMSTATUS_UNKNOWN)
    {
        return IPWMSTEP_NOT_OK;
    }

    HAL_GPIO_WritePin(PWM_STEP_STATE0_PORT, PWM_STEP_STATE0_PIN, IPwmStep_ConvertToGPIOState(pwmStepA));
    return IPWMSTEP_OK;
}

/**
 * @brief Writes the pwmStepB (STATE1) value to the corresponding GPIO pin.
 * @param pwmStepB The value to write.
 * @return Status of the operation.
 */
IPwmStep_StatusType IPwmStep_writePwmStepB_HAL(cmPwmStep pwmStepB)
{
    if (pwmStepB < PWMSTEP_PWMSTATUS_LOW || pwmStepB > PWMSTEP_PWMSTATUS_UNKNOWN)
    {
        return IPWMSTEP_NOT_OK;
    }

    HAL_GPIO_WritePin(PWM_STEP_STATE1_PORT, PWM_STEP_STATE1_PIN, IPwmStep_ConvertToGPIOState(pwmStepB));
    return IPWMSTEP_OK;
}

/**
 * @brief Writes the pwmStepC (STATE2) value to the corresponding GPIO pin.
 * @param pwmStepC The value to write.
 * @return Status of the operation.
 */
IPwmStep_StatusType IPwmStep_writePwmStepC_HAL(cmPwmStep pwmStepC)
{
    if (pwmStepC < PWMSTEP_PWMSTATUS_LOW || pwmStepC > PWMSTEP_PWMSTATUS_UNKNOWN)
    {
        return IPWMSTEP_NOT_OK;
    }

    HAL_GPIO_WritePin(PWM_STEP_STATE2_PORT, PWM_STEP_STATE2_PIN, IPwmStep_ConvertToGPIOState(pwmStepC));
    return IPWMSTEP_OK;
}

/**
 * @brief Starts the PWM timer on TIM1_CH3 (PA10).
 */
IPwmStep_StatusType IPwmStep_startTimer_HAL(void)
{
    if (HAL_TIM_PWM_Start(&htim1, PWM_TIMER_CHANNEL) != HAL_OK)
    {
        return IPWMSTEP_NOT_OK;
    }
    return IPWMSTEP_OK;
}

/**
 * @brief Stops the PWM timer on TIM1_CH3 (PA10).
 */
IPwmStep_StatusType IPwmStep_stopTimer_HAL(void)
{
    if (HAL_TIM_PWM_Stop(&htim1, PWM_TIMER_CHANNEL) != HAL_OK)
    {
        return IPWMSTEP_NOT_OK;
    }
    return IPWMSTEP_OK;
}

/**
 * @brief Sets the PWM frequency on TIM1_CH3.
 * @param frequency Desired frequency in Hz.
 * @return Status of the operation.
 */
IPwmStep_StatusType IPwmStep_setFrequency_HAL(uint32_t frequency)
{
    if (frequency == 0 || frequency > 100000)
    {
        return IPWMSTEP_NOT_OK;
    }

    /* TIM1 is on APB2, which runs at SYSTEM_CLOCK_FREQ (170MHz) */
    uint32_t timerClock = 170000000U;
    uint32_t prescaler = (timerClock / (frequency * 1000)) - 1;

    __HAL_TIM_SET_PRESCALER(&htim1, prescaler);
    __HAL_TIM_SET_AUTORELOAD(&htim1, 999);  /**< ARR fixed to 999 for 1000 steps */

    pwmFrequency = frequency;

    return IPWMSTEP_OK;
}

/**
 * @brief Sets the PWM duty cycle on TIM1_CH3.
 * @param dutyCycle Desired duty cycle in range (0-1000).
 * @return Status of the operation.
 */
IPwmStep_StatusType IPwmStep_setDutyCycle_HAL(uint16_t dutyCycle)
{
    if (dutyCycle > 1000)
    {
        return IPWMSTEP_NOT_OK;
    }

    /* CCR value determines duty cycle */
    uint32_t ccrValue = (999 * dutyCycle) / 1000;
    __HAL_TIM_SET_COMPARE(&htim1, PWM_TIMER_CHANNEL, ccrValue);

    pwmDutyCycle = dutyCycle;

    return IPWMSTEP_OK;
}

