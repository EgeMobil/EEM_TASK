#ifndef IINPUT_H_
#define IINPUT_H_

#include "Abstract_TemplateComponentName.h"

/**
 * @brief Status type for the IInput interface.
 */
typedef enum
{
    IINPUT_OK = 0,      /**< Operation completed successfully. */
    IINPUT_NOT_OK       /**< Operation failed. */
} IInput_StatusType;

/**
 * @brief Structure defining the function pointers for IInput interface.
 */
typedef struct
{
    IInput_StatusType (*writeInputValue)(float value);
    float (*readInputValue)(void);

    IInput_StatusType (*writeStatus)(TEMPLATE_ResultStatus status);
    TEMPLATE_ResultStatus (*readStatus)(void);

} IInput;

/**
 * @brief Global instance of the IInput interface.
 */
extern IInput InputInterface;

/* Function prototypes */
IInput_StatusType IInput_writeInputValue_Impl(float value);
float IInput_readInputValue_Impl(void);

IInput_StatusType IInput_writeStatus_Impl(TEMPLATE_ResultStatus status);
TEMPLATE_ResultStatus IInput_readStatus_Impl(void);

#endif /* IINPUT_H_ */
