#include "GateDriverController_private.h"

/* Instance definition */
static dtGateDriverController instance;

/* Getter Setter Implementation */

/* FaultReg1 Getter and Setter */
IDRV8353_StatusType GateDriverController_setFaultReg1_Impl(dtGateDriverController_faultReg1 faultReg1)
{
    instance.faultReg1 = faultReg1;
    return IDRV8353_OK;
}

dtGateDriverController_faultReg1 GateDriverController_getFaultReg1_Impl(void)
{
    return instance.faultReg1;
}

/* VgsStatus Getter and Setter */
IDRV8353_StatusType GateDriverController_setVgsStatus_Impl(dtGateDriverController_vgsStatus vgsStatus)
{
    instance.vgsStatus = vgsStatus;
    return IDRV8353_OK;
}

dtGateDriverController_vgsStatus GateDriverController_getVgsStatus_Impl(void)
{
    return instance.vgsStatus;
}

/* DriverControl Getter and Setter */
IDRV8353_StatusType GateDriverController_setDriverControl_Impl(dtGateDriverController_driverControl driverControl)
{
    instance.driverControl = driverControl;
    return IDRV8353_OK;
}

dtGateDriverController_driverControl GateDriverController_getDriverControl_Impl(void)
{
    return instance.driverControl;
}

/* GateDriveHS Getter and Setter */
IDRV8353_StatusType GateDriverController_setGateDriveHS_Impl(dtGateDriverController_gateDriveHS gateDriveHS)
{
    instance.gateDriveHS = gateDriveHS;
    return IDRV8353_OK;
}

dtGateDriverController_gateDriveHS GateDriverController_getGateDriveHS_Impl(void)
{
    return instance.gateDriveHS;
}

/* GateDriveLS Getter and Setter */
IDRV8353_StatusType GateDriverController_setGateDriveLS_Impl(dtGateDriverController_gateDriveLS gateDriveLS)
{
    instance.gateDriveLS = gateDriveLS;
    return IDRV8353_OK;
}

dtGateDriverController_gateDriveLS GateDriverController_getGateDriveLS_Impl(void)
{
    return instance.gateDriveLS;
}

/* OCPControl Getter and Setter */
IDRV8353_StatusType GateDriverController_setOCPControl_Impl(dtGateDriverController_ocpControl ocpControl)
{
    instance.ocpControl = ocpControl;
    return IDRV8353_OK;
}

dtGateDriverController_ocpControl GateDriverController_getOCPControl_Impl(void)
{
    return instance.ocpControl;
}

/* toString() Implementation */
char* GateDriverController_toString(void)
{
    char* output = (char*)malloc(512); // Yeterli bir buffer boyutu
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


/* Constructor Implementation */
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
    instance.faultReg1.word = 0x0000; // Default value for FaultReg1
    instance.vgsStatus.word = 0x0000; // Default value for VgsStatus
    instance.driverControl.word = 0x0000; // Default value for DriverControl

    /* GateDriveHS (LOCK = 011b, IDRIVEP_HS = 1111b, IDRIVEN_HS = 1111b) */
    instance.gateDriveHS.control_bits.LOCK = 0b011;
    instance.gateDriveHS.control_bits.IDRIVEP_HS = 0b1111;
    instance.gateDriveHS.control_bits.IDRIVEN_HS = 0b1111;

    /* GateDriveLS (CBC = 1b, TDRIVE = 11b, IDRIVEP_LS = 1111b, IDRIVEN_LS = 1111b) */
    instance.gateDriveLS.control_bits.CBC = 0b1;
    instance.gateDriveLS.control_bits.TDRIVE = 0b11;
    instance.gateDriveLS.control_bits.IDRIVEP_LS = 0b1111;
    instance.gateDriveLS.control_bits.IDRIVEN_LS = 0b1111;

    /* OCPControl (TRETRY = 0b, DEAD_TIME = 01b, OCP_MODE = 01b, OCP_DEG = 10b, VDS_LVL = 1101b) */
    instance.ocpControl.control_bits.TRETRY = 0b0;
    instance.ocpControl.control_bits.DEAD_TIME = 0b01;
    instance.ocpControl.control_bits.OCP_MODE = 0b01;
    instance.ocpControl.control_bits.OCP_DEG = 0b10;
    instance.ocpControl.control_bits.VDS_LVL = 0b1101; // Default 1.0 V
}


/* Singelton Instance Getter */
dtGateDriverController* GateDriverController_GetInstance(void)
{
    return &instance;
}
