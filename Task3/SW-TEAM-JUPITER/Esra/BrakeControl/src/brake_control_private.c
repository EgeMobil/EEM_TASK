#include "brake_control_private.h" 
#include "abs_algorithm.h" 
#include <math.h>

static int current_brake_pressure = MIN_PRESSURE; //mevcut fren basıncı
 bool abs_active = false; //ABS aktif mi? 
static float wheel_speeds[4] = {0.0f}; //tekerlek hızları 
static float vehicle_speed = 0.0;
//fren basıncı güncelleme 
void update_brake_pressure(int pressure) {
    if(pressure < MIN_PRESSURE) {
        pressure = MIN_PRESSURE; 
    } else if(pressure > MAX_PRESSURE) {
        pressure = MAX_PRESSURE; 
    }
    
    float brake_force = calculate_brake_force(pressure); 
    current_brake_pressure = (int)brake_force; 

    set_hardware_brake_pressure(current_brake_pressure); 
}

float calculate_brake_force(float pressure) {
    if(vehicle_speed > 50.0f) {
        return pressure * 1.5f; 
    } else {
        return pressure;
    }
}
float get_brake_pressure(void) {
    return (float)current_brake_pressure;
}

//ABS durumunu kontrol et 

 bool check_abs_status(void) {
   // float vehicle_speed = get_vehicle_speed(); 
    if(vehicle_speed < MIN_ABS_SPEED) {
        abs_active = false; 
        return false; 
    }

    float avg_wheel_speed = 0.0f;
    for (int i = 0; i < 4; i++) {
        avg_wheel_speed += wheel_speeds[i];
    }
    avg_wheel_speed /= 4.0f;

    float slip = (vehicle_speed - avg_wheel_speed) / vehicle_speed;
    if (slip > ABS_THRESHOLD) {
        abs_active = true;
        return true;
    }

    return abs_active;
}

//tekerlek hızlarını kontrol et 
//bu algoritmaya tekrar bakılabilir 
void monitor_wheel_speeds(void) {
    for(int i = 0; i < 4; i++) {
        float sensor_speed = read_wheel_speed_sensor(i); 

        if(sensor_speed >= MIN_WHEEL_SPEED && 
        sensor_speed <= MAX_WHEEL_SPEED) {
            wheel_speeds[i] = sensor_speed; 
        }
    }
   float sum_speeds = 0.0f; 
   for(int i = 0; i < 4; i++) {
    sum_speeds += wheel_speeds[i]; 
   }
   vehicle_speed = sum_speeds / 4.0f;
}

float get_wheel_speed_by_index(int wheel_index) {
    if(wheel_index >= 0 && wheel_index < 4) {
        return wheel_speeds[wheel_index]; 
    }
    return 0.0f; 
}