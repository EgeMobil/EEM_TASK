#include "ITimerInterruptStatus.h"
#include "stm32g4xx_hal.h"

/* TIM2 Instance Definition */
extern TIM_HandleTypeDef htim2;

/* System Clock Frequency (in Hz) */
#define SYSTEM_CLOCK_FREQ 170000000U  /**< System clock frequency: 170MHz */

/* APB1 Timer Clock Calculation:
 * TIM2 is located on APB1, which runs at SYSTEM_CLOCK_FREQ / 2 = 85MHz.
 * The timer clock (TIMxCLK) is derived as follows:
 *
 *   APB1 Timer Clock = SYSTEM_CLOCK_FREQ / 2 = 85 MHz
 *
 * To achieve a 1ms interrupt, we need:
 *
 *   Timer Period (1ms) = 1000 Hz Frequency
 *
 * The formula to set TIM2:
 *
 *   TIMxCLK = APB1 Timer Clock / (PSC + 1) / (ARR + 1)
 *
 * Choosing PSC = 84:
 *
 *   TIMxCLK = 85 MHz / (84 + 1) = 1 MHz
 *
 * ARR should be:
 *
 *   ARR = (1MHz / 1000Hz) - 1 = 999
 *
 * Thus, PSC = 84 and ARR = 999 will generate a 1ms timer interrupt.
 */
#define TIM2_PRESCALER  84   /**< Prescaler value for TIM2 */
#define TIM2_ARR        999  /**< Auto-reload value for TIM2 */

/**
 * @brief Configures TIM2 for 1ms interrupt and starts it.
 *
 * This function configures TIM2 with a 1ms period by setting the prescaler
 * and auto-reload register values appropriately. The timer is then started
 * with interrupt enabled.
 *
 * @return Status of the operation.
 */
ITimerInterrupt_StatusType ITimerInterrupt_startTimer_HAL(void)
{
    /* Configure TIM2 Prescaler and Auto-reload for 1ms interrupt */
    htim2.Instance = TIM2;
    htim2.Init.Prescaler = TIM2_PRESCALER;  /**< Set prescaler to divide clock */
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;  /**< Count up mode */
    htim2.Init.Period = TIM2_ARR;  /**< Set auto-reload register */
    htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;

    /* Apply the configuration */
    if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
    {
        return ITIMER_INTERRUPT_NOT_OK;
    }

    /* Start TIM2 with interrupt enabled */
    if (HAL_TIM_Base_Start_IT(&htim2) != HAL_OK)
    {
        return ITIMER_INTERRUPT_NOT_OK;
    }

    return ITIMER_INTERRUPT_OK;
}

/**
 * @brief Stops TIM2 interrupt.
 *
 * This function stops the TIM2 timer and disables the interrupt.
 *
 * @return Status of the operation.
 */
ITimerInterrupt_StatusType ITimerInterrupt_stopTimer_HAL(void)
{
    /* Stop TIM2 with interrupt disabled */
    if (HAL_TIM_Base_Stop_IT(&htim2) != HAL_OK)
    {
        return ITIMER_INTERRUPT_NOT_OK;
    }

    return ITIMER_INTERRUPT_OK;
}

