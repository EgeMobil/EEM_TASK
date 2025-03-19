#ifndef MOTORDRIVERCOMMPROXY_PUBLIC_H_
#define MOTORDRIVERCOMMPROXY_PUBLIC_H_

/** 
 * @file MotorDriverCommProxy_public.h
 * @brief Public header for Motor Driver Communication Proxy (MDCP).
 * 
 * This file provides the public interface for the MotorDriverCommProxy class, including its constructor,
 * Singleton pattern getter, and runnable function prototypes.
 */

/* Include the public definition header */
#include "MotorDriverCommProxy_definition.h"

/** 
 * @brief Constructor prototype for MotorDriverCommProxy.
 * 
 * This function initializes the MotorDriverCommProxy class, setting up necessary resources.
 */
extern void MotorDriverCommProxy_CTOR(void);

/** 
 * @brief Singleton pattern getter for MotorDriverCommProxy instance.
 * 
 * This function returns the singleton instance of the MotorDriverCommProxy class.
 * @return A pointer to the singleton instance of the MotorDriverCommProxy.
 */
extern dtMotorDriverCommProxy* MotorDriverCommProxy_GetInstance(void);

/** 
 * @brief Runnable function prototype to refresh the MotorDriverCommProxy instance.
 * 
 * This function is responsible for refreshing the MotorDriverCommProxy, ensuring it is up-to-date.
 */
extern FUNC(void, MotorDriverCommProxy_ruRefresh)(void);

/** 
 * @brief Runnable function prototype to update the indicator status.
 * 
 * This function updates the indicator status in the MotorDriverCommProxy.
 */
extern FUNC(void, MotorDriverCommProxy_ruUpdateIndicator)(void);

/** 
 * @brief Runnable function prototype to update the wheel speed.
 * 
 * This function updates the wheel speed in the MotorDriverCommProxy.
 */
extern FUNC(void, MotorDriverCommProxy_ruUpdateWheelSpeed)(void);

#endif /* MOTORDRIVERCOMMPROXY_PUBLIC_H_ */
