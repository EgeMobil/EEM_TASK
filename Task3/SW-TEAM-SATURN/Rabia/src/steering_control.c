#include "steering_control_public.h"
#include "steering_control_private.h"
#include "definition.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct SteeringControlManager
{
    struct SteeringControlData privateData;
};

static double processSensorData(double rawValue, double offset)
{
    double normalizedValue = (rawValue - 500.0) / 10.0; // ornek olcekleme
    return normalizedValue + offset;
}

SteeringControlManager *Steering_create()
{
    SteeringControlManager *manager = (SteeringControlManager *)malloc(sizeof(SteeringControlManager));
    if (manager != NULL)
    {
        // baslangic degerleri
        manager->privateData.rawSensorValue = 0.0;
        manager->privateData.calibrationOffset = 0.0;
        manager->privateData.currentAngle = 0.0;
    }
    return manager;
}

bool Steering_setAngle(SteeringControlManager *manager, double angle)
{
    if (manager == NULL)
    {
        return false;
    }
    if (angle >= MIN_STEERING_ANGLE && angle <= MAX_STEERING_ANGLE)
    {

        manager->privateData.currentAngle = angle;
        return true;
    }
    else
    {
        printf("UYARI: İstenen direksiyon açısı sınırların dışında: %.2f\n", angle);
        return false;
    }
}

double Steering_getAngle(const SteeringControlManager *manager)
{
    if (manager == NULL)
    {
        return NAN;
    }
    return manager->privateData.currentAngle;
}

void Steering_calibrate(SteeringControlManager *manager)
{
    if (manager == NULL)
    {
        return;
    }

    double currentRawValue = 500.0; // ornek raw value
    manager->privateData.calibrationOffset = -processSensorData(currentRawValue, 0.0);
    printf("Direksiyon kalibre edildi.\n");
}

void Steering_destroy(SteeringControlManager *manager)
{
    free(manager);
}

void simulateSensorRead(SteeringControlManager *manager, double newRawValue)
{
    if (manager != NULL)
    {
        manager->privateData.rawSensorValue = newRawValue;
        manager->privateData.currentAngle = processSensorData(manager->privateData.rawSensorValue, manager->privateData.calibrationOffset);

        if (manager->privateData.currentAngle < MIN_STEERING_ANGLE)
        {
            manager->privateData.currentAngle = MIN_STEERING_ANGLE;
        }
        else if (manager->privateData.currentAngle > MAX_STEERING_ANGLE)
        {
            manager->privateData.currentAngle = MAX_STEERING_ANGLE;
        }
    }
}

// test
int main()
{
    SteeringControlManager *steeringManager = Steering_create();

    if (steeringManager != NULL)
    {
        printf("Başlangıç açısı: %.2f\n", Steering_getAngle(steeringManager));

        Steering_calibrate(steeringManager);
        printf("Kalibrasyon sonrası açı: %.2f\n", Steering_getAngle(steeringManager));

        Steering_setAngle(steeringManager, 30.0);
        printf("Ayar sonrası açı: %.2f\n", Steering_getAngle(steeringManager));

        Steering_setAngle(steeringManager, 90.0); // sinir disi deger

        simulateSensorRead(steeringManager, 550.0);
        printf("Sensör okuması sonrası açı: %.2f\n", Steering_getAngle(steeringManager));

        Steering_destroy(steeringManager);
    }
    else
    {
        fprintf(stderr, "SteeringControlManager oluşturulamadı!\n");
        return 1;
    }

    return 0;
}