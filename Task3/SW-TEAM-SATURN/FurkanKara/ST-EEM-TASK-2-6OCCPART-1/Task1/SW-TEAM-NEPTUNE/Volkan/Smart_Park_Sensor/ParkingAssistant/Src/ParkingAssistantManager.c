#include "../Inc/ParkingAssistantManager_private.h"
#include "../Inc/ParkingAssistantManager_public.h"

parking_asistant_t ParkingAssistantManager = { .State= Sensor_OK,
                                            .FrontSensors[0] = {.CalculationDistancePtr = CalculationDistance,
                                                           },
                                            .FrontSensors[1] = {.CalculationDistancePtr = CalculationDistance,
                                                           },
                                            .FrontSensors[2] = {.CalculationDistancePtr = CalculationDistance,
                                                            },
                                            .FrontSensors[3] = {.CalculationDistancePtr = CalculationDistance,
                                                            },
                                            .RearSensors[0] = {.CalculationDistancePtr = CalculationDistance,
                                                                },
                                            .RearSensors[1] = {.CalculationDistancePtr = CalculationDistance,
                                                                 },
                                            .RearSensors[2] = {.CalculationDistancePtr = CalculationDistance,
                                                                 },
                                            .RearSensors[3] = {.CalculationDistancePtr = CalculationDistance,
                                                                 },
                                            .CurrentVehicleSpeed =0,
                                            .CurrentGear =0,
                                            .UpdateAndVerifyDistanceWithFrontSensorsPtr = UpdateAndVerifyDistanceWithFrontSensors,
                                            .UpdateAndVerifyDistanceWithRearSensorsPtr = UpdateAndVerifyDistanceWithRearSensors,
                                            .SetSoundLevelPtr = SetSoundLevel,
                                            .SetSoundPeriodPtr = SetSoundPeriod,
                                            .SetImagePtr       = SetImage,
                                            .SetSensorErrorPtr   = SetSensorError,
                                            .LoopPeriod        = 100,
                                            
};


/*
 * Bu fonskiyon ulturasonik sensörü çalıştırır ve verileri okur.
 * Ultrasonik sensörün çalışma prensibi bir ses dalgası yollayıp onun ne kadar sürede geri döndüğüyle
 * ve bu seçen sürenin mesafeye çevrilmesi prensibine dayanır.
 * param1 : Ses Dalgasını gönderileceği pin
 * param2 : Ses Dalgasının geri dönüşünü algılanacak  pin
 * return : Bu fonskiyonun geri dönüş değeri bize mesafe bilgisini veririr.
*/
float CalculationDistance(GPIO_TypeDef TRIG_PIN, GPIO_TypeDef ECHO_PIN){
    float distance=0;
    // BIR DEFINE YAPISI ILE DONANIM SECILEBILIR ONA GORE WRITE READ KOMUTLARI CALISTIRILABILIR


    // TRIG VE ECHO PINLERIYLE GEREKELI ALGORITMA GERCEKLESTIRILIR
    

    return distance;

}


/*
 * Bu fonskiyon park asistanı ön mesafe bilgisine ihtiyaç duydugu zaman çalışır
 * sensörleri okur ve range kontrolü yapılır, sensörlerin değerleri güncellenir.
 * return : Park asistanının durumunu güncellemek için değer döndürür.
*/
parking_assistanst_prosses_t UpdateAndVerifyDistanceWithFrontSensors(void){

    for(int i=0; i < NUMBER_OF_FRONT_SENSOR; i++){
        
        ParkingAssistantManager.FrontSensors[i].dataDistance = ParkingAssistantManager.FrontSensors[i].CalculationDistancePtr(ParkingAssistantManager.FrontSensors[i].TrigPin,ParkingAssistantManager.FrontSensors[i].TrigPin);
        if(ParkingAssistantManager.FrontSensors[i].dataDistance < DISTANCE_MIN_VAL || ParkingAssistantManager.FrontSensors[i].dataDistance > DISTANCE_MAX_VAL){
            ParkingAssistantManager.FrontSensors[i].State =  Sensor_ERROR;
        }else 
            ParkingAssistantManager.FrontSensors[i].State =  Sensor_OK;
    }
        

    return ParkingAssistant_Control_Front;
}
/*
 * Bu fonskiyon park asistanı arka mesafe bilgisine ihtiyaç duydugu zaman çalışır
 * sensörleri okur ve sensörlerin değerleri güncellenir.
 * return : Park asistanının durumunu güncellemek için değer döndürür.
*/
parking_assistanst_prosses_t UpdateAndVerifyDistanceWithRearSensors(void){

    for(int i=0; i < NUMBER_OF_REAR_SENSOR; i++){
        
        ParkingAssistantManager.RearSensors[i].dataDistance = ParkingAssistantManager.RearSensors[i].CalculationDistancePtr(ParkingAssistantManager.RearSensors[i].TrigPin,ParkingAssistantManager.RearSensors[i].TrigPin);
        if(ParkingAssistantManager.RearSensors[i].dataDistance < DISTANCE_MIN_VAL || ParkingAssistantManager.RearSensors[i].dataDistance > DISTANCE_MAX_VAL){
            ParkingAssistantManager.RearSensors[i].State =  Sensor_ERROR;
        }else 
            ParkingAssistantManager.RearSensors[i].State =  Sensor_OK;
    }
    return ParkingAssistant_Control_Rear;
}
/*
 * Bu fonskiyonlar ses seviyesi, sesin periyodu ve ekrandaki görseli günceller.
*/
void SetSoundLevel(void){
    ;;
   }
void SetSoundPeriod(void){
   ;;
}
void SetImage(void){
   ;;
}

void SetSensorError(void){

    for(int i=0; i<NUMBER_OF_FRONT_SENSOR; i++){
        if(ParkingAssistantManager.FrontSensors[i].State == Sensor_ERROR){
            // BURADA KULLANICIYA SENSORÜN BOZUK OLDUGUNU GÖSTERİR
        }
    }

    for(int i=0; i<NUMBER_OF_REAR_SENSOR; i++){
        if(ParkingAssistantManager.RearSensors[i].State == Sensor_ERROR){
            // BURADA KULLANICIYA SENSORÜN BOZUK OLDUGUNU GÖSTERİR
        }
    }
}