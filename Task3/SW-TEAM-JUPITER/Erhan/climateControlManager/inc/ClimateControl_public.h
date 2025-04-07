#ifndef _CLIMATE_CONTROL_PUBLIC_H
#define _CLIMATE_CONTROL_PUBLIC_H

#include "ClimateControl_definition.h"

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

void Fanstatus_IsClosed(void);
void Fanstatus_IsClosed(void);

void ClimateControl_ruInitialisation(void);
void ClimateControl_ruProsses(void);


#endif // _CLIMATE_CONTROL_PUBLIC_H