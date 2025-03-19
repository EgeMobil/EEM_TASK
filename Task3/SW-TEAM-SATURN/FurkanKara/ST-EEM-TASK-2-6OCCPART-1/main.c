#include "climate_control_public.h"
#include <stdio.h>

int main() {
    int choice;
    float temp;
    int speed;

    while (1) {
        printf("\n=== Klima Kontrol Sistemi ===\n");
        printf("1. Sicaklik Ayarla\n");
        printf("2. Mevcut Sicakligi Goruntule\n");
        printf("3. Fan Hizini Ayarla\n");
        printf("4. Cikis\n");
        printf("Secminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Yeni sicaklik girin: ");
                scanf("%f", &temp);
                Climate_setTemperature(temp);
                break;

            case 2:
                printf("Mevcut sicaklik: %.1f°C\n", Climate_getCurrentTemp());
                break;

            case 3:
                printf("Fan hizini ayarlayin (1: Dusuk, 2: Orta, 3: Yuksek): ");
                scanf("%d", &speed);
                Climate_adjustFanSpeed(speed);
                break;

            case 4:
                printf("Programdan cikiliyor...\n");
                return 0;

            default:
                printf("Hatali giris! Lutfen tekrar deneyin.\n");
        }
    }

    return 0;
}
