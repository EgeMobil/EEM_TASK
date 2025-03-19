#ifndef INC_PEDALCONTROLLER_INTERNAL_H_
#define INC_PEDALCONTROLLER_INTERNAL_H_

#include <stdint.h>


uint8_t GetAverageIfConsistent(void);
uint8_t CalculatePedalPercentage(void);


extern uint16_t pedal_values[2];
extern uint16_t pedal_primary;
extern uint16_t pedal_secondary;

#endif /* INC_PEDALCONTROLLER_INTERNAL_H_ */
