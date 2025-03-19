// main.c
#include "acceleration_control_public.h"
#include <stdio.h>

int main() {
    Acceleration_setThrottle(0.8f);
    printState();
    return 0;
}