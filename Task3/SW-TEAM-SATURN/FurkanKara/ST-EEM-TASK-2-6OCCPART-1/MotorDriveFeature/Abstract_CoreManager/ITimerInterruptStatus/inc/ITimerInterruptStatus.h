#ifndef ITIMER_INTERRUPT_STATUS_H_
#define ITIMER_INTERRUPT_STATUS_H_

#include "Abstract_CoreManager.h"

/**
 * @brief Status type for the ITimerInterruptStatus interface.
 */
typedef enum
{
    ITIMER_INTERRUPT_OK = 0,   /**< Operation completed successfully. */
    ITIMER_INTERRUPT_NOT_OK    /**< Operation failed. */
} ITimerInterrupt_StatusType;

/**
 * @brief Structure defining the function pointers for ITimerInterruptStatus interface.
 */
typedef struct
{
    /**
     * @brief Starts the timer interrupt.
     * @return Status of the operation.
     */
    ITimerInterrupt_StatusType (*startTimer)(void);

    /**
     * @brief Stops the timer interrupt.
     * @return Status of the operation.
     */
    ITimerInterrupt_StatusType (*stopTimer)(void);

    /**
     * @brief Write the millisecond value for timer interrupt configuration.
     * @param millisecond Millisecond value to write.
     * @return Status of the operation.
     */
    ITimerInterrupt_StatusType (*writeMillisecond)(cmMillisecond millisecond);

    /**
     * @brief Read the current millisecond value for timer interrupt configuration.
     * @return Current millisecond value.
     */
    cmMillisecond (*readMillisecond)(void);

    /**
     * @brief Write the second value for timer interrupt configuration.
     * @param second Second value to write.
     * @return Status of the operation.
     */
    ITimerInterrupt_StatusType (*writeSecond)(cmSecond second);

    /**
     * @brief Read the current second value for timer interrupt configuration.
     * @return Current second value.
     */
    cmSecond (*readSecond)(void);

    /**
     * @brief Write the minute value for timer interrupt configuration.
     * @param minute Minute value to write.
     * @return Status of the operation.
     */
    ITimerInterrupt_StatusType (*writeMinute)(cmMinute minute);

    /**
     * @brief Read the current minute value for timer interrupt configuration.
     * @return Current minute value.
     */
    cmMinute (*readMinute)(void);

    /**
     * @brief Write the hour value for timer interrupt configuration.
     * @param hour Hour value to write.
     * @return Status of the operation.
     */
    ITimerInterrupt_StatusType (*writeHour)(cmHour hour);

    /**
     * @brief Read the current hour value for timer interrupt configuration.
     * @return Current hour value.
     */
    cmHour (*readHour)(void);

    /**
     * @brief Write the day value for timer interrupt configuration.
     * @param day Day value to write.
     * @return Status of the operation.
     */
    ITimerInterrupt_StatusType (*writeDay)(cmDay day);

    /**
     * @brief Read the current day value for timer interrupt configuration.
     * @return Current day value.
     */
    cmDay (*readDay)(void);
} ITimerInterruptStatus;

/**
 * @brief Global instance of the ITimerInterruptStatus interface.
 */
extern ITimerInterruptStatus TimerInterruptInterface;

/* Function prototypes */

/**
 * @brief Starts the timer interrupt.
 *
 * This function enables and starts the configured timer interrupt.
 *
 * @return Status of the operation:
 *         - `ITIMER_INTERRUPT_OK` if the operation was successful.
 *         - `ITIMER_INTERRUPT_NOT_OK` if there was an issue.
 */
ITimerInterrupt_StatusType ITimerInterrupt_startTimer_Impl(void);

/**
 * @brief Stops the timer interrupt.
 *
 * This function disables the timer interrupt.
 *
 * @return Status of the operation:
 *         - `ITIMER_INTERRUPT_OK` if the operation was successful.
 *         - `ITIMER_INTERRUPT_NOT_OK` if there was an issue.
 */
ITimerInterrupt_StatusType ITimerInterrupt_stopTimer_Impl(void);

