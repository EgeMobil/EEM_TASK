#ifndef __TEMPSENSOR_H
#define __TEMPSENSOR_H

#ifdef _WIN32
    #include <windows.h>
    #define msleep(x) Sleep(x)
#else
    #include <unistd.h>
    #define msleep(x) usleep((x) * 1000)
#endif

#define MIN_TEMP        -40.0
#define MAX_TEMP        105.0
#define FREQ            100
#define OFFSET          0.5

#define BUFFER_SIZE     50

float getTemp(void);
void updateTemp(void);

void add2Buffer(void);
float getAvgTemp(void);

#endif