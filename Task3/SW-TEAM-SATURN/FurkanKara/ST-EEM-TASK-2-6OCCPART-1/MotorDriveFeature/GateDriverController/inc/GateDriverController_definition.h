/**
 * @file GateDriverController_definition.h
 * @brief Definition header file for the Gate Driver Controller.
 * 
 * This file contains the definitions, data types, and structure declarations 
 * for the Gate Driver Controller. It includes the necessary interfaces 
 * and dependencies for managing gate driver operations, such as fault detection, 
 * Vgs status, driver control, and over-current protection control.
 * 
 * @author [Your Name]
 * @date [Date]
 */

#ifndef GATEDRIVERCONTROLLER_DEFINITION_H_
#define GATEDRIVERCONTROLLER_DEFINITION_H_

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

/* ECU StateManager Global Include */
#include "ECUStateManager_global.h"

/* Receiver Port Interface Definition Include */
#include "IDRV8353.h"

/* Sender Port Interface Definition Include */

/**
 * @brief Enum for Gate Driver Controller return values.
 * 
 * This enum defines the possible return values for functions in the Gate Driver Controller.
 */
typedef enum
{
    GDC_ERR = 0,    /**< Error occurred. */
    GDC_EOK,        /**< Operation successful. */
    GDC_UNKNOWN     /**< Unknown state. */
} dtGdcReturn;

/**
 * @brief Return type alias for Gate Driver Controller functions.
 * 
 * This alias is used to define the return type for functions within the Gate Driver Controller.
 */
typedef dtGdcReturn dtGateDriverController_gdcReturn;

/**
 * @brief Alias for fault register type.
 * 
 * This alias is used for the fault register type in the Gate Driver Controller.
 */
typedef cmFaultReg1 dtGateDriverController_faultReg1;

/**
 * @brief Alias for Vgs status type.
 * 
 * This alias is used for the Vgs status type in the Gate Driver Controller.
 */
typedef cmVgsStatus dtGateDriverController_vgsStatus;

/**
 * @brief Alias for driver control type.
 * 
 * This alias is used for the driver control type in the Gate Driver Controller.
 */
typedef cmDriverControl dtGateDriverController_driverControl;

/**
 * @brief Alias for high-side gate drive type.
 * 
 * This alias is used for the high-side gate drive type in the Gate Driver Controller.
 */
typedef cmGateDriveHS dtGateDriverController_gateDriveHS;

/**
 * @brief Alias for low-side gate drive type.
 * 
 * This alias is used for the low-side gate drive type in the Gate Driver Controller.
 */
typedef cmGateDriveLS dtGateDriverController_gateDriveLS;

/**
 * @brief Alias for over-current protection control type.
 * 
 * This alias is used for the over-current protection control type in the Gate Driver Controller.
 */
typedef cmOCPControl dtGateDriverController_ocpControl;

/**
 * @brief Gate Driver Controller configuration structure.
 * 
 * This structure contains the configuration attributes for the Gate Driver Controller,
 * including various control parameters and the interface pointer.
 */
typedef struct 
{
    /* Interface Pointer */
    IDRV8353* IDRV8353; /**< Pointer to the Gate Driver Controller interface. */

    /* Attributes */
    dtGateDriverController_faultReg1 faultReg1; /**< Fault register 1 configuration. */
    dtGateDriverController_vgsStatus vgsStatus; /**< Vgs status configuration. */
    dtGateDriverController_driverControl driverControl; /**< Driver control configuration. */
    dtGateDriverController_gateDriveHS gateDriveHS; /**< High-side gate drive configuration. */
    dtGateDriverController_gateDriveLS gateDriveLS; /**< Low-side gate drive configuration. */
    dtGateDriverController_ocpControl ocpControl; /**< Over-current protection control configuration. */

    /* Getter/Setter Function Pointers */
    /**
     * @brief Sets the fault register 1 configuration.
     * @param faultReg1 Fault register configuration to set.
     * @return Status of the operation.
     */
    IDRV8353_StatusType (*setFaultReg1)(dtGateDriverController_faultReg1 faultReg1);

    /**
     * @brief Gets the current fault register 1 configuration.
     * @return Current fault register configuration.
     */
    dtGateDriverController_faultReg1 (*getFaultReg1)(void);

    /**
     * @brief Sets the Vgs status configuration.
     * @param vgsStatus Vgs status configuration to set.
     * @return Status of the operation.
     */
    IDRV8353_StatusType (*setVgsStatus)(dtGateDriverController_vgsStatus vgsStatus);

    /**
     * @brief Gets the current Vgs status configuration.
     * @return Current Vgs status configuration.
     */
    dtGateDriverController_vgsStatus (*getVgsStatus)(void);

    /**
     * @brief Sets the driver control configuration.
     * @param driverControl Driver control configuration to set.
     * @return Status of the operation.
     */
    IDRV8353_StatusType (*setDriverControl)(dtGateDriverController_driverControl driverControl);

    /**
     * @brief Gets the current driver control configuration.
     * @return Current driver control configuration.
     */
    dtGateDriverController_driverControl (*getDriverControl)(void);

    /**
     * @brief Sets the high-side gate drive configuration.
     * @param gateDriveHS High-side gate drive configuration to set.
     * @return Status of the operation.
     */
    IDRV8353_StatusType (*setGateDriveHS)(dtGateDriverController_gateDriveHS gateDriveHS);

    /**
     * @brief Gets the current high-side gate drive configuration.
     * @return Current high-side gate drive configuration.
     */
    dtGateDriverController_gateDriveHS (*getGateDriveHS)(void);

    /**
     * @brief Sets the low-side gate drive configuration.
     * @param gateDriveLS Low-side gate drive configuration to set.
     * @return Status of the operation.
     */
    IDRV8353_StatusType (*setGateDriveLS)(dtGateDriverController_gateDriveLS gateDriveLS);

    /**
     * @brief Gets the current low-side gate drive configuration.
     * @return Current low-side gate drive configuration.
     */
    dtGateDriverController_gateDriveLS (*getGateDriveLS)(void);

    /**
     * @brief Sets the over-current protection control configuration.
     * @param ocpControl Over-current protection control configuration to set.
     * @return Status of the operation.
     */
    IDRV8353_StatusType (*setOCPControl)(dtGateDriverController_ocpControl ocpControl);

    /**
     * @brief Gets the current over-current protection control configuration.
     * @return Current over-current protection control configuration.
     */
    dtGateDriverController_ocpControl (*getOCPControl)(void);

    /* toString Function Pointer */
    /**
     * @brief Converts the current configuration to a string representation.
     * @return A string representation of the Gate Driver Controller configuration.
     */
    char* (*toString)(void);

} dtGateDriverController;

#endif /* GATEDRIVERCONTROLLER_DEFINITION_H_ */
