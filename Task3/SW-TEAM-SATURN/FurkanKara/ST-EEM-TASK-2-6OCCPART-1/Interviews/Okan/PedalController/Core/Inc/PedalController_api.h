#ifndef INC_PEDALCONTROLLER_API_H_
#define INC_PEDALCONTROLLER_API_H_

#include "stdint.h"


extern uint16_t pedal_values[2];
extern uint16_t pedal_primary;
extern uint16_t pedal_secondary;


void ProcessADCValues(void);
uint8_t GetAverageIfConsistent(void);
uint8_t CalculatePedalPercentage(void);

#endif /* INC_PEDALCONTROLLER_API_H_ */
