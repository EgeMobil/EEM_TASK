/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include "unistd.h"

typedef enum {
    wait,
    temperatureMeasure,
    heatingControl,
    coolingControl
}stateMachine;

float temperatureSensor(void){
    //tempereture measure codes..
    return 28.2f;
}

void heater(float temperature){
    if(temperature<18.0f){
        //heater on
        printf("Heater ON\n");
    }else{
        //heater off
        printf("Heater OFF\n");
    }
}

void cooler(float temperature){
    if(temperature>28.0f){
        //cooler on
        printf("Cooler ON\n");
    }else{
        //cooler off
        printf("Cooler OFF\n");
    }
}

void shutdown(){
    //cooler off
    printf("Cooler OFF\n");
    //heater off
    printf("Heater OFF\n");
}

void main(void)
{
    stateMachine currentState=temperatureMeasure;
    float temperature=0;
    
    while(1){
        switch (currentState)
        {
        case wait:
            printf("Waiting for next measurement.\n");
            sleep(10);
            currentState=temperatureMeasure;
            break;
        case temperatureMeasure:
            printf("Temperature Measuring.\n");
            temperature = temperatureSensor();
            currentState=heatingControl;
            break;
        case heatingControl:
            printf("Heating controlling.\n");
            heater(temperature);
            currentState=coolingControl;
            break;
        case coolingControl:
            printf("Cooling controlling.\n");
            cooler(temperature);
            currentState=wait;
            break;
        default:
            printf("Wrong State, Everythin will set OFF.\n");
            return;
            break;
        }
    }
}
