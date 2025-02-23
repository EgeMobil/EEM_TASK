
#include <PedalController_config.h>
#include "main.h"

#define TOLERANCE 41
#define MIN_ADC_VALUE 409
#define MAX_ADC_VALUE 3686

uint16_t pedal_values[2];
uint16_t pedal_primary;
uint16_t pedal_secondary;
uint16_t AVGPEDALREAD;
uint8_t PEDALPERCENTAGE;
uint8_t CONSISTENCY_FLAG = 0;
uint8_t PEDAL_OUT_OF_RANGE_FLAG = 0;

void ProcessADCValues(void)
{
    pedal_primary = pedal_values[0];
    pedal_secondary = pedal_values[1];


    if (GetAverageIfConsistent())
    {
        CalculatePedalPercentage();
    }
    else
    {
        PEDALPERCENTAGE = 0;
    }
}

uint8_t GetAverageIfConsistent(void)
{
    uint16_t difference = (pedal_primary > pedal_secondary)
                          ? (pedal_primary - pedal_secondary)
                          : (pedal_secondary - pedal_primary);

    if (difference <= TOLERANCE)
    {
        AVGPEDALREAD = (pedal_primary + pedal_secondary) / 2;
        CONSISTENCY_FLAG = 1;
        return 1;
    }

    CONSISTENCY_FLAG = 0;
    return 0;
}

uint8_t CalculatePedalPercentage(void)
{
    if (AVGPEDALREAD >= MIN_ADC_VALUE && AVGPEDALREAD <= MAX_ADC_VALUE)
    {
        PEDALPERCENTAGE = ((AVGPEDALREAD - MIN_ADC_VALUE) * 100) / (MAX_ADC_VALUE - MIN_ADC_VALUE);
        PEDAL_OUT_OF_RANGE_FLAG = 0;
    }
    else
    {
        PEDALPERCENTAGE = 0;
        PEDAL_OUT_OF_RANGE_FLAG = 1;
    }

    return PEDAL_OUT_OF_RANGE_FLAG;
}
