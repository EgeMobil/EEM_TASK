/* Doxygen Runable Comment */

#include "HALLSensorConfiguration_private.h"


/**
 * @brief Updates the state of the Hall sensors and corresponding PWM steps for BLDC motor control.
 * 
 * This function simulates the six-step commutation sequence for a BLDC motor based on the Hall sensor states.
 * The table below represents the switching pattern and the corresponding Hall-effect code:
 * 
 * ```
 * Hall-effect Code    100       110       010       011       001       101
 * Angle (°)           0°        60°       120°      180°      240°      300°
 * 
 * Phase (S1)          ON        ON        OFF       OFF       OFF       ON
 * Phase (S2)          OFF       ON        ON        ON        OFF       OFF
 * Phase (S3)          OFF       OFF       OFF       ON        ON        ON
 * Phase (S4)          ON        ON        ON        OFF       OFF       OFF
 * Phase (S5)          OFF       OFF       ON        ON        ON        OFF
 * Phase (S6)          ON        OFF       OFF       OFF       ON        ON
 * ```
 * 
 * - **Hall-effect Code:** Represents the specific Hall sensor states (e.g., `100`, `110`, etc.).
 * - **Angle (°):** Indicates the electrical angle of the rotor.
 * - **Phases (S1-S6):**
 *   - Each phase (S1 to S6) represents the switching state of the inverter phases.
 *   - **`ON`:** Active state (switch is closed).
 *   - **`OFF`:** Inactive state (switch is open).
 * 
 * This table demonstrates the six-step commutation pattern for a BLDC motor, showing the active and inactive states of each phase during each step.
 */
FUNC(void, HALLSensorConfiguration_ruUpdateC)(void)
{
    dtHALLSensorConfiguration_PwmStep pwmStepC = PWMSTEP_PWMSTATUS_UNKNOWN;

    /* Get Singleton Instance */
    dtHALLSensorConfiguration* hsc = HALLSensorConfiguration_GetInstance();

    /* Read HALL from interfaces */
    hsc->getHallCConfig().setRisingEdgeFlag( hsc->IHALLC->readRisingEdgeCFlag() );
    hsc->getHallCConfig().setFallingEdgeFlag( hsc->IHALLC->readFallingEdgeCFlag() );

    /* Set pwmStep for HALL C */
    if(( HALLC_RISING_EDGE_SET == hsc->getHallCConfig().getRisingEdgeFlag() ) && ( HALLC_FALLING_EDGE_RESET == hsc->getHallCConfig().getFallingEdgeFlag() ) )
    {
        pwmStepC = PWMSTEP_PWMSTATUS_HIGH;
        /* Local handlers for debug */
        hsc->getHallCConfig().setStatus(HALLC_STATUS_HIGH);
    }
    else if(( HALLC_RISING_EDGE_RESET == hsc->getHallCConfig().getRisingEdgeFlag() ) && ( HALLC_FALLING_EDGE_SET == hsc->getHallCConfig().getFallingEdgeFlag() ) )
    {
        pwmStepC = PWMSTEP_PWMSTATUS_LOW;
        /* Local handlers for debug */
        hsc->getHallCConfig().setStatus(HALLC_STATUS_LOW);
    }
    else
    {
        /* Maintain previous state */
        pwmStepC = ( hsc->getHallCConfig().getStatus() == HALLC_STATUS_HIGH) ? PWMSTEP_PWMSTATUS_HIGH : PWMSTEP_PWMSTATUS_LOW;

    }

    /* Send Pwm Step */
    hsc->IPwmStep->writePwmStepC(pwmStepC);

}
