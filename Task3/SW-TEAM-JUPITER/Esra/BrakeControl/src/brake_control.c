//fren API'leri 

#include "brake_control_private.h" 
#include "brake_control_public.h"
#include "abs_algorithm.h" 
#include "definition.h"


//fren basıncı uygula
BrakeStatus apply_brake(void) {
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


//fren serbest bırak 
BrakeStatus release_brake(void) {
    if (!is_brake_system_ready()) {
        return BRAKE_ERROR;
    }
    float current_pressure = get_brake_pressure();
    
    // Gradually decrease brake pressure
    while (current_pressure > MIN_PRESSURE) {
        current_pressure -= BRAKE_RELEASE_RATE;
        if (current_pressure < MIN_PRESSURE) {
            current_pressure = MIN_PRESSURE;
        }
        update_brake_pressure(current_pressure);
        system_delay(BRAKE_CONTROL_DELAY_MS);
    }
    
    return BRAKE_OK;
}

void update_brake_pressure(int pressure) {
    if (pressure < MIN_PRESSURE) {
        pressure = MIN_PRESSURE;
    } else if (pressure > MAX_PRESSURE) {
        pressure = MAX_PRESSURE;
    }

    // Update hardware brake pressure
    set_hardware_brake_pressure(pressure);
    
    // Monitor system after pressure change
    monitor_wheel_speeds();
}

//ABS algoritması
void abs_interention(void) {
    float slip = calculate_wheel_slip();
    
    if (slip > ABS_THRESHOLD) {
        adjust_brake_force_for_abs(slip);
    }
    
    monitor_wheel_speeds();
}