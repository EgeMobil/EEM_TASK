#ifndef SOURCE_H
#define SOURCE_H

#include <stdint.h>

typedef struct {
    uint16_t adc_value1;
    uint16_t adc_value2;
} pedal_data_t;


typedef struct{
    uint16_t speed;
    uint16_t throttle;
} displayed_data_t;

void savePedalData(pedal_data_t* data);
pedal_data_t* getLastPedalData();

void saveDisplayedData(displayed_data_t data);
displayed_data_t* getLastDisplayedData();

#endif