#ifndef INC_LOGSUBSYSTEM_H_
#define INC_LOGSUBSYSTEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LOG_TYPE_SYSTEM     0
#define LOG_TYPE_ERROR      1
#define LOG_TYPE_THROTTLE   2

#define SYSTEM_LOG_PATH     "Logs/SystemLog.txt"
#define ERROR_LOG_PATH      "Logs/ErrorLog.txt"
#define THROTTLE_LOG_PATH   "Logs/ThrottleLog.txt"

void LOG(const char* message, uint8_t type);
void LOG_MESSAGE(const char* message);
void LOG_ERROR(const char* message);

#endif
