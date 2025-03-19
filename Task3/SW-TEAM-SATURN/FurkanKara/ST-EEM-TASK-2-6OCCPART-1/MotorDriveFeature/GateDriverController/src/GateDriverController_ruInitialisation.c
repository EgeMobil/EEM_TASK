/**
 * @file GateDriverController_private.c
 * @brief Private functions for the Gate Driver Controller.
 * 
 * This file contains private functions for internal use within the Gate Driver Controller.
 * It includes the initialization and refresh operations that manage the behavior of 
 * the gate driver.
 * 
 */

#include "GateDriverController_private.h"

/**
 * @brief Initialization runnable for the Gate Driver Controller.
 * 
 * This function performs the initialization tasks for the Gate Driver Controller, 
 * including setting the default configuration values and initializing the gate driver.
 * It performs the following steps:
 * - Retrieves the singleton instance of the Gate Driver Controller.
 * - Retrieves the current driver control register values.
 * - Sets the PWM mode to 1x.
 * - Updates the driver control register.
 * - Initializes the Gate Driver hardware interface.
 */
FUNC(void, GateDriverController_ruInitialisation)(void)
{  
    /* Get Singleton Instance */
    dtGateDriverController* gdc = GateDriverController_GetInstance();

    /* Initialize Attributes to Default Values */
    gdc->faultReg1.word = 0x0000;
    gdc->vgsStatus.word = 0x0000;
    gdc->driverControl.word = 0x0000;

    /* GateDriveHS default configuration */
    gdc->gateDriveHS.control_bits.LOCK = 0b011;
    gdc->gateDriveHS.control_bits.IDRIVEP_HS = 0b1111;
    gdc->gateDriveHS.control_bits.IDRIVEN_HS = 0b1111;

    /* GateDriveLS default configuration */
    gdc->gateDriveLS.control_bits.CBC = 0b1;
    gdc->gateDriveLS.control_bits.TDRIVE = 0b11;
    gdc->gateDriveLS.control_bits.IDRIVEP_LS = 0b1111;
    gdc->gateDriveLS.control_bits.IDRIVEN_LS = 0b1111;

    /* OCPControl default configuration */
    gdc->ocpControl.control_bits.TRETRY = 0b0;
    gdc->ocpControl.control_bits.DEAD_TIME = 0b01;
    gdc->ocpControl.control_bits.OCP_MODE = 0b01;
    gdc->ocpControl.control_bits.OCP_DEG = 0b10;
    gdc->ocpControl.control_bits.VDS_LVL = 0b1101; // Default 1.0 V

    /* Set PWM Mode 1x */
    gdc->driverControl.control_bits.PWM_MODE =  PWM_MODE_1_INPUT;
    
    /* Initialise Gate Driver */
    gdc->IDRV8353->Init();

    /* Read Gate Driver Registers for after init */
    gdc->setFaultReg1(gdc->IDRV8353->readFaultReg1());
    gdc->setVgsStatus(gdc->IDRV8353->readVgsStatus());;
    gdc->setDriverControl(gdc->IDRV8353->readDriverControl());
    gdc->setGateDriveHS(gdc->IDRV8353->readGateDriveHS());
    gdc->setGateDriveLS(gdc->IDRV8353->readGateDriveLS());
    gdc->setOCPControl(gdc->IDRV8353->readOCPControl());

}
