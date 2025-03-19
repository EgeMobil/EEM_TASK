#include "MotorDriverCommProxy_private.h"
/** 
 * @file MotorDriverCommProxy_ruRefresh.c
 * @brief Refreshes the motor driver communication proxy.
 * 
 * This function retrieves the singleton instance of MotorDriverCommProxy and forwards 
 * the PDU (Protocol Data Unit) to the communication line by writing the indicator 
 * and wheel speed data.
 * 
 * @details This function is responsible for refreshing the communication proxy by 
 * forwarding the indicator and wheel speed data to the corresponding communication 
 * interfaces.
 */
FUNC(void, MotorDriverCommProxy_ruRefresh)(void)
{
    /* Get Singleton Instance */
    dtMotorDriverCommProxy* mdcp = MotorDriverCommProxy_GetInstance();

    /* Forward PDU to Comm Line */
    mdcp->IIndicator->writeIndicator(mdcp->getIndicator()); /**< Forward indicator to communication line */
    mdcp->IHALLWheelSpeed->writeHALLWheelSpeed(mdcp->getHWheelSpeed()); /**< Forward HALL wheel speed to communication line, marked for later processing */
}
