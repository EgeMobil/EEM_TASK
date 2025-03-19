#ifndef LED_H
#define LED_H

#include <stdint.h>
#include <stdio.h>
#include "BUTTON.h"

void LED_Init();
void LED_Write();
void LED_IDLE();
void LED_MODE_1();
void LED_MODE_2();
void LED_MODE_3();
void delay(uint32_t time);

#endif