#include "MotorDriverCommProxy_private.h"
/** 
 * @file MotorDriverCommProxy_ruUpdateWheelSpeed.c
 * @brief Updates the wheel speed in the motor driver communication proxy.
 * 
 * This function reads the current wheel speed and updates the Protocol Data Unit (PDU) 
 * with the latest value. The real vehicle speed can also be calculated and updated in 
 * the future.
 * 
 * @details The function retrieves the current wheel speed from the HALL sensor, 
 * calculates the real vehicle speed (marked for later implementation), and updates 
 * the wheel speed in the motor driver communication proxy.
 */
FUNC(void, MotorDriverCommProxy_ruUpdateWheelSpeed)(void)
{
    /* Get Singleton Instance */
    dtMotorDriverCommProxy* mdcp = MotorDriverCommProxy_GetInstance();

    static dtMotorDriverCommProxy_HALLWheelSpeed currentSpeed = 0; /**< Static variable to hold current wheel speed */

    /* Read and update wheel speed PDU variables */
    currentSpeed = mdcp->IHALLWheelSpeed->readHALLWheelSpeed(); /**< Read current wheel speed from HALL sensor */
    
    /* Calculate Real speed on vehicle */
    //@LATER  /**< Placeholder for real vehicle speed calculation */

    /* Update PDU */
    mdcp->setHWheelSpeed(currentSpeed); /**< Update the Protocol Data Unit (PDU) with the current wheel speed */
}
