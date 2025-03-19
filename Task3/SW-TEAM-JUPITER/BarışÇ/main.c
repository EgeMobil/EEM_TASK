#include <stdio.h>
#include <stdlib.h>
#include "acc_public.h"


/*

Reviewerlara not: Şehir dışında olduğum için ve kendi bilgisayarımda yapamadığım için cmake ile derleyemedim.
 Bu yüzden sadece kodları commitleyebiliyorum. 

*/

void showStatus() {
    ACC_State state = ACC_getState();
    float speed = ACC_getSetSpeed();
    
    printf("ACC DURUM\n");
    printf("Durum: ");
    switch (state) {
        case ACC_OFF:     printf("KAPALI\n"); break;
        case ACC_STANDBY: printf("HAZIR\n"); break;
        case ACC_ACTIVE:  printf("AKTİF\n"); break;
    }
    
    printf("Ayarlanan hız: %.1f km/h\n", speed);
}

int main() {
    ACC_init();
    showStatus();
    ACC_Result result = ACC_enable();
    if (result != ACC_OK) {
        printf("Etkinleştirme başarısız!\n");
    }
    showStatus();
    ACC_setSpeed(100.0f);

    // Test döngüsü - Normalde while(1) içinde olacak
    for (int i = 0; i < 10; i++) {
        ACC_update();
    }

    ACC_disable();
    showStatus();
}
