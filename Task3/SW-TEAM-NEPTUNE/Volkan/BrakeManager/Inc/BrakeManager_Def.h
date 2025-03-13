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

    BrakeStatus_t Status;
    ABS_Status_t ABS_Status;

    /* Private variables --> bunlara doğrudan erişim olmayacak. */
    float   current_brake_pressure;  /* Fren basıncı */
    uint8_t abs_active;             /* ABS aktif mi? */
    uint8_t brake_active;
    float   vehicle_speed;

    /* Private fonksiyonlar */
    void (*applyBrakePressure)(float pressure);  /* Fren basıncı uygular */
    void (*releaseBrakePressure)(void);         /* Freni bırakır */

    void (*setBrakePressure)(float pressure);   /* Fren basıncını set eder */
    void (*setVehicleSpeed)(float speed);   /* Fren basıncını set eder */

    ABS_Status_t (*manangmentABS)(void);        /* ABS'yi yönetir */
    void (*absAlgorithm)(void);                 /* ABS algoritmasını çalıştırır */
    const char* (*toString)(void);              /* Nesne bilgisini stringe çevirir */
};

typedef struct BrakeManager BrakeManager_t;



#endif /* BRAKEMANAGER_DEF_H */
