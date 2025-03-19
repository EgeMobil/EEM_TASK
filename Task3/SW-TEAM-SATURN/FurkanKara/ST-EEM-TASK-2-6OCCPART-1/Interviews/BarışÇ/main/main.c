#include <stdio.h>
#include "application.h"

void app_main(void)
{
    startSystems();
    while (1)
    {
        gasPedal();
        displayUpdate();
        delay(10);
    }
}
