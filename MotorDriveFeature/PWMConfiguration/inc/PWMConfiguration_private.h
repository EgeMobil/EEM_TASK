#ifndef PWMCONFIGURATION_PRIVATE_H_
#define PWMCONFIGURATION_PRIVATE_H_

/** 
 * @file PWMConfiguration_Private.h
 * @brief Private header for the PWM configuration, including pin definitions, constructor prototypes, and function implementations.
 */

/* CompName definition include */
#include "PWMConfiguration_definition.h"

/** 
 * @brief Pin definitions for HALL sensors and brake/direction control.
 * These macros define the GPIO pins and ports used by the system for the hall sensors and the brake and direction signals.
 */
#define HALLA_OUTPUT_PIN      IGPIOSTATUS_PIN_15  /**< HALL A pin output */
#define HALLA_OUTPUT_PORT     IGPIOSTATUS_PORT_B  /**< HALL A port output */

#define HALLB_OUTPUT_PIN      IGPIOSTATUS_PIN_9   /**< HALL B pin output */
#define HALLB_OUTPUT_PORT     IGPIOSTATUS_PORT_A  /**< HALL B port output */

#define HALLC_OUTPUT_PIN      IGPIOSTATUS_PIN_14  /**< HALL C pin output */
#define HALLC_OUTPUT_PORT     IGPIOSTATUS_PORT_B  /**< HALL C port output */

#define BRAKE_OUTPUT_PIN      IGPIOSTATUS_PIN_1   /**< Brake output pin (to be finalized) */
#define BRAKE_OUTPUT_PORT     IGPIOSTATUS_PORT_C  /**< Brake output port (to be finalized) */

#define DIRECTION_OUTPUT_PIN  IGPIOSTATUS_PIN_2   /**< Direction output pin (to be finalized) */
#define DIRECTION_OUTPUT_PORT IGPIOSTATUS_PORT_C  /**< Direction output port (to be finalized) */

/** 
 * @brief Constructor for PWM configuration.
 * Initializes the PWM configuration instance and sets up all relevant parameters.
 */
void PWMConfiguration_CTOR(void);

/** 
 * @brief Get the singleton instance of PWM configuration.
 * @return Pointer to the PWM configuration instance.
 */
dtPWMConfiguration* PWMConfiguration_GetInstance(void);

/** 
 * @name Singleton base class getter/setter prototypes
 * @{
 */

/** 
 * @brief Set the frequency value in PWM configuration.
 * @param value The frequency value to set.
 */
void setFrequency_Impl(uint16_t value);

/** 
 * @brief Get the current frequency value from PWM configuration.
 * @return The current frequency value.
 */
uint16_t getFrequency_Impl(void);

/** 
 * @brief Set the duty cycle value in PWM configuration.
 * @param value The duty cycle value to set.
 */
void setDutyCycle_Impl(uint16_t value);

/** 
 * @brief Get the current duty cycle value from PWM configuration.
 * @return The current duty cycle value.
 */
uint16_t getDutyCycle_Impl(void);

/** 
 * @brief Set the speed status in PWM configuration.
 * @param value The speed status to set.
 */
void setSpeedStatus_Impl(dtPWMConfiguration_speedStatus value);

/** 
 * @brief Get the current speed status from PWM configuration.
 * @return The current speed status.
 */
dtPWMConfiguration_speedStatus getSpeedStatus_Impl(void);

/** 
 * @brief Set the direction status in PWM configuration.
 * @param value The direction status to set.
 */
void setDirectionStatus_Impl(dtPWMConfiguration_directionStatusType value);

/** 
 * @brief Get the current direction status from PWM configuration.
 * @return The current direction status.
 */
dtPWMConfiguration_directionStatusType getDirectionStatus_Impl(void);

/** 
 * @brief Set the brake status in PWM configuration.
 * @param value The brake status to set.
 */
void setBrakeStatus_Impl(dtPWMConfiguration_brakeStatusType value);

/** 
 * @brief Get the current brake status from PWM configuration.
 * @return The current brake status.
 */
dtPWMConfiguration_brakeStatusType getBrakeStatus_Impl(void);

/** 
 * @brief Get a string representation of the PWM configuration.
 * @return The string representation of the PWM configuration.
 */
const char* toString_Impl(void);

/** @} */

/** 
 * @name Singleton base class functional behavior prototypes
 * @{
 */

/** 
 * @brief Start the PWM timer.
 */
void startTimer_Impl(void);

/** 
 * @brief Stop the PWM timer.
 */
void stopTimer_Impl(void);

/** 
 * @brief Set the timer frequency for PWM.
 * @param value The frequency value to set.
 */
void setTimerFrequency_Impl(uint16_t value);

/** 
 * @brief Set the timer duty cycle for PWM.
 * @param value The duty cycle value to set.
 */
void setTimerDutyCycle_Impl(uint16_t value);

/** @} */

/** 
 * @name Runables
 * @{
 */

/** 
 * @brief Initialize the PWM configuration.
 */
FUNC(void, PWMConfiguration_ruInitialisation)(void);

/** 
 * @brief Update the PWM configuration.
 */
FUNC(void, PWMConfiguration_ruUpdate)(void);

/** 
 * @brief Refresh the PWM configuration.
 */
FUNC(void, PWMConfiguration_ruRefresh)(void);

/** @} */

#endif /* PWMCONFIGURATION_PRIVATE_H_ */
