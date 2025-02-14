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
#else
    DRV8353_Init();
#endif
}

uint16_t DRV8353_Read_Impl(uint8_t reg_addr)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Read from register addr: 0x%02X, returning 0x07FF for test\n", reg_addr);
    return 0x07FF; // Simulated value
#else
    return DRV8353_Read(reg_addr);
#endif
}

uint16_t DRV8353_Write_Impl(uint8_t reg_addr, uint16_t reg_value)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Write to register: 0x%02X, Value: 0x%04X\n", reg_addr, reg_value);
    return reg_value;
#else
    return DRV8353_Write(reg_addr, reg_value);
#endif
}

uint8_t DRV8353_SetGain_Impl(uint8_t gain)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Gain set to: %d\n", gain);
    return gain;
#else
    return (DRV8353_SetGain((DRV_Gain)gain) == RETVAL_OK) ? IDRV8353_OK : IDRV8353_NOT_OK;
#endif
}

uint8_t DRV8353_GetGain_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Gain retrieved, returning test value 0x01.\n");
    return 0x01;
#else
    return DRV8353_GetGain();
#endif
}

uint8_t DRV8353_SetVDSLimit_Impl(uint8_t lmt)
{
#ifndef STM32G431xx
    printf("[IDRV8353] VDS Limit set to: %d\n", lmt);
    return lmt;
#else
    return (DRV8353_SetVDSLimit((DRV_VDS_Limit)lmt) == RETVAL_OK) ? IDRV8353_OK : IDRV8353_NOT_OK;
#endif
}

uint8_t DRV8353_GetVDSLimit_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] VDS Limit retrieved, returning test value 0x02.\n");
    return 0x02;
#else
    return DRV8353_GetVDSLimit();
#endif
}

uint8_t DRV8353_SetGateStrength_Impl(uint32_t strength)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Gate strength set to: %u\n", strength);
    return 0x01; // Simulate success
#else
    return (DRV8353_SetGateStrength(strength) == RETVAL_OK) ? IDRV8353_OK : IDRV8353_NOT_OK;
#endif
}

uint32_t DRV8353_GetGateStrength_Impl(void)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Gate strength retrieved, returning test value 0x01.\n");
    return 0x01;
#else
    return DRV8353_GetGateStrength();
#endif
}

void DRV8353_SetCalibration_Impl(uint8_t channel)
{
#ifndef STM32G431xx
    printf("[IDRV8353] Calibration set for channel: %d\n", channel);
#else
    DRV8353_SetCalibration(channel);
#endif
}
