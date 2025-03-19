#include <stdio.h>
#include "traction_control_private.h"

// Singleton için statik değişkenler
static TCS_Manager instance;
static uint8_t is_initialized = 0;

/**
 * @brief Singleton örneğini döndürür.
 */
TCS_Manager* TCS_Manager_GetInstance() {
    if (!is_initialized) {
        TCS_Manager_CTOR();
        is_initialized = 1;
    }
    return &instance;
}

//  TCS Durum Fonksiyonları
static void Traction_enableImp(void) {
    instance.initialstatus = TCS_ENABLED;
    printf("Traction enabled\n");
}

static void Traction_disableImp(void) {
    instance.initialstatus = TCS_DISABLED;
    printf("Traction disabled\n");
}

static TcsStatus_t Traction_getStatusImp(void) {
    printf("Traction status queried\n");
    return instance.initialstatus;
}

//  Pedal Bilgi Fonksiyonları
static PedalState_t TCS_Manager_getBrakeImpl(void) {
    return instance.brake_position;
}

static PedalState_t TCS_Manager_getWheelSpeedImpl(void) {
    return instance.wheel_speed;
}

static PedalState_t TCS_Manager_getThrottleImpl(void) {
    return instance.throttle_position;
}

//  Çekiş Kaybı Tespiti
static void Tcs_Traction_Detection_lossImpl(void) {
    if (instance.getWheelSpeed() < WHEEL_SPEED_MIN) {
        printf("Motor traction loss detected!\n");
        if (instance.traction_getStatus() == TCS_DISABLED) {
            instance.traction_enable();
        }
    }
}

//  Pedal Durumuna Göre Çekiş Kontrolü
static void Tcs_set_tractionImpl(void) {
    if (instance.getThrottlePosition() == PEDAL_PRESSED) {
        instance.traction_enable();
    } else if (instance.getBrakePosition() == PEDAL_PRESSED) {
        instance.traction_disable();
    } else {
        instance.initialstatus = TCS_ERROR;
    }
}

//  Yapıcı Fonksiyon (Constructor)
void TCS_Manager_CTOR(void) {
    // Varsayılan değer atamaları
    instance.initialstatus = TCS_DISABLED;
    instance.throttle_position = PEDAL_RELEASED;
    instance.brake_position = PEDAL_RELEASED;

    // Fonksiyon pointer atamaları
    instance.getBrakePosition = TCS_Manager_getBrakeImpl;
    instance.getWheelSpeed = TCS_Manager_getWheelSpeedImpl;
    instance.getThrottlePosition = TCS_Manager_getThrottleImpl;

    instance.traction_enable = Traction_enableImp;
    instance.traction_disable = Traction_disableImp;
    instance.traction_getStatus = Traction_getStatusImp;

    instance.Tcs_set_traction = Tcs_set_tractionImpl;
    instance.Tcs_Traction_Detection_loss = Tcs_Traction_Detection_lossImpl;
}
