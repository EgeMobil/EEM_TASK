/**
 * @file GateDriverController.c
 * @brief Implementation file for the Gate Driver Controller.
 * 
 * This file contains the implementation of the Gate Driver Controller, which manages
 * the configuration of various registers for controlling the gate driver. The controller 
 * interacts with hardware to set and get fault registers, gate drive statuses, and other 
 * related configurations.
 * 
 * Key functionalities include:
 * - Setting and getting fault registers, gate drive statuses, and control registers.
 * - A string representation of the current configuration for debugging purposes.
 * - Initialization of the controller with default values.
 * 
 * The file follows a singleton design pattern to ensure only one instance of the gate 
 * driver controller exists during runtime.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#include "GateDriverController_private.h"

/**
 * @brief Gate Driver Controller Instance.
 * 
 * A static instance of the `dtGateDriverController` structure that holds the 
 * current state and configuration of the Gate Driver Controller.
 */
static dtGateDriverController instance;

/* Getter Setter Implementation */

/**
 * @brief Sets the Fault Register 1 value.
 * 
 * @param faultReg1 The fault register value to set.
 * @return Status of the operation.
 */
IDRV8353_StatusType GateDriverController_setFaultReg1_Impl(dtGateDriverController_faultReg1 faultReg1)
{
    instance.faultReg1 = faultReg1;
    return IDRV8353_OK;
}

/**
 * @brief Gets the current Fault Register 1 value.
 * 
 * @return The current Fault Register 1 value.
 */
dtGateDriverController_faultReg1 GateDriverController_getFaultReg1_Impl(void)
{
    return instance.faultReg1;
}

/**
 * @brief Sets the Vgs Status value.
 * 
 * @param vgsStatus The Vgs status to set.
 * @return Status of the operation.
 */
IDRV8353_StatusType GateDriverController_setVgsStatus_Impl(dtGateDriverController_vgsStatus vgsStatus)
{
    instance.vgsStatus = vgsStatus;
    return IDRV8353_OK;
}

/**
 * @brief Gets the current Vgs Status value.
 * 
 * @return The current Vgs Status value.
 */
dtGateDriverController_vgsStatus GateDriverController_getVgsStatus_Impl(void)
{
    return instance.vgsStatus;
}

/**
 * @brief Sets the Driver Control value.
 * 
 * @param driverControl The driver control value to set.
 * @return Status of the operation.
 */
IDRV8353_StatusType GateDriverController_setDriverControl_Impl(dtGateDriverController_driverControl driverControl)
{
    instance.driverControl = driverControl;
    return IDRV8353_OK;
}

/**
 * @brief Gets the current Driver Control value.
 * 
 * @return The current Driver Control value.
 */
dtGateDriverController_driverControl GateDriverController_getDriverControl_Impl(void)
{
    return instance.driverControl;
}

/**
 * @brief Sets the Gate Drive High Side value.
 * 
 * @param gateDriveHS The gate drive high side value to set.
 * @return Status of the operation.
 */
IDRV8353_StatusType GateDriverController_setGateDriveHS_Impl(dtGateDriverController_gateDriveHS gateDriveHS)
{
    instance.gateDriveHS = gateDriveHS;
    return IDRV8353_OK;
}

/**
 * @brief Gets the current Gate Drive High Side value.
 * 
 * @return The current Gate Drive High Side value.
 */
dtGateDriverController_gateDriveHS GateDriverController_getGateDriveHS_Impl(void)
{
    return instance.gateDriveHS;
}

/**
 * @brief Sets the Gate Drive Low Side value.
 * 
 * @param gateDriveLS The gate drive low side value to set.
 * @return Status of the operation.
 */
IDRV8353_StatusType GateDriverController_setGateDriveLS_Impl(dtGateDriverController_gateDriveLS gateDriveLS)
{
    instance.gateDriveLS = gateDriveLS;
    return IDRV8353_OK;
}

/**
 * @brief Gets the current Gate Drive Low Side value.
 * 
 * @return The current Gate Drive Low Side value.
 */
dtGateDriverController_gateDriveLS GateDriverController_getGateDriveLS_Impl(void)
{
    return instance.gateDriveLS;
}

/**
 * @brief Sets the OCP Control value.
 * 
 * @param ocpControl The OCP control value to set.
 * @return Status of the operation.
 */
