
#define SIL_TEST

/* Public Access */
#ifdef SIL_TEST
#include "ECUStateManager_public.h"
#include "BrakeAndDirectionManager_public.h"
#include "GateDriverController_public.h"
#include "HALLSensorConfiguration_public.h"
#include "InterruptHandlerManager_public.h"
#include "MotorDriverCommProxy_public.h"
#include "MotorDriverControlManager_public.h"
#include "MotorDriverDcmProxy_public.h"
#include "PWMConfiguration_public.h"
#include "SpeedControlManager_public.h"
#endif

#define TEST_HALL_A_PORT ((dtInterruptHandlerManager_portName)EXTIRQ_PORTNAME_GPIOB)
#define TEST_HALL_A_PIN  ((dtInterruptHandlerManager_pinName)EXTIRQ_PINNAME_6)

#define TEST_HALL_B_PORT ((dtInterruptHandlerManager_portName)EXTIRQ_PORTNAME_GPIOB)
#define TEST_HALL_B_PIN  ((dtInterruptHandlerManager_pinName)EXTIRQ_PINNAME_7)

#define TEST_HALL_C_PORT ((dtInterruptHandlerManager_portName)EXTIRQ_PORTNAME_GPIOA)
#define TEST_HALL_C_PIN  ((dtInterruptHandlerManager_pinName)EXTIRQ_PINNAME_5)


int main()
{
    SpeedInterface.writeSpeed(0);
    BdrInterface.writeBdr(0x0100);

    /* 1-0-0 HALL Start state. */
    GPIOStatusInterface.writePinState(GPIOSTATUS_PIN_SET , TEST_HALL_A_PORT, TEST_HALL_A_PIN);
    GPIOStatusInterface.writePinState(GPIOSTATUS_PIN_RESET , TEST_HALL_B_PORT, TEST_HALL_B_PIN);
    GPIOStatusInterface.writePinState(GPIOSTATUS_PIN_RESET , TEST_HALL_C_PORT, TEST_HALL_C_PIN);

    ECUStateManager();   

    return 0;
}
