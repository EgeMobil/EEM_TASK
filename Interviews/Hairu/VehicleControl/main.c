
/**
 * @file main.c
 * @author Hairu
 * @brief Main entry point of the application
 * @version 0.1
 * @date 2025-02-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "source.h"
#include "interface.h"
#include "controller.h"
#include "application.h"
#include <unistd.h>

int main(void)
{
    // 1. System initialization
    System_Init();

    // 2. Initialize other layers
    Source_Init();
    Interface_Init();
    Application_Init();
    
    // 3. Main loop
    while (1)
    {
        
        Application_RunCycle();
        
        // 10 ms delay
        usleep(10000);
    }

    return 0;
}
