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
    instance.HALL.halla_status = state;
}

/**
 * @brief Sets the state status for Hall B.
 * 
 * @param state State status to set for Hall B.
 */
void setHallBState_Impl(dtInterruptHandlerManager_HallBStateStatus state)
{
    instance.HALL.hallb_status = state;
}

/**
 * @brief Sets the state status for Hall C.
 * 
 * @param state State status to set for Hall C.
 */
void setHallCState_Impl(dtInterruptHandlerManager_HallCStateStatus state)
{
    instance.HALL.hallc_status = state;
}

/**
 * @brief Gets the current state status for Hall A.
 * 
 * @return The current state status for Hall A.
 */
dtInterruptHandlerManager_HallAStateStatus getHallAState_Impl(void)
{
    return instance.HALL.halla_status;
}

/**
 * @brief Gets the current state status for Hall B.
 * 
 * @return The current state status for Hall B.
 */
dtInterruptHandlerManager_HallBStateStatus getHallBState_Impl(void)
{
    return instance.HALL.hallb_status;
}

/**
 * @brief Gets the current state status for Hall C.
 * 
 * @return The current state status for Hall C.
 */
dtInterruptHandlerManager_HallCStateStatus getHallCState_Impl(void)
{
    return instance.HALL.hallc_status;
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


void setHallAPinState_Impl(dtInterruptHandlerManager_pinState state)
{
    instance.hall_A = state;
    printf("[InterruptHandlerManager] Hall A pin state set to: %d\n", state);
}

void setHallBPinState_Impl(dtInterruptHandlerManager_pinState state)
{
    instance.hall_B = state;
    printf("[InterruptHandlerManager] Hall B pin state set to: %d\n", state);
}

void setHallCPinState_Impl(dtInterruptHandlerManager_pinState state)
{
    instance.hall_C = state;
    printf("[InterruptHandlerManager] Hall C pin state set to: %d\n", state);
}

dtInterruptHandlerManager_pinState getHallAPinState_Impl(void)
{
    printf("[InterruptHandlerManager] Hall A pin state retrieved: %d\n", instance.hall_A);
    return instance.hall_A;
}

dtInterruptHandlerManager_pinState getHallBPinState_Impl(void)
{
    printf("[InterruptHandlerManager] Hall B pin state retrieved: %d\n", instance.hall_B);
    return instance.hall_B;
}

dtInterruptHandlerManager_pinState getHallCPinState_Impl(void)
{
    printf("[InterruptHandlerManager] Hall C pin state retrieved: %d\n", instance.hall_C);
    return instance.hall_C;
}

/* Hall A Implementations */
void setHallAStatus_Impl(dtInterruptHandlerManager_HallAStateStatus status) {
    instance.HALL.halla_status = status;
}
dtInterruptHandlerManager_HallAStateStatus getHallAStatus_Impl(void) {
    return instance.HALL.halla_status;
}

void setHallAFallingEdgeFlag_Impl(dtInterruptHandlerManager_FallingEdgeAFlag flag) {
    instance.HALL.halla_fe_flag = flag;
}
dtInterruptHandlerManager_FallingEdgeAFlag getHallAFallingEdgeFlag_Impl(void) {
    return instance.HALL.halla_fe_flag;
}

void setHallARisingEdgeFlag_Impl(dtInterruptHandlerManager_RisingEdgeAFlag flag) {
    instance.HALL.halla_re_flag = flag;
}
dtInterruptHandlerManager_RisingEdgeAFlag getHallARisingEdgeFlag_Impl(void) {
    return instance.HALL.halla_re_flag;
}

void setHallAFallingEdgeCount_Impl(dtInterruptHandlerManager_FallingEdgeACount count) {
    instance.HALL.halla_fe_count = count;
}
dtInterruptHandlerManager_FallingEdgeACount getHallAFallingEdgeCount_Impl(void) {
    return instance.HALL.halla_fe_count;
}

void setHallARisingEdgeCount_Impl(dtInterruptHandlerManager_RisingEdgeACount count) {
    instance.HALL.halla_re_count = count;
}
dtInterruptHandlerManager_RisingEdgeACount getHallARisingEdgeCount_Impl(void) {
    return instance.HALL.halla_re_count;
}

/* Hall B Implementations */
void setHallBStatus_Impl(dtInterruptHandlerManager_HallBStateStatus status) {
    instance.HALL.hallb_status = status;
}
dtInterruptHandlerManager_HallBStateStatus getHallBStatus_Impl(void) {
    return instance.HALL.hallb_status;
}

void setHallBFallingEdgeFlag_Impl(dtInterruptHandlerManager_FallingEdgeBFlag flag) {
    instance.HALL.hallb_fe_flag = flag;
}
dtInterruptHandlerManager_FallingEdgeBFlag getHallBFallingEdgeFlag_Impl(void) {
    return instance.HALL.hallb_fe_flag;
}

void setHallBRisingEdgeFlag_Impl(dtInterruptHandlerManager_RisingEdgeBFlag flag) {
    instance.HALL.hallb_re_flag = flag;
}
dtInterruptHandlerManager_RisingEdgeBFlag getHallBRisingEdgeFlag_Impl(void) {
    return instance.HALL.hallb_re_flag;
}

void setHallBFallingEdgeCount_Impl(dtInterruptHandlerManager_FallingEdgeBCount count) {
    instance.HALL.hallb_fe_count = count;
}
dtInterruptHandlerManager_FallingEdgeBCount getHallBFallingEdgeCount_Impl(void) {
    return instance.HALL.hallb_fe_count;
}

void setHallBRisingEdgeCount_Impl(dtInterruptHandlerManager_RisingEdgeBCount count) {
    instance.HALL.hallb_re_count = count;
}
dtInterruptHandlerManager_RisingEdgeBCount getHallBRisingEdgeCount_Impl(void) {
    return instance.HALL.hallb_re_count;
}

/* Hall C Implementations */
void setHallCStatus_Impl(dtInterruptHandlerManager_HallCStateStatus status) {
    instance.HALL.hallc_status = status;
}
dtInterruptHandlerManager_HallCStateStatus getHallCStatus_Impl(void) {
    return instance.HALL.hallc_status;
}

void setHallCFallingEdgeFlag_Impl(dtInterruptHandlerManager_FallingEdgeCFlag flag) {
    instance.HALL.hallc_fe_flag = flag;
}
dtInterruptHandlerManager_FallingEdgeCFlag getHallCFallingEdgeFlag_Impl(void) {
    return instance.HALL.hallc_fe_flag;
}

void setHallCRisingEdgeFlag_Impl(dtInterruptHandlerManager_RisingEdgeCFlag flag) {
    instance.HALL.hallc_re_flag = flag;
}
dtInterruptHandlerManager_RisingEdgeCFlag getHallCRisingEdgeFlag_Impl(void) {
    return instance.HALL.hallc_re_flag;
}

void setHallCFallingEdgeCount_Impl(dtInterruptHandlerManager_FallingEdgeCCount count) {
    instance.HALL.hallc_fe_count = count;
}
dtInterruptHandlerManager_FallingEdgeCCount getHallCFallingEdgeCount_Impl(void) {
    return instance.HALL.hallc_fe_count;
}

void setHallCRisingEdgeCount_Impl(dtInterruptHandlerManager_RisingEdgeCCount count) {
    instance.HALL.hallc_re_count = count;
}
dtInterruptHandlerManager_RisingEdgeCCount getHallCRisingEdgeCount_Impl(void) {
    return instance.HALL.hallc_re_count;
}

/* toString() Implementation */

/**
 * @brief Converts the cmPortName enum value to a string.
 * 
 * @param value The cmPortName value to convert.
 * @return A string representation of the cmPortName value.
 */
const char* getStringFromPortName(cmExtIrqPortName value)
{
    switch (value)
    {
        case EXTIRQ_PORTNAME_GPIOA: return "GPIOA";
        case EXTIRQ_PORTNAME_GPIOB: return "GPIOB";
        case EXTIRQ_PORTNAME_GPIOC: return "GPIOC";
        case EXTIRQ_PORTNAME_GPIOD: return "GPIOD";
        case EXTIRQ_PORTNAME_GPIOE: return "GPIOE";
        case EXTIRQ_PORTNAME_UNKNOWN: return "NULL";
        default: return "UNKNOWN_PORT";
    }
}

/**
 * @brief Converts the cmPinName enum value to a string.
 * 
 * @param value The cmPinName value to convert.
 * @return A string representation of the cmPinName value.
 */
const char* getStringFromPinName(cmExtIrqPinName value)
{
    switch (value)
    {
        case EXTIRQ_PINNAME_0: return "PIN_0";
        case EXTIRQ_PINNAME_1: return "PIN_1";
        case EXTIRQ_PINNAME_2: return "PIN_2";
        case EXTIRQ_PINNAME_3: return "PIN_3";
        case EXTIRQ_PINNAME_4: return "PIN_4";
        case EXTIRQ_PINNAME_5: return "PIN_5";
        case EXTIRQ_PINNAME_6: return "PIN_6";
        case EXTIRQ_PINNAME_7: return "PIN_7";
        case EXTIRQ_PINNAME_8: return "PIN_8";
        case EXTIRQ_PINNAME_9: return "PIN_9";
        case EXTIRQ_PINNAME_10: return "PIN_10";
        case EXTIRQ_PINNAME_11: return "PIN_11";
        case EXTIRQ_PINNAME_12: return "PIN_12";
        case EXTIRQ_PINNAME_13: return "PIN_13";
        case EXTIRQ_PINNAME_14: return "PIN_14";
        case EXTIRQ_PINNAME_15: return "PIN_15";
        case EXTIRQ_PINNAME_UNKNOWN: return "NULL";
        default: return "UNKNOWN_PIN";
    }
}

/**
 * @brief Converts the cmTriggerType enum value to a string.
 * 
 * @param value The cmTriggerType value to convert.
 * @return A string representation of the cmTriggerType value.
 */
const char* getStringFromTriggerType(cmExtIrqTriggerType value)
{
    switch (value)
    {
        case EXTIRQ_TRIGGERTYPE_UNKNOWN: return "UNKNOWN";
        case EXTIRQ_TRIGGERTYPE_RISINGEDGE: return "RISING_EDGE";
        case EXTIRQ_TRIGGERTYPE_FALLINGEDGE: return "FALLING_EDGE";
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
        case HALLA_STATUS_HIGH: return "HALLA_HIGH";
        case HALLA_STATUS_LOW: return "HALLA_LOW";
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
        case HALLB_STATUS_HIGH: return "HALLB_HIGH";
        case HALLB_STATUS_LOW: return "HALLB_LOW";
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
        case HALLC_STATUS_HIGH: return "HALLC_HIGH";
        case HALLC_STATUS_LOW: return "HALLC_LOW";
        case HALLC_STATUS_UNKNOWN: return "HALLC_UNKNOWN";
        default: return "UNKNOWN_HALLC_STATE";
    }
}


/**
 * @brief Converts the RisingEdgeFlag enum value to a string for Hall A.
 * 
 * @param flag The RisingEdgeFlag value to convert.
 * @return A string representation of the RisingEdgeFlag value.
 */
const char* getStringFromRisingEdgeAFlag(cmRisingEdgeAFlag flag)
{
    switch (flag)
    {
        case HALLA_RISING_EDGE_RESET: return "RESET";
        case HALLA_RISING_EDGE_SET: return "SET";
        case HALLA_RISING_EDGE_UNKNOWN: return "UNKNOWN";
        default: return "INVALID";
    }
}

/**
 * @brief Converts the FallingEdgeFlag enum value to a string for Hall A.
 * 
 * @param flag The FallingEdgeFlag value to convert.
 * @return A string representation of the FallingEdgeFlag value.
 */
const char* getStringFromFallingEdgeAFlag(cmFallingEdgeAFlag flag)
{
    switch (flag)
    {
        case HALLA_FALLING_EDGE_RESET: return "RESET";
        case HALLA_FALLING_EDGE_SET: return "SET";
        case HALLA_FALLING_EDGE_UNKNOWN: return "UNKNOWN";
        default: return "INVALID";
    }
}

/**
 * @brief Converts the RisingEdgeFlag enum value to a string for Hall B.
 * 
 * @param flag The RisingEdgeFlag value to convert.
 * @return A string representation of the RisingEdgeFlag value.
 */
const char* getStringFromRisingEdgeBFlag(cmRisingEdgeBFlag flag)
{
    switch (flag)
    {
        case HALLB_RISING_EDGE_RESET: return "RESET";
        case HALLB_RISING_EDGE_SET: return "SET";
        case HALLB_RISING_EDGE_UNKNOWN: return "UNKNOWN";
        default: return "INVALID";
    }
}

/**
 * @brief Converts the FallingEdgeFlag enum value to a string for Hall B.
 * 
 * @param flag The FallingEdgeFlag value to convert.
 * @return A string representation of the FallingEdgeFlag value.
 */
const char* getStringFromFallingEdgeBFlag(cmFallingEdgeBFlag flag)
{
    switch (flag)
    {
        case HALLB_FALLING_EDGE_RESET: return "RESET";
        case HALLB_FALLING_EDGE_SET: return "SET";
        case HALLB_FALLING_EDGE_UNKNOWN: return "UNKNOWN";
        default: return "INVALID";
    }
}

/**
 * @brief Converts the RisingEdgeFlag enum value to a string for Hall C.
 * 
 * @param flag The RisingEdgeFlag value to convert.
 * @return A string representation of the RisingEdgeFlag value.
 */
const char* getStringFromRisingEdgeCFlag(cmRisingEdgeCFlag flag)
{
    switch (flag)
    {
        case HALLC_RISING_EDGE_RESET: return "RESET";
        case HALLC_RISING_EDGE_SET: return "SET";
        case HALLC_RISING_EDGE_UNKNOWN: return "UNKNOWN";
        default: return "INVALID";
    }
}

/**
 * @brief Converts the FallingEdgeFlag enum value to a string for Hall C.
 * 
 * @param flag The FallingEdgeFlag value to convert.
 * @return A string representation of the FallingEdgeFlag value.
 */
const char* getStringFromFallingEdgeCFlag(cmFallingEdgeCFlag flag)
{
    switch (flag)
    {
        case HALLC_FALLING_EDGE_RESET: return "RESET";
        case HALLC_FALLING_EDGE_SET: return "SET";
        case HALLC_FALLING_EDGE_UNKNOWN: return "UNKNOWN";
        default: return "INVALID";
    }
}



char* InterruptHandlerManager_toString(void)
{
    char* output = (char*)malloc(512); // Daha büyük bir buffer
    if (output == NULL)
    {
        return strdup("Memory allocation failed.");
    }

    snprintf(output, 512,
             "[InterruptHandlerManager]:\n"
             "External IRQ:\n"
             "  Port: %s, Pin: %s, Trigger: %s\n"
             "Timer IRQ:\n"
             "  ms: %d, sec: %d, min: %d, hour: %d, day: %d\n"
             "HALL:\n"
             "  HallA:\n"
             "    Status: %s, RisingEdgeFlag: %s, FallingEdgeFlag: %s\n"
             "    RisingEdgeCount: %d, FallingEdgeCount: %d\n"
             "  HallB:\n"
             "    Status: %s, RisingEdgeFlag: %s, FallingEdgeFlag: %s\n"
             "    RisingEdgeCount: %d, FallingEdgeCount: %d\n"
             "  HallC:\n"
             "    Status: %s, RisingEdgeFlag: %s, FallingEdgeFlag: %s\n"
             "    RisingEdgeCount: %d, FallingEdgeCount: %d\n",
             getStringFromPortName(instance.externalIrq.port),
             getStringFromPinName(instance.externalIrq.pin),
             getStringFromTriggerType(instance.externalIrq.trigger),
             instance.timerIrq.ms,
             instance.timerIrq.sec,
             instance.timerIrq.min,
             instance.timerIrq.hour,
             instance.timerIrq.day,
             getStringFromHallAStateStatus(instance.HALL.halla_status),
             getStringFromRisingEdgeAFlag(instance.HALL.halla_re_flag),
             getStringFromFallingEdgeAFlag(instance.HALL.halla_fe_flag),
             instance.HALL.halla_re_count,
             instance.HALL.halla_fe_count,
             getStringFromHallBStateStatus(instance.HALL.hallb_status),
             getStringFromRisingEdgeBFlag(instance.HALL.hallb_re_flag),
             getStringFromFallingEdgeBFlag(instance.HALL.hallb_fe_flag),
             instance.HALL.hallb_re_count,
             instance.HALL.hallb_fe_count,
             getStringFromHallCStateStatus(instance.HALL.hallc_status),
             getStringFromRisingEdgeCFlag(instance.HALL.hallc_re_flag),
             getStringFromFallingEdgeCFlag(instance.HALL.hallc_fe_flag),
             instance.HALL.hallc_re_count,
             instance.HALL.hallc_fe_count);

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

    instance.externalIrq.setPort(EXTIRQ_PORTNAME_UNKNOWN);
    instance.externalIrq.setPin(EXTIRQ_PINNAME_UNKNOWN);
    instance.externalIrq.setTrigger(EXTIRQ_TRIGGERTYPE_UNKNOWN);
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
    /* Assign function pointers for Hall A */
    instance.HALL.setHallAStatus = setHallAState_Impl;
    instance.HALL.getHallAStatus = getHallAState_Impl;
    instance.HALL.setHallAFallingEdgeFlag = setHallAFallingEdgeFlag_Impl;
    instance.HALL.getHallAFallingEdgeFlag = getHallAFallingEdgeFlag_Impl;
    instance.HALL.setHallARisingEdgeFlag = setHallARisingEdgeFlag_Impl;
    instance.HALL.getHallARisingEdgeFlag = getHallARisingEdgeFlag_Impl;
    instance.HALL.setHallAFallingEdgeCount = setHallAFallingEdgeCount_Impl;
    instance.HALL.getHallAFallingEdgeCount = getHallAFallingEdgeCount_Impl;
    instance.HALL.setHallARisingEdgeCount = setHallARisingEdgeCount_Impl;
    instance.HALL.getHallARisingEdgeCount = getHallARisingEdgeCount_Impl;

    /* Assign function pointers for Hall B */
    instance.HALL.setHallBStatus = setHallBState_Impl;
    instance.HALL.getHallBStatus = getHallBState_Impl;
    instance.HALL.setHallBFallingEdgeFlag = setHallBFallingEdgeFlag_Impl;
    instance.HALL.getHallBFallingEdgeFlag = getHallBFallingEdgeFlag_Impl;
    instance.HALL.setHallBRisingEdgeFlag = setHallBRisingEdgeFlag_Impl;
    instance.HALL.getHallBRisingEdgeFlag = getHallBRisingEdgeFlag_Impl;
    instance.HALL.setHallBFallingEdgeCount = setHallBFallingEdgeCount_Impl;
    instance.HALL.getHallBFallingEdgeCount = getHallBFallingEdgeCount_Impl;
    instance.HALL.setHallBRisingEdgeCount = setHallBRisingEdgeCount_Impl;
    instance.HALL.getHallBRisingEdgeCount = getHallBRisingEdgeCount_Impl;

    /* Assign function pointers for Hall C */
    instance.HALL.setHallCStatus = setHallCState_Impl;
    instance.HALL.getHallCStatus = getHallCState_Impl;
    instance.HALL.setHallCFallingEdgeFlag = setHallCFallingEdgeFlag_Impl;
    instance.HALL.getHallCFallingEdgeFlag = getHallCFallingEdgeFlag_Impl;
    instance.HALL.setHallCRisingEdgeFlag = setHallCRisingEdgeFlag_Impl;
    instance.HALL.getHallCRisingEdgeFlag = getHallCRisingEdgeFlag_Impl;
    instance.HALL.setHallCFallingEdgeCount = setHallCFallingEdgeCount_Impl;
    instance.HALL.getHallCFallingEdgeCount = getHallCFallingEdgeCount_Impl;
    instance.HALL.setHallCRisingEdgeCount = setHallCRisingEdgeCount_Impl;
    instance.HALL.getHallCRisingEdgeCount = getHallCRisingEdgeCount_Impl;

    /* Initialize default values for Hall A, B, and C */
    instance.HALL.setHallAStatus(HALLA_STATUS_UNKNOWN);
    instance.HALL.setHallBStatus(HALLB_STATUS_UNKNOWN);
    instance.HALL.setHallCStatus(HALLC_STATUS_UNKNOWN);

    instance.HALL.setHallAFallingEdgeFlag(HALLA_FALLING_EDGE_UNKNOWN);
    instance.HALL.setHallBFallingEdgeFlag(HALLB_FALLING_EDGE_UNKNOWN);
    instance.HALL.setHallCFallingEdgeFlag(HALLC_FALLING_EDGE_UNKNOWN);

    instance.HALL.setHallARisingEdgeFlag(HALLA_RISING_EDGE_UNKNOWN);
    instance.HALL.setHallBRisingEdgeFlag(HALLB_RISING_EDGE_UNKNOWN);
    instance.HALL.setHallCRisingEdgeFlag(HALLC_RISING_EDGE_UNKNOWN);

    instance.HALL.setHallAFallingEdgeCount(0);
    instance.HALL.setHallBFallingEdgeCount(0);
    instance.HALL.setHallCFallingEdgeCount(0);

    instance.HALL.setHallARisingEdgeCount(0);
    instance.HALL.setHallBRisingEdgeCount(0);
    instance.HALL.setHallCRisingEdgeCount(0);
}

/**
 * @brief Constructor for the Interrupt Handler Manager.
 * 
 * Initializes the function pointers, assigns initial values, and binds the interfaces.
 */
void InterruptHandlerManager_CTOR(void)
{
    /* Function pointer Implementation */
    instance.getExternalIrq = getExternalIrq_Impl;
    instance.setExternalIrq = setExternalIrq_Impl;
    instance.getTimerIrq = getTimerIrq_Impl;
    instance.setTimerIrq = setTimerIrq_Impl;
    instance.getHALL = getHALL_Impl;
    instance.setHALL = setHALL_Impl;

    instance.setHallAPinState = setHallAPinState_Impl;
    instance.getHallAPinState = getHallAPinState_Impl;
    instance.setHallBPinState = setHallBPinState_Impl;
    instance.getHallBPinState = getHallBPinState_Impl;
    instance.setHallCPinState = setHallCPinState_Impl;
    instance.getHallCPinState = getHallCPinState_Impl;

    instance.toString = InterruptHandlerManager_toString;

    /* Child class constructors */
    ExternalIrqConfiguration_CTOR();
    TimerIrqConfiguration_CTOR();
    HALLConfiguration_CTOR();

    /* Interface assignment */
    instance.IExternalInterruptStatus = &ExternalInterruptInterface;
    instance.ITimerInterruptStatus = &TimerInterruptInterface;
    instance.IGPIOStatus = &GPIOStatusInterface;
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
