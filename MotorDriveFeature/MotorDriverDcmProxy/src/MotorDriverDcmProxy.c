#include "MotorDriverDcmProxy_private.h"

/* Instance definition */
static dtMotorDriverDcmProxy instance;

/* Getter Setter Implementation */

/* PwmError Getter and Setter */
static void MotorDriverDcmProxy_setPwmError_Impl(dtPwmError error)
{
    instance.pwmErr = error;
}

static dtPwmError MotorDriverDcmProxy_getPwmError_Impl(void)
{
    return instance.pwmErr;
}

/* BdrError Getter and Setter */
static void MotorDriverDcmProxy_setBdrError_Impl(dtBdrError error)
{
    instance.bdrErr = error;
}

static dtBdrError MotorDriverDcmProxy_getBdrError_Impl(void)
{
    return instance.bdrErr;
}

/* IrqError Getter and Setter */
static void MotorDriverDcmProxy_setIrqError_Impl(dtIrqError error)
{
    instance.irqErr = error;
}

static dtIrqError MotorDriverDcmProxy_getIrqError_Impl(void)
{
    return instance.irqErr;
}

/* SpeedError Getter and Setter */
static void MotorDriverDcmProxy_setSpeedError_Impl(dtSpeedError error)
{
    instance.speedErr = error;
}

static dtSpeedError MotorDriverDcmProxy_getSpeedError_Impl(void)
{
    return instance.speedErr;
}

/* GdrError Getter and Setter */
static void MotorDriverDcmProxy_setGdrError_Impl(dtGdrError error)
{
    instance.gdrErr = error;
}

static dtGdrError MotorDriverDcmProxy_getGdrError_Impl(void)
{
    return instance.gdrErr;
}

/* toString() Implementation */
static char* MotorDriverDcmProxy_toString_Impl(void)
{
    char* output = (char*)malloc(512); // Yeterli bir buffer boyutu
    if (output == NULL)
    {
        return strdup("Memory allocation failed.");
    }

    snprintf(output, 512,
             "[MotorDriverDcmProxy Registers]:\n"
             "PwmError: %d\n"
             "BdrError: %d\n"
             "IrqError: %d\n"
             "SpeedError: %d\n"
             "GdrError: %d\n",
             instance.pwmErr,
             instance.bdrErr,
             instance.irqErr,
             instance.speedErr,
             instance.gdrErr);

    return output;
}

/* Constructor Implementation */
void MotorDriverDcmProxy_CTOR(void)
{
    /* Initialize the Interface Pointers */
    instance.IMotorDriveError = &MotorDriveErrorInterface;

    /* Initialize Function Pointers */
    instance.getPwmError = MotorDriverDcmProxy_getPwmError_Impl;
    instance.setPwmError = MotorDriverDcmProxy_setPwmError_Impl;

    instance.getBdrError = MotorDriverDcmProxy_getBdrError_Impl;
    instance.setBdrError = MotorDriverDcmProxy_setBdrError_Impl;

    instance.getIrqError = MotorDriverDcmProxy_getIrqError_Impl;
    instance.setIrqError = MotorDriverDcmProxy_setIrqError_Impl;

    instance.getSpeedError = MotorDriverDcmProxy_getSpeedError_Impl;
    instance.setSpeedError = MotorDriverDcmProxy_setSpeedError_Impl;

    instance.getGdrError = MotorDriverDcmProxy_getGdrError_Impl;
    instance.setGdrError = MotorDriverDcmProxy_setGdrError_Impl;

    instance.toString = MotorDriverDcmProxy_toString_Impl;

    /* Initialize Attributes to Default Values */
    instance.pwmErr = PWM_ERR_UNKNOWN;
    instance.bdrErr = BDR_ERR_UNKNOWN;
    instance.irqErr = IRQ_ERR_UNKNOWN;
    instance.speedErr = SPEED_ERR_UNKNOWN;
    instance.gdrErr = GDR_ERR_UNKNOWN;
}

/* Singleton Instance Getter */
dtMotorDriverDcmProxy* MotorDriverDcmProxy_GetInstance(void)
{
    return &instance;
}

/* Functional Behaviour Implementation */
/* Burada işlevsel davranışlar için ek metotlar tanımlanabilir */
