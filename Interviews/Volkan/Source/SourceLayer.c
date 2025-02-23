#include "SourceLayer.h"

extern CAN_Message_t Message;

/*
 * Bu fonskiyon hata mesajlarını hafızaya kaydeder.
 * Eğer aynı hatadan belli bir eşik değeri kadar yaşandıysa
 * Gösterge panelinde Gaz Pedalı arızasını gösterir
 */
void DM1_Logging(Pedal_t* p){

	WriteToFlash(p->error);
	if(p->error == PEDAL_DATA_OUT_OF_RANGE){
		p->Counter_error++;
	}
	if(p->Counter_error == 100){
		p->Warning=1;
	}
}

/*
 * Bu Fonksiyon Gönderilen CAN Mesajında bir değişiklik olursa
 * Gönderilen CAN mesajını günceller
 * Eğer Pedalda bir hata varsa sadece warning mesajını gönderir
 */
void updateCANMessage(Pedal_t* p){

	if(p->Warning !=0){
		Message.Warning  = p->Warning;
	}else{
		Message.Position = p->Position;
	}
	p->state = PEDAL_IDLE;
}

/*
 * Gosterge paneli CANBUS hattında var mı onun kontrolü yapılır. İlk açılış anında yoksa program başlamaz.
 * Fakat program koşarken hattan düşerse sistem çalışmaya devam eder.
 */
void IsClusterRunning(){

}

/*
 * Elektronik Fren sistemi CANBUS Hattında mı onun kontrolü yapılır.
 *
 */
void IsEBSRunning(){

}
