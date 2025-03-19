#include "acc_public.h"
#include "acc_private.h"
#include <stdio.h>

static struct {
    ACC_State state;            // Durum
    float setSpeed;             // Ayarlanan hız
    float currentSpeed;         // Mevcut hız
    float leadDistance;         // Öndeki araç mesafesi
} acc = {
    .state = ACC_OFF,
    .setSpeed = 0,
    .currentSpeed = 0,
    .leadDistance = 100,
};


float ACC_getVehicleSpeed(void) {
    // Araç sensöründen oku
    return 90.0f;
}


float ACC_getLeadVehicleDistance(void) {
    // Radar sensöründen oku
    return 40.0f;
}

float ACC_calculateSafeDistance(float speed) {

    // Mesafe = hız / 2
    float distance = speed / 2.0f;

    if (distance < MIN_DISTANCE_M) {
        distance = MIN_DISTANCE_M;
    }
    
    return distance;
}

float ACC_calculateAcceleration(void) {
    float acceleration = 0.0f;
    float safeDistance = ACC_calculateSafeDistance(acc.currentSpeed);
    
    // Öndeki araç 100m'den yakınsa, yavaşlama yap
    if (acc.leadDistance < 100) {
        // Yavaşlama ivmesi formülleri burada olacak şimdilik -1
        acceleration = -1.0f;
    } else {
        // Önde 100m içinde araç yoksa, ayarlanan hıza göre ivmelen
        // Başka formüllerle değiştirilebilir şimdilik 1
        acceleration = 1.0f * (acc.setSpeed - acc.currentSpeed);
    }
    
    return acceleration;
}

void ACC_sendAccelerationCommand(float acceleration) {
    //Kontrol kısmına gönderilmesi gereken değerler
    printf("İvme kontrol: %.2f m/s²\n", acceleration);
}

ACC_Result ACC_init(void) {
    acc.state = ACC_STANDBY;
    printf("ACC başlatıldı\n");
    return ACC_OK;
}

ACC_Result ACC_enable(void) {
    if (acc.state == ACC_OFF) {
        return ACC_ERROR;
    }
    acc.currentSpeed = ACC_getVehicleSpeed();
    if (acc.currentSpeed < MIN_SPEED_KMH) {
        printf("Hız çok düşük (%.1f km/h)\n", acc.currentSpeed);
        return ACC_ERROR;
    }
    if (acc.currentSpeed > MAX_SPEED_KMH) {
        printf("Hız çok yüksek (%.1f km/h)\n", acc.currentSpeed);
        return ACC_ERROR;
    }
    acc.setSpeed = acc.currentSpeed;
    acc.state = ACC_ACTIVE;
    printf("ACC aktifleştirildi, hız: %.1f km/h\n", acc.setSpeed);
    return ACC_OK;
}

ACC_Result ACC_disable(void) {
    acc.state = ACC_STANDBY;
    printf("ACC devre dışı bırakıldı\n");
    return ACC_OK;
}

ACC_Result ACC_setSpeed(float speedKmh) {
    if (speedKmh < MIN_SPEED_KMH || speedKmh > MAX_SPEED_KMH) {
        printf("Geçersiz hız değeri: %.1f km/h\n", speedKmh);
        return ACC_ERROR;
    }
    acc.setSpeed = speedKmh;
    printf("Hız ayarlandı: %.1f km/h\n", speedKmh);
    return ACC_OK;
}


ACC_State ACC_getState(void) {
    return acc.state;
}

float ACC_getSetSpeed(void) {
    return acc.setSpeed;
}

ACC_Result ACC_update(void) {
    if (acc.state != ACC_ACTIVE) {
        return ACC_OK;
    }
    acc.currentSpeed = ACC_getVehicleSpeed();
    acc.leadDistance = ACC_getLeadVehicleDistance();
    float safeDistance = ACC_calculateSafeDistance(acc.currentSpeed);
    if (acc.leadDistance < safeDistance) {
        printf("UYARI: Güvenli mesafe ihlali!\n");
        ACC_disable();
        // Burada frenleme yapılabilir
        return ACC_ERROR;
    }
    float acceleration = ACC_calculateAcceleration();
    ACC_sendAccelerationCommand(acceleration);
    
    return ACC_OK;
}
