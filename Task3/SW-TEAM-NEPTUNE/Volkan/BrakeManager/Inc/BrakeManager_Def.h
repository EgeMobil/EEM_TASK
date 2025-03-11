#ifndef BRAKEMANAGER_DEF_H
#define BRAKEMANAGER_DEF_H

#include <stdint.h>

/* Fren hata durumları */
typedef enum {
    BRAKE_ON,
    BRAKE_OFF
} BrakeStatus_t;

typedef enum {
    ABS_ON,
    ABS_OFF,
} ABS_Status_t;

struct BrakeManager {

    // Public Stateler
    BrakeStatus_t Status;
    ABS_Status_t ABS_Status;

    /* Private variables --> bunlara doğrudan erişim olmayacak. */
    float   current_brake_pressure;  /* Fren basıncı */
    uint8_t abs_active;             /* ABS aktif mi? */
    float   pedal_position;          /* Pedal konumu (0-10 arası) */
    float   vehicle_speed;           /* Araç hızı */
    float   wheel_speed;            /* Tekerlek hızı */
    uint8_t brake_active;

    /* Private fonksiyonlar */
    void (*applyBrakePressure)(float pressure);  /* Fren basıncı uygular */
    float (*readCurrentPressure)(void);     /* Fren basıncını okur */
    void (*releaseBrakePressure)(void);     /* Freni bırakır */
    void (*regulateBrakePressure)(void);    /* Fren basıncını düzenler */
    int  (*detectWheelSlip)(void);           /* Kayma tespiti yapılır */
    void  (*setPedalPos)(float pedalPos);    /* Fren pedalını okur */
    void (*pedalPosToPressure)(void);       /* Fren pedalını basınca dönüştürür */
    void (*setVehicleSpeed)(float speed);   /* Nesnenin araç hızını günceller*/
    void (*setWheelSpeed)(float wheel_Speed);/* Nesnenin araç hızını günceller*/
    ABS_Status_t (*manangmentABS)(void);     /* ABS nin aktif olup olmadığına karar verir*/    
};

typedef struct BrakeManager BrakeManager_t;

void BrakeManager_CTOR(void);   /* Constructor */


#endif /* BRAKEMANAGER_DEF_H */
