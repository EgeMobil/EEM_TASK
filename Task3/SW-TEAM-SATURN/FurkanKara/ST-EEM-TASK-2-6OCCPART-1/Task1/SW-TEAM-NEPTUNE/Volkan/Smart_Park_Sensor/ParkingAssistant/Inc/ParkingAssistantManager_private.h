#ifndef PARKING_SENSOR_MANAGER_PRIVATE_H_
#define PARKING_SENSOR_MANAGER_PRIVATE_H_

#include "ParkingAssistantManager_def.h"

float CalculationDistance(GPIO_TypeDef ECHO_PIN, GPIO_TypeDef TRIG_PIN);

sensor_return_t CheckRangeDistance (float);

parking_assistanst_prosses_t UpdateAndVerifyDistanceWithFrontSensors(void);
parking_assistanst_prosses_t UpdateAndVerifyDistanceWithRearSensors(void);

parking_asistant_t CheckInformationForProsses(void);

extern parking_asistant_t ParkingAssistantManager ;

void SetSoundLevel(void);
void SetSoundPeriod(void);
void SetImage(void);
void SetSensorError(void);

#endif /* PARKING_SENSOR_MANAGER_PRIVATE_H_*/