
#include "interface.h"
#include "source.h"
#include "system.h"


pedal_data_t* readADCData(){
    pedal_data_t adcData;
    adcData.adc_value1=adcRead();
    adcData.adc_value2=adcRead();
    return &adcData;
}

void motorControl(uint16_t data){
    motorSend(data);
}
