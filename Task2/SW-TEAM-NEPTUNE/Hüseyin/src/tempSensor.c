#include "tempSensor.h"
#include <unistd.h>

static float temp = 0.0;
static int direction = 1;

static float tempBuffer[BUFFER_SIZE];
static int bufferIndex = 0;
static int bufferCount = 0;

void updateTemp(void) {
    while(1) {
        temp += direction * OFFSET;

        if (temp >= MAX_TEMP) 
            direction = -1;

        else if (temp <= MIN_TEMP) 
            direction = 1;

        
        msleep(1000 / FREQ);
    }
}

float getTemp(void) {
    return temp;
}

void add2Buffer(void) {
    *(tempBuffer + bufferIndex) = temp;
    bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;

    if (bufferCount < BUFFER_SIZE) {
        bufferCount++;
    }
}

float getAvgTemp(void) {
    if (bufferCount == 0)
        return 0.0;

    float sum = 0.0;
    float *ptr = tempBuffer;

    for (int i = 0; i < bufferCount; i++)
        sum += *(ptr + i);

    return sum / bufferCount;
}