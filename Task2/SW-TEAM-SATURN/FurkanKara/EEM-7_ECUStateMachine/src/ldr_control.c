#include "ldr_control.h"
#include <stdio.h>

void initLdrControl(LdrControl *ldr, int threshold, int hysteresis){
    ldr->threshold = threshold;
    ldr->hysteresis = hysteresis;
    ldr->currentState = IDLE;
}

void updateLdrState(LdrControl *ldr, int ldrValue){
    switch(ldr->currentState){
        case IDLE:
            if(ldrValue < ldr->threshold){
                ldr->currentState = LED_ON;
                printf("LED Acildi\n");
            }
            break;

        case LED_ON:
            if(ldrValue > ldr->threshold + ldr->hysteresis){
                ldr->currentState = LED_OFF;
                printf("LED Kapandi\n");
            }
            break;
        
        case LED_OFF:
            if(ldrValue < ldr->threshold){
                ldr->currentState = LED_ON;
                printf("LED Tekar Acildi\n");
            }
            break;
    }
}