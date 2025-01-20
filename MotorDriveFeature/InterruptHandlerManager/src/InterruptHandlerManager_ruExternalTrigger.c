
#include "InterruptHandlerManager_private.h"

FUNC(void, InterruptHandlerManager_ruExternalTrigger)(void)
{
    static uint32_t exti_re_count_a = 0;
    static uint32_t exti_fe_count_a = 0;
    static uint32_t exti_re_count_b = 0;
    static uint32_t exti_fe_count_b = 0;
    static uint32_t exti_re_count_c = 0;
    static uint32_t exti_fe_count_c = 0;

    /* Get Singleton Instance */
    dtInterruptHandlerManager* ihm = InterruptHandlerManager_GetInstance();
        
    /* Read port, pin and trigger type and set External irq attributes */
    ihm->getExternalIrq().setPort( ihm->IExternalInterruptStatus->readPortName() );
    ihm->getExternalIrq().setPin( ihm->IExternalInterruptStatus->readPinName() );
    ihm->getExternalIrq().setTrigger( ihm->IExternalInterruptStatus->readTriggerType());

    /* Check If Irq Comes HALL A Port - Pin */
    if( ( HALL_A_PORT == ihm->getExternalIrq().getPort() ) && ( HALL_A_PIN == ihm->getExternalIrq().getPin() ) )
    {       
        /* Check If IRQ RisingEdge triggered or FallingEdge triggered*/
        if( EXTIRQ_TRIGGERTYPE_RISINGEDGE == ihm->getExternalIrq().getTrigger() )
        {
           ihm->getHALL().setHallARisingEdgeFlag(HALLA_RISING_EDGE_SET);
           ihm->getHALL().setHallAFallingEdgeFlag(HALLA_FALLING_EDGE_RESET);
           /* Status changed into high */
           ihm->getHALL().setHallAStatus(HALLA_STATUS_HIGH);
           /* Increase rising edge count for A */
           exti_re_count_a++;
           ihm->getHALL().setHallARisingEdgeCount(exti_re_count_a);
        }
        else if( EXTIRQ_TRIGGERTYPE_FALLINGEDGE == ihm->getExternalIrq().getTrigger() )
        {
           ihm->getHALL().setHallARisingEdgeFlag(HALLA_RISING_EDGE_RESET);
           ihm->getHALL().setHallAFallingEdgeFlag(HALLA_FALLING_EDGE_SET);
           /* Status changed into low */
           ihm->getHALL().setHallAStatus(HALLA_STATUS_LOW);
           /* Increase falling edge count for A */
           exti_fe_count_a++;
           ihm->getHALL().setHallAFallingEdgeCount(exti_fe_count_a);
        }
        else
        {
           ihm->getHALL().setHallARisingEdgeFlag(HALLA_RISING_EDGE_UNKNOWN);
           ihm->getHALL().setHallAFallingEdgeFlag(HALLA_FALLING_EDGE_UNKNOWN);
           ihm->getHALL().setHallAStatus(HALLA_STATUS_UNKNOWN);
        }

        /* Set Unknown Others B and C */
        ihm->getHALL().setHallBRisingEdgeFlag(HALLB_RISING_EDGE_UNKNOWN);
        ihm->getHALL().setHallBFallingEdgeFlag(HALLB_FALLING_EDGE_UNKNOWN);
        ihm->getHALL().setHallCRisingEdgeFlag(HALLC_RISING_EDGE_UNKNOWN);
        ihm->getHALL().setHallCFallingEdgeFlag(HALLC_FALLING_EDGE_UNKNOWN);

    }
    /* Check If Irq Comes HALL B Port - Pin */
    else if( ( HALL_B_PORT == ihm->getExternalIrq().getPort() ) && ( HALL_B_PIN == ihm->getExternalIrq().getPin() ) )
    {
        /* Check If IRQ RisingEdge triggered or FallingEdge triggered*/
        if( EXTIRQ_TRIGGERTYPE_RISINGEDGE == ihm->getExternalIrq().getTrigger() )
        {
           ihm->getHALL().setHallBRisingEdgeFlag(HALLB_RISING_EDGE_SET);
           ihm->getHALL().setHallBFallingEdgeFlag(HALLB_FALLING_EDGE_RESET);
           /* Status changed into high */
           ihm->getHALL().setHallBStatus(HALLB_STATUS_HIGH);
           /* Increase rising edge count for B */
           exti_re_count_b++;
           ihm->getHALL().setHallBRisingEdgeCount(exti_re_count_b);
        }
        else if( EXTIRQ_TRIGGERTYPE_FALLINGEDGE == ihm->getExternalIrq().getTrigger() )
        {
            ihm->getHALL().setHallBRisingEdgeFlag(HALLB_RISING_EDGE_RESET);
            ihm->getHALL().setHallBFallingEdgeFlag(HALLB_FALLING_EDGE_SET);
            /* Status changed into low */
            ihm->getHALL().setHallBStatus(HALLB_STATUS_LOW);
            /* Increase falling edge count for B */
           exti_fe_count_b++;
           ihm->getHALL().setHallBFallingEdgeCount(exti_fe_count_b);
        }
        else
        {
            ihm->getHALL().setHallBRisingEdgeFlag(HALLB_RISING_EDGE_UNKNOWN);
            ihm->getHALL().setHallBFallingEdgeFlag(HALLB_FALLING_EDGE_UNKNOWN);
            ihm->getHALL().setHallBStatus(HALLB_STATUS_UNKNOWN);
        }

        /* Set Unknown Others A and C */
        ihm->getHALL().setHallARisingEdgeFlag(HALLA_RISING_EDGE_UNKNOWN);
        ihm->getHALL().setHallAFallingEdgeFlag(HALLA_FALLING_EDGE_UNKNOWN);
        ihm->getHALL().setHallCRisingEdgeFlag(HALLC_RISING_EDGE_UNKNOWN);
        ihm->getHALL().setHallCFallingEdgeFlag(HALLC_FALLING_EDGE_UNKNOWN);

    }
    /* Check If Irq Comes HALL C Port - Pin */
    else if( ( HALL_C_PORT == ihm->getExternalIrq().getPort() ) && ( HALL_C_PIN == ihm->getExternalIrq().getPin() ) )
    {
        /* Check If IRQ RisingEdge triggered or FallingEdge triggered*/
        if( EXTIRQ_TRIGGERTYPE_RISINGEDGE == ihm->getExternalIrq().getTrigger() )
        {
           ihm->getHALL().setHallCRisingEdgeFlag(HALLC_RISING_EDGE_SET);
           ihm->getHALL().setHallCFallingEdgeFlag(HALLC_FALLING_EDGE_RESET);
           /* Status changed into high */
           ihm->getHALL().setHallCStatus(HALLC_STATUS_HIGH);
           /* Increase rising edge count for C */
           exti_re_count_c++;
           ihm->getHALL().setHallCRisingEdgeCount(exti_re_count_c);
        }
        else if( EXTIRQ_TRIGGERTYPE_FALLINGEDGE == ihm->getExternalIrq().getTrigger() )
        {
            ihm->getHALL().setHallCRisingEdgeFlag(HALLA_RISING_EDGE_RESET);
            ihm->getHALL().setHallCFallingEdgeFlag(HALLA_FALLING_EDGE_SET);
            /* Status changed into low */
            ihm->getHALL().setHallCStatus(HALLC_STATUS_LOW);
            /* Increase falling edge count for C */
            exti_fe_count_c++;
            ihm->getHALL().setHallCFallingEdgeCount(exti_fe_count_c);
        }
        else
        {
            ihm->getHALL().setHallCRisingEdgeFlag(HALLC_RISING_EDGE_UNKNOWN);
            ihm->getHALL().setHallCFallingEdgeFlag(HALLC_FALLING_EDGE_UNKNOWN);
            ihm->getHALL().setHallCStatus(HALLC_STATUS_UNKNOWN);
        }

        /* Set Unknown Others A and B */
        ihm->getHALL().setHallARisingEdgeFlag(HALLA_RISING_EDGE_UNKNOWN);
        ihm->getHALL().setHallAFallingEdgeFlag(HALLA_FALLING_EDGE_UNKNOWN);
        ihm->getHALL().setHallBRisingEdgeFlag(HALLB_RISING_EDGE_UNKNOWN);
        ihm->getHALL().setHallBFallingEdgeFlag(HALLB_FALLING_EDGE_UNKNOWN);
    

    }
    else
    {
        /* Defensive coding */
    }

    /* Write Current Interrupt Status to HALL A,B,C Line*/
    ihm->IHALLA->writeRisingEdgeAFlag ( ihm->getHALL().getHallARisingEdgeFlag() );
    ihm->IHALLA->writeFallingEdgeAFlag( ihm->getHALL().getHallAFallingEdgeFlag() );
    ihm->IHALLB->writeRisingEdgeBFlag ( ihm->getHALL().getHallBRisingEdgeFlag() );
    ihm->IHALLB->writeFallingEdgeBFlag( ihm->getHALL().getHallBFallingEdgeFlag() );
    ihm->IHALLC->writeRisingEdgeCFlag ( ihm->getHALL().getHallCRisingEdgeFlag() );
    ihm->IHALLC->writeFallingEdgeCFlag( ihm->getHALL().getHallCFallingEdgeFlag() );

}