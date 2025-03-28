#include "../inc/Climate_TempSensor.h"

static float temp = 0.0;
static int direction = 1; // Changes linearly between upper and lower boundaries

float* getTemp(void) {
    return &temp;
}

void* updateTemp(void* arg) {
    float* temp = (float*)arg;  // Gelen void* argümanını float*'a çevir

    if (temp == NULL) return NULL;

    while(1) {
        *temp += direction * OFFSET;

        if (*temp >= MAX_TEMP) 
            direction = -1;
        else if (*temp <= MIN_TEMP) 
            direction = 1;

        msleep(1000 / FREQ);
    }

    return NULL;
}

void startTempThread(void) {
    pthread_t tempThread;
    
    if (pthread_create(&tempThread, NULL, updateTemp, (void*)&temp) != 0) 
        perror("Temperature thread can not started!\n");
    else
        printf("Temperature thread started!\n");

    pthread_detach(tempThread);
}
