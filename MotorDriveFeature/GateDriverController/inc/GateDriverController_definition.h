#ifndef GATEDRIVERCONTROLLER_DEFINITION_H_
#define GATEDRIVERCONTROLLER_DEFINITION_H_

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

/* ECU StateManager Global Include*/
#include "ECUStateManager_global.h"

/* Receiver Port Interface Definition Include */
#include "IDRV8353.h"

/* Sender Port Interface Definition Include */

/* Base Return Value Definition */
typedef enum
{
    GDC_ERR = 0,
    GDC_EOK ,
    GDC_UNKNOWN
}dtGdcReturn;

/* Compu Method Alias Type Definitions */
typedef dtGdcReturn dtGateDriverController_gdcReturn;

typedef cmFaultReg1     dtGateDriverController_faultReg1;
typedef cmVgsStatus     dtGateDriverController_vgsStatus;
typedef cmDriverControl dtGateDriverController_driverControl;
typedef cmGateDriveHS   dtGateDriverController_gateDriveHS;
typedef cmGateDriveLS   dtGateDriverController_gateDriveLS;
typedef cmOCPControl    dtGateDriverController_ocpControl;

/* Configuration Child-Class Definition (IF NEEDED!) */

/* BaseClass Definition */
typedef struct 
{
    /* Interface Pointer */
    IDRV8353* IDRV8353;

    /* Attributes */
    dtGateDriverController_faultReg1 faultReg1;
    dtGateDriverController_vgsStatus vgsStatus;
    dtGateDriverController_driverControl driverControl;
    dtGateDriverController_gateDriveHS gateDriveHS;
    dtGateDriverController_gateDriveLS gateDriveLS;
    dtGateDriverController_ocpControl ocpControl;

    /* Getter/Setter Function Pointers */
    IDRV8353_StatusType (*setFaultReg1)(dtGateDriverController_faultReg1 faultReg1);
    dtGateDriverController_faultReg1 (*getFaultReg1)(void);

    IDRV8353_StatusType (*setVgsStatus)(dtGateDriverController_vgsStatus vgsStatus);
    dtGateDriverController_vgsStatus (*getVgsStatus)(void);

    IDRV8353_StatusType (*setDriverControl)(dtGateDriverController_driverControl driverControl);
    dtGateDriverController_driverControl (*getDriverControl)(void);

    IDRV8353_StatusType (*setGateDriveHS)(dtGateDriverController_gateDriveHS gateDriveHS);
    dtGateDriverController_gateDriveHS (*getGateDriveHS)(void);

    IDRV8353_StatusType (*setGateDriveLS)(dtGateDriverController_gateDriveLS gateDriveLS);
    dtGateDriverController_gateDriveLS (*getGateDriveLS)(void);

    IDRV8353_StatusType (*setOCPControl)(dtGateDriverController_ocpControl ocpControl);
    dtGateDriverController_ocpControl (*getOCPControl)(void);

    /* toString Function Pointer */
    char* (*toString)(void);

}dtGateDriverController;


#endif /* GATEDRIVERCONTROLLER_DEFINITION_H_ */