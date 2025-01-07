#include "InterruptHandlerManager_private.h"

/**
 * @brief Interrupt Handler Manager Instance.
 * 
 * A static instance of the `dtInterruptHandlerManager` structure that holds the 
 * current state and configuration of the Interrupt Handler Manager.
 */
static dtInterruptHandlerManager instance;

/* Getter/Setter Implementation */

/* ihmExternalIrqConfiguration: Getter/Setter Implementations */

/**
 * @brief Sets the port configuration for the external IRQ.
 * 
 * @param port Port configuration to set.
 */
void setExternalIrqPort_Impl(dtInterruptHandlerManager_portName port)
{
    instance.externalIrq.port = port;
}

/**
 * @brief Sets the pin configuration for the external IRQ.
 * 
 * @param pin Pin configuration to set.
 */
void setExternalIrqPin_Impl(dtInterruptHandlerManager_pinName pin)
{
    instance.externalIrq.pin = pin;
}

/**
 * @brief Sets the trigger type configuration for the external IRQ.
 * 
 * @param trigger Trigger type configuration to set.
 */
void setExternalIrqTrigger_Impl(dtInterruptHandlerManager_triggerType trigger)
{
    instance.externalIrq.trigger = trigger;
}

/**
 * @brief Gets the current port configuration for the external IRQ.
 * 
 * @return The current port configuration.
 */
dtInterruptHandlerManager_portName getExternalIrqPort_Impl(void)
{
    return instance.externalIrq.port;
}

/**
 * @brief Gets the current pin configuration for the external IRQ.
 * 
 * @return The current pin configuration.
 */
dtInterruptHandlerManager_pinName getExternalIrqPin_Impl(void)
{
    return instance.externalIrq.pin;
}

/**
 * @brief Gets the current trigger type configuration for the external IRQ.
 * 
 * @return The current trigger type configuration.
 */
dtInterruptHandlerManager_triggerType getExternalIrqTrigger_Impl(void)
{
    return instance.externalIrq.trigger;
}


/* ihmTimerIrqConfiguration: Getter/Setter Implementations */

/**
 * @brief Sets the millisecond configuration for the timer IRQ.
 * 
 * @param ms Millisecond configuration to set.
 */
void setTimerIrqMillisecond_Impl(dtInterruptHandlerManager_millisecond ms)
{
    instance.timerIrq.ms = ms;
}

/**
 * @brief Sets the second configuration for the timer IRQ.
 * 
 * @param sec Second configuration to set.
 */
void setTimerIrqSecond_Impl(dtInterruptHandlerManager_second sec)
{
    instance.timerIrq.sec = sec;
}

/**
 * @brief Sets the minute configuration for the timer IRQ.
 * 
 * @param min Minute configuration to set.
 */
void setTimerIrqMinute_Impl(dtInterruptHandlerManager_minute min)
{
    instance.timerIrq.min = min;
}

/**
 * @brief Sets the hour configuration for the timer IRQ.
 * 
 * @param hour Hour configuration to set.
 */
void setTimerIrqHour_Impl(dtInterruptHandlerManager_hour hour)
{
    instance.timerIrq.hour = hour;
}

/**
 * @brief Sets the day configuration for the timer IRQ.
 * 
 * @param day Day configuration to set.
 */
void setTimerIrqDay_Impl(dtInterruptHandlerManager_day day)
{
    instance.timerIrq.day = day;
}

/**
 * @brief Gets the current millisecond configuration for the timer IRQ.
 * 
 * @return The current millisecond configuration.
 */
dtInterruptHandlerManager_millisecond getTimerIrqMillisecond_Impl(void)
{
    return instance.timerIrq.ms;
}

/**
 * @brief Gets the current second configuration for the timer IRQ.
 * 
 * @return The current second configuration.
 */
dtInterruptHandlerManager_second getTimerIrqSecond_Impl(void)
{
    return instance.timerIrq.sec;
}

/**
 * @brief Gets the current minute configuration for the timer IRQ.
 * 
 * @return The current minute configuration.
 */
dtInterruptHandlerManager_minute getTimerIrqMinute_Impl(void)
{
    return instance.timerIrq.min;
}

/**
 * @brief Gets the current hour configuration for the timer IRQ.
 * 
 * @return The current hour configuration.
 */
dtInterruptHandlerManager_hour getTimerIrqHour_Impl(void)
{
    return instance.timerIrq.hour;
}

