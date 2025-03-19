#include "application.h"
#include "controller.h"
#include "system.h"

#include "source.h"

void startSystems(){
    adcInit();
    accelertionSensorInit();
    motorInit();
    displayInit();
}


void gasPedal(){
    motoraGazVer();
}

void displayUpdate(){
    showDataOnDisplay();
}