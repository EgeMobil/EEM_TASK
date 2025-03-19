#include "../Inc/ParkingAssistantManager_private.h"
#include "../Inc/ParkingAssistantManager_public.h"


extern parking_asistant_t ParkingAssistantManager ;

/* Bu fonksiyon gerekli şartlar sağlanıp sensörden veri okunursa o verileri işler 
 * Eğer alarm seviyelerinde bir değerde ise sensör nesnesinin alarm değişkenlerini ayarlar.
 * Verinin işlenebilmesi için sensörde hata olmaması gerekiyor.
 */
void ParkingAssistant_Front_Control(void){
        
    for(int i=0; i<NUMBER_OF_FRONT_SENSOR; i++){
        if(ParkingAssistantManager.FrontSensors[i].State != Sensor_ERROR){
            if(ParkingAssistantManager.FrontSensors[i].dataDistance < YELLOW_ALARM_DISTANCE && ParkingAssistantManager.FrontSensors[i].dataDistance > RED_ALARM_DISTANCE){
                ParkingAssistantManager.FrontSensors[i].State = Sensor_Yellow_Alarm;
                ParkingAssistantManager.Alarm = FRONT_ALARM;
            }
            else if(ParkingAssistantManager.FrontSensors[i].dataDistance < RED_ALARM_DISTANCE){
                ParkingAssistantManager.FrontSensors[i].State = Sensor_Red_Alarm;
                ParkingAssistantManager.Alarm = FRONT_ALARM;
            }
            else{
                ParkingAssistantManager.FrontSensors[i].State = Sensor_OK;
                ParkingAssistantManager.Alarm = IDLE;
            }
        }
    }
        
}

/* Bu fonksiyon gerekli şartlar sağlanıp sensörden veri okunursa o verileri işler 
 * Eğer alarm seviyelerinde bir değerde ise sensör nesnesinin alarm değişkenlerini ayarlar.
 * Verinin işlenebilmesi için sensörde hata olmaması gerekiyor.
 */
void ParkingAssistant_Rear_Control(void){
    
    for(int i=0; i<NUMBER_OF_FRONT_SENSOR; i++){
        if(ParkingAssistantManager.RearSensors[i].State != Sensor_ERROR){
            if(ParkingAssistantManager.RearSensors[i].dataDistance < YELLOW_ALARM_DISTANCE && ParkingAssistantManager.RearSensors[i].dataDistance > RED_ALARM_DISTANCE){
                ParkingAssistantManager.RearSensors[i].State = Sensor_Yellow_Alarm;
                ParkingAssistantManager.Alarm = REAR_ALARM;
                ParkingAssistantManager.LoopPeriod =50;
            }
            else if(ParkingAssistantManager.RearSensors[i].dataDistance < RED_ALARM_DISTANCE){
                ParkingAssistantManager.RearSensors[i].State = Sensor_Red_Alarm;
                ParkingAssistantManager.Alarm = REAR_ALARM;
                ParkingAssistantManager.LoopPeriod =25;
            }
            else{
                ParkingAssistantManager.RearSensors[i].State = Sensor_OK;
                ParkingAssistantManager.Alarm = IDLE;
                ParkingAssistantManager.LoopPeriod =100;
            }
        }
    }
    ParkingAssistantManager.State = ParkingAssistant_Update;
}