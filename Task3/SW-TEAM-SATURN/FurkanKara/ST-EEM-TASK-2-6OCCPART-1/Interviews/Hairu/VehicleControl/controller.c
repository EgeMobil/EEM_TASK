/**
 * @file controller.c
 * @author Hairu
 * @brief Deligates data retrieval to the system layer and source layer
 * @version 0.1
 * @date 2025-02-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "controller.h"
#include "system.h"
#include "source.h"
#include <stdio.h>

/**
 * @brief Deligate the task of reading potentiometer 1 value to the system layer
 * 
 * @return int 
 */
int Controller_GetPot1Reading(void){
    printf("Pot 1 Reading request is successfully  deligated to Sytem layer! \n");
    return System_GetPot1Reading();
}

/**
 * @brief Deligate the task of reading potentiometer 2 value to the system layer
 * 
 * @return int 
 */
int Controller_GetPot2Reading(void){
    printf("Pot 2 Reading request is successfully  deligated to Sytem layer! \n");
    return System_GetPot2Reading();
}

/**
 * @brief Deligate the task of reading min speed value to the source layer
 * 
 * @return int 
 */
int Controller_GetMinSpeed(void){
    printf("Minimum speed read request from EEPROM is deligated to Source layer! \n");
    return Source_GetMinSpeed();
}

/**
 * @brief Deligate the task of reading max speed value to the source layer
 * 
 * @return int 
 */
int Controller_GetMaxSpeed(void){
    printf("Maximum speed read request FROM eeprom is deligated to Source layer! \n");
    return Source_GetMaxSpeed();
}