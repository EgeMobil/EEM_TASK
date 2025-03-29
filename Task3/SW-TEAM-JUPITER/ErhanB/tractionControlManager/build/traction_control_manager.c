#include "traction_control_manager.h"

TractionControlHandle_t tcs;

void tcs_init_ru(void)
{
    tcs_init(&tcs);
}

void tcs_control_ru(void)
{
    tcs_control(&tcs);
}