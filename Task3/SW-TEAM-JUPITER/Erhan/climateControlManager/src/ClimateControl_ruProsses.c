#include "ClimateControl_public.h"


#define DESIRED_VALUE 25.0 //istenen sıcaklık değeri


int n = 10; //while döngüsünün çevrim sayısı


void ClimateControl_ruProsses(void)
{
    climateControlConfig.Fanstatus_IsOpenPtr();

    if(CCM_ERR == climateControlConfig.setTemperaturePtr(DESIRED_VALUE)) //;sil istenen sıcaklık set edildi
    {
        // return 0;
    }


    while (n--)
    {
        if(CCM_ERR == climateControlConfig.adjustFanSpeedPtr()) //fan hızı ayarlandı
        {
                    // return 0;
        }
        // return 0;
    }
    printf("ambient temperature reached %fl degrees.\n", climateControlConfig.getCurrentTempPtr());
}