/**
 * @brief Gets the current day configuration for the timer IRQ.
 * 
 * @return The current day configuration.
 */
dtInterruptHandlerManager_day getTimerIrqDay_Impl(void)
{
    return instance.timerIrq.day;
}


/**
 * @brief Sets the state status for Hall A.
 * 
 * @param state State status to set for Hall A.
 */
void setHallAState_Impl(dtInterruptHandlerManager_HallAStateStatus state)
{
    instance.HALL.halla_state = state;
}

/**
 * @brief Sets the state status for Hall B.
 * 
 * @param state State status to set for Hall B.
 */
void setHallBState_Impl(dtInterruptHandlerManager_HallBStateStatus state)
{
    instance.HALL.hallb_state = state;
}

/**
 * @brief Sets the state status for Hall C.
 * 
 * @param state State status to set for Hall C.
 */
void setHallCState_Impl(dtInterruptHandlerManager_HallCStateStatus state)
{
    instance.HALL.hallc_state = state;
}

/**
 * @brief Gets the current state status for Hall A.
 * 
 * @return The current state status for Hall A.
 */
dtInterruptHandlerManager_HallAStateStatus getHallAState_Impl(void)
{
    return instance.HALL.halla_state;
}

/**
 * @brief Gets the current state status for Hall B.
 * 
 * @return The current state status for Hall B.
 */
dtInterruptHandlerManager_HallBStateStatus getHallBState_Impl(void)
{
    return instance.HALL.hallb_state;
}

/**
 * @brief Gets the current state status for Hall C.
 * 
 * @return The current state status for Hall C.
 */
dtInterruptHandlerManager_HallCStateStatus getHallCState_Impl(void)
{
    return instance.HALL.hallc_state;
}

/**
 * @brief Gets the current external IRQ configuration.
 * 
 * @return The current configuration of type `ihmExternalIrqConfiguration`.
 */
ihmExternalIrqConfiguration getExternalIrq_Impl(void)
{
    return instance.externalIrq;
}

/**
 * @brief Sets the external IRQ configuration.
 * 
 * @param config The external IRQ configuration to set.
 */
void setExternalIrq_Impl(ihmExternalIrqConfiguration config)
{
    instance.externalIrq = config;
}

/**
 * @brief Gets the current timer IRQ configuration.
 * 
 * @return The current configuration of type `ihmTimerIrqConfiguration`.
 */
ihmTimerIrqConfiguration getTimerIrq_Impl(void)
{
    return instance.timerIrq;
}

/**
 * @brief Sets the timer IRQ configuration.
 * 
 * @param config The timer IRQ configuration to set.
 */
void setTimerIrq_Impl(ihmTimerIrqConfiguration config)
{
    instance.timerIrq = config;
}

/**
 * @brief Gets the current HALL configuration.
 * 
 * @return The current configuration of type `ihmHALLConfiguration`.
 */
ihmHALLConfiguration getHALL_Impl(void)
{
    return instance.HALL;
}

/**
 * @brief Sets the HALL configuration.
 * 
 * @param config The HALL configuration to set.
 */
void setHALL_Impl(ihmHALLConfiguration config)
{
    instance.HALL = config;
}


/* toString() Implementation */

/**
 * @brief Converts the cmPortName enum value to a string.
 * 
 * @param value The cmPortName value to convert.
 * @return A string representation of the cmPortName value.
 */
const char* getStringFromPortName(cmPortName value)
{
    switch (value)
    {
        case PORTNAME_GPIOA: return "GPIOA";
        case PORTNAME_GPIOB: return "GPIOB";
        case PORTNAME_GPIOC: return "GPIOC";
        case PORTNAME_GPIOD: return "GPIOD";
        case PORTNAME_GPIOE: return "GPIOE";
        case PORTNAME_NULL: return "NULL";
        default: return "UNKNOWN_PORT";
    }
}

/**
 * @brief Converts the cmPinName enum value to a string.
 * 
 * @param value The cmPinName value to convert.
 * @return A string representation of the cmPinName value.
 */
