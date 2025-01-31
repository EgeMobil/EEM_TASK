#include "IPwmStep.h"

/**
 * @brief Instance of the IPwmStep interface.
 */
IPwmStep PwmStepInterface = {
    .writePwmStepA = IPwmStep_writePwmStepA_Impl,
    .readPwmStepA = IPwmStep_readPwmStepA_Impl,
    .writePwmStepB = IPwmStep_writePwmStepB_Impl,
    .readPwmStepB = IPwmStep_readPwmStepB_Impl,
    .writePwmStepC = IPwmStep_writePwmStepC_Impl,
    .readPwmStepC = IPwmStep_readPwmStepC_Impl
};

/* Static variables for storing current states */
static cmPwmStep currentPwmStepA = PWMSTEP_PWMSTATUS_UNKNOWN;
static cmPwmStep currentPwmStepB = PWMSTEP_PWMSTATUS_UNKNOWN;
static cmPwmStep currentPwmStepC = PWMSTEP_PWMSTATUS_UNKNOWN;

/* Implementation for pwmStepA */
IPwmStep_StatusType IPwmStep_writePwmStepA_Impl(cmPwmStep pwmStepA)
{
    if (pwmStepA < PWMSTEP_PWMSTATUS_LOW || pwmStepA > PWMSTEP_PWMSTATUS_UNKNOWN)
    {
#ifndef defined(STM32G431xx)
        printf("[IPwmStep] Invalid pwmStepA value: %d\n", pwmStepA);
#endif
        return IPWMSTEP_NOT_OK;
    }
    currentPwmStepA = pwmStepA;
#ifndef defined(STM32G431xx)
    printf("[IPwmStep] pwmStepA written: %d\n", pwmStepA);
#endif
    return IPWMSTEP_OK;
}

cmPwmStep IPwmStep_readPwmStepA_Impl(void)
{
#ifndef defined(STM32G431xx)
    printf("[IPwmStep] pwmStepA read: %d\n", currentPwmStepA);
#endif
    return currentPwmStepA;
}

/* Implementation for pwmStepB */
IPwmStep_StatusType IPwmStep_writePwmStepB_Impl(cmPwmStep pwmStepB)
{
    if (pwmStepB < PWMSTEP_PWMSTATUS_LOW || pwmStepB > PWMSTEP_PWMSTATUS_UNKNOWN)
    {
#ifndef defined(STM32G431xx)
        printf("[IPwmStep] Invalid pwmStepB value: %d\n", pwmStepB);
#endif
        return IPWMSTEP_NOT_OK;
    }
    currentPwmStepB = pwmStepB;
#ifndef defined(STM32G431xx)
    printf("[IPwmStep] pwmStepB written: %d\n", pwmStepB);
#endif
    return IPWMSTEP_OK;
}

cmPwmStep IPwmStep_readPwmStepB_Impl(void)
{
#ifndef defined(STM32G431xx)
    printf("[IPwmStep] pwmStepB read: %d\n", currentPwmStepB);
#endif
    return currentPwmStepB;
}

/* Implementation for pwmStepC */
IPwmStep_StatusType IPwmStep_writePwmStepC_Impl(cmPwmStep pwmStepC)
{
    if (pwmStepC < PWMSTEP_PWMSTATUS_LOW || pwmStepC > PWMSTEP_PWMSTATUS_UNKNOWN)
    {
#ifndef defined(STM32G431xx)
        printf("[IPwmStep] Invalid pwmStepC value: %d\n", pwmStepC);
#endif
        return IPWMSTEP_NOT_OK;
    }
    currentPwmStepC = pwmStepC;
#ifndef defined(STM32G431xx)
    printf("[IPwmStep] pwmStepC written: %d\n", pwmStepC);
#endif
    return IPWMSTEP_OK;
}

cmPwmStep IPwmStep_readPwmStepC_Impl(void)
{
#ifndef defined(STM32G431xx)
    printf("[IPwmStep] pwmStepC read: %d\n", currentPwmStepC);
#endif
    return currentPwmStepC;
}
