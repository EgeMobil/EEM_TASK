#ifndef PARKING_SENSOR_MANAGER_DEF_H_
#define PARKING_SENSOR_MANAGER_DEF_H_

#include "ArmCortexGPIO.h"
#include "stdint.h"

#define NUMBER_OF_FRONT_SENSOR 4
#define NUMBER_OF_REAR_SENSOR  4
#define DISTANCE_MAX_VAL 255
#define DISTANCE_MIN_VAL 1
#define YELLOW_ALARM_DISTANCE  150
#define RED_ALARM_DISTANCE     75



typedef enum{
    Sensor_OK=0,
    Sensor_Yellow_Alarm,
    Sensor_Red_Alarm,
    Sensor_ERROR
}sensor_return_t;


typedef enum{
    ParkingAssistant_OFF=0,
    ParkingAssistant_Calculation,
    ParkingAssistant_Control_Front,
    ParkingAssistant_Control_Rear,
    ParkingAssistant_Update,
    ParkingAssistant_Waiting,
    ParkingAssistant_Error
}parking_assistanst_prosses_t;

typedef enum{
    FRONT_ALARM,
    REAR_ALARM,
    IDLE
}alarm_t;

typedef struct{
    sensor_return_t   State;
    float             dataDistance;                                                                     // Park sensörünün mesafe bilgisini tutacağı değişken.
   
    GPIO_TypeDef      TrigPin;                                                                          // Sensor nesnesinin donanım ile bağlı olacağı trigger pini
    GPIO_TypeDef      EchoPin;                                                                          // Sensor nesnesinin donanım ile bağlı olacağı echo pini
    
    float             (*CalculationDistancePtr)(GPIO_TypeDef TRIG_PIN, GPIO_TypeDef ECHO_PIN );        // Sensörden okunan verileri mesafeye çevirir.

    sensor_return_t   (*CheckRangeDistancePtr)(float);                                                 // Mesafe bilgisi doğru mu geliyor. Kontrolü sağlanır
}sensor_t;


typedef struct
{
    parking_assistanst_prosses_t    State;
    sensor_t                        FrontSensors[NUMBER_OF_FRONT_SENSOR];                       // Bir yönde 4 adet sensörümüz olacak.
    sensor_t                        RearSensors[NUMBER_OF_REAR_SENSOR];                         // Bir yönde 4 adet sensörümüz olacak.

    int                             CurrentVehicleSpeed;                                        // Aracın anlık hızı.
    uint8_t                         CurrentGear;                                                // Anlık aracın vites bilgisi.

    parking_assistanst_prosses_t    (*UpdateAndVerifyDistanceWithFrontSensorsPtr)(void);        // 4 Sensör için distance verilerini günceller.
    parking_assistanst_prosses_t    (*UpdateAndVerifyDistanceWithRearSensorsPtr)(void);         // 4 Sensör için distance verilerini günceller.

    void                            (*SetSoundLevelPtr)(void);                                  // SOUND LEVELI AYARLAR
    void                            (*SetSoundPeriodPtr)(void);                                 // Periyod LEVELI AYARLAR
    void                            (*SetImagePtr)(void);                                       // Ekranda aracın ne kadar yakın oldugunu gösteren resmi ayarlar
    void                            (*SetSensorErrorPtr)(void);                                    // Sensorlerdeki hatayı kullanıcıya bildirir.

    parking_assistanst_prosses_t    (*CheckInformationForProssesPtr)(void);                     // Vites ve Hız bilgisine göre akışı yönetecek fonskiyon       

    alarm_t                         Alarm;                                                      // Bu değişken Asistanın Alarm verip vermeyeceğine karar veriri.

    int                             LoopPeriod;                                                 // Sensörden veri güncelleme değeri mesafeye göre değişir
}parking_asistant_t;




extern parking_asistant_t ParkingAssistantManager ;




#endif /* PARKING_SENSOR_MANAGER_DEF_H_*/