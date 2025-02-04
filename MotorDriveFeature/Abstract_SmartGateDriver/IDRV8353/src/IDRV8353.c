#include "IDRV8353.h"

// Registers
#define ADDR_DRVREG_FAULT1       0x00
#define ADDR_DRVREG_VGSSTATUS    0x01
#define ADDR_DRVREG_CTRL         0x02
#define ADDR_DRVREG_GATEH        0x03
#define ADDR_DRVREG_GATEL        0x04
#define ADDR_DRVREG_OCP          0x05
#define ADDR_DRVREG_CSA          0x06
#define ADDR_DRVREG_CAL          0x07

IDRV8353 DRV8353Interface = {
    .writeFaultReg1 = IDRV8353_writeFaultReg1_Impl,
    .readFaultReg1 = IDRV8353_readFaultReg1_Impl,

    .writeVgsStatus = IDRV8353_writeVgsStatus_Impl,
    .readVgsStatus = IDRV8353_readVgsStatus_Impl,

    .writeDriverControl = IDRV8353_writeDriverControl_Impl,
    .readDriverControl = IDRV8353_readDriverControl_Impl,

    .writeGateDriveHS = IDRV8353_writeGateDriveHS_Impl,
    .readGateDriveHS = IDRV8353_readGateDriveHS_Impl,

    .writeGateDriveLS = IDRV8353_writeGateDriveLS_Impl,
    .readGateDriveLS = IDRV8353_readGateDriveLS_Impl,

    .writeOCPControl = IDRV8353_writeOCPControl_Impl,
    .readOCPControl = IDRV8353_readOCPControl_Impl,

    /* Complex Device Driver Access */
    .Init = DRV8353_Init_Impl,
    .Transaction = DRV8353_Transaction_Impl,
    .Read = DRV8353_Read_Impl,
    .Write = DRV8353_Write_Impl,
    .SetGain = DRV8353_SetGain_Impl,
    .GetGain = DRV8353_GetGain_Impl,
    .SetVDSLimit = DRV8353_SetVDSLimit_Impl,
    .GetVDSLimit = DRV8353_GetVDSLimit_Impl,
    .SetGateStrength = DRV8353_SetGateStrength_Impl,
    .GetGateStrength = DRV8353_GetGateStrength_Impl,
    .SetCalibration = DRV8353_SetCalibration_Impl
};

/* Static Variables for Register Storage */
static cmFaultReg1 currentFaultReg1;
static cmVgsStatus currentVgsStatus;
static cmDriverControl currentDriverControl;
static cmGateDriveHS currentGateDriveHS;
static cmGateDriveLS currentGateDriveLS;
static cmOCPControl currentOCPControl;

/* Register Access Implementation */
IDRV8353_StatusType IDRV8353_writeFaultReg1_Impl(cmFaultReg1 fault)
{
#ifndef STM32G431xx
    printf("[IDRV8353] FaultReg1 written: 0x%04X\n", fault.word);
#endif
    currentFaultReg1 = fault;
    DRV8353Interface.Write(ADDR_DRVREG_FAULT1, fault.word);
    return IDRV8353_OK;
}

cmFaultReg1 IDRV8353_readFaultReg1_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] FaultReg1 read: 0x%04X\n", currentFaultReg1.word);
#endif
    currentFaultReg1.word = DRV8353Interface.Read(ADDR_DRVREG_FAULT1);
    return currentFaultReg1;
}

IDRV8353_StatusType IDRV8353_writeVgsStatus_Impl(cmVgsStatus status)
{
#ifndef STM32G431xx
    printf("[IDRV8353] VgsStatus written: 0x%04X\n", currentVgsStatus.word);
#endif
    currentVgsStatus = status;
    DRV8353Interface.Write(ADDR_DRVREG_VGSSTATUS, currentVgsStatus.word);
    return IDRV8353_OK;
}

cmVgsStatus IDRV8353_readVgsStatus_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] VgsStatus read: 0x%04X\n", currentVgsStatus.word);
#endif
    currentVgsStatus.word = DRV8353Interface.Read(ADDR_DRVREG_VGSSTATUS);
    return currentVgsStatus;
}

