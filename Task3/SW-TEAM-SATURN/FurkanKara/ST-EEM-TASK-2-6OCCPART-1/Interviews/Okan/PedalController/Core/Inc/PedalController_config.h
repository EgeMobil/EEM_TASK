
#ifndef INC_PEDALCONTROLLER_CONFIG_H_
#define INC_PEDALCONTROLLER_CONFIG_H_

#include <PedalController_api.h>
#include <PedalController_internal.h>

#ifdef __cplusplus
extern "C" {
#endif


extern uint16_t pedal_values[2];
extern uint16_t pedal_primary;
extern uint16_t pedal_secondary;

void ProcessADCValues(void);
uint8_t GetAverageIfConsistent(void);
uint8_t CalculatePedalPercentage(void);

#ifdef __cplusplus
}
#endif

#endif /* INC_PEDALCONTROLLER_CONFIG_H_ */
