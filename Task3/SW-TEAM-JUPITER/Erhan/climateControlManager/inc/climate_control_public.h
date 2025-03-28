#ifndef _CLIMATE_CONTROL_PUBLIC_H
#define _CLIMATE_CONTROL_PUBLIC_H

#include "definition.h"

typedef enum //eklendi
{
    fanIsOpen,
    FanIsClosed,
}CCM_FanStatus;

extern st_climateControlConfig climateControlConfig;

void initClimateControl(void);

en_CCMReturn setTemperature( float newTemp);



float getCurrentTemp(void);


en_CCMReturn adjustFanSpeed(void);




#endif // _CLIMATE_CONTROL_PUBLIC_H