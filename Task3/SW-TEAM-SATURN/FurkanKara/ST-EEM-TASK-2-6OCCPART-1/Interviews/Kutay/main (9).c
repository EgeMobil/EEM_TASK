#include <stdio.h>

//Source Layer

float pedalPoz(float pedal_verisi){
    float pedal_alt = 0.5; //Pedal'dan alınabilecek alt sınır verisi.
    float pedal_ust = 4.5; //Pedaldan alınabilecek üst sınır verisi.

    return pedal_verisi/(pedal_ust-pedal_alt); //Pedaldan gelen veri 0-1 arasında bir değere dönüştürüldü. Bu değer ile motor kontrolü yapılacak.
}

//Controller Layer

int pedalKontrol(float pedal_poz){ //Pedaldan gelen verilerin motor kontrolüne uygunluğu kontrol edilir.
    if(pedal_poz>=0 && pedal_poz<=1){
        return 1;
    }
    else{
        return 0;
    }
}

//Application Layer

int motorHiziniAyarla(float pedal_poz, float* motorHizi){ //Motor hizini pedal poziyonuna göre ayarlar.
    *motorHizi = pedal_poz;
    if (*motorHizi == pedal_poz)
    {
        return 1; // Motor hızı doğru ayarlanmışsa 1 döndürür.
    }
    else{
        return 0;
    }
    
}

//Interface Layer

void gostergePaneli(float motorHizi){
    float hiz = 200*motorHizi; // En fazla 200 km/sa hıza ulaştığı farz edilerek motor hızı bilgisinden yorumlanan bir hız değerini gösteriyor.
    printf("Gösterge Paneli: Motor Hızı = %%%.2f -- Hız = %.2f", motorHizi, hiz);
}

//System Layer

typedef struct
{
    int isError;
    int dongu;  //Döngü parametrei zamanlama ifade etmesi için kullanılmıştır. 
    float pedalVerisi;
    float motorHizi;
    float hiz;
}Logs ;


void logData(Logs logArray[], int dongu, float pedalVerisi, float motorHizi, float hiz, int isError){
    
    logArray[dongu].isError = isError;
    logArray[dongu].dongu = dongu;
    logArray[dongu].pedalVerisi = pedalVerisi;
    logArray[dongu].motorHizi = motorHizi;
    logArray[dongu].hiz = hiz;
    if (isError)
    {
        printf("\nHata! - Döngü: %d - Motor Hızı: %f - Pedal Ferisi: %f - Pedal Verisi: %f, Hız: %f\n", dongu, motorHizi, pedalVerisi, hiz);
    }else{
        printf("\nBilgilendirme - Döngü: %d - Motor Hızı: %f - Pedal Ferisi: %f - Pedal Verisi: %f, Hız: %f\n", dongu, motorHizi, pedalVerisi, hiz);
    }
}

//Main Program
int main()
{
    //Alınan veriler
    float pedal_verisi = 0;
    float motor_hizi = 0;
    float hiz = 0;

    //Diğer veriler
    float pedal_poz;
    int dongu = 0;
    Logs log[100];

    while (1) //Superloop
    {
        gostergePaneli(motor_hizi);
        scanf("%f\n", pedal_verisi); //Simülasyon amaçlı her döngüde pedal verisini tekrar tanımlanır. Normal şartlarda bu veriler interruptlarla alınmalı.
        dongu++;
        pedal_poz = pedalPoz(pedal_verisi);
        if (pedalKontrol(pedal_poz))
        {
            if (motorHiziniAyarla(pedal_poz, &motor_hizi))
            {
                logData(log, dongu, pedal_poz, motor_hizi, hiz, 0); 
            }else
            {
                logData(log, dongu, pedal_poz, motor_hizi, hiz, 1); 
            }
        }else
        {
            logData(log, dongu, pedal_poz, motor_hizi, hiz, 1); //Pedaldan gelen veri doğru ayarlanmışsa log bu sorunlara göre tuturlur.
        }
        
    }
    
    return 0;
}
