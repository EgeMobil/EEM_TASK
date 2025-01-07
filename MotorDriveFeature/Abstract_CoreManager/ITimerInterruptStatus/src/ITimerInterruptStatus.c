#include "ITimerInterruptStatus.h"

/**
 * @brief Instance of the ITimerInterruptStatus interface.
 */
ITimerInterruptStatus TimerInterruptInterface = {
    .writeMillisecond = ITimerInterrupt_writeMillisecond_Impl,
    .readMillisecond = ITimerInterrupt_readMillisecond_Impl,
    .writeSecond = ITimerInterrupt_writeSecond_Impl,
    .readSecond = ITimerInterrupt_readSecond_Impl,
    .writeMinute = ITimerInterrupt_writeMinute_Impl,
    .readMinute = ITimerInterrupt_readMinute_Impl,
    .writeHour = ITimerInterrupt_writeHour_Impl,
    .readHour = ITimerInterrupt_readHour_Impl,
    .writeDay = ITimerInterrupt_writeDay_Impl,
    .readDay = ITimerInterrupt_readDay_Impl
};

/* Static variables for storing current states */
static cmMillisecond currentMillisecond = 0;
static cmSecond currentSecond = 0;
static cmMinute currentMinute = 0;
static cmHour currentHour = 0;
static cmDay currentDay = 0;

/**
 * @brief Implementation for writing the millisecond value.
 * @param millisecond Millisecond value to write.
 * @return Status of the operation.
 */
ITimerInterrupt_StatusType ITimerInterrupt_writeMillisecond_Impl(cmMillisecond millisecond)
{
    currentMillisecond = millisecond;
    printf("[ITimerInterrupt] Millisecond written: %u\n", millisecond);
    return ITIMER_INTERRUPT_OK;
}

/**
 * @brief Implementation for reading the millisecond value.
 * @return Current millisecond value.
 */
cmMillisecond ITimerInterrupt_readMillisecond_Impl(void)
{
    printf("[ITimerInterrupt] Millisecond read: %u\n", currentMillisecond);
    return currentMillisecond;
}

/**
 * @brief Implementation for writing the second value.
 * @param second Second value to write.
 * @return Status of the operation.
 */
ITimerInterrupt_StatusType ITimerInterrupt_writeSecond_Impl(cmSecond second)
{
    currentSecond = second;
    printf("[ITimerInterrupt] Second written: %u\n", second);
    return ITIMER_INTERRUPT_OK;
}

/**
 * @brief Implementation for reading the second value.
 * @return Current second value.
 */
cmSecond ITimerInterrupt_readSecond_Impl(void)
{
    printf("[ITimerInterrupt] Second read: %u\n", currentSecond);
    return currentSecond;
}

/**
 * @brief Implementation for writing the minute value.
 * @param minute Minute value to write.
 * @return Status of the operation.
 */
ITimerInterrupt_StatusType ITimerInterrupt_writeMinute_Impl(cmMinute minute)
{
    currentMinute = minute;
    printf("[ITimerInterrupt] Minute written: %u\n", minute);
    return ITIMER_INTERRUPT_OK;
}

/**
 * @brief Implementation for reading the minute value.
 * @return Current minute value.
 */
cmMinute ITimerInterrupt_readMinute_Impl(void)
{
    printf("[ITimerInterrupt] Minute read: %u\n", currentMinute);
    return currentMinute;
}

/**
 * @brief Implementation for writing the hour value.
 * @param hour Hour value to write.
 * @return Status of the operation.
 */
ITimerInterrupt_StatusType ITimerInterrupt_writeHour_Impl(cmHour hour)
{
    currentHour = hour;
    printf("[ITimerInterrupt] Hour written: %u\n", hour);
    return ITIMER_INTERRUPT_OK;
}

/**
 * @brief Implementation for reading the hour value.
 * @return Current hour value.
 */
cmHour ITimerInterrupt_readHour_Impl(void)
{
    printf("[ITimerInterrupt] Hour read: %u\n", currentHour);
    return currentHour;
}

/**
 * @brief Implementation for writing the day value.
 * @param day Day value to write.
 * @return Status of the operation.
 */
ITimerInterrupt_StatusType ITimerInterrupt_writeDay_Impl(cmDay day)
{
    currentDay = day;
    printf("[ITimerInterrupt] Day written: %u\n", day);
    return ITIMER_INTERRUPT_OK;
}

/**
 * @brief Implementation for reading the day value.
 * @return Current day value.
 */
cmDay ITimerInterrupt_readDay_Impl(void)
{
    printf("[ITimerInterrupt] Day read: %u\n", currentDay);
    return currentDay;
}
