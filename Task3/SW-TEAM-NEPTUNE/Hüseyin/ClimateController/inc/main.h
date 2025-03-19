#ifndef __MAIN_H
#define __MAIN_H  

#include "Climate_Public.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <poll.h>
#include <string.h>

#define TIMEOUT_MS 1000

int getInputWithTimeout(float* input);

#endif