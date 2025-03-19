#ifndef PWMCONFIGURATION_PUBLIC_H_
#define PWMCONFIGURATION_PUBLIC_H_

/** 
 * @file PWMConfiguration_Public.h
 * @brief Public header for the PWM configuration, providing access to constructor and runable prototypes.
 */

/* Include the public definition header */
#include "PWMConfiguration_definition.h"

/** 
 * @brief Constructor external prototype for public access.
 * Initializes the PWM configuration. This function is called to set up the PWM configuration instance.
 */
void PWMConfiguration_CTOR(void);

/** 
 * @brief Singleton base class getter external prototype for public access.
 * @return Pointer to the PWM configuration instance.
 * Provides access to the singleton instance of the PWM configuration class.
 */
dtPWMConfiguration* PWMConfiguration_GetInstance(void);

/** 
 * @name Runable Prototypes for public access
 * @{
 */

/** 
 * @brief Initializes the PWM configuration.
 * This function is responsible for initializing the PWM configuration when called.
 */
extern FUNC(void, PWMConfiguration_ruInitialisation)(void);

/** 
 * @brief Updates the PWM configuration.
 * This function performs updates to the PWM configuration.
 */
extern FUNC(void, PWMConfiguration_ruUpdate)(void);

/** 
 * @brief Refreshes the PWM configuration.
 * This function refreshes the current state of the PWM configuration.
 */
extern FUNC(void, PWMConfiguration_ruRefresh)(void);

/** @} */

#endif /* PWMCONFIGURATION_PUBLIC_H_ */
