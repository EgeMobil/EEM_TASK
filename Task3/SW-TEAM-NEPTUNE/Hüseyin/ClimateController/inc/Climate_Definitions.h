#ifndef __CLIMATE_DEFINITIONS_H
#define __CLIMATE_DEFINITIONS_H

#define CLIMATE_MIN_TEMP    5.0
#define CLIMATE_MAX_TEMP    55.0

typedef enum {
    FAN_PWM_OFF,    // %0
    FAN_PWM_LOW,    // %25
    FAN_PWM_MID,    // %50
    FAN_PWM_HIGH,   // %75
    FAN_PWM_MAX     // %100
} FanLevel;

typedef enum {
    FAN_AIR_HOT,
    FAN_AIR_COOL
} FanAirType;

struct Climate {

    FanLevel fanLevel;

    // Inner Private Values/Functions
    // C++, Class "private" Section
    FanAirType fanAirType;
    float targetTemp;
    float currentTemp;

    void (*setTargetTemp) (float*);
    void (*setFanLevel) (void);
};

typedef struct Climate Climate_Obj;

#endif