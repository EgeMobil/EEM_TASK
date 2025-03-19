#include "controller.h"
#include "source.h"
#include "system.h"

void motoraGazVer(){
    uint16_t gazData=0;
    pedal_data_t* data = readADCData();
    if(data->adc_value1!=data->adc_value2){
        gazData=0;
        //error log
    }else{
        gazData = ((data->adc_value1 - 0.5) / (4.5 - 0.5)) * 100;
    }
    savePedalData(data);
    motorControl(gazData);
}

void showDataOnDisplay(){
    sendDisplay();
}