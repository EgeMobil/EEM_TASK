/** 
 * @file MotorDriverDcmProxy_private.h
 * @brief Private header file for the Motor Driver DCM Proxy, defining internal methods and singleton access.
 */

#ifndef MOTORDRIVERDCMPROXY_PRIVATE_H_
#define MOTORDRIVERDCMPROXY_PRIVATE_H_

/* CompName definition include */
#include "MotorDriverDcmProxy_definition.h"

/** 
 * @brief Gets the singleton instance of the MotorDriverDcmProxy.
 * 
 * This function returns a pointer to the singleton instance of the MotorDriverDcmProxy structure.
 * @return Pointer to the dtMotorDriverDcmProxy instance.
 */
dtMotorDriverDcmProxy* MotorDriverDcmProxy_GetInstance(void);

/** 
 * @brief Initializes the MotorDriverDcmProxy instance.
 * 
 * This constructor function sets up the function pointers and initializes the attributes of 
 * the MotorDriverDcmProxy instance to default values.
 */
void MotorDriverDcmProxy_CTOR(void);

/** 
 * @brief Refreshes the MotorDriverDcmProxy instance.
 * 
 * This runnable function is responsible for refreshing the MotorDriverDcmProxy instance.
 * The implementation should define the necessary actions to update or refresh the state.
 */
FUNC(void, MotorDriverDcmProxy_ruRefresh)(void);

/** 
 * @brief Collects data for the MotorDriverDcmProxy instance.
 * 
 * This runnable function collects data related to the MotorDriverDcmProxy instance. The 
 * specific functionality will depend on the system's requirements.
 */
FUNC(void, MotorDriverDcmProxy_ruCollect)(void);

#endif /* MOTORDRIVERDCMPROXY_PRIVATE_H_ */