IDRV8353_StatusType IDRV8353_writeDriverControl_Impl(cmDriverControl control)
{
#ifndef STM32G431xx
    printf("[IDRV8353] DriverControl written: 0x%04X\n", control.word);
#endif
    currentDriverControl = control;
    return IDRV8353_OK;
}

cmDriverControl IDRV8353_readDriverControl_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] DriverControl read: 0x%04X\n", currentDriverControl.word);
#endif
    return currentDriverControl;
}

IDRV8353_StatusType IDRV8353_writeGateDriveHS_Impl(cmGateDriveHS hs)
{
#ifndef STM32G431xx
    printf("[IDRV8353] GateDriveHS written: 0x%04X\n", hs.word);
#endif
    currentGateDriveHS = hs;
    return IDRV8353_OK;
}

cmGateDriveHS IDRV8353_readGateDriveHS_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] GateDriveHS read: 0x%04X\n", currentGateDriveHS.word);
#endif
    return currentGateDriveHS;
}

IDRV8353_StatusType IDRV8353_writeGateDriveLS_Impl(cmGateDriveLS ls)
{
#ifndef STM32G431xx
    printf("[IDRV8353] GateDriveLS written: 0x%04X\n", ls.word);
#endif
    currentGateDriveLS = ls;
    return IDRV8353_OK;
}

cmGateDriveLS IDRV8353_readGateDriveLS_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] GateDriveLS read: 0x%04X\n", currentGateDriveLS.word);
#endif
    return currentGateDriveLS;
}

IDRV8353_StatusType IDRV8353_writeOCPControl_Impl(cmOCPControl ocp)
{
#ifndef STM32G431xx
    printf("[IDRV8353] OCPControl written: 0x%04X\n", ocp.word);
#endif
    currentOCPControl = ocp;
    return IDRV8353_OK;
}

cmOCPControl IDRV8353_readOCPControl_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] OCPControl read: 0x%04X\n", currentOCPControl.word);
#endif
    return currentOCPControl;
}

/* Complex Device Driver Access Implementation */
void DRV8353_Init_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Initialization performed.\n");
#endif
}

uint16_t DRV8353_Transaction_Impl(uint16_t DataOut)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Transaction with DataOut: 0x%04X\n", DataOut);
#endif
    return DataOut; // Simulate a transaction returning the same data
}

uint16_t DRV8353_Read_Impl(uint8_t reg_addr)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Read from register addr: 0x%02X value is 0x7FF for test \n", reg_addr);
#endif
    return 0x7FF; // Simulate reading the maximum possible value
}

uint16_t DRV8353_Write_Impl(uint8_t reg_addr, uint16_t reg_value)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Write to register: 0x%02X, Value: 0x%04X\n", reg_addr, reg_value);
#endif
    return reg_value; // Simulate writing and returning the written value
}

uint8_t DRV8353_SetGain_Impl(uint8_t gain)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Gain set to: %d\n", gain);
#endif
    return gain;
}

uint8_t DRV8353_GetGain_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Gain retrieved.\n");
#endif
    return 0x01; // Simulate a gain value
}

uint8_t DRV8353_SetVDSLimit_Impl(uint8_t lmt)
{
#ifndef STM32G431xx
    printf("[IDRV8353] VDS Limit set to: %d\n", lmt);
#endif
    return lmt;
}

uint8_t DRV8353_GetVDSLimit_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] VDS Limit retrieved.\n");
#endif
    return 0x02; // Simulate a limit value
}

uint8_t DRV8353_SetGateStrength_Impl(uint32_t strength)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Gate strength set to: %u\n", strength);
#endif
    return 0x01; // Simulate success
}

uint32_t DRV8353_GetGateStrength_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Gate strength retrieved.\n");
#endif
    return 0x01; // Simulate a gate strength value
}

void DRV8353_SetCalibration_Impl(uint8_t channel)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Calibration set for channel: %d\n", channel);
#endif
}
