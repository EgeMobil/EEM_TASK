/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "GateDriverController_private.h"

FUNC(void, GateDriverController_ruRefresh)(void)
{
    /* Get Singleton Instance */
    dtGateDriverController* gdc = GateDriverController_GetInstance();

    /* Read register and Update Attributes */
    gdc->setFaultReg1(gdc->IDRV8353->readFaultReg1());
    gdc->setVgsStatus(gdc->IDRV8353->readVgsStatus());
    //gdc->setDriverControl(gdc->IDRV8353->readDriverControl());
    //gdc->setGateDriveHS(gdc->IDRV8353->readGateDriveHS());
    //gdc->setGateDriveLS(gdc->IDRV8353->readGateDriveLS());
    //gdc->setOCPControl(gdc->IDRV8353->readOCPControl());

    /* Check Errors and report if needed */
    /* Check Errors in FaultReg1 */
    if (gdc->getFaultReg1().status_bits.FAULT == FAULT_ACTIVE)
    {
        // Report FAULT error
    }
    if (gdc->getFaultReg1().status_bits.VDS_OCP == VDS_OCP_ACTIVE)
    {
        // Report VDS_OCP error
    }
    if (gdc->getFaultReg1().status_bits.GDF == GDF_ACTIVE)
    {
        // Report Gate Drive Fault (GDF)
    }
    if (gdc->getFaultReg1().status_bits.UVLO == UVLO_ACTIVE)
    {
        // Report Undervoltage Lockout (UVLO)
    }
    if (gdc->getFaultReg1().status_bits.OTSD == OTSD_ACTIVE)
    {
        // Report Overtemperature Shutdown (OTSD)
    }
    if (gdc->getFaultReg1().status_bits.VDS_HA == VDS_HA_ACTIVE)
    {
        // Report VDS Fault in Phase HA
    }
    if (gdc->getFaultReg1().status_bits.VDS_LA == VDS_LA_ACTIVE)
    {
        // Report VDS Fault in Phase LA
    }
    if (gdc->getFaultReg1().status_bits.VDS_HB == VDS_HB_ACTIVE)
    {
        // Report VDS Fault in Phase HB
    }
    if (gdc->getFaultReg1().status_bits.VDS_LB == VDS_LB_ACTIVE)
    {
        // Report VDS Fault in Phase LB
    }
    if (gdc->getFaultReg1().status_bits.VDS_HC == VDS_HC_ACTIVE)
    {
        // Report VDS Fault in Phase HC
    }
    if (gdc->getFaultReg1().status_bits.VDS_LC == VDS_LC_ACTIVE)
    {
        // Report VDS Fault in Phase LC
    }
    
    /* Check Errors in VgsStatus */
    if (gdc->getVgsStatus().status_bits.SA_OC == SA_OC_ACTIVE)
    {
        // Report Overcurrent Fault in Phase SA
    }
    if (gdc->getVgsStatus().status_bits.SB_OC == SB_OC_ACTIVE)
    {
        // Report Overcurrent Fault in Phase SB
    }
    if (gdc->getVgsStatus().status_bits.SC_OC == SC_OC_ACTIVE)
    {
        // Report Overcurrent Fault in Phase SC
    }
    if (gdc->getVgsStatus().status_bits.OTW == OTW_ACTIVE)
    {
        // Report Overtemperature Warning (OTW)
    }
    if (gdc->getVgsStatus().status_bits.GDUV == GDUV_ACTIVE)
    {
        // Report Gate Driver Undervoltage Fault (GDUV)
    }
    if (gdc->getVgsStatus().status_bits.VGS_HA == VGS_HA_ACTIVE)
    {
        // Report Gate-Source Voltage Fault in Phase HA
    }
    if (gdc->getVgsStatus().status_bits.VGS_LA == VGS_LA_ACTIVE)
    {
        // Report Gate-Source Voltage Fault in Phase LA
    }
    if (gdc->getVgsStatus().status_bits.VGS_HB == VGS_HB_ACTIVE)
    {
        // Report Gate-Source Voltage Fault in Phase HB
    }
    if (gdc->getVgsStatus().status_bits.VGS_LB == VGS_LB_ACTIVE)
    {
        // Report Gate-Source Voltage Fault in Phase LB
    }
    if (gdc->getVgsStatus().status_bits.VGS_HC == VGS_HC_ACTIVE)
    {
        // Report Gate-Source Voltage Fault in Phase HC
    }
    if (gdc->getVgsStatus().status_bits.VGS_LC == VGS_LC_ACTIVE)
    {
        // Report Gate-Source Voltage Fault in Phase LC
    }


}
