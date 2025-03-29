#ifndef DEFINITION_H_
#define DEFINITION_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*!> slip ratio threshold (as percentage, in float) */
#define TCS_SLIP_THRESHOLD      (0.2f)

/*!> control frequency (in ms) */
#define TCS_CONTROL_FREQ        (10u)

/*!> min wheel speed for TCS enabled (in float) */
#define TCS_WHEEL_MIN_SPEED     (1.4f)

/*!> max torque (in float) */
#define TCS_MAX_TORQUE          (500.0f)

typedef enum
{
    WHEEL_FRONT_LEFT = 0,
    WHEEL_FRONT_RIGHT,
    WHEEL_REAR_LEFT,
    WHEEL_REAR_RIGHT
} WheelId_t;

typedef enum
{
    TCS_STATUS_NORMAL = 0,
    TCS_STATUS_SLIP_DETECTED,
    TCS_STATUS_TRACTION_LOSS
} TcsStatus_t;

typedef enum
{
    TCS_ERROR = 0,
    TCS_DISABLED,
    TCS_ENABLED
} TcsInitStatus_t;

typedef struct 
{
    TcsInitStatus_t initStatus;
    TcsStatus_t status;
    float wheel_speeds[4];
    float vehicle_speed;
    float acceleration;
    float slip_ratios[4];
    float slip_threshold;
    float control_frequency_ms;
    float torque_limit;
    float current_torque;
    uint8_t slipper_wheel_count;
} TractionControlHandle_t;



#endif