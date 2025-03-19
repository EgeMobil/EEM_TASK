#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "main.h"

int main(void) {

    pthread_t tempThread;
    if (pthread_create(&tempThread, NULL, temperatureThread, NULL) != 0) {
        printf("Thread can't created!\n");
        return -1;
    }

    while (1) {
        add2Buffer();
        float avgTemp = getAvgTemp();

        printf("\033[2K\rTemperature: %.2f°C\t|\tAverage: %.2f°C", getTemp(), avgTemp);
        fflush(stdout);
        
        msleep(1000);
    }

    pthread_join(tempThread, NULL);

    return 0;
}

void *temperatureThread(void*) {
    updateTemp();
    return NULL;
}
