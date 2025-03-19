#ifndef TRACTION_CONTROL_DEFINITION_H
#define TRACTION_CONTROL_DEFINITION_H

#include <stdio.h>
#include <stdint.h>

#define WHEEL_SPEED_MIN  50

/**
 * @brief Pedal durumlarını belirtir.
 */
typedef enum {
    PEDAL_RELEASED = 0,
    PEDAL_PRESSED
} PedalState_t;

/**
 * @brief Sensör verilerini içeren yapı.
 */
typedef struct {
    uint32_t brakeposition;
    uint32_t throttleposition;
    uint16_t wheelspeed;
} SensorState_t;

/**
 * @brief Çekiş kontrol (TCS) durumu.
 */
typedef enum {
    TCS_ERROR = 0,
    TCS_ENABLED,
    TCS_DISABLED
} TcsStatus_t;

/**
 * @brief TCS Manager Sınıfı
 */
typedef struct {
    // Sensör değişkenleri
    TcsStatus_t initialstatus;
    uint32_t wheel_speed; 
    PedalState_t throttle_position;
    PedalState_t brake_position;

    SensorState_t sensor_type;

    // Metotlar (Fonksiyon pointerları)
    PedalState_t (*getWheelSpeed)(void);
    PedalState_t (*getBrakePosition)(void);
    PedalState_t (*getThrottlePosition)(void);

    void (*traction_enable)(void);
    void (*traction_disable)(void);
    TcsStatus_t (*traction_getStatus)(void);

    void (*Tcs_Traction_Detection_loss)(void);
    void (*Tcs_set_traction)(void);
} TCS_Manager;

#endif 