#include "AppLayer.h"
#include "System.h"
#include "variables.h"
#include "ControlLayer.h"
extern  Pedal_t Pedal;
uint8_t RequestEBS;
int main(){

    CANBUSInit();				// 100ms periyot ile CAN Messajı göndermek için
    while(IsClusterRunning()); 	// Cluster(Gosterge Paneli) ile haberleşme başlayana kadar programı başlatma
    
    DMAInit();   				// Sürekli olarak ADC'yi okur.
    ADCInit();
    TimerInit(); 				// 10ms periyot ile Pedalın ADC verisi güncellemek için kullanılır.
    TimerForEBS();              // 500 ms periyot ile bir kesme oluşturur ve ABS sistemi sorgulanır.
    while(1){
        
        if(Pedal.state == PEDAL_READY_TO_READ){ 		 	// EĞER PEDAL BOS DURUMDAYSA GELEN VERİYİ HESAPLAR VEYA HATA DONDURUR
        	adcToThrottlePosition(adc1,adc2,&Pedal);        // KESME FONSKİYONUNDAN BURAYA YONLENDIRME YAPILIR
        }
        else if(PEDAL_READY_FOR_COMM){ 	    	 			// VERIDE BIR DEGISIKLIK VARSA VEYA HATA VARSA MESAJI GUNCELLER
            updateCANMessage(&Pedal);
        }
        else if(Pedal.state == PEDAL_ERROR){ 				// ERROR VARSA ILK ONCE DIAGNOSTIC MESAJ GONDERILIR
        	DM1_error();
        	Pedal.state == PEDAL_ERROR_LOG;
        }
        else if(Pedal.state == PEDAL_ERROR_LOG){			// DIAGNOSTIC MESAJ GONDERILDIYSE HATA HAFIZAYA ALINIR
        	DM1_Logging(&Pedal);
        	Pedal.state == PEDAL_READY_FOR_COMM;
        }

    	SetEngineRPM(&Pedal);                   			//  MOTOR HIZI HESAPLANIR
    	if(RequestEBS){										// EBS 500Ms periyot ile kontrol edilir.

    		IsEBSRunning();									// Bu fonskiyonun çıktısına göre sistem kendi çalışmasını değiştirebilir.
    	}
    }
}
