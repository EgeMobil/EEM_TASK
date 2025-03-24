#include "abs_algorithm.h" 
#include "brake_control_private.h" 

//wheel slip hesaplaması 
float calculate_wheel_slip(void) {
     float vehicle_speed = get_vehicle_speed(); 
     float wheel_speed = get_wheel_speed(); 

     if(vehicle_speed < 0.1f) {
        return 0.0f;
     }

     float slip  = (vehicle_speed - wheel_speed) / vehicle_speed; 

     if(slip < 0.0f) slip = 0.0f; 
    if(slip > 1.0f) slip = 1.0f;
     
    return slip; 
}

//ABS müdahalesini başlat 
void abs_intervention(void) {
     float slip = calculate_wheel_slip(); 
     if(slip > ABS_THRESHOLD) {
        abs_active = true; 
        adjust_brake_force_for_abs(slip); 
     } else {
        abs_active = false; 
     }
}

void adjust_brake_force_for_abs(float slip) {
    //ABS aktifse fren gücünü kısıtla veya ayarla
    if(abs_active) {
    float brake_reduction; 

    if(slip> CRITICAL_SLIP_THRESHOLD) {
        brake_reduction = MAX_BRAKE_REDUCTION; 
    } else { 
        brake_reduction = (slip - ABS_THRESHOLD) / (CRITICAL_SLIP_THRESHOLD - ABS_THRESHOLD) * 
        MAX_BRAKE_REDUCTION;
    }

    float current_brake_force = get_brake_force(); 
    float adjusted_force = current_brake_force * (1.0f - brake_reduction);
        set_brake_force(adjusted_force);

    }
}