/**
 * @brief Writes the millisecond value for timer interrupt configuration.
 * 
 * This function sets the millisecond value for timer interrupts.
 * 
 * @param millisecond Millisecond value to write. Must be a valid value of type `cmMillisecond`.
 * @return Status of the operation:
 *         - `ITIMER_INTERRUPT_OK` if the operation was successful.
 *         - `ITIMER_INTERRUPT_NOT_OK` if the input is invalid.
 */
ITimerInterrupt_StatusType ITimerInterrupt_writeMillisecond_Impl(cmMillisecond millisecond);

/**
 * @brief Reads the millisecond value for timer interrupt configuration.
 * 
 * This function retrieves the currently set millisecond value for timer interrupts.
 * 
 * @return The current millisecond value of type `cmMillisecond`.
 */
cmMillisecond ITimerInterrupt_readMillisecond_Impl(void);

/**
 * @brief Writes the second value for timer interrupt configuration.
 * 
 * This function sets the second value for timer interrupts.
 * 
 * @param second Second value to write. Must be a valid value of type `cmSecond`.
 * @return Status of the operation:
 *         - `ITIMER_INTERRUPT_OK` if the operation was successful.
 *         - `ITIMER_INTERRUPT_NOT_OK` if the input is invalid.
 */
ITimerInterrupt_StatusType ITimerInterrupt_writeSecond_Impl(cmSecond second);

/**
 * @brief Reads the second value for timer interrupt configuration.
 * 
 * This function retrieves the currently set second value for timer interrupts.
 * 
 * @return The current second value of type `cmSecond`.
 */
cmSecond ITimerInterrupt_readSecond_Impl(void);

/**
 * @brief Writes the minute value for timer interrupt configuration.
 * 
 * This function sets the minute value for timer interrupts.
 * 
 * @param minute Minute value to write. Must be a valid value of type `cmMinute`.
 * @return Status of the operation:
 *         - `ITIMER_INTERRUPT_OK` if the operation was successful.
 *         - `ITIMER_INTERRUPT_NOT_OK` if the input is invalid.
 */
ITimerInterrupt_StatusType ITimerInterrupt_writeMinute_Impl(cmMinute minute);

/**
 * @brief Reads the minute value for timer interrupt configuration.
 * 
 * This function retrieves the currently set minute value for timer interrupts.
 * 
 * @return The current minute value of type `cmMinute`.
 */
cmMinute ITimerInterrupt_readMinute_Impl(void);

/**
 * @brief Writes the hour value for timer interrupt configuration.
 * 
 * This function sets the hour value for timer interrupts.
 * 
 * @param hour Hour value to write. Must be a valid value of type `cmHour`.
 * @return Status of the operation:
 *         - `ITIMER_INTERRUPT_OK` if the operation was successful.
 *         - `ITIMER_INTERRUPT_NOT_OK` if the input is invalid.
 */
ITimerInterrupt_StatusType ITimerInterrupt_writeHour_Impl(cmHour hour);

/**
 * @brief Reads the hour value for timer interrupt configuration.
 * 
 * This function retrieves the currently set hour value for timer interrupts.
 * 
 * @return The current hour value of type `cmHour`.
 */
cmHour ITimerInterrupt_readHour_Impl(void);

/**
 * @brief Writes the day value for timer interrupt configuration.
 * 
 * This function sets the day value for timer interrupts.
 * 
 * @param day Day value to write. Must be a valid value of type `cmDay`.
 * @return Status of the operation:
 *         - `ITIMER_INTERRUPT_OK` if the operation was successful.
 *         - `ITIMER_INTERRUPT_NOT_OK` if the input is invalid.
 */
ITimerInterrupt_StatusType ITimerInterrupt_writeDay_Impl(cmDay day);

/**
 * @brief Reads the day value for timer interrupt configuration.
 * 
 * This function retrieves the currently set day value for timer interrupts.
 * 
 * @return The current day value of type `cmDay`.
 */
cmDay ITimerInterrupt_readDay_Impl(void);

#ifdef STM32G431xx
ITimerInterrupt_StatusType ITimerInterrupt_startTimer_HAL(void);
ITimerInterrupt_StatusType ITimerInterrupt_stopTimer_HAL(void);
#endif


#endif /* ITIMER_INTERRUPT_STATUS_H_ */
