#include <stdint.h>

#include "../inc/Climate_Private.h"
#include "../inc/Climate_Public.h"
#include "../inc/Climate_TempSensor.h"

static Climate_Obj climate;     // Main Climate Object Declaration

void SetTargetTemp_Def(float* target) {
    climate.targetTemp = *target;
}

void SetFanLevel_Def() {
    float diff = climate.targetTemp - climate.currentTemp;
    if(diff > 0)
        climate.fanAirType = FAN_AIR_HOT;
    else {
        climate.fanAirType = FAN_AIR_COOL;
        diff *= -1; // To make it absolute value and prevent using abs function
    }
        
    if(diff > 30)
        climate.fanLevel = FAN_PWM_MAX;
    else if(diff > 20)
        climate.fanLevel = FAN_PWM_HIGH;
    else if(diff > 10)
        climate.fanLevel = FAN_PWM_MID;
    else if(diff > 0)
        climate.fanLevel = FAN_PWM_LOW;
    else
        climate.fanLevel = FAN_PWM_OFF;
}

void Climate_UserSetTargetTemp(float* targetTemp) {
    if((*targetTemp > CLIMATE_MIN_TEMP) && (*targetTemp < CLIMATE_MAX_TEMP)) {
        climate.setTargetTemp(targetTemp);
        printf("Climate Target Temperature set to %.2f", *targetTemp);
    }
    else
        printf("Invalid temperature. Please enter a value between %.2fC and %.2fC", CLIMATE_MIN_TEMP, CLIMATE_MAX_TEMP);
}

void displayData(float carTemp, float targetTemp, int fanLevel, const char* airType) {
    printf("\033[H\033[J");  // Terminali temizle
    printf("CAR TEMP\tTARGET TEMP\tFAN LEVEL\tAIR TYPE\n");
    printf("%.2f\t\t%.2f\t\t%d\t\t%s\n", carTemp, targetTemp, fanLevel, airType);
    printf("\nSET TARGET TEMP:");
    fflush(stdout);  // Buffer'ı temizle, anında yazdır
}

void Climate_Update(void) {
    climate.currentTemp = *getTemp();
    climate.setFanLevel();

    char* airType;
    if(climate.fanAirType == FAN_AIR_COOL)
        airType = "COOL";
    else
        airType = "WARM";

    displayData(climate.currentTemp, climate.targetTemp, climate.fanLevel, airType);
}

static void Climate_PrivateInit(void) {
    climate.currentTemp     = 0.0;
    climate.targetTemp      = 20.0;     // Optimal Temperature (Celcius)

    climate.setFanLevel     = SetFanLevel_Def;
    climate.setTargetTemp   = SetTargetTemp_Def;
}

Climate_Obj* Climate_GetObj(void) {
    static uint8_t isInit = 0;
    if(!isInit) {
        Climate_PrivateInit();
        isInit = 1;
    }

    return &climate;
}

void Climate_PublicInit(void) {
    startTempThread();
    Climate_GetObj();
}