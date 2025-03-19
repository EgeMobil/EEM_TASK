/**
 * @file AcceleratorPedalManager_ruProsses.c
 * @brief Contains the process management and state machine logic for the Accelerator Pedal Manager module.
 *
 * This file includes the implementation of the `AcceleratorPedalManager_ruProsses` function, 
 * which is responsible for controlling the state machine of the Accelerator Pedal Manager system.
 * 
 * The function operates in a state machine model with three key states:
 * - `APMru_Check`: The system performs voltage conversion using `AcceleratorPedalManager_ruConversion`. 
 *   After the conversion, the state transitions to `APMru_Conversion`.
 * - `APMru_Conversion`: The system checks the validity of the voltage values using `AcceleratorPedalManager_ruCheck`.
 *   After the check, the state transitions to `APMru_Update`.
 * - `APMru_Update`: The system performs updates with `AcceleratorPedalManager_ruUpdate`. 
 *   After the update, the process is reset to `APMru_Check`.
 * @author erhan can
 * @date 20.02.2025
 */


#include "AcceleratorPedalManager_private.h"


/**
 * @brief The current state of the Accelerator Pedal Manager process.
 *
 * This variable holds the current state of the Accelerator Pedal Manager system, 
 * which is used in the state machine to control the flow of operations. The value 
 * of `APMru_prosses` determines which step in the process the system is currently executing.
*/
dtAPMru_prosses APMru_prosses;

/**
 * @brief Manages the state transitions and operations for the Accelerator Pedal Manager system.
 *
 * This function controls the state machine of the Accelerator Pedal Manager by performing
 * different tasks based on the current state (`APMru_prosses`). It handles three main states:
 * 
 * - `APMru_Check`:
 * - `APMru_Conversion`: 
 * - `APMru_Update`: 
 * 
 * This function ensures the sequential execution of the Accelerator Pedal Manager operations 
 * and facilitates the correct flow of the state machine.
 */
void AcceleratorPedalManager_ruProsses(void)
{
    /* switch case for state machine */
    switch (APMru_prosses)
    {
        case APMru_Check:
            AcceleratorPedalManager_ruConversion();
            APMru_prosses = APMru_Conversion;
        break;

        case APMru_Conversion:
            AcceleratorPedalManager_ruCheck();
            APMru_prosses = APMru_Update;
        break;

        case APMru_Update:
            AcceleratorPedalManager_ruUpdate();
            APMru_prosses = APMru_Check;
        break;



    }
}