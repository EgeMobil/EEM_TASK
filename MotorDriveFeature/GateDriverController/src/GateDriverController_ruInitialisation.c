/* Doxygen Runable Comment */

#include "GateDriverController_private.h"

/* Baseclass private access include */

FUNC(void, GateDriverController_ruInitialisation)(void)
{  
    dtGateDriverController_driverControl currentDriveControlReg;

    /* Get Singleton Instance */
    dtGateDriverController* gdc = GateDriverController_GetInstance();

    /* Get register default values */
    currentDriveControlReg = gdc->getDriverControl();

    /* Setp PWM Mode 1x */
    currentDriveControlReg.control_bits.PWM_MODE = PWM_MODE_1_INPUT;
    
    /* Set register value for driver control */
    gdc->setDriverControl(currentDriveControlReg);
    
    /* Initialise Gate Driver */
    gdc->IDRV8353->Init();
}
