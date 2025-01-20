#ifndef IDRV8353_H_
#define IDRV8353_H_

#include "Abstract_SmartGateDriver.h"

/**
 * @brief Status type for the IDRV8353 interface.
 */
typedef enum
{
    IDRV8353_OK = 0,        /**< Operation completed successfully. */
    IDRV8353_NOT_OK         /**< Operation failed. */
} IDRV8353_StatusType;

/**
 * @brief Structure defining the function pointers for IDRV8353 interface.
 */
typedef struct
{
    IDRV8353_StatusType (*writeFaultReg1)(cmFaultReg1 fault);
    cmFaultReg1 (*readFaultReg1)(void);

    IDRV8353_StatusType (*writeVgsStatus)(cmVgsStatus status);
    cmVgsStatus (*readVgsStatus)(void);

    IDRV8353_StatusType (*writeDriverControl)(cmDriverControl control);
    cmDriverControl (*readDriverControl)(void);

    IDRV8353_StatusType (*writeGateDriveHS)(cmGateDriveHS hs);
    cmGateDriveHS (*readGateDriveHS)(void);

    IDRV8353_StatusType (*writeGateDriveLS)(cmGateDriveLS ls);
    cmGateDriveLS (*readGateDriveLS)(void);

    IDRV8353_StatusType (*writeOCPControl)(cmOCPControl ocp);
    cmOCPControl (*readOCPControl)(void);

    /* Complex Device Driver Access */
    void (*Init)(void);
    uint16_t (*Transaction)(uint16_t DataOut);
    uint16_t (*Read)(uint8_t reg_addr);
    uint16_t (*Write)(uint8_t reg_addr, uint16_t reg_value);
    uint8_t (*SetGain)(uint8_t gain);
    uint8_t (*GetGain)(void);
    uint8_t (*SetVDSLimit)(uint8_t lmt);
    uint8_t (*GetVDSLimit)(void);
    uint8_t (*SetGateStrength)(uint32_t strength);
    uint32_t (*GetGateStrength)(void);
    void (*SetCalibration)(uint8_t channel);

} IDRV8353;

extern IDRV8353 DRV8353Interface;

/* Function prototypes */
IDRV8353_StatusType IDRV8353_writeFaultReg1_Impl(cmFaultReg1 fault);
cmFaultReg1 IDRV8353_readFaultReg1_Impl(void);

IDRV8353_StatusType IDRV8353_writeVgsStatus_Impl(cmVgsStatus status);
cmVgsStatus IDRV8353_readVgsStatus_Impl(void);

IDRV8353_StatusType IDRV8353_writeDriverControl_Impl(cmDriverControl control);
cmDriverControl IDRV8353_readDriverControl_Impl(void);

IDRV8353_StatusType IDRV8353_writeGateDriveHS_Impl(cmGateDriveHS hs);
cmGateDriveHS IDRV8353_readGateDriveHS_Impl(void);

IDRV8353_StatusType IDRV8353_writeGateDriveLS_Impl(cmGateDriveLS ls);
cmGateDriveLS IDRV8353_readGateDriveLS_Impl(void);

IDRV8353_StatusType IDRV8353_writeOCPControl_Impl(cmOCPControl ocp);
cmOCPControl IDRV8353_readOCPControl_Impl(void);

/* Function Prototypes for Complex Device Driver Access */
void DRV8353_Init_Impl(void);
uint16_t DRV8353_Transaction_Impl(uint16_t DataOut);
uint16_t DRV8353_Read_Impl(uint8_t reg_addr);
uint16_t DRV8353_Write_Impl(uint8_t reg_addr, uint16_t reg_value);
uint8_t DRV8353_SetGain_Impl(uint8_t gain);
uint8_t DRV8353_GetGain_Impl(void);
uint8_t DRV8353_SetVDSLimit_Impl(uint8_t lmt);
uint8_t DRV8353_GetVDSLimit_Impl(void);
uint8_t DRV8353_SetGateStrength_Impl(uint32_t strength);
uint32_t DRV8353_GetGateStrength_Impl(void);
void DRV8353_SetCalibration_Impl(uint8_t channel);

#endif /* IDRV8353_H_ */
