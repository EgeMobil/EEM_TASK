//brakecontrol
#include "brake_control_public.h"
#include "brake_control_private.h"
#include "definition.h"
#include "abs_algorithm.h"

static BrakeStatus last_status = BRAKE_OK;
static float last_applied_pressure = 0.0f;

BrakeStatus Brake_Apply(void) {
    // Check system status
    if (!is_brake_system_ready()) {
        last_status = BRAKE_ERROR;
        return BRAKE_ERROR;
    }

    if (check_abs_status()) {
        abs_intervention();
        last_status = BRAKE_ABS_ACTIVE;
        return BRAKE_ABS_ACTIVE;
    }

    update_brake_pressure(MAX_PRESSURE);
    last_applied_pressure = MAX_PRESSURE;
    monitor_wheel_speeds();
    
    last_status = BRAKE_OK;
    return BRAKE_OK;
}


BrakeStatus Brake_Release(void) {
    if (!is_brake_system_ready()) {
        last_status = BRAKE_ERROR;
        return BRAKE_ERROR;
    }

    // Gradual release to prevent sudden changes
    float current_pressure = get_brake_pressure();
    while (current_pressure > MIN_PRESSURE) {
        current_pressure -= BRAKE_RELEASE_RATE;
        if (current_pressure < MIN_PRESSURE) {
            current_pressure = MIN_PRESSURE;
        }
       update_brake_pressure(current_pressure);
    }
    last_applied_pressure = MIN_PRESSURE;
    last_status = BRAKE_OK;
    return BRAKE_OK;
}


BrakeStatus Brake_SetPressure(float pressure) {
    // Validate input pressure
    if (!is_brake_system_ready()) {
        last_status = BRAKE_ERROR;
        return BRAKE_ERROR;
    }
    if (pressure < 0.0f) {
        last_status = BRAKE_INVALID_PARAM;
        return BRAKE_INVALID_PARAM;
    }
    // Clamp pressure within valid range
    float validated_pressure = pressure;
    if (validated_pressure < MIN_PRESSURE) {
        validated_pressure = MIN_PRESSURE;
    } else if (validated_pressure > MAX_PRESSURE) {
        validated_pressure = MAX_PRESSURE;
    }

    // Apply pressure with ABS check
    if (check_abs_status()) {
        abs_intervention();
        last_status = BRAKE_ABS_ACTIVE;
        return BRAKE_ABS_ACTIVE;
    }

    update_brake_pressure(validated_pressure);
    last_applied_pressure = validated_pressure;
    monitor_wheel_speeds();

    last_status = BRAKE_OK;
    return BRAKE_OK;
}