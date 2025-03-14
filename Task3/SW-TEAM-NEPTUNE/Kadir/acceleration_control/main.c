#include "acceleration_control_public.h"
#include "definition.h"
#include <stdio.h>

int main() {
    int throttleInput = 0;
    int maxPower = MAX_POWER;
    
    // Başlangıç mesajı
    printf("Acceleration Control System\n");
    printf("Max Power: %d\n", MAX_POWER);
    printf("Enter a throttle value between 0 and 100: ");
    
    // Kullanıcıdan throttle değeri al
    if (scanf("%d", &throttleInput) != 1) {
        printf("Invalid input.\n");
        return -1;  // sayı harici bir değer girilirse
    }

    // Throttle değerini set edilecek
    if (throttleInput >= 0 && throttleInput <= 100) {
        Acceleration_setThrottle(throttleInput);
        printf("Throttle set to: %d\n", throttleInput);
    } else {
        printf("Invalid throttle value. It must be between 0 and 100.\n");
        return -1;  // 0 - 100 arası girmediği zaman
    }

    // Gücü sınırlamak için limit belirle
    Acceleration_limitPower(maxPower);

    // İvmelenme ve motor gücü hesaplamaları
    Acceleration_applyAcceleration();

    return 0;
}
