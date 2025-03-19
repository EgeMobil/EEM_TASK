/**
 * @file source.c
 * @author Hairu
 * @brief This layer is responsible for reading the min and max speed values from the EEPROM.
 * @version 0.1
 * @date 2025-02-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "source.h"
#include <stdio.h>

/*VariableS to mimic reading from EEPROM*/
static int minSpeed = 0;
static int maxSpeed = 100;


/**
 * @brief Initializes EEPROM
 * 
 */
void Source_Init(void)
{    
    //EEPROM_Init();
    printf("EEPROM initialized successfully! \n");
}


/**
 * @brief Provides the minimum speed value
 * 
 * @return int 
 */
int Source_GetMinSpeed(void)
{
    // minSpeed = EEPROM_Read(MIN_SPEED_ADDRESS);
    printf("Min Speed read successfully from EEPROM! \n");
    return minSpeed;
}


/**
 * @brief Provides the maximum speed value
 * 
 * @return int 
 */
int Source_GetMaxSpeed(void)
{
    // maxSpeed = EEPROM_Read(MAX_SPEED_ADDRESS);
    printf("Max Speed read successfully from EEPROM! \n");
    return maxSpeed;
}
 