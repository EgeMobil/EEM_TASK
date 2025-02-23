#include "System/logSubSystem.h"

void LOG(const char* message, uint8_t type) {
    FILE* file;

    switch (type)
    {
    case LOG_TYPE_SYSTEM:
        break;
    case LOG_TYPE_ERROR:
        break;
    case LOG_TYPE_THROTTLE:
        break;

    default:
        break;
    }
}