
/**
 * @file AcceleratorPedalManager_ruCheck.c
 * @brief Functions to check and validate the incoming data for the accelerator pedal system.
 *
 * This file contains the implementation of the `AcceleratorPedalManager_ruCheck` function, which is responsible 
 * for checking and validating the incoming data from the accelerator pedal system. The function performs two key 
 * checks:
 * 1. Verifies the correctness of the voltage values by using a checksum function to compare primary and 
 *    complementary voltages.
 * 2. Checks the gear position using the `gearControlPtr` function to ensure the gear is in the correct position.
 * 
 * Based on the results of these checks, the function triggers appropriate actions, such as updating the system 
 * state or notifying the user of errors. It helps ensure that the accelerator pedal system operates within the 
 * desired parameters and that necessary actions are taken in case of errors or inconsistencies.
 * @author erhan can
 * @date 20.02.2025
 */


#include "AcceleratorPedalManager_private.h"


/**
 * @brief Checks the correctness of voltage values and gear position.
 *
 * This function performs two main checks:
 * 1. It validates the primary and complementary voltage values using the checksum function.
 *    - If the voltage values are correct, a success message is sent.
 *    - If the voltage values are incorrect, an error message is sent, and the process state is set to `APMru_Check`.
 * 2. It verifies the gear position using the `gearControlPtr` function.
 *    - If the gear is in the correct position, a success message is sent, and the process state is set to `APMru_Update`.
 *    - If the gear is in the incorrect position, an error message is sent, and the process state is set to `APMru_Check`.
 *
 * The function handles the transition between different states of the Accelerator Pedal Manager based on the results 
 * of these checks, ensuring the system operates correctly before proceeding.
 */
void AcceleratorPedalManager_ruCheck(void)
{
    /* Checks the accuracy of incoming voltage values */
    if( APM_EOK == AcceleratorPedalManager.checkSumVoltagePtr( AcceleratorPedalManager.dataVoltagePrimary, AcceleratorPedalManager.dataVoltageComplementary ))
    {
        serial_message("apm check voltage ok\n");
    }else
    {
        
        serial_message("apm check voltage eror\n");
        APMru_prosses = APMru_Check;
    }
     /* Checks that the incoming gear is in the correct position */
    if( AcceleratorPedalManager.gearControlPtr() == 1 )
    {
        serial_message("vites doğru konumda\n");
        APMru_prosses = APMru_Update; 
    }else
    {
        serial_message("vites yanlış konumda\n");
        APMru_prosses = APMru_Check;
    }
}