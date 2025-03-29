#include "climate_control_public.h"
#include "climate_control_private.h"

#include <math.h> // fabs() için
#include <stdio.h>

st_climateControlConfig climateControlConfig;

static const char* CCMFanSpeedModes[] = {"Low Mode", "Middle Mode", "High Mode", "Very High Mode"}; //eklendi

//ortam sıcaklığını get eden fonskiyon
float getCurrentTemp(void)
{
    return climateControlConfig.temperatureCurrent;
}

//istenen sıcaklığı set eden fonksiyon
en_CCMReturn setTemperature( float newTemp)
{    
    if (newTemp >= MAX_TEMPERATURE && newTemp <= MIN_TEMPERATURE)
        return CCM_ERR;
    
    climateControlConfig.temperatureDesired = newTemp;
    return CCM_EOK;
}

//sıcaklık sensöründen veri okuyan ve fan hızını ayarlayan fonksiyon
en_CCMReturn adjustFanSpeed(void)
{
    if(climateControlConfig.FanStatus) //eklendi
    {
        printf("Air conditioner is off\n"); 
        return CCM_EOK;
    }

    if (CCM_EOK != Value_temperatureSensor())
        return CCM_ERR;

    if (CCM_EOK != config_FanSpeed())
        return CCM_ERR;
    
    return CCM_EOK;
}

//init işlemini yapan fonksiyon
void initClimateControl(void)
{
    climateControlConfig.temperatureCurrent = CURRENT_TEMPERATURE;
    climateControlConfig.getCurrentTempPtr  = getCurrentTemp;
    climateControlConfig.setTemperaturePtr  = setTemperature;
    climateControlConfig.adjustFanSpeedPtr  = adjustFanSpeed;
    
}

//fan hızını ayarlayan fonksiyon
static en_CCMReturn config_FanSpeed(void) //değişti static eklendi
{
    if      (abs(climateControlConfig.temperatureCurrent - climateControlConfig.temperatureDesired) >= 7)
    {
        printf("The fan is running in %s.\n", CCMFanSpeedModes[VeryHighMode]); //eklendi
        return CCM_EOK;
    }else if(abs(climateControlConfig.temperatureCurrent - climateControlConfig.temperatureDesired) >= 5)
    {
        printf("The fan is running in %s.\n", CCMFanSpeedModes[HighMode]); //eklendi
        return CCM_EOK;
    }else if(abs(climateControlConfig.temperatureCurrent - climateControlConfig.temperatureDesired) >= 3)
    {
        printf("The fan is running in %s.\n", CCMFanSpeedModes[MiddleMode]); //eklendi
        return CCM_EOK;
    }else if(abs(climateControlConfig.temperatureCurrent - climateControlConfig.temperatureDesired) >= 0)
    {
        printf("The fan is running in %s.\n", CCMFanSpeedModes[LowMode]); //eklendi
        return CCM_EOK;
    }
    return CCM_EOK; //burayı düzenle gönder
}


//sıcaklık sensöründen veri okuyan fonksiyon (değeri arttıran veya düşüren fonksiyon)
static en_CCMReturn Value_temperatureSensor(void) //değişti static eklendi
{
    if (climateControlConfig.temperatureCurrent <= climateControlConfig.temperatureDesired)
    {
        climateControlConfig.temperatureCurrent++;
        return CCM_EOK;
    }
    else if (climateControlConfig.temperatureCurrent >= climateControlConfig.temperatureDesired)
    {
        climateControlConfig.temperatureCurrent--;
        return CCM_EOK;
    }
    return CCM_ERR;

}

