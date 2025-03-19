/**
 * @file system.c
 * @author Hairu
 * @brief Low level, hardware dependent codes are implemented here.
 * @version 0.1
 * @date 2025-02-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include "system.h"
#include <stdio.h>

void System_Init(void){
    // Initialize potentiometers and motor pins.
    // Timer is initialized
    // ADC is initialized


    // motor_pin_init();
    // pot_pin_init();
    // timer_init();
    // adc_init();
    printf("pot and and motor pins initialized successfully! \n");
    printf("Timer initialized successfully! \n");
    printf("ADC initialized successfully! \n");
}

/**
 * @brief reads potentiometer 1 value (0.5 - 4.5V)
 * 
 * @return int 
 */
int System_GetPot1Reading(void){
    
    // normally int read_value = adc_read(pot1_pin);
    // but for now I will just set read_value to 10
    int read_value = 10;
    printf("ADC value of Pot 1 is read successfully! \n");
    return read_value;

}

/**
 * @brief reads potentiometer 2 value (0.5 - 4.5V)
 * 
 * @return int 
 */
int System_GetPot2Reading(void){
    
    // normally int read_value = adc_read(pot2_pin);
    // but for now I will just set read_value to 10
    int read_value = 10;
    printf("ADC value of Pot 2 is read successfully! \n");
    return read_value;

}

/**
 * @brief sets the motor speed (0-100%)
 * 
 * @param speed 
 */
void System_SetMotorSpeed(int speed){
    // normally motor_set_speed(speed);
    // but for now I will just print the speed
    printf("Motor speed is set to %d \n", speed);
}

/**
 * @brief sets the motor torque (0-100%)
 * 
 * @param torque 
 */
void System_SetMotorTorque(int torque){
    // normally motor_set_speed(speed);
    // but for now I will just print the speed
    printf("Motor torque is set to %d \n", torque);
}