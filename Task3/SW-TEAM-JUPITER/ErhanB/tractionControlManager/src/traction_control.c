#include "../inc/traction_control_private.h"

/*
 * @brief Traction Control System constructor
 *
 * @param tcsHandle = TCS config structure 
 * */
void tcs_ctor(TractionControlHandle_t *tcsHandle)
{
    tcsHandle->acceleration = 0;
    tcsHandle->control_frequency_ms = TCS_CONTROL_FREQ;
    tcsHandle->current_torque = 0;
    tcsHandle->initStatus = TCS_DISABLED;
    RESET_SLIP(WHEEL_FRONT_LEFT);
    RESET_SLIP(WHEEL_FRONT_RIGHT);
    RESET_SLIP(WHEEL_REAR_LEFT);
    RESET_SLIP(WHEEL_REAR_RIGHT);
    tcsHandle->slip_threshold = TCS_SLIP_THRESHOLD;
    tcsHandle->slipper_wheel_count = 0;
    tcsHandle->status = TCS_STATUS_NORMAL;
    tcsHandle->torque_limit = TCS_MAX_TORQUE;
    tcsHandle->vehicle_speed = 0;
    RESET_WHEEL_SPEED(WHEEL_FRONT_LEFT);
    RESET_WHEEL_SPEED(WHEEL_FRONT_RIGHT);
    RESET_WHEEL_SPEED(WHEEL_REAR_LEFT);
    RESET_WHEEL_SPEED(WHEEL_REAR_RIGHT);
}

/*
 * @brief set car acceleration
 *
 * @param tcsHandle = TCS config structure 
 * @param accel = currently acceleration
 * */
static void set_acceleration(TractionControlHandle_t *tcsHandle, float accel)
{
    tcsHandle->acceleration = accel;
}

/*
 * @brief set car wheels speeds
 *
 * @param tcsHandle = TCS config structure 
 * @param speeds = currently wheel speeds
 * */
static void set_wheel_speeds(TractionControlHandle_t *tcsHandle, float *speeds)
{
    SET_WHEEL_SPEED(WHEEL_FRONT_LEFT, speeds[WHEEL_FRONT_LEFT]);
    SET_WHEEL_SPEED(WHEEL_FRONT_RIGHT, speeds[WHEEL_FRONT_RIGHT]);
    SET_WHEEL_SPEED(WHEEL_REAR_LEFT, speeds[WHEEL_REAR_LEFT]);
    SET_WHEEL_SPEED(WHEEL_REAR_RIGHT, speeds[WHEEL_REAR_RIGHT]);
}

/*
 * @brief set engine torque
 *
 * @param tcsHandle = TCS config structure 
 * @param torque = currently torque
 * */
static void set_engine_torque(TractionControlHandle_t *tcsHandle, float torque)
{
    tcsHandle->current_torque = torque;
}

/*
 * @brief set vehicle speed
 *
 * @param tcsHandle = TCS config structure 
 * @param speed = currently speed
 * */
static void set_vehicle_speed(TractionControlHandle_t *tcsHandle, float speed)
{
    tcsHandle->vehicle_speed = speed;
}

/*
 * @brief get wheel speed
 *
 * @param tcsHandle = TCS config structure 
 * @param wheelId = choosing front/rear and right/left wheel
 * */
static float get_wheel_speed(TractionControlHandle_t *tcsHandle, WheelId_t wheelId)
{
    return tcsHandle->wheel_speeds[wheelId];
}

/*
 * @brief get car acceleration
 *
 * @param tcsHandle = TCS config structure 
 * */
static float get_acceleration(TractionControlHandle_t *tcsHandle)
{
    return tcsHandle->acceleration;
}

/*
 * @brief calculating slip ratio
 *
 * @param tcsHandle = TCS config structure 
 * @param wheelId = choosing front/rear and right/left wheel
 * */
static float calculate_slip_ratio(TractionControlHandle_t *tcsHandle, WheelId_t wheel)
{
    float slip_ratio = ( (get_wheel_speed(tcsHandle, wheel) - tcsHandle->vehicle_speed) / tcsHandle->vehicle_speed );
    return slip_ratio;
}

/*
 * @brief calculating slip ratio totally
 *
 * @param tcsHandle = TCS config structure 
 * */
static void calculate_slip_ratios(TractionControlHandle_t *tcsHandle)
{
    tcsHandle->slip_ratios[WHEEL_FRONT_LEFT] = calculate_slip_ratio(tcsHandle, WHEEL_FRONT_LEFT);

    tcsHandle->slip_ratios[WHEEL_FRONT_RIGHT] = calculate_slip_ratio(tcsHandle, WHEEL_FRONT_RIGHT);

    tcsHandle->slip_ratios[WHEEL_REAR_LEFT] = calculate_slip_ratio(tcsHandle, WHEEL_REAR_LEFT);

    tcsHandle->slip_ratios[WHEEL_REAR_RIGHT] = calculate_slip_ratio(tcsHandle, WHEEL_REAR_RIGHT);
}

/*
 * @brief detecting car slip
 *
 * @param tcsHandle = TCS config structure 
 * */
static void detect_slip(TractionControlHandle_t *tcsHandle)
{
    calculate_slip_ratios(tcsHandle);
    for(int i=0;i<4;i++)
    {
        if(tcsHandle->slip_ratios[i] >= TCS_SLIP_THRESHOLD)
        {
            tcsHandle->status = TCS_STATUS_TRACTION_LOSS;
            tcsHandle->slipper_wheel_count++;
            printf("Vehicle experiencing loss of traction\n");
        }
        if(tcsHandle->slipper_wheel_count>1)
        {
            tcsHandle->status = TCS_STATUS_SLIP_DETECTED;
            printf("The vehicle is skidding\n");
            break;
        }
    }
}

/*
 * @brief enable car TCS
 *
 * @param tcsHandle = TCS config structure 
 * */
TcsInitStatus_t traction_enable(TractionControlHandle_t *tcsHandle)
{
    tcsHandle->initStatus = TCS_ENABLED;
    return TCS_ENABLED;
}   

/*
 * @brief disable car TCS
 *
 * @param tcsHandle = TCS config structure 
 * */
TcsInitStatus_t traction_disable(TractionControlHandle_t *tcsHandle)
{
    tcsHandle->initStatus = TCS_DISABLED;
    return TCS_DISABLED;
}

/*
 * @brief get car slip status
 *
 * @param tcsHandle = TCS config structure 
 * */
TcsStatus_t traction_get_status(TractionControlHandle_t *tcsHandle)
{
    return tcsHandle->status;
}

/*
 * @brief tcs initialization
 *
 * */
void tcs_init(TractionControlHandle_t *tcsHandle)
{
    tcs_ctor(tcsHandle);
    if(traction_enable(tcsHandle) == TCS_ENABLED)
    {
        printf("TCS Enabled\n");
    }
}

/*
 * @brief set car dynamically status 
 *
 * @param tcsHandle = TCS config structure 
 * */
void tcs_control(TractionControlHandle_t *tcsHandle)
{
    float accel = 2.3; /* sensor simulate */
    float v_speed = 20.0; /* sensor simulate */
    float w_speeds[] = {29.9, 20.1, 25.0, 19.8}; /* sensor simulate */
    float c_torque = 450.0; /* sensor simulate */
    set_engine_torque(tcsHandle, c_torque);
    set_vehicle_speed(tcsHandle, v_speed);
    set_wheel_speeds(tcsHandle, w_speeds);
    set_acceleration(tcsHandle, accel);
    detect_slip(tcsHandle);
}



