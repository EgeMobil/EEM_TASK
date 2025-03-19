#include "../Inc/ParkingAssistantManager_private.h"
#include "../Inc/ParkingAssistantManager_public.h"


/* Bu fonskiyon Park Sensörünün çalışması için uygun koşullar sağlandığını kontrol eder.
 * Eğer uygun koşullar sağlandıysa aracın hareketine göre o yöndeki park sensörlerini çalıştırır.
 * Eğer uygun koşullar sağlanmaz ise sensör off konumunda bekler.
*/
void ParkingAssistant_Calculation_Verify(void){

    if(ParkingAssistantManager.CurrentGear > 0 && ParkingAssistantManager.CurrentVehicleSpeed < 5 ){

        ParkingAssistantManager.State = ParkingAssistantManager.UpdateAndVerifyDistanceWithFrontSensorsPtr();
    }
    else if(ParkingAssistantManager.CurrentGear == 255 && ParkingAssistantManager.CurrentVehicleSpeed < 5 ){

        ParkingAssistantManager.State = ParkingAssistantManager.UpdateAndVerifyDistanceWithRearSensorsPtr();
    }
    else{
        ParkingAssistantManager.State = ParkingAssistant_OFF;
    }
}
