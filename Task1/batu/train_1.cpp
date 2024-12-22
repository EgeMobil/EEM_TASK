#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <windows.h>

typedef enum {
    IDLE,    // tren istasyonda bekliyor
    LOADING, // tren yolcu alıyor ve indiriyor
    MOVING,  // tren öbür istasyona hareket ediyor
    STOPPING // tren durağa yaklaştı yavaşladı ve durdu
} trainStates;

void updateTrain(trainStates* train){
    static int station = 1;
    switch (*train)
    {
    case IDLE:
        printf("%d. istasyondasınız\n",station);
        printf("Tren hazırlanmakta şimdi yolcu alımı yapacak.\n");
        *train = LOADING;
        break;
    case LOADING:
        station++;
        printf("Tren yolcu alımını tammamladı şimdi %d. istasyona doğru harekete geçiyor.\n",station);
        *train = MOVING;
        break;
    case MOVING:
        printf("Tren durağa yaklaştı şimdi yavaşlayarak duracak.\n");
        *train = STOPPING;
        break;
    case STOPPING:
        printf("Tren %d. istasyonda durdu şimdi bekleme moduna giriyor.\n\n",station);
        *train = IDLE;
        break;
    default:
        break;
    }
}



int main(){
    setlocale(LC_ALL,"Turksih");
    trainStates EgeMobil;
    EgeMobil = IDLE;
    char trainStart;
    int ww = 0;
    int stationNumber = 4;
    do{//doğru giriş emri verilene kadar devam ediyor
    printf("Treni başlatmak için 's' e basınız.\n");
    scanf(" %c",&trainStart); //start için izin alma
    trainStart = tolower(trainStart); //capslock hatası engelleme
    switch (trainStart)//giriş kontrolü
    {
    case 's':
        printf("tren başlıyor\n");
        ww = 0;
        break;
    
    default:
        printf("hatalı giriş\ntekrar girin\n");
        ww = 1;
        break;
    }
    }while(ww);
    while(trainStart = 's'){
        for(int i = 0; i < stationNumber*4;i++){
            updateTrain(&EgeMobil);//durum güncellemsi
            Sleep(2000);//bekleme süresi
        }
        break;
    }
    getchar();
    getchar();
    return 0;
}
/*
    State Machine
 -state
Idle: tren durakta beklemekte
Loading: trene yolcu inmekte veya binmekte
Moving: tren hareket halinde
Stopping: tren yavaşlamakta ve duracak

 -Events
Başlangıcı: Manuel olarak sistem başlatıldı.
Loading bitti: Yolcu iniş binişi tamamlandı Durum: Loading -> Moving
Yeni istasyon: İstasyona gelince yavaşladı ve durdu Durum: Moving -> Stopping
Durdu: Tren durduktan sonra bekleme moduna girdi Durum Stopping -> Idle

 -Actions
Idle: Yolcular istasyonda ve tren Yolcu alımı için emir beklemekte
Loading: Emir geldikten sonra tren yolcu alımı yapmakta
Moving: Tren harekete geçti ve öbür durağa ilerlemekte
Stopping: Tren durağa geldi yavaşladı ve durdu   
*/

