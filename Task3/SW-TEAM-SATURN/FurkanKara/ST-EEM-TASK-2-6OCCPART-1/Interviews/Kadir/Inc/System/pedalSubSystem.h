#ifndef INC_PEDALSUBSYSTEM_H_
#define INC_PEDALSUBSYSTEM_H_

#include <stdlib.h>
#include <pthread.h>

#define MIN_VOLTAGE     0.5 
#define MAX_VOLTAGE     4.5
#define REF_VOLTAGE     5.0
#define UPDATE_TIME     10000

static float            throttleSensor_0 = 0.0;
static float            throttleSensor_1 = 0.0;
static pthread_mutex_t  lock;
static pthread_t        threadID;

void startThrottleThread(void);

float readThrottleSensor_0(void);
float readThrottleSensor_1(void);

#endif