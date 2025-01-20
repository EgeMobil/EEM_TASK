#include "IExternalInterruptStatus.h"
#include <stdio.h>

/**
 * @brief Instance of the IExternalInterruptStatus interface.
 */
IExternalInterruptStatus ExternalInterruptInterface = {
    .writePortName = IExternalInterrupt_writePortName_Impl,
    .readPortName = IExternalInterrupt_readPortName_Impl,
    .writePinName = IExternalInterrupt_writePinName_Impl,
    .readPinName = IExternalInterrupt_readPinName_Impl,
    .writeTriggerType = IExternalInterrupt_writeTriggerType_Impl,
    .readTriggerType = IExternalInterrupt_readTriggerType_Impl
};

/* Static variables for storing current states */
static cmExtIrqPortName currentPortName = EXTIRQ_PORTNAME_UNKNOWN;
static cmExtIrqPinName currentPinName = EXTIRQ_PINNAME_UNKNOWN;
static cmExtIrqTriggerType currentTriggerType = EXTIRQ_TRIGGERTYPE_UNKNOWN;

/**
 * @brief Implementation for writing the port name.
 * @param portName Port name to write.
 * @return Status of the operation.
 */
IExternalInterrupt_StatusType IExternalInterrupt_writePortName_Impl(cmExtIrqPortName portName)
{
    currentPortName = portName;
    printf("[IExternalInterrupt] Port name written: %d\n", portName);
    return IEXTERNAL_INTERRUPT_OK;
}

/**
 * @brief Implementation for reading the port name.
 * @return Current port name.
 */
cmExtIrqPortName IExternalInterrupt_readPortName_Impl(void)
{
    printf("[IExternalInterrupt] Port name read: %d\n", currentPortName);
    return currentPortName;
}

/**
 * @brief Implementation for writing the pin name.
 * @param pinName Pin name to write.
 * @return Status of the operation.
 */
IExternalInterrupt_StatusType IExternalInterrupt_writePinName_Impl(cmExtIrqPinName pinName)
{
    currentPinName = pinName;
    printf("[IExternalInterrupt] Pin name written: %d\n", pinName);
    return IEXTERNAL_INTERRUPT_OK;
}

/**
 * @brief Implementation for reading the pin name.
 * @return Current pin name.
 */
cmExtIrqPinName IExternalInterrupt_readPinName_Impl(void)
{
    printf("[IExternalInterrupt] Pin name read: %d\n", currentPinName);
    return currentPinName;
}

/**
 * @brief Implementation for writing the trigger type.
 * @param triggerType Trigger type to write.
 * @return Status of the operation.
 */
IExternalInterrupt_StatusType IExternalInterrupt_writeTriggerType_Impl(cmExtIrqTriggerType triggerType)
{
    currentTriggerType = triggerType;
    printf("[IExternalInterrupt] Trigger type written: %d\n", triggerType);
    return IEXTERNAL_INTERRUPT_OK;
}

/**
 * @brief Implementation for reading the trigger type.
 * @return Current trigger type.
 */
cmExtIrqTriggerType IExternalInterrupt_readTriggerType_Impl(void)
{
    printf("[IExternalInterrupt] Trigger type read: %d\n", currentTriggerType);
    return currentTriggerType;
}
