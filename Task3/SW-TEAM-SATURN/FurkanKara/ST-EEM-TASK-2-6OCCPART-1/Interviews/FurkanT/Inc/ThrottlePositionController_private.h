/*
 * ThrottlePositionController_private.h
 *
 *  Created on: Feb 15, 2025
 *      Author: furka
 */

#ifndef INC_THROTTLEPOSITIONCONTROLLER_PRIVATE_H_
#define INC_THROTTLEPOSITIONCONTROLLER_PRIVATE_H_

#include <stdint.h>

// Private variables
uint8_t GetAverageIfConsistent(void);
uint8_t CalculatePedalPercentage(void);
extern uint32_t READVALUEPRIMARY;
extern uint32_t READVALUESECONDARY;

#endif /* INC_THROTTLEPOSITIONCONTROLLER_PRIVATE_H_ */
