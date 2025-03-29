#include "Inc/BrakeManager_Public.h"
#include <stdio.h>

// Deneme amaçlı koyulmuş değişkenler.
extern float pressure,speed;
int main(){
    
    BrakeManager_ruInit();                              // Nesne doğru parametreler ile başlatılır. 

    BrakeManager_t* bm = BrakeManager_GetInstance();    // Başlatılan nesnenin adresi alınır.

    const char* statusString = bm->toString();           // Nesnenin o anki güncel durumu tostring() ile ekran bastırılmak için bufferlanır.

    printf("%s", statusString);

    int i=0;
    while(i<20){
        // Fonskiyonları test amaçlı hız ve basınç bilgisi gönderilir çıktı olarak nesnenin adresini gözlemleyebilirsiniz.

        speed = 50;

        if(i%2 == 0) pressure = i;
        else pressure=0;
        
        BrakeManager_ruUpdateSelf();

        BrakeManager_ruControl();
        i++;
    }

}