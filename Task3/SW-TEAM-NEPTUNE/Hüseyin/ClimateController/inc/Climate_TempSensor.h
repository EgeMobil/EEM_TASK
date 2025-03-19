#ifndef __CLIMATE_TEMPSENSOR_H
#define __CLIMATE_TEMPSENSOR_H

// Independent Temperature Sensor
#include <stdio.h>
#include <pthread.h>
// OS Based Inline Timing Function
#ifdef _WIN32
    #include <windows.h>
    #define msleep(x) Sleep(x)
#else
    #include <unistd.h>
    #define msleep(x) usleep((x) * 1000)
#endif

#define MIN_TEMP        0.0
#define MAX_TEMP        60.0
#define FREQ            100
#define OFFSET          0.5

float* getTemp(void);
void* updateTemp(void* arg);
void startTempThread(void);

#endif