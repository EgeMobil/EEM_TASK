/**
 * @file AcceleratorPedalManager_ruInitialisation.c
 * @brief Contains the initialization logic for the Accelerator Pedal Manager module.
 *
 * This file includes the implementation of the `AcceleratorPedalManager_ruInitialisation` 
 * function, which is responsible for initializing the state of the Accelerator Pedal Manager system.
 * @author erhan can
 * @date 20.02.2025
 */
#include "AcceleratorPedalManager_private.h"



/**
 * @brief Initializes the Accelerator Pedal Manager system by setting the initial state.
 *
 * This function sets the initial state of the Accelerator Pedal Manager system by 
 * assigning the value `APMru_Check` to the `APMru_prosses` variable. 
 * This state serves as the starting point for the state machine, preparing the system 
 * for further checks and processing.
 */
void AcceleratorPedalManager_ruInitialisation(void)
{
    APMru_prosses = APMru_Check;
    serial_message("state macihne için init işlemi yapıldı");
}
