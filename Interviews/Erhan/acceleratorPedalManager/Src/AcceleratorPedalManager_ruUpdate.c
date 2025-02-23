/**
 * @file AcceleratorPedalManager_ruUpdate.c
 * @brief This file contains the implementation of the `AcceleratorPedalManager_ruUpdate` function.
 * 
 * The `AcceleratorPedalManager_ruUpdate` function is responsible for updating the Accelerator Pedal 
 * Manager system, sending data to the motor driver, and managing timing intervals.
 * @author erhan can
 * @date 20.02.2025
 */ 
 
#include "AcceleratorPedalManager_private.h"


/**
 * @brief Updates the motor driver data and dashboard data.
 * 
 * This function updates the motor driver data by calling the function pointed to by 
 * `setApmMotorDriverDataPtr` with the calculated motor value (`VolageToMotorValue`). 
 * It also updates the dashboard data by calling the function pointed to by 
 * `setApmDashboardDataPtr` with the calculated dashboard value (`VolageToDashboardValue`). 
 * Additionally, it updates the `intervalLastTick` with the current system tick value from `HAL_GetTick()`.
 * 
 * This function is responsible for sending updated values to both the motor driver and the dashboard.
 */
void AcceleratorPedalManager_ruUpdate(void)
{
    AcceleratorPedalManager.setApmMotorDriverDataPtr(VolageToMotorValue() );
    AcceleratorPedalManager.setApmDashboardDataPtr(VolageToDashboardValue());
    serial_message("veriler set edildi");
    intervalLastTick  = HAL_GetTick();
}