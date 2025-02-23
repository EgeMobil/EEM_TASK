#include <stdio.h>
#include <unistd.h>
#include "../include/logger.h"
#include "../include/system.h"
#include "../include/controller.h"

int main(void) {
    if (log_init(NULL) != 0) {
        fprintf(stderr, "Log dosyasi acilmadi!\n");
        return -1;
    }

    system_init();

    while (1) {
        float motorSpeed = processGasPedalData();
        log_message(LOG_LEVEL_DEBUG, "Motor Hizi : %.2f RPM", motorSpeed);

        usleep(10000);
    }

    log_close();
    return 0;
}