IDRV8353_StatusType GateDriverController_setOCPControl_Impl(dtGateDriverController_ocpControl ocpControl)
{
    instance.ocpControl = ocpControl;
    return IDRV8353_OK;
}

/**
 * @brief Gets the current OCP Control value.
 * 
 * @return The current OCP Control value.
 */
dtGateDriverController_ocpControl GateDriverController_getOCPControl_Impl(void)
{
    return instance.ocpControl;
}

/**
 * @brief Converts the Gate Driver Controller configuration to a string.
 * 
 * @return A dynamically allocated string representation of the current configuration.
 *         Caller is responsible for freeing the memory.
 */
char* GateDriverController_toString(void)
{
    char* output = (char*)malloc(512); // Sufficient buffer size
    if (output == NULL)
    {
        return strdup("Memory allocation failed.");
    }

    snprintf(output, 512,
             "[GateDriverController Registers]:\n"
             "FaultReg1: 0x%04X\n"
             "VgsStatus: 0x%04X\n"
             "DriverControl: 0x%04X\n"
             "GateDriveHS: 0x%04X\n"
             "GateDriveLS: 0x%04X\n"
             "OCPControl: 0x%04X\n",
             instance.faultReg1.word,
             instance.vgsStatus.word,
             instance.driverControl.word,
             instance.gateDriveHS.word,
             instance.gateDriveLS.word,
             instance.ocpControl.word);

    return output;
}

/**
 * @brief Constructor for the Gate Driver Controller.
 * 
 * Initializes the function pointers, assigns initial values for the controller,
 * and binds the interfaces.
 */
void GateDriverController_CTOR(void)
{
    /* Initialize the Interface Pointer */
    instance.IDRV8353 = &DRV8353Interface;

    /* Initialize Function Pointers */
    instance.setFaultReg1 = GateDriverController_setFaultReg1_Impl;
    instance.getFaultReg1 = GateDriverController_getFaultReg1_Impl;
    instance.setVgsStatus = GateDriverController_setVgsStatus_Impl;
    instance.getVgsStatus = GateDriverController_getVgsStatus_Impl;
    instance.setDriverControl = GateDriverController_setDriverControl_Impl;
    instance.getDriverControl = GateDriverController_getDriverControl_Impl;
    instance.setGateDriveHS = GateDriverController_setGateDriveHS_Impl;
    instance.getGateDriveHS = GateDriverController_getGateDriveHS_Impl;
    instance.setGateDriveLS = GateDriverController_setGateDriveLS_Impl;
    instance.getGateDriveLS = GateDriverController_getGateDriveLS_Impl;
    instance.setOCPControl = GateDriverController_setOCPControl_Impl;
    instance.getOCPControl = GateDriverController_getOCPControl_Impl;
    instance.toString = GateDriverController_toString;

    /* Initialize Attributes to Default Values */
    instance.faultReg1.word = 0x0000;
    instance.vgsStatus.word = 0x0000;
    instance.driverControl.word = 0x0000;

    /* GateDriveHS default configuration */
    instance.gateDriveHS.control_bits.LOCK = 0b011;
    instance.gateDriveHS.control_bits.IDRIVEP_HS = 0b1111;
    instance.gateDriveHS.control_bits.IDRIVEN_HS = 0b1111;

    /* GateDriveLS default configuration */
    instance.gateDriveLS.control_bits.CBC = 0b1;
    instance.gateDriveLS.control_bits.TDRIVE = 0b11;
    instance.gateDriveLS.control_bits.IDRIVEP_LS = 0b1111;
    instance.gateDriveLS.control_bits.IDRIVEN_LS = 0b1111;

    /* OCPControl default configuration */
    instance.ocpControl.control_bits.TRETRY = 0b0;
    instance.ocpControl.control_bits.DEAD_TIME = 0b01;
    instance.ocpControl.control_bits.OCP_MODE = 0b01;
    instance.ocpControl.control_bits.OCP_DEG = 0b10;
    instance.ocpControl.control_bits.VDS_LVL = 0b1101; // Default 1.0 V
}

/**
 * @brief Public function to access the Gate Driver Controller instance.
 * 
 * @return Pointer to the static `dtGateDriverController` instance.
 */
dtGateDriverController* GateDriverController_GetInstance(void)
{
    return &instance;
}
