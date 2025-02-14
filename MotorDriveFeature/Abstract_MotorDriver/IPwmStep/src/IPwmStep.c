#include "IPwmStep.h"

/**
 * @brief Instance of the IPwmStep interface.
 */
IPwmStep PwmStepInterface = {
    .writePwmStepA = IPwmStep_writePwmStepA_Impl,
    .writePwmStepB = IPwmStep_writePwmStepB_Impl,
    .writePwmStepC = IPwmStep_writePwmStepC_Impl,
	.readPwmStepA = IPwmStep_readPwmStepA_Impl,
	.readPwmStepB = IPwmStep_readPwmStepB_Impl,
	.readPwmStepC = IPwmStep_readPwmStepC_Impl,
    .startTimer = IPwmStep_startTimer_Impl,
    .stopTimer = IPwmStep_stopTimer_Impl,
    .setFrequency = IPwmStep_setFrequency_Impl,
    .setDutyCycle = IPwmStep_setDutyCycle_Impl
};

/* Static variables for storing current states */
static cmPwmStep currentPwmStepA = PWMSTEP_PWMSTATUS_UNKNOWN;
static cmPwmStep currentPwmStepB = PWMSTEP_PWMSTATUS_UNKNOWN;
static cmPwmStep currentPwmStepC = PWMSTEP_PWMSTATUS_UNKNOWN;
static uint32_t currentFrequency = 15000; /**< Default frequency in Hz */
static uint16_t currentDutyCycle = 0;  /**< Default duty cycle in range 0-1000 */

/* Implementation for pwmStepA */
IPwmStep_StatusType IPwmStep_writePwmStepA_Impl(cmPwmStep pwmStepA)
{
    if (pwmStepA < PWMSTEP_PWMSTATUS_LOW || pwmStepA > PWMSTEP_PWMSTATUS_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IPwmStep] Invalid pwmStepA value: %d\n", pwmStepA);
#endif
        return IPWMSTEP_NOT_OK;
    }

    /* Call HAL function to actually set the pin state */
    IPwmStep_StatusType status = IPwmStep_writePwmStepA_HAL(pwmStepA);

    if (status == IPWMSTEP_OK)
    {
        /* Cache the written state in case it's needed later */
        currentPwmStepA = pwmStepA;
    }
    else
    {
    	currentPwmStepA = PWMSTEP_PWMSTATUS_UNKNOWN;
    }

#ifndef STM32G431xx
    printf("[IPwmStep] pwmStepA written: %d\n", pwmStepA);
#else

#endif



    return IPWMSTEP_OK;
}

cmPwmStep IPwmStep_readPwmStepA_Impl(void)
{
#ifndef STM32G431xx
    printf("[IPwmStep] pwmStepA read: %d\n", currentPwmStepA);
#endif
    return currentPwmStepA;
}

/* Implementation for pwmStepB */
IPwmStep_StatusType IPwmStep_writePwmStepB_Impl(cmPwmStep pwmStepB)
{
    if (pwmStepB < PWMSTEP_PWMSTATUS_LOW || pwmStepB > PWMSTEP_PWMSTATUS_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IPwmStep] Invalid pwmStepB value: %d\n", pwmStepB);
#endif
        return IPWMSTEP_NOT_OK;
    }

    /* Call HAL function to actually set the pin state */
    IPwmStep_StatusType status = IPwmStep_writePwmStepB_HAL(pwmStepB);

    if (status == IPWMSTEP_OK)
    {
        /* Cache the written state in case it's needed later */
        currentPwmStepB = pwmStepB;
    }
    else
    {
    	currentPwmStepB = PWMSTEP_PWMSTATUS_UNKNOWN;
    }


#ifndef STM32G431xx
    printf("[IPwmStep] pwmStepB written: %d\n", pwmStepB);
#endif

    /* Update status of pwmStep B */


    return IPWMSTEP_OK;
}

cmPwmStep IPwmStep_readPwmStepB_Impl(void)
{
#ifndef STM32G431xx
    printf("[IPwmStep] pwmStepB read: %d\n", currentPwmStepB);
#endif
    return currentPwmStepB;
}

/* Implementation for pwmStepC */
IPwmStep_StatusType IPwmStep_writePwmStepC_Impl(cmPwmStep pwmStepC)
{
    if (pwmStepC < PWMSTEP_PWMSTATUS_LOW || pwmStepC > PWMSTEP_PWMSTATUS_UNKNOWN)
    {
#ifndef STM32G431xx
        printf("[IPwmStep] Invalid pwmStepC value: %d\n", pwmStepC);
#endif
        return IPWMSTEP_NOT_OK;
    }

    /* Call HAL function to actually set the pin state */
   IPwmStep_StatusType status = IPwmStep_writePwmStepC_HAL(pwmStepC);

   if (status == IPWMSTEP_OK)
   {
       /* Cache the written state in case it's needed later */
       currentPwmStepC = pwmStepC;
   }
   else
   {
	   currentPwmStepC = PWMSTEP_PWMSTATUS_UNKNOWN;
   }

#ifndef STM32G431xx
    printf("[IPwmStep] pwmStepC written: %d\n", pwmStepC);
#endif
    return IPWMSTEP_OK;
}

cmPwmStep IPwmStep_readPwmStepC_Impl(void)
{
#ifndef STM32G431xx
    printf("[IPwmStep] pwmStepC read: %d\n", currentPwmStepC);
#endif
    return currentPwmStepC;
}

/**
 * @brief Starts the PWM timer.
 * @return Status of the operation.
 */
IPwmStep_StatusType IPwmStep_startTimer_Impl(void)
{
#ifndef STM32G431xx
    printf("[IPwmStep] pwmStep Timer Start ");
    return IPWMSTEP_OK;
#else
    return IPwmStep_startTimer_HAL();
#endif
}


/**
 * @brief Stops the PWM timer.
 * @return Status of the operation.
 */
IPwmStep_StatusType IPwmStep_stopTimer_Impl(void)
{
#ifndef STM32G431xx
    printf("[IPwmStep] pwmStep Timer Stop ");
    return IPWMSTEP_OK;
#else
    return IPwmStep_stopTimer_HAL();
#endif
}

/**
 * @brief Sets the PWM frequency.
 * @param frequency Desired frequency in Hz.
 * @return Status of the operation.
 */
IPwmStep_StatusType IPwmStep_setFrequency_Impl(uint32_t frequency)
{
#ifndef STM32G431xx
    printf("[IPwmStep] setFrequency %u ", frequency);
    return IPWMSTEP_OK;
#else
    IPwmStep_StatusType status = IPwmStep_setFrequency_HAL(frequency);

    if (status == IPWMSTEP_OK)
    {
        currentFrequency = frequency;
    }

    return status;
#endif
}

/**
 * @brief Sets the PWM duty cycle.
 * @param dutyCycle Desired duty cycle in range 0-1000.
 * @return Status of the operation.
 */
IPwmStep_StatusType IPwmStep_setDutyCycle_Impl(uint16_t dutyCycle)
{
    if (dutyCycle > 1000)
    {
        return IPWMSTEP_NOT_OK;
    }
#ifndef STM32G431xx
    printf("[IPwmStep] setDutyCycle %u ", dutyCycle);
    return IPWMSTEP_OK;
#else
    IPwmStep_StatusType status = IPwmStep_setDutyCycle_HAL(dutyCycle);

    if (status == IPWMSTEP_OK)
    {
        currentDutyCycle = dutyCycle;
    }

    return status;
#endif
}


