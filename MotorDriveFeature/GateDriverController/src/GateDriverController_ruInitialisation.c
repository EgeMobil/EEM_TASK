/**
 * @file GateDriverController_private.c
 * @brief Private functions for the Gate Driver Controller.
 * 
 * This file contains private functions for internal use within the Gate Driver Controller.
 * It includes the initialization and refresh operations that manage the behavior of 
 * the gate driver.
 * 
 */

#include "GateDriverController_private.h"

/**
 * @brief Initialization runnable for the Gate Driver Controller.
 * 
 * This function performs the initialization tasks for the Gate Driver Controller, 
 * including setting the default configuration values and initializing the gate driver.
 * It performs the following steps:
 * - Retrieves the singleton instance of the Gate Driver Controller.
 * - Retrieves the current driver control register values.
 * - Sets the PWM mode to 1x.
 * - Updates the driver control register.
 * - Initializes the Gate Driver hardware interface.
 */
FUNC(void, GateDriverController_ruInitialisation)(void)
{  
    dtGateDriverController_driverControl currentDriveControlReg;

    /* Get Singleton Instance */
    dtGateDriverController* gdc = GateDriverController_GetInstance();

    /* Get register default values */
    currentDriveControlReg = gdc->getDriverControl();

    /* Set PWM Mode 1x */
    currentDriveControlReg.control_bits.PWM_MODE = PWM_MODE_1_INPUT;
    
    /* Set register value for driver control */
    gdc->setDriverControl(currentDriveControlReg);
    
    /* Initialise Gate Driver */
    gdc->IDRV8353->Init();
}
