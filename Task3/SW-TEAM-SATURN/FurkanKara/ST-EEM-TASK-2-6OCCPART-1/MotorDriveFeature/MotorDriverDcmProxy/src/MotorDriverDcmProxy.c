/** 
 * @file MotorDriverDcmProxy.c
 * @brief Implementation of the Motor Driver DCM Proxy with error handling and diagnostics.
 */

/* Baseclass private access include */
#include "MotorDriverDcmProxy_private.h"

/* Instance definition */
static dtMotorDriverDcmProxy instance;

/** 
 * @brief Setter for PWM error.
 * 
 * This function sets the PWM error for the motor driver.
 * 
 * @param error The PWM error value to set.
 */
static void MotorDriverDcmProxy_setPwmError_Impl(dtPwmError error)
{
    instance.pwmErr = error;
}

/** 
 * @brief Getter for PWM error.
 * 
 * This function returns the current PWM error.
 * 
 * @return The current PWM error.
 */
static dtPwmError MotorDriverDcmProxy_getPwmError_Impl(void)
{
    return instance.pwmErr;
}

/** 
 * @brief Setter for BDR error.
 * 
 * This function sets the BDR error for the motor driver.
 * 
 * @param error The BDR error value to set.
 */
static void MotorDriverDcmProxy_setBdrError_Impl(dtBdrError error)
{
    instance.bdrErr = error;
}

/** 
 * @brief Getter for BDR error.
 * 
 * This function returns the current BDR error.
 * 
 * @return The current BDR error.
 */
static dtBdrError MotorDriverDcmProxy_getBdrError_Impl(void)
{
    return instance.bdrErr;
}

/** 
 * @brief Setter for IRQ error.
 * 
 * This function sets the IRQ error for the motor driver.
 * 
 * @param error The IRQ error value to set.
 */
static void MotorDriverDcmProxy_setIrqError_Impl(dtIrqError error)
{
    instance.irqErr = error;
}

/** 
 * @brief Getter for IRQ error.
 * 
 * This function returns the current IRQ error.
 * 
 * @return The current IRQ error.
 */
static dtIrqError MotorDriverDcmProxy_getIrqError_Impl(void)
{
    return instance.irqErr;
}

/** 
 * @brief Setter for Speed error.
 * 
 * This function sets the Speed error for the motor driver.
 * 
 * @param error The Speed error value to set.
 */
static void MotorDriverDcmProxy_setSpeedError_Impl(dtSpeedError error)
{
    instance.speedErr = error;
}

/** 
 * @brief Getter for Speed error.
 * 
 * This function returns the current Speed error.
 * 
 * @return The current Speed error.
 */
static dtSpeedError MotorDriverDcmProxy_getSpeedError_Impl(void)
{
    return instance.speedErr;
}

/** 
 * @brief Setter for GDR error.
 * 
 * This function sets the GDR error for the motor driver.
 * 
 * @param error The GDR error value to set.
 */
static void MotorDriverDcmProxy_setGdrError_Impl(dtGdrError error)
{
    instance.gdrErr = error;
}

/** 
 * @brief Getter for GDR error.
 * 
 * This function returns the current GDR error.
 * 
 * @return The current GDR error.
 */
static dtGdrError MotorDriverDcmProxy_getGdrError_Impl(void)
{
    return instance.gdrErr;
}

/** 
 * @brief Converts the motor driver error states to a string representation.
 * 
 * This function creates a string representation of the motor driver error states 
 * and returns it. This string can be used for diagnostics or logging.
 * 
 * @return A string representing the motor driver error states.
 */
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

/** 
 * @brief Constructor for MotorDriverDcmProxy.
 * 
 * This function initializes the singleton instance of the MotorDriverDcmProxy 
 * and sets up the function pointers and interface connections.
 * It also initializes the error states to their default values.
 */
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

/** 
 * @brief Retrieves the singleton instance of MotorDriverDcmProxy.
 * 
 * This function returns the instance of the MotorDriverDcmProxy. 
 * The singleton pattern ensures only one instance of this class exists.
 * 
 * @return The singleton instance of the MotorDriverDcmProxy.
 */
dtMotorDriverDcmProxy* MotorDriverDcmProxy_GetInstance(void)
{
    return &instance;
}

/* Functional Behaviour Implementation */
/* Burada işlevsel davranışlar için ek metotlar tanımlanabilir */
