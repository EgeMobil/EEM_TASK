#ifndef _CLIMATE_CONTROL_DEFINITION_H
#define _CLIMATE_CONTROL_DEFINITION_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// Sıcaklık sınırları
#define MIN_TEMPERATURE 16.0  // Minimum sıcaklık (°C)
#define MAX_TEMPERATURE 36.0  // Maksimum sıcaklık (°C)


typedef enum
{ 
    LowMode,
    MiddleMode,
    HighMode, 
    VeryHighMode,
}en_CCMFanMode; //eklendi

#define CURRENT_TEMPERATURE 17.0 //ortam sıcaklığı

typedef enum
{
    CCM_ERR = 0,    // Error
    CCM_EOK,        // Successful operation
} en_CCMReturn;


typedef struct 
{
    float temperatureCurrent; //mevcut sıcaklık
    float temperatureDesired; //istenen istenen sıcaklık
    float FanStatus;          //fan açık mı kapalı mı //eklendi
    char* FanSpeedMode;                               //eklendi

    float        (*getCurrentTempPtr)(void);
    en_CCMReturn (*setTemperaturePtr)(float);
    en_CCMReturn (*adjustFanSpeedPtr)(void);
    void         (*Fanstatus_IsOpenPtr)(void);
    void         (*Fanstatus_IsClosedPtr)(void);

}st_climateControlConfig;



#endif // _CLIMATE_CONTROL_DEFINITION_H