const char* getStringFromPinName(cmPinName value)
{
    switch (value)
    {
        case PINNAME_0: return "PIN_0";
        case PINNAME_1: return "PIN_1";
        case PINNAME_2: return "PIN_2";
        case PINNAME_3: return "PIN_3";
        case PINNAME_4: return "PIN_4";
        case PINNAME_5: return "PIN_5";
        case PINNAME_6: return "PIN_6";
        case PINNAME_7: return "PIN_7";
        case PINNAME_8: return "PIN_8";
        case PINNAME_9: return "PIN_9";
        case PINNAME_10: return "PIN_10";
        case PINNAME_11: return "PIN_11";
        case PINNAME_12: return "PIN_12";
        case PINNAME_13: return "PIN_13";
        case PINNAME_14: return "PIN_14";
        case PINNAME_15: return "PIN_15";
        case PINNAME_NULL: return "NULL";
        default: return "UNKNOWN_PIN";
    }
}

/**
 * @brief Converts the cmTriggerType enum value to a string.
 * 
 * @param value The cmTriggerType value to convert.
 * @return A string representation of the cmTriggerType value.
 */
const char* getStringFromTriggerType(cmTriggerType value)
{
    switch (value)
    {
        case TRIGGERTYPE_UNKNOWN: return "UNKNOWN";
        case TRIGGERTYPE_RISINGEDGE: return "RISING_EDGE";
        case TRIGGERTYPE_FALLINGEDGE: return "FALLING_EDGE";
        default: return "UNKNOWN_TRIGGER";
    }
}

/**
 * @brief Converts the cmHallAStateStatus enum value to a string.
 * 
 * @param value The cmHallAStateStatus value to convert.
 * @return A string representation of the cmHallAStateStatus value.
 */
const char* getStringFromHallAStateStatus(cmHallAStateStatus value)
{
    switch (value)
    {
        case HALLA_STATUS_ENABLE: return "HALLA_ENABLED";
        case HALLA_STATUS_DISABLE: return "HALLA_DISABLED";
        case HALLA_STATUS_UNKNOWN: return "HALLA_UNKNOWN";
        default: return "UNKNOWN_HALLA_STATE";
    }
}

/**
 * @brief Converts the cmHallBStateStatus enum value to a string.
 * 
 * @param value The cmHallBStateStatus value to convert.
 * @return A string representation of the cmHallBStateStatus value.
 */
const char* getStringFromHallBStateStatus(cmHallBStateStatus value)
{
    switch (value)
    {
        case HALLB_STATUS_ENABLE: return "HALLB_ENABLED";
        case HALLB_STATUS_DISABLE: return "HALLB_DISABLED";
        case HALLB_STATUS_UNKNOWN: return "HALLB_UNKNOWN";
        default: return "UNKNOWN_HALLB_STATE";
    }
}

/**
 * @brief Converts the cmHallCStateStatus enum value to a string.
 * 
 * @param value The cmHallCStateStatus value to convert.
 * @return A string representation of the cmHallCStateStatus value.
 */
const char* getStringFromHallCStateStatus(cmHallCStateStatus value)
{
    switch (value)
    {
        case HALLC_STATUS_ENABLE: return "HALLC_ENABLED";
        case HALLC_STATUS_DISABLE: return "HALLC_DISABLED";
        case HALLC_STATUS_UNKNOWN: return "HALLC_UNKNOWN";
        default: return "UNKNOWN_HALLC_STATE";
    }
}



/**
 * @brief Converts the Interrupt Handler Manager configuration to a string.
 * 
 * @return A dynamically allocated string representation of the current configuration.
 *         Caller is responsible for freeing the memory.
 */
char* InterruptHandlerManager_toString(void)
{
    char* output = (char*)malloc(256);
    if (output == NULL)
    {
        return strdup("Memory allocation failed.");
    }

    snprintf(output, 256,
             "[InterruptHandlerManager]: External IRQ: [Port: %s, Pin: %s, Trigger: %s], "
             "Timer IRQ: [ms: %d, sec: %d, min: %d, hour: %d, day: %d], "
             "HALL: [HallA: %s, HallB: %s, HallC: %s]",
             getStringFromPortName(instance.externalIrq.port),
             getStringFromPinName(instance.externalIrq.pin),
             getStringFromTriggerType(instance.externalIrq.trigger),
             instance.timerIrq.ms,
             instance.timerIrq.sec,
             instance.timerIrq.min,
             instance.timerIrq.hour,
             instance.timerIrq.day,
             getStringFromHallAStateStatus(instance.HALL.halla_state),
             getStringFromHallBStateStatus(instance.HALL.hallb_state),
             getStringFromHallCStateStatus(instance.HALL.hallc_state));

    return output;
}

