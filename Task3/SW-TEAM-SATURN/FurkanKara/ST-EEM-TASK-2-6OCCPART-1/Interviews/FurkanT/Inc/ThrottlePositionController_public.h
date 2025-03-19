/*
 * ThrottlePositionController_public.h
 *
 *  Created on: Feb 15, 2025
 *      Author: furka
 */

#ifndef INC_THROTTLEPOSITIONCONTROLLER_PUBLIC_H_
#define INC_THROTTLEPOSITIONCONTROLLER_PUBLIC_H_

#include <stdint.h>

void ProcessADCValues(void);
extern uint32_t READVALUEBUFFER[2];
extern uint8_t CONSISTENCY_FLAG;
extern uint8_t PEDAL_OUT_OF_RANGE_FLAG;
extern uint8_t PEDALPERCENTAGE;

#endif /* INC_THROTTLEPOSITIONCONTROLLER_PUBLIC_H_ */
