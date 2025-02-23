#include "InterruptService.h"
#include "variables.h"
extern struct Pedal_t Pedal;

//#include "variables.h"
uint8_t TIM1_Flag=0;
uint8_t DMA_ADC_Flag=0;

/* 
* Bu kesme fonskiyonu temsili bir fonskiyondur.
* DMA ile ADC verilerini circular ve continuous olarak okunur. 
*/
void DMA_ADC_IRQHandler(void){
    if(DMA_ADC_Flag){
        DMA_ADC_Flag=0;
    }
}

/*
* Bu kesme fonskiyonu her 10ms'de bir kesme üreterek adc verilerini okumamıza izin verecek 
*/
void TIM1_IRQHandler(void){
    if(TIM1_Flag){
        TIM1_Flag=0;
    }
    if(Pedal.state == PEDAL_IDLE) Pedal.state = PEDAL_READY_TO_READ;
}




/*
* Bu kesme fonskiyonu her 100msde CAN_Message_t'den yaratılan Message nesnesini hatta basar.
*/
void CAN_IRQHandler(void){

}

/*
 * 500 ms periyot ile bir kesme oluşturur ve ABS sistemi sorgulanır.
 */
extern uint8_t RequestEBS;
void TimerForEBS_IRQHandler(void){
	RequestEBS=1;
}


