#include <stdio.h>
#include "traction_control_definition.h"
#include "traction_control_public.h"

int main(void) {
    // TCS_Manager yapısının tek örneğini başlatmak
    TCS_Manager* tcs = TCS_Manager_GetInstance();

    // TCS_Manager yapılandırması
    TCS_Manager_CTOR();

    // İlk durumda traction durumu
    printf("Initial Traction Status: %d\n", tcs->traction_getStatus());
    
    // Motor hızı ve pedal durumlarına göre traction kontrolünü test etme
    // Örneğin: Throttle pedalını basma
    tcs->throttle_position = PEDAL_PRESSED;  // Throttle pedalını bastık
    tcs->Tcs_set_traction();  // Traction kontrolünü güncelle

    // Brake pedalına basıldığında traction durumu
    tcs->brake_position = PEDAL_PRESSED;  // Brake pedalına basıldı
    tcs->Tcs_set_traction();  // Traction kontrolünü tekrar güncelle

    // Traction durumu
    printf("Final Traction Status: %d\n", tcs->traction_getStatus());

    // Motor çekiş kaybı durumu
    tcs->Tcs_Traction_Detection_loss();

    return 0;
}
