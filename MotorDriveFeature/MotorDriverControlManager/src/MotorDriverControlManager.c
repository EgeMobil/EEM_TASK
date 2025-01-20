#include "MotorDriverControlManager_private.h"

/* Instance definition */
static dtMotorDriverControlManager instance;

/* Getter Setter Implementation */

/* Speed Getter and Setter */
static void MotorDriverControlManager_setSpeed_Impl(dtMotorDriverControlManager_Speed speed)
{
    instance.speed = speed;
}

static dtMotorDriverControlManager_Speed MotorDriverControlManager_getSpeed_Impl(void)
{
    return instance.speed;
}

/* Bdr Getter and Setter */
static void MotorDriverControlManager_setBdr_Impl(dtMotorDriverControlManager_Bdr bdr)
{
    instance.bdr = bdr;
}

static dtMotorDriverControlManager_Bdr MotorDriverControlManager_getBdr_Impl(void)
{
    return instance.bdr;
}

/* RawSpeedStatus Getter and Setter */
static void MotorDriverControlManager_setRawSpeedStatus_Impl(dtMotorDriverControlManager_RawSpeedStatus status)
{
    instance.rawSpeedStatus = status;
}

static dtMotorDriverControlManager_RawSpeedStatus MotorDriverControlManager_getRawSpeedStatus_Impl(void)
{
    return instance.rawSpeedStatus;
}

/* BrakeStatus Getter and Setter */
static void MotorDriverControlManager_setBrakeStatus_Impl(dtMotorDriverControlManager_BrakeStatus status)
{
    instance.brakeStatus = status;
}

static dtMotorDriverControlManager_BrakeStatus MotorDriverControlManager_getBrakeStatus_Impl(void)
{
    return instance.brakeStatus;
}

/* DirectionStatus Getter and Setter */
static void MotorDriverControlManager_setDirectionStatus_Impl(dtMotorDriverControlManager_DirectionStatus status)
{
    instance.directionStatus = status;
}

static dtMotorDriverControlManager_DirectionStatus MotorDriverControlManager_getDirectionStatus_Impl(void)
{
    return instance.directionStatus;
}

/* toString Implementation */
static char* MotorDriverControlManager_toString_Impl(void)
{
    char* output = (char*)malloc(512); // Yeterli bir buffer boyutu
    if (output == NULL)
    {
        return strdup("Memory allocation failed.");
    }

    snprintf(output, 512,
             "[MotorDriverControlManager Registers]:\n"
             "Speed: %d\n"
             "Bdr: %d\n"
             "RawSpeedStatus: %d\n"
             "BrakeStatus: %d\n"
             "DirectionStatus: %d\n",
             instance.speed,
             instance.bdr,
             instance.rawSpeedStatus,
             instance.brakeStatus,
             instance.directionStatus);

    return output;
}

/* Constructor Implementation */
void MotorDriverControlManager_CTOR(void)
{
    /* Initialize the Interface Pointers */
    instance.ISpeed = &SpeedInterface;
    instance.IBdr = &BdrInterface;
    instance.IRawSpeed = &RawSpeedInterface;
    instance.IBrakeAndDirection = &BrakeAndDirectionInterface;

    /* Initialize Function Pointers */
    instance.getSpeed = MotorDriverControlManager_getSpeed_Impl;
    instance.setSpeed = MotorDriverControlManager_setSpeed_Impl;

    instance.getBdr = MotorDriverControlManager_getBdr_Impl;
    instance.setBdr = MotorDriverControlManager_setBdr_Impl;

    instance.getRawSpeedStatus = MotorDriverControlManager_getRawSpeedStatus_Impl;
    instance.setRawSpeedStatus = MotorDriverControlManager_setRawSpeedStatus_Impl;

    instance.getBrakeStatus = MotorDriverControlManager_getBrakeStatus_Impl;
    instance.setBrakeStatus = MotorDriverControlManager_setBrakeStatus_Impl;

    instance.getDirectionStatus = MotorDriverControlManager_getDirectionStatus_Impl;
    instance.setDirectionStatus = MotorDriverControlManager_setDirectionStatus_Impl;

    instance.toString = MotorDriverControlManager_toString_Impl;

    /* Initialize Attributes to Default Values */
    instance.speed = 0;
    instance.bdr = 0;
    instance.rawSpeedStatus = 0;
    instance.brakeStatus = 0;
    instance.directionStatus = 0;
}

/* Singleton Instance Getter */
dtMotorDriverControlManager* MotorDriverControlManager_GetInstance(void)
{
    return &instance;
}
