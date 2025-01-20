#ifndef IEXTERNAL_INTERRUPT_STATUS_H_
#define IEXTERNAL_INTERRUPT_STATUS_H_

#include "Abstract_CoreManager.h"

/**
 * @brief Status type for the IExternalInterruptStatus interface.
 */
typedef enum
{
    IEXTERNAL_INTERRUPT_OK = 0, /**< Operation completed successfully. */
    IEXTERNAL_INTERRUPT_NOT_OK  /**< Operation failed. */
} IExternalInterrupt_StatusType;

/**
 * @brief Structure defining the function pointers for IExternalInterruptStatus interface.
 */
typedef struct
{
    /**
     * @brief Write the port name for external interrupt.
     * @param portName Port name to write.
     * @return Status of the operation.
     */
    IExternalInterrupt_StatusType (*writePortName)(cmExtIrqPortName portName);

    /**
     * @brief Read the current port name for external interrupt.
     * @return Current port name.
     */
    cmExtIrqPortName (*readPortName)(void);

    /**
     * @brief Write the pin name for external interrupt.
     * @param pinName Pin name to write.
     * @return Status of the operation.
     */
    IExternalInterrupt_StatusType (*writePinName)(cmExtIrqPinName pinName);

    /**
     * @brief Read the current pin name for external interrupt.
     * @return Current pin name.
     */
    cmExtIrqPinName (*readPinName)(void);

    /**
     * @brief Write the trigger type for external interrupt.
     * @param triggerType Trigger type to write.
     * @return Status of the operation.
     */
    IExternalInterrupt_StatusType (*writeTriggerType)(cmExtIrqTriggerType triggerType);

    /**
     * @brief Read the current trigger type for external interrupt.
     * @return Current trigger type.
     */
    cmExtIrqTriggerType (*readTriggerType)(void);
} IExternalInterruptStatus;

/**
 * @brief Global instance of the IExternalInterruptStatus interface.
 */
extern IExternalInterruptStatus ExternalInterruptInterface;

/* Function prototypes */

/**
 * @brief Implementation for writing the port name.
 * 
 * This function sets the port name for external interrupt configuration.
 * 
 * @param portName Port name to write. Must be a valid value of type `cmPortName`.
 * @return Status of the operation. Returns `IEXTERNAL_INTERRUPT_OK` on success, 
 *         or `IEXTERNAL_INTERRUPT_NOT_OK` if the input is invalid.
 */
IExternalInterrupt_StatusType IExternalInterrupt_writePortName_Impl(cmExtIrqPortName portName);

/**
 * @brief Implementation for reading the port name.
 * 
 * This function retrieves the currently set port name for external interrupt configuration.
 * 
 * @return The current port name of type `cmPortName`.
 */
cmExtIrqPortName IExternalInterrupt_readPortName_Impl(void);

/**
 * @brief Implementation for writing the pin name.
 * 
 * This function sets the pin name for external interrupt configuration.
 * 
 * @param pinName Pin name to write. Must be a valid value of type `cmPinName`.
 * @return Status of the operation. Returns `IEXTERNAL_INTERRUPT_OK` on success, 
 *         or `IEXTERNAL_INTERRUPT_NOT_OK` if the input is invalid.
 */
IExternalInterrupt_StatusType IExternalInterrupt_writePinName_Impl(cmExtIrqPinName pinName);

/**
 * @brief Implementation for reading the pin name.
 * 
 * This function retrieves the currently set pin name for external interrupt configuration.
 * 
 * @return The current pin name of type `cmPinName`.
 */
cmExtIrqPinName IExternalInterrupt_readPinName_Impl(void);

/**
 * @brief Implementation for writing the trigger type.
 * 
 * This function sets the trigger type for external interrupt configuration.
 * 
 * @param triggerType Trigger type to write. Must be a valid value of type `cmTriggerType`.
 * @return Status of the operation. Returns `IEXTERNAL_INTERRUPT_OK` on success, 
 *         or `IEXTERNAL_INTERRUPT_NOT_OK` if the input is invalid.
 */
IExternalInterrupt_StatusType IExternalInterrupt_writeTriggerType_Impl(cmExtIrqTriggerType triggerType);

/**
 * @brief Implementation for reading the trigger type.
 * 
 * This function retrieves the currently set trigger type for external interrupt configuration.
 * 
 * @return The current trigger type of type `cmTriggerType`.
 */
cmExtIrqTriggerType IExternalInterrupt_readTriggerType_Impl(void);


#endif /* IEXTERNAL_INTERRUPT_STATUS_H_ */
