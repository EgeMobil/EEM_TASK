#ifndef PARKING_SENSOR_MANAGER_PUBLIC_H_
#define PARKING_SENSOR_MANAGER_PUBLIC_H_

#include "ParkingAssistantManager_def.h"


void ParkingAssistans_Init(void);
void ParkingAssistant_Prosses(void);
void ParkingAssistant_Calculation_Verify(void);
void ParkingAssistant_Front_Control(void);
void ParkingAssistant_Rear_Control(void);
void ParkingAssistant_UpdateSoundAndImage(void);


#endif /* PARKING_SENSOR_MANAGER_PUBLIC_H_*/