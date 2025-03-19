#include "../include/pedal_control.h"
#include <stdio.h>
#include <windows.h> // sleep fonksiyonu için

// Ana program döngüsü
int main() {
    float sensor1, sensor2;
    
    while (1) {
        read_pedal_sensors(&sensor1, &sensor2);
        process_pedal_input(sensor1, sensor2);
        printf("Sensor1: %.2f V, Sensor2: %.2f V\n", sensor1, sensor2);

        Sleep(10); // 10 ms bekleme
    }
    
    return 0;
}