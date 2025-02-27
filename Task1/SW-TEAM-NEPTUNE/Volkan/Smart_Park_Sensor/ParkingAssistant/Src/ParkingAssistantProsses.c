#include "../Inc/ParkingAssistantManager_private.h"
#include "../Inc/ParkingAssistantManager_public.h"

/* Bu fonskiyonda iş akışı kontrol edilir.
*/
void ParkingAssistant_Prosses(void){

        switch(ParkingAssistantManager.State){

            case ParkingAssistant_Waiting:
                ParkingAssistant_Calculation_Verify();
                break;
            case ParkingAssistant_Control_Front:
                ParkingAssistant_Front_Control();
                break;
            case ParkingAssistant_Control_Rear:
                ParkingAssistant_Rear_Control();
                break;
            case ParkingAssistant_Update:
                ParkingAssistant_UpdateSoundAndImage();
                break;
            case ParkingAssistant_OFF:
                ParkingAssistantManager.State = ParkingAssistant_Waiting;
                break;
            default:
                 ParkingAssistantManager.State = ParkingAssistant_Waiting;
                break;
        }

}