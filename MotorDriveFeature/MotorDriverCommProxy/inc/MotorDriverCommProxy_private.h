/** 
 * @file MotorDriverCommProxy_private.h
 * @brief Private definitions for the Motor Driver Communication Proxy (MDCP).
 * 
 * This header file contains the private functions for the MotorDriverCommProxy class and functions related to the Singleton pattern.
 */
#ifndef MOTORDRIVERCOMMPROXY_PRIVATE_H_
#define MOTORDRIVERCOMMPROXY_PRIVATE_H_

/* CompName definition include */
#include "MotorDriverCommProxy_definition.h"

/** 
 * @brief Prototype of the constructor for MotorDriverCommProxy.
 * 
 * Provides the necessary configuration to instantiate an example of the MotorDriverCommProxy class.
 */
void MotorDriverCommProxy_CTOR(void);

/** 
 * @brief Prototype to get an instance of the MotorDriverCommProxy class using the Singleton pattern.
 * 
 * This function provides access to a single instance of the MotorDriverCommProxy class.
 * @return The instance of the MotorDriverCommProxy class.
 */
dtMotorDriverCommProxy* MotorDriverCommProxy_GetInstance(void);

/** 
 * @brief Function to refresh the MotorDriverCommProxy instance.
 * 
 * This function initiates a process to update the MotorDriverCommProxy instance.
 */
FUNC(void, MotorDriverCommProxy_ruRefresh)(void);

/** 
 * @brief Function to update the indicator in the MotorDriverCommProxy.
 * 
 * This function updates the indicator status.
 */
FUNC(void, MotorDriverCommProxy_ruUpdateIndicator)(void);

/** 
 * @brief Function to update the wheel speed in the MotorDriverCommProxy.
 * 
 * This function updates the wheel speed.
 */
FUNC(void, MotorDriverCommProxy_ruUpdateWheelSpeed)(void);

#endif /* MOTORDRIVERCOMMPROXY_PRIVATE_H_ */
