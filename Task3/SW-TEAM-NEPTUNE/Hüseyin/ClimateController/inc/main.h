#ifndef __MAIN_H
#define __MAIN_H  

#include "Climate_Public.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifdef _WIN32
    #include <conio.h>
    #include <time.h>
#else
    #include <poll.h>
    #include <unistd.h>
#endif

#define TIMEOUT_MS 1000

int getInputWithTimeout(float* input);

#endif