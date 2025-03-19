#include "source.h"

pedal_data_t lastPedalData;


pedal_data_t* getLastPedalData(){
    return &lastPedalData;
}

void savePedalData(pedal_data_t* data){
    memcpy(&lastPedalData, data, sizeof(pedal_data_t));
}
