#include "System/system.h"

float checkThrottleLevel(void) {
    float v0 = readThrottleSensor_0();
    float v1 = readThrottleSensor_1();

    if ((v0 + v1 < MIN_VOLTAGE + MAX_VOLTAGE) || (v0 + v1 > MIN_VOLTAGE + MAX_VOLTAGE)) {
        char messageBuffer[50];
        snprintf(messageBuffer, sizeof(messageBuffer), "Incompatible Sensor Values! v0: %f, v1: %f", v0, v1);
        LOG(messageBuffer, LOG_TYPE_THROTTLE);

        return CODE_SYSTEM_ERROR;
    }

    return (v0 - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE);
}