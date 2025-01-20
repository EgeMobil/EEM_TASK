#ifndef PWMCONFIGURATION_PRIVATE_H_
#define PWMCONFIGURATION_PRIVATE_H_

/* CompName definition include */
#include "PWMConfiguration_definition.h"

#define HALLA_OUTPUT_PIN 	  IGPIOSTATUS_PIN_15
#define HALLA_OUTPUT_PORT     IGPIOSTATUS_PORT_B

#define HALLB_OUTPUT_PIN      IGPIOSTATUS_PIN_9
#define HALLB_OUTPUT_PORT     IGPIOSTATUS_PORT_A

#define HALLC_OUTPUT_PIN      IGPIOSTATUS_PIN_14
#define HALLC_OUTPUT_PORT     IGPIOSTATUS_PORT_B

#define BRAKE_OUTPUT_PIN      IGPIOSTATUS_PIN_1   /* @LATER */ 
#define BRAKE_OUTPUT_PORT     IGPIOSTATUS_PORT_C  /* @LATER */

#define DIRECTION_OUTPUT_PIN    IGPIOSTATUS_PIN_2 /* @LATER */
#define DIRECTION_OUTPUT_PORT   IGPIOSTATUS_PORT_C /* @LATER */

/* Constructor Prototype */
void PWMConfiguration_CTOR(void);

dtPWMConfiguration* PWMConfiguration_GetInstance(void);

/* Singelton base class getter/setter prototype */
void setFrequency_Impl(uint16_t value);
uint16_t getFrequency_Impl(void);
void setDutyCycle_Impl(uint16_t value);
uint16_t getDutyCycle_Impl(void);
void setSpeedStatus_Impl(dtPWMConfiguration_speedStatus value);
dtPWMConfiguration_speedStatus getSpeedStatus_Impl(void);
void setDirectionStatus_Impl(dtPWMConfiguration_directionStatusType value);
dtPWMConfiguration_directionStatusType getDirectionStatus_Impl(void);
void setBrakeStatus_Impl(dtPWMConfiguration_brakeStatusType value);
dtPWMConfiguration_brakeStatusType getBrakeStatus_Impl(void);
const char* toString_Impl(void);

/* Singelton base class functional behaviour prototype */
void startTimer_Impl(void);
void stopTimer_Impl(void);
void setTimerFrequency_Impl(uint16_t value);
void setTimerDutyCycle_Impl(uint16_t value);

/* Runables */
FUNC(void, PWMConfiguration_ruInitialisation)(void);
FUNC(void, PWMConfiguration_ruUpdate)(void);
FUNC(void, PWMConfiguration_ruRefresh)(void);

#endif /* PWMCONFIGURATION_PRIVATE_H_ */