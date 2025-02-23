#include "System/pedalSubSystem.h"

void* throttleUpdateThread(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        throttleSensor_0 = MIN_VOLTAGE + ((float)rand() / RAND_MAX) * (MAX_VOLTAGE - MIN_VOLTAGE);
        throttleSensor_1 = REF_VOLTAGE - throttleSensor_0;  
        pthread_mutex_unlock(&lock);

        usleep(UPDATE_TIME);
    }
    return NULL;
}

void startThrottleThread(void) {
    srand(time(NULL));  
    pthread_mutex_init(&lock, NULL);
    pthread_create(&threadID, NULL, throttleUpdateThread, NULL);
}

float readThrottleSensor_0(void) {
    float throttleVoltage_0 = 0.0;
    pthread_mutex_lock(&lock);
    throttleVoltage_0 = throttleSensor_0;
    pthread_mutex_unlock(&lock);

    return throttleSensor_0;
}

float readThrottleSensor_1(void) {
    float throttleVoltage_1 = 0.0;
    pthread_mutex_lock(&lock);
    throttleVoltage_1 = throttleSensor_1;
    pthread_mutex_unlock(&lock);

    return throttleSensor_1;
}