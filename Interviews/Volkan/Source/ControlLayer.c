#include "ControlLayer.h"
#include "variables.h"
#define ADC_MIN_VAL 0.5
#define ADC_MAX_VAL 4.5
#define POSITION_TRESHOLD 0


/*
*  Bu Fonskiyon ADC'den gelen Ham datayı Voltaja çevirip pedalın ilgili değişkenlerine atar.
*  Ve Pedalın pozisyon bilgisi hesaplanır.
*  Eğer bu işlem sırasında pedaldan yanlış bir veri gelirse diğer işlemlere devam edilmeden
*  pedal error durumuna düşer
*/
uint8_t adcToThrottlePosition(uint8_t* adc1,uint8_t* adc2, Pedal_t* p){
    p->state = PEDAL_BUSY;

    /*
     *  ADC Datası işlenip Range Kontrolünden geçirilir.
     */
    p->HighValue = ConvertToVoltage(adc1);
    p->LowValue  = ConvertToVoltage(adc2);

    if(p->HighValue > 4.5 || p->HighValue < 0.5 || p->LowValue > 4.5 || p->LowValue < 0.5  ){
    	p->state = PEDAL_ERROR;
    	p->error = PEDAL_DATA_OUT_OF_RANGE;
    	return 0 ;
    }

    /*
     * Pozisyon bilgisi hesaplanır ve emin olmak için bir kez daha data doğru geldi mi kontrolü yapılır.
     */
    p->Position = p->HighValue + p->LowValue;
    if(p->Position > ADC_MAX_VAL + POSITION_TRESHOLD || p->Position < ADC_MIN_VAL - POSITION_TRESHOLD){
    	p->state = PEDAL_ERROR;
    	p->error = PEDAL_DATA_OUT_OF_RANGE;
    	return 0 ;
    }
    /*
     * Eğer hiç bir hata yoksa Pedal pozisyonu CANBUS üzerinden dağıtılmaya ve Gösterge Panelinde Gösterilmeye hazır.
     */
    if(p->PrevPosition != p->Position){
    	p->state = PEDAL_READY_FOR_COMM;
    }else{
    	p->state = PEDAL_IDLE;
    }
    p->PrevPosition = p->Position;
    return 1;
}


/*
 * Bu fonskiyon ADC Verisini Voltaja çevirir.
 */
uint8_t ConvertToVoltage(uint8_t val){

	uint8_t returnValue=0;
	// Donanım tasarımına göre Analog Değer Voltaj değerine dönüştürülecek fonskiyon

	return returnValue;
}

/*
 * Bu fonksiyon Gaz pedalından gelen veriye göre motorun hızını kontrol eder.
 * Eğer gaz pedalında bir arıza varsa Tork keser Güvenli bir duruş sağlar
 */
void SetEngineRPM(Pedal_t* p){

	if(p->state == PEDAL_ERROR){
		if(EngineRPM > 0){

			// TORK KES
		}
	}else{

			// Gelen pozisyon bilgisi ile hızı yönet
	}
}




