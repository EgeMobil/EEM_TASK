#include <stdio.h>  
#include <ldr_control.h>

int readADC();

int main()
{
    printf("Akilli aydinlatma sistemi baslatiliyor.\n");
    LdrControl ldrSystem;
    initLdrControl(&ldrSystem, 300, 50);

    while(1)
    {
        int sensorDegeri = readADC();

        printf("LDR Sensor Degeri: %d\n", sensorDegeri);
        updateLdrState(&ldrSystem, sensorDegeri);
    }

    return 0;
}

int readADC()
{
    int deger;
    printf("LDR degerini girin: ");
    scanf("%d", &deger);
    return deger;
}
