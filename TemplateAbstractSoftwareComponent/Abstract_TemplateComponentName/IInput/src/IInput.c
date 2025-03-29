#include "IInput.h"
#include <stdio.h>

/**
 * @brief Instance of the IInput interface.
 */
IInput InputInterface = {
    .writeInputValue = IInput_writeInputValue_Impl,
    .readInputValue = IInput_readInputValue_Impl,
    .writeStatus = IInput_writeStatus_Impl,
    .readStatus = IInput_readStatus_Impl
};

/* Static variables for storing current input data */
static float currentInputValue = 0.0f;
static TEMPLATE_ResultStatus currentStatus = TEMPLATE_STATUS_OK;

/**
 * @brief Implementation for writing the input value.
 * @param value Input value to write.
 * @return Status of the operation.
 */
IInput_StatusType IInput_writeInputValue_Impl(float value)
{
    currentInputValue = value;
    printf("[IInput] Input value written: %.2f\n", value);
    return IINPUT_OK;
}

/**
 * @brief Implementation for reading the input value.
 * @return Current input value.
 */
float IInput_readInputValue_Impl(void)
{
    printf("[IInput] Input value read: %.2f\n", currentInputValue);
    return currentInputValue;
}

/**
 * @brief Implementation for writing the calculation status.
 * @param status Status to write.
 * @return Status of the operation.
 */
IInput_StatusType IInput_writeStatus_Impl(TEMPLATE_ResultStatus status)
{
    currentStatus = status;
    printf("[IInput] Status written: %d\n", status);
    return IINPUT_OK;
}

/**
 * @brief Implementation for reading the calculation status.
 * @return Current status.
 */
TEMPLATE_ResultStatus IInput_readStatus_Impl(void)
{
    printf("[IInput] Status read: %d\n", currentStatus);
    return currentStatus;
}
