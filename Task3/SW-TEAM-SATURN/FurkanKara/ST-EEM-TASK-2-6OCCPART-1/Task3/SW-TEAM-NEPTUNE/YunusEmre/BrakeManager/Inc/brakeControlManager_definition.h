#ifndef BRAKECONTROLMANAGER_DEFINITION_H
#define BRAKECONTROLMANAGER_DEFINITION_H

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"

#define MAX_BRAKE_PRESSURE              100 //100 unit
#define ABS_BRAKE_TRESHOLD_PRESSURE     80 //100 unit

/**
 * @brief Enum for Brake Status return values.
 */
typedef enum
{
    BRAKE_NOT_PRESSED = 0,
    BRAKE_PRESSED,
} breakStatus_e;

/**
 * @brief Enum for Brake ABS Status return values.
 */
typedef enum
{
    BRAKE_ABS_NOT_ACTIVATED = 0,
    BRAKE_ABS_ACTIVATED,
} breakAbsStatus_e;

typedef struct
{
    /* Attributes */
    uint16_t  maxBrakePressure;
    uint16_t  brakeAbsLimitPressure;
    uint16_t        brakePressure;
    breakStatus_e   brakeStatus;
    breakAbsStatus_e  brakeAbsStatus;

    /* Getter/Setter Function Pointers */
    void (*setBrakePressure)(uint16_t pressureValue);
    uint16_t (*getBrakePressure)(void);
    breakStatus_e (*getBrakeStatus)(void);
    breakAbsStatus_e (*getbBrakeAbsStatus)(void);

    /* toString Function Pointer */
    char* (*toString)(void); /**< Function to convert the structure to a string representation */

}BrakeControlManager_t;

#endif // BRAKECONTROLMANAGER_DEFINITION_H



