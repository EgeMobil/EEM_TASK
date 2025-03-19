#include "../Inc/ParkingAssistantManager_private.h"
#include "../Inc/ParkingAssistantManager_public.h"

extern int IntervalTime;


/* Bu fonskiyon kullanıcı ile iletişime geçer. Nesnenin mesafe bilgisine göre ekranda gösterilecek uyarıları ve
 * Sesli ikazın periyodunu ve ses düzeyini ayarlar.
 * Eğer sensörlerde hata var ise kullanıcıya bunu bildirir.
*/
void ParkingAssistant_UpdateSoundAndImage(void){

            ParkingAssistantManager.SetImagePtr();
            ParkingAssistantManager.SetSoundLevelPtr();
            ParkingAssistantManager.SetSoundPeriodPtr();
            ParkingAssistantManager.SetSensorErrorPtr();

            ParkingAssistantManager.State = ParkingAssistant_Waiting;
            // IntervalTime şuanki zaman atanır.
}