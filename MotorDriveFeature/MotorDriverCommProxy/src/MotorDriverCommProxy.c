#include "MotorDriverCommProxy_private.h"

/* Instance definition */
static dtMotorDriverCommProxy instance;

/* Getter/Setter Implementation */

/* IBdr Getter and Setter */
static void MotorDriverCommProxy_setIBdr_Impl(dtMotorDriverCommProxy_indicatorBdrStatus status)
{
    instance.iBdr = status;
}

static dtMotorDriverCommProxy_indicatorBdrStatus MotorDriverCommProxy_getIBdr_Impl(void)
{
    return instance.iBdr;
}

/* ISpeed Getter and Setter */
static void MotorDriverCommProxy_setISpeed_Impl(dtMotorDriverCommProxy_indicatorSpeedStatus status)
{
    instance.iSpeed = status;
}

static dtMotorDriverCommProxy_indicatorSpeedStatus MotorDriverCommProxy_getISpeed_Impl(void)
{
    return instance.iSpeed;
}

/* HWheelSpeed Getter and Setter */
static void MotorDriverCommProxy_setHWheelSpeed_Impl(dtMotorDriverCommProxy_HALLWheelSpeed speed)
{
    instance.hWheelSpeed = speed;
}

static dtMotorDriverCommProxy_HALLWheelSpeed MotorDriverCommProxy_getHWheelSpeed_Impl(void)
{
    return instance.hWheelSpeed;
}

/* Indicator Getter and Setter */
static void MotorDriverCommProxy_setIndicator_Impl(dtMotorDriverCommProxy_indicator indicator)
{
    instance.indicator = indicator;
}

static dtMotorDriverCommProxy_indicator MotorDriverCommProxy_getIndicator_Impl(void)
{
    return instance.indicator;
}

/* WheelSpeed Getter and Setter */
static void MotorDriverCommProxy_setWheelSpeed_Impl(dtMotorDriverCommProxy_wheelSpeed speed)
{
    instance.wheelSpeed = speed;
}

static dtMotorDriverCommProxy_wheelSpeed MotorDriverCommProxy_getWheelSpeed_Impl(void)
{
    return instance.wheelSpeed;
}

/* toString Implementation */
static char* MotorDriverCommProxy_toString_Impl(void)
{
    char* output = (char*)malloc(512); // Yeterli bir buffer boyutu
    if (output == NULL)
    {
        return strdup("Memory allocation failed.");
    }

    snprintf(output, 512,
             "[MotorDriverCommProxy Registers]:\n"
             "IBdr Brake: %d\n"
             "IBdr Direction: %d\n"
             "ISpeed: %d\n"
             "HWheelSpeed: %d\n"
             "Indicator: %d\n"
             "WheelSpeed: %d\n",
             instance.iBdr.brakeStatus,
             instance.iBdr.directionStatus,
             instance.iSpeed,
             instance.hWheelSpeed,
             instance.indicator,
             instance.wheelSpeed);

    return output;
}

/* Constructor Implementation */
void MotorDriverCommProxy_CTOR(void)
{
    /* Initialize the Interface Pointers */
    instance.IIndicatorBdrStatus = &IndicatorBdrStatusInterface;
    instance.IIndicatorSpeedStatus = &IndicatorSpeedStatusInterface;
    instance.IHALLWheelSpeed = &HALLWheelSpeedInterface;
    instance.IIndicator = &IndicatorInterface;
    instance.IWheelSpeed = &WheelSpeedInterface;

    /* Initialize Function Pointers */
    instance.getIBdr = MotorDriverCommProxy_getIBdr_Impl;
    instance.setIBdr = MotorDriverCommProxy_setIBdr_Impl;

    instance.getISpeed = MotorDriverCommProxy_getISpeed_Impl;
    instance.setISpeed = MotorDriverCommProxy_setISpeed_Impl;

    instance.getHWheelSpeed = MotorDriverCommProxy_getHWheelSpeed_Impl;
    instance.setHWheelSpeed = MotorDriverCommProxy_setHWheelSpeed_Impl;

    instance.getIndicator = MotorDriverCommProxy_getIndicator_Impl;
    instance.setIndicator = MotorDriverCommProxy_setIndicator_Impl;

    instance.getWheelSpeed = MotorDriverCommProxy_getWheelSpeed_Impl;
    instance.setWheelSpeed = MotorDriverCommProxy_setWheelSpeed_Impl;

    instance.toString = MotorDriverCommProxy_toString_Impl;

    /* Initialize Attributes to Default Values */
    instance.iBdr.byte = 0;
    instance.iSpeed = 0;
    instance.hWheelSpeed = 0;
    instance.indicator = 0;
    instance.wheelSpeed = 0;
}

/* Singleton Instance Getter */
dtMotorDriverCommProxy* MotorDriverCommProxy_GetInstance(void)
{
    return &instance;
}

/* Functional Behaviour Implementation */
/* Burada işlevsel metodlar eklenebilir */
