#ifndef DEFINITION_H 
#define DEFINITION_H  

//fren basınç limitleri 
#define MIN_PRESSURE 0.0f
#define MAX_PRESSURE 100.0f
#define MAX_PRESSURE_CHANGE_RATE   20.0f  // bar/second
#define BRAKE_CONTROL_DELAY_MS     10

#define ABS_THRESHOLD 0.2f
#define CRITICAL_SLIP 0.3f
#define ABS_DECREASE_RATE 10.0f //abs fren basıncı azaltma oranı 
#define ABS_INCREASE_RATE 5.0f
//tekerlek hızları ve sensör parametreleri 

#define MIN_WHEEL_SPEED 2.0f 
#define MAX_WHEEL_SPEED 250.0f 
#define WHEEL_SENSOR_RATE 100.0f 

#define MIN_ABS_SPEED 5.0f 
#define MAX_BRAKE_TEMP 150.0f 

#define BRAKE_RELEASE_RATE    5.0f 



#endif 