#include <stdio.h>
#include "Inc/brakeControlManager_public.h"

int main()
{
    BrakeControlManager_t* BrakeManager = brakeControlManager_GetInstance();

    const char* statusString = BrakeManager->toString();
    printf("%s", statusString);

}
