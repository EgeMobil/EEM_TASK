/* Doxygen Runable Comment */

/* Baseclass private access include */
#include "MotorDriverCommProxy_private.h"

FUNC(void, MotorDriverCommProxy_ruUpdateIndicator)(void)
{
    /* Indicator lamp static variables */
    static dtMotorDriverCommProxy_brakeLamp     brakeLamp = MDCP_BRAKELAMP_UNKNOWN;
    static dtMotorDriverCommProxy_directionLamp D_directionLamp = MDCP_DIRECTIONLAMP_UNKNOWN;
    static dtMotorDriverCommProxy_directionLamp R_directionLamp = MDCP_DIRECTIONLAMP_UNKNOWN;
    static dtMotorDriverCommProxy_speedLamp     speedLamp = MDCP_SPEEDLAMP_UNKNOWN;

    /* Get Singleton Instance */
    dtMotorDriverCommProxy* mdcp = MotorDriverCommProxy_GetInstance();

    /* Read and update indicator pdu variables */
    mdcp->setIBdr( mdcp->IIndicatorBdrStatus->readIndicatorBdrStatus() );
    mdcp->setISpeed( mdcp->IIndicatorSpeedStatus->readIndicatorSpeedStatus() );
    
    dtMotorDriverCommProxy_indicatorBdrStatus currentIndicatorBdr = mdcp->getIBdr();
    dtMotorDriverCommProxy_indicatorSpeedStatus currentIndicatorSpeed = mdcp->getISpeed();

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
            /* Very H igh Speed */
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
        dtMotorDriverCommProxy_brakeLamp     brake : 4; // İlk 4 bit
        dtMotorDriverCommProxy_directionLamp D_direction : 4; // İkinci 4 bit
        dtMotorDriverCommProxy_directionLamp R_direction : 4; // Üçüncü 4 bit
        dtMotorDriverCommProxy_speedLamp     speed : 4; // Dördüncü 4 bit
        }lamp; // Bit seviyesinde erişim 
    }indicator;

    indicator.lamp.brake        = brakeLamp;
    indicator.lamp.D_direction  = D_directionLamp;
    indicator.lamp.R_direction  = R_directionLamp;
    indicator.lamp.speed        = speedLamp;

    /* Update PDU */
    mdcp->setIndicator(indicator.word);

}
