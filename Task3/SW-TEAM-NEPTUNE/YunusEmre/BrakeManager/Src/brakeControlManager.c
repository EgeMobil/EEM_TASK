#include "Inc/brakeControlManager_private.h"

static BrakeControlManager_t instance;

static void brakeControlManager_setBrakePressure(uint16_t pressureValue);
static uint16_t brakeControlManager_getBrakePressure(void);
static breakStatus_e brakeControlManager_getBrakeStatus(void);
static breakAbsStatus_e brakeControlManager_getbBrakeAbsStatus(void);
static char* brakeControlManager_toString_Impl(void);

/**
 * @brief Constructor for brakeControlManager.
 *
 * This function initializes the instance of brakeControlManager by setting function pointers
 * and default values for the attributes.
 */
void brakeControlManager_CTOR(void)
{ 
    instance.maxBrakePressure       = MAX_BRAKE_PRESSURE;
    instance.brakeAbsLimitPressure  = ABS_BRAKE_TRESHOLD_PRESSURE;
    instance.brakeStatus            = BRAKE_NOT_PRESSED;
    instance.brakeAbsStatus         = BRAKE_ABS_NOT_ACTIVATED;
    instance.brakePressure          = 0;
    instance.setBrakePressure       = brakeControlManager_setBrakePressure;
    instance.getBrakePressure       = brakeControlManager_getBrakePressure;
    instance.getBrakeStatus         = brakeControlManager_getBrakeStatus;
    instance.getbBrakeAbsStatus     = brakeControlManager_getbBrakeAbsStatus;
    instance.toString               = brakeControlManager_toString_Impl;
}

/**
 * @brief Gets the singleton instance of brakeControlManager.
 *
 * This function returns the pointer to the singleton instance of the brakeControlManager.
 *
 * @return Pointer to the singleton instance of brakeControlManager.
 */
BrakeControlManager_t* brakeControlManager_GetInstance(void)
{
    static uint8_t isInitialized = 0;
    if (!isInitialized) {
        brakeControlManager_CTOR();
        isInitialized = 1;
    }
    return &instance;
}

/**
 * @brief Converts the brakeControlManager instance to a string representation.
 *
 * This function creates a string representation of the brakeControlManager instance's current state.
 *
 * @return A string representation of the brakeControlManager instance.
 */
static char* brakeControlManager_toString_Impl(void)
{
    char* output = (char*)malloc(512); // Yeterli bir buffer boyutu
    if (output == NULL)
    {
        return strdup("Memory allocation failed.");
    }

    snprintf(output, 512,
             "[brakeControlManager Registers]:\n"
             "brake Pressure: %d\n"     // 1-100 unit
             "brake Status: %d\n"       // Pressed or not Pressed
             "brake ABS status: %d\n",   // ABS activated or not
             instance.brakePressure,
             instance.brakeStatus,
             instance.brakeAbsStatus);

    return output;
}
static void brakeControlManager_setBrakePressure(uint16_t pressureValue)
{
    if( pressureValue <= instance.maxBrakePressure)
    {
        instance.brakePressure  = pressureValue;
        instance.brakeStatus    = BRAKE_PRESSED;
    }
    else if(pressureValue == 0)
    {
        instance.brakePressure  = pressureValue;
        instance.brakeStatus    = BRAKE_NOT_PRESSED;
    }
    else
    {
        //Nop
    }

    if(pressureValue >= instance.brakeAbsLimitPressure)
    {
        instance.brakeAbsStatus = BRAKE_ABS_ACTIVATED;
    }
    else
    {
        instance.brakeAbsStatus = BRAKE_ABS_NOT_ACTIVATED;
    }

}

static uint16_t brakeControlManager_getBrakePressure(void)
{
    return instance.brakePressure;
}

static breakStatus_e brakeControlManager_getBrakeStatus(void)
{
    return instance.brakeStatus;
}

static breakAbsStatus_e brakeControlManager_getbBrakeAbsStatus(void)
{
    return instance.brakeAbsStatus;
}
