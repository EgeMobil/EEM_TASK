#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdint.h>
#include "source.h"

pedal_data_t* readADCData();
void motorControl(uint16_t data);

#endif