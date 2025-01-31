#include "MotorDriverCommProxy_private.h"
/** 
 * @file MotorDriverCommProxy_ruUpdateIndicator.c
 * @brief Updates the motor driver indicator lamps based on the current status.
 * 
 * This function reads the indicator status for brake, direction, and speed, and updates 
 * the corresponding lamps (brake, direction, and speed) accordingly. The function also 
 * handles the lamp states and updates the indicator PDU (Protocol Data Unit).
 * 
 * @details The function performs the following actions:
 * 1. Reads the brake status and updates the brake lamp.
 * 2. Reads the direction status and updates the forward and reverse direction lamps.
 * 3. Reads the speed status and updates the corresponding speed lamp.
 * 4. Constructs the final indicator PDU to represent the state of all lamps and updates it.
 */
FUNC(void, MotorDriverCommProxy_ruUpdateIndicator)(void)
{
    /* Indicator lamp static variables */
    static dtMotorDriverCommProxy_brakeLamp     brakeLamp = MDCP_BRAKELAMP_UNKNOWN; /**< Static variable to hold brake lamp status */
    static dtMotorDriverCommProxy_directionLamp D_directionLamp = MDCP_DIRECTIONLAMP_UNKNOWN; /**< Static variable for the forward direction lamp */
    static dtMotorDriverCommProxy_directionLamp R_directionLamp = MDCP_DIRECTIONLAMP_UNKNOWN; /**< Static variable for the reverse direction lamp */
    static dtMotorDriverCommProxy_speedLamp     speedLamp = MDCP_SPEEDLAMP_UNKNOWN; /**< Static variable for the speed lamp */

    /* Get Singleton Instance */
    dtMotorDriverCommProxy* mdcp = MotorDriverCommProxy_GetInstance();

    /* Read and update indicator PDU variables */
    mdcp->setIBdr(mdcp->IIndicatorBdrStatus->readIndicatorBdrStatus()); /**< Update the brake and direction status */
    mdcp->setISpeed(mdcp->IIndicatorSpeedStatus->readIndicatorSpeedStatus()); /**< Update the speed status */
    
    dtMotorDriverCommProxy_indicatorBdrStatus currentIndicatorBdr = mdcp->getIBdr(); /**< Get current brake and direction status */
    dtMotorDriverCommProxy_indicatorSpeedStatus currentIndicatorSpeed = mdcp->getISpeed(); /**< Get current speed status */

    /* BRAKE :: ENABLE-DISABLE-UNKOWN */
    if( BRAKE_ENABLE == currentIndicatorBdr.brakeStatus )
    {
        /* Turn-on brake-lamp */
        brakeLamp = MDCP_BRAKELAMP_ON;
    }
    else if( BRAKE_DISABLE == currentIndicatorBdr.brakeStatus )
    {
        /* Turn-off brake-lamp */
        brakeLamp = MDCP_BRAKELAMP_OFF;
    }
    else
    {
        /* Turn-on warning lamp*/
        brakeLamp = MDCP_BRAKELAMP_WARNING;
    }

    /* DIRECTION :: BACKWARD-FORWARD-UNKOWN */
    if( DIRECTION_BACKWARD == currentIndicatorBdr.directionStatus )
    {
        /* Turn-on  R-lamp */
        R_directionLamp = MDCP_DIRECTIONLAMP_OFF;
        /* Turn-off D-lamp */
        D_directionLamp = MDCP_DIRECTIONLAMP_ON;
    }
    else if( DIRECTION_FORWARD == currentIndicatorBdr.directionStatus )
    {
        /* Turn-off R-lamp */
        R_directionLamp = MDCP_DIRECTIONLAMP_ON;
        /* Turn-on  D-lamp */
        D_directionLamp = MDCP_DIRECTIONLAMP_OFF;
    }
    else
    {
        /* Turn-on warning lamp*/
        R_directionLamp = MDCP_DIRECTIONLAMP_WARNING;
        D_directionLamp = MDCP_DIRECTIONLAMP_WARNING;      
    }

    /* Pedal-gas-speed indicator */
    if( currentIndicatorSpeed != INDICATORSPEEDSTATUS_UNKNOWN)
    {
        if( currentIndicatorSpeed == INDICATORSPEEDSTATUS_LOWSPEED )
        {
            /* Low speed lamp */
            speedLamp = MDCP_SPEEDLAMP_LOW;
        }
        else if( currentIndicatorSpeed == INDICATORSPEEDSTATUS_MIDSPEED )
        {
            /* Mid speed lamp */
            speedLamp = MDCP_SPEEDLAMP_MID;
        }
        else if( currentIndicatorSpeed == INDICATORSPEEDSTATUS_HIGHSPEED )
        {
            /* High speed */
            speedLamp = MDCP_SPEEDLAMP_HIGH;
        }
        else if( currentIndicatorSpeed == INDICATORSPEEDSTATUS_VERYHIGHSPEED )
        {
            /* Very High Speed */
            speedLamp = MDCP_SPEEDLAMP_VERYHIGH;
        }
        else
        {
            /* Turn-on warning lamp*/
            speedLamp = MDCP_SPEEDLAMP_UNKNOWN;
        }
    }
    else
    {
        /* Turn-on warning lamp*/
        speedLamp = MDCP_SPEEDLAMP_UNKNOWN;
    }

    /* Update Indicator PDU */
    union 
    {
        uint16_t word; 
        struct
        {
            dtMotorDriverCommProxy_brakeLamp     brake : 4; /**< Brake lamp status (4 bits) */
            dtMotorDriverCommProxy_directionLamp D_direction : 4; /**< Forward direction lamp status (4 bits) */
            dtMotorDriverCommProxy_directionLamp R_direction : 4; /**< Reverse direction lamp status (4 bits) */
            dtMotorDriverCommProxy_speedLamp     speed : 4; /**< Speed lamp status (4 bits) */
        }lamp; /**< Bit-level access to indicator status */
    }indicator;

    indicator.lamp.brake        = brakeLamp; /**< Assign brake lamp status */
    indicator.lamp.D_direction  = D_directionLamp; /**< Assign forward direction lamp status */
    indicator.lamp.R_direction  = R_directionLamp; /**< Assign reverse direction lamp status */
    indicator.lamp.speed        = speedLamp; /**< Assign speed lamp status */

    /* Update PDU */
    mdcp->setIndicator(indicator.word); /**< Set the updated indicator word */
}
