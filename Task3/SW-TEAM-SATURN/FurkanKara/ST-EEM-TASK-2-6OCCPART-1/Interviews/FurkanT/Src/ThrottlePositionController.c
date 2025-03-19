/*
 * ThrottlePositionController.c
 *
 *  Created on: Feb 15, 2025
 *      Author: Furkan Türker Akşit
 *      Linkedin: https://www.linkedin.com/in/furkanakşit/
 */
#include "main.h"
#include "ThrottlePositionController_definition.h"

#define TOLERANCE 41 // %1 tolerance for 12-bit ADC
#define MIN_ADC_VALUE 409
#define MAX_ADC_VALUE 3686

uint32_t READVALUEBUFFER[2];

uint32_t READVALUEPRIMARY;
uint32_t READVALUESECONDARY;
uint32_t AVGPEDALREAD;
uint8_t PEDALPERCENTAGE;
uint8_t CONSISTENCY_FLAG = 0;
uint8_t PEDAL_OUT_OF_RANGE_FLAG = 0;

void ProcessADCValues(void)
{
	READVALUEPRIMARY = READVALUEBUFFER[0];
	READVALUESECONDARY = READVALUEBUFFER[1];
	GetAverageIfConsistent();
}

uint8_t GetAverageIfConsistent(void)
{
	if (READVALUEPRIMARY > READVALUESECONDARY)
	{
		if ((READVALUEPRIMARY - READVALUESECONDARY) <= TOLERANCE)
		{
			AVGPEDALREAD = (READVALUEPRIMARY + READVALUESECONDARY) / 2;
			CONSISTENCY_FLAG = 1; // Values are consistent
			return CalculatePedalPercentage();
		}
	}
	else
	{
		if ((READVALUESECONDARY - READVALUEPRIMARY) <= TOLERANCE)
		{
			AVGPEDALREAD = (READVALUEPRIMARY + READVALUESECONDARY) / 2;
			CONSISTENCY_FLAG = 1; // Values are consistent
			return CalculatePedalPercentage();
		}
	}
	CONSISTENCY_FLAG = 0; // Values are not consistent
	return CONSISTENCY_FLAG;
}

uint8_t CalculatePedalPercentage(void)
{
	if (AVGPEDALREAD >= MIN_ADC_VALUE && AVGPEDALREAD <= MAX_ADC_VALUE)
	{
		PEDALPERCENTAGE = ((AVGPEDALREAD - MIN_ADC_VALUE) * 100) / (MAX_ADC_VALUE - MIN_ADC_VALUE);
		PEDAL_OUT_OF_RANGE_FLAG = 0;	// Pedal percentage is in range

		return PEDAL_OUT_OF_RANGE_FLAG;
	}
	else
	{
		PEDALPERCENTAGE = 0;		 // Out of range
		PEDAL_OUT_OF_RANGE_FLAG = 1; // Pedal percentage is out of range
		return PEDAL_OUT_OF_RANGE_FLAG;
	}
}
