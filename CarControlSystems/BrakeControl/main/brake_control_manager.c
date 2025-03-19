#include "brake_control_public.h"
#include "brake_control_private.h"
#include "abs_algorithm.h" 
#include "definition.h" 

//fren yap
BrakeStatus brake_apply(void) { 
    if(!is_brake_system_ready()) {
        return BRAKE_ERROR; 
    }
    bool abs_needed = check_abs_status(); 
    if(abs_needed) {
        abs_intervention(); 
        return BRAKE_ABS_ACTIVE; 
    }
    update_brake_pressure(MAX_PRESSURE); 
    return BRAKE_OK;


}

//freni serbest bırak
BrakeStatus brake_release(void) {
    float current_pressure = get_brake_pressure(); 

    while (current_pressure > MIN_PRESSURE) {
        current_pressure -= ABS_DECREASE_RATE;
        if (current_pressure < MIN_PRESSURE) {
            current_pressure = MIN_PRESSURE;
        }
        update_brake_pressure(current_pressure);
        system_delay(BRAKE_CONTROL_DELAY_MS);
    }
    
    return BRAKE_OK;

}

//fren basınç ayarı 
BrakeStatus brake_set_pressure(int pressure) {
    if (pressure < MIN_PRESSURE || pressure > MAX_PRESSURE) {
        return BRAKE_INVALID_PARAM;
    }

    // Check system status
    if (!is_brake_system_ready()) {
        return BRAKE_ERROR;
    }

    // Check if ABS should intervene
    if (check_abs_status()) {
        abs_intervention();
        return BRAKE_ABS_ACTIVE;
    }

    update_brake_pressure(pressure);
    return BRAKE_OK;
}