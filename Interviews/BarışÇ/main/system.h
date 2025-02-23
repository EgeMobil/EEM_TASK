#ifndef SYSTEM_H
#define SYSTEM_H

#include "source.h"



void adcInit();
void accelertionSensorInit();
void motorInit();
void displayInit();



uint16_t adcRead();
void motorSend(uint16_t motorData);

#endif