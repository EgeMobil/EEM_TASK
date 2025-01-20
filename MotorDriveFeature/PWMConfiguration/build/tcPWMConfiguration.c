#include "tcPWMConfiguration.h"

void tcPWMConfiguration(void)
{
    printf("[PWMConfiguration]\n");

    /* CTOR */
    PWMConfiguration_CTOR();

    /* Get Singelton Instance For Test */
    dtPWMConfiguration* manager = PWMConfiguration_GetInstance();

    /* Read PWMConfiguration  before Initialisation */
    printf("[PRE-INIT] %s \n", manager->toString() );

    /* PwmStep IF Initial values */
    PwmStepInterface.writePwmStepA(PWMSTEP_PWMSTATUS_UNKNOWN);
    PwmStepInterface.writePwmStepB(PWMSTEP_PWMSTATUS_UNKNOWN);
    PwmStepInterface.writePwmStepC(PWMSTEP_PWMSTATUS_UNKNOWN);

    /* Speed Brake and Direction Initial Values */
    BrakeStatusInterface.writeBrake(BRAKE_STATUS_UNKNOWN);
    SpeedStatusInterface.writeSpeedStatus(0U);
    DirectionStatusInterface.writeDirection(DIRECTION_FORWARD);

    /* Initalize PWMConfiguration */
    PWMConfiguration_ruInitialisation();

    /* Read PWMConfiguration Status after Initialisation */
    printf("[POST-INIT] %s \n", manager->toString() );

    /* Define Six-Step Sequence */
    const uint8_t sixStepSequence[6][3] = {
        {PWMSTEP_PWMSTATUS_HIGH, PWMSTEP_PWMSTATUS_LOW, PWMSTEP_PWMSTATUS_LOW}, // Step 1
        {PWMSTEP_PWMSTATUS_LOW, PWMSTEP_PWMSTATUS_HIGH, PWMSTEP_PWMSTATUS_LOW}, // Step 2
        {PWMSTEP_PWMSTATUS_LOW, PWMSTEP_PWMSTATUS_LOW, PWMSTEP_PWMSTATUS_HIGH}, // Step 3
        {PWMSTEP_PWMSTATUS_HIGH, PWMSTEP_PWMSTATUS_LOW, PWMSTEP_PWMSTATUS_HIGH}, // Step 4
        {PWMSTEP_PWMSTATUS_HIGH, PWMSTEP_PWMSTATUS_HIGH, PWMSTEP_PWMSTATUS_LOW}, // Step 5
        {PWMSTEP_PWMSTATUS_LOW, PWMSTEP_PWMSTATUS_HIGH, PWMSTEP_PWMSTATUS_HIGH}  // Step 6
    };

    /* Speed Brake and Direction Initial Values */
    BrakeStatusInterface.writeBrake(BRAKE_STATUS_DISABLE);
    SpeedStatusInterface.writeSpeedStatus(100U);
    DirectionStatusInterface.writeDirection(DIRECTION_FORWARD);

    for (uint8_t step = 0; step < 6; step++)
    {
        printf("[TEST] Applying Step %d: A=%d, B=%d, C=%d\n",
               step + 1,
               sixStepSequence[step][0],
               sixStepSequence[step][1],
               sixStepSequence[step][2]);

        /* Set PwmStep values for this step */
        PwmStepInterface.writePwmStepA(sixStepSequence[step][0]);
        PwmStepInterface.writePwmStepB(sixStepSequence[step][1]);
        PwmStepInterface.writePwmStepC(sixStepSequence[step][2]);

        /* Execute Update */
        PWMConfiguration_ruUpdate();

        /* Read Configuration Status After Update */
        printf("[POST-UPDATE - Step %d] %s \n", step + 1, manager->toString());
    }

    return;
}
