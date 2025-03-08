#ifndef LDR_CONTROL_H
#define LDR_CONTROL_H

typedef enum{
    IDLE,
    LED_ON,
    LED_OFF
}State;

typedef struct{
    int threshold;
    int hysteresis;
    State currentState;
}LdrControl;

void initLdrControl(LdrControl *ldr, int threshold, int hysteresis);
void updateLdrState(LdrControl *ldr, int ldrValue);

#endif