/* Constructor Implementations */

/**
 * @brief Constructor for the External IRQ Configuration.
 * 
 * Initializes the external IRQ configuration and assigns default values.
 */
void ExternalIrqConfiguration_CTOR(void)
{
    instance.externalIrq.setPort = setExternalIrqPort_Impl;
    instance.externalIrq.getPort = getExternalIrqPort_Impl;

    instance.externalIrq.setPin = setExternalIrqPin_Impl;
    instance.externalIrq.getPin = getExternalIrqPin_Impl;

    instance.externalIrq.setTrigger = setExternalIrqTrigger_Impl;
    instance.externalIrq.getTrigger = getExternalIrqTrigger_Impl;

    instance.externalIrq.setPort(PORTNAME_NULL);
    instance.externalIrq.setPin(PINNAME_NULL);
    instance.externalIrq.setTrigger(TRIGGERTYPE_UNKNOWN);
}

/**
 * @brief Constructor for the Timer IRQ Configuration.
 * 
 * Initializes the timer IRQ configuration and assigns default values.
 */
void TimerIrqConfiguration_CTOR(void)
{
    instance.timerIrq.setMillisecond = setTimerIrqMillisecond_Impl;
    instance.timerIrq.getMillisecond = getTimerIrqMillisecond_Impl;

    instance.timerIrq.setSecond = setTimerIrqSecond_Impl;
    instance.timerIrq.getSecond = getTimerIrqSecond_Impl;

    instance.timerIrq.setMinute = setTimerIrqMinute_Impl;
    instance.timerIrq.getMinute = getTimerIrqMinute_Impl;

    instance.timerIrq.setHour = setTimerIrqHour_Impl;
    instance.timerIrq.getHour = getTimerIrqHour_Impl;

    instance.timerIrq.setDay = setTimerIrqDay_Impl;
    instance.timerIrq.getDay = getTimerIrqDay_Impl;

    instance.timerIrq.setMillisecond(0);
    instance.timerIrq.setSecond(0);
    instance.timerIrq.setMinute(0);
    instance.timerIrq.setHour(0);
    instance.timerIrq.setDay(0);
}

/**
 * @brief Constructor for the HALL Configuration.
 * 
 * Initializes the HALL configuration and assigns default values.
 */
void HALLConfiguration_CTOR(void)
{
    instance.HALL.setHallAState = setHallAState_Impl;
    instance.HALL.getHallAState = getHallAState_Impl;

    instance.HALL.setHallBState = setHallBState_Impl;
    instance.HALL.getHallBState = getHallBState_Impl;

    instance.HALL.setHallCState = setHallCState_Impl;
    instance.HALL.getHallCState = getHallCState_Impl;

    instance.HALL.setHallAState(HALLA_STATUS_UNKNOWN);
    instance.HALL.setHallBState(HALLB_STATUS_UNKNOWN);
    instance.HALL.setHallCState(HALLC_STATUS_UNKNOWN);
}

/**
 * @brief Constructor for the Interrupt Handler Manager.
 * 
 * Initializes the function pointers, assigns initial values, and binds the interfaces.
 */
void InterruptHandlerManager_CTOR(void)
{
    /* Child class constructors */
    ExternalIrqConfiguration_CTOR();
    TimerIrqConfiguration_CTOR();
    HALLConfiguration_CTOR();

    /* Function pointer Implementation */
    instance.getExternalIrq = getExternalIrq_Impl;
    instance.setExternalIrq = setExternalIrq_Impl;
    instance.getTimerIrq = getTimerIrq_Impl;
    instance.setTimerIrq = setTimerIrq_Impl;
    instance.getHALL = getHALL_Impl;
    instance.setHALL = setHALL_Impl;
    instance.toString = InterruptHandlerManager_toString;

    /* Interface assignment */
    instance.IExternalInterruptStatus = &ExternalInterruptInterface;
    instance.ITimerInterruptStatus = &TimerInterruptInterface;
    instance.IHALLA = &HALLAInterface;
    instance.IHALLB = &HALLBInterface;
    instance.IHALLC = &HALLCInterface;
}

/**
 * @brief Public function to access the Interrupt Handler Manager instance.
 * 
 * @return Pointer to the static `dtInterruptHandlerManager` instance.
 */
dtInterruptHandlerManager* InterruptHandlerManager_GetInstance(void)
{
    return &instance;
}

/* Functional Behaviour Implementation */
