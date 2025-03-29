#include "..\inc\traction_control_public.h"
#include "stdio.h"
int main()
{
    Traction_enable();
    Traction_disable();
    Traction_getStatus();
    TractionControl_update();
    printf("REFERENCE_SPEED");

    return 0;
}