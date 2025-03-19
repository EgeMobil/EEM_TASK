#include "../include/controller.h"
#include "../include/logger.h"
#include "../include/interface.h"
#include <stdio.h>

#define MIN_VOLTAGE 0.5f
#define MAX_VOLTAGE 4.5f
#define MAX_MOTOR_SPEED 6000.0f // RPM

float processGasPedalData(void) {
  // Analog sensor versini oku
  float sensorValue = readGasPedalSensor();

  // veriyi araliga yerlestir
  // simule veride aralik disinda veri gelmeyecek [0.5, 4.5]
  if (sensorValue < MIN_VOLTAGE) {
    log_message(LOG_LEVEL_ERROR,"Gaz pedali sensor verisi esik degerden dusuk: %.2f\n", sensorValue);
    sensorValue = MIN_VOLTAGE;
  } else if (sensorValue > MAX_VOLTAGE) {
    log_message(LOG_LEVEL_ERROR,"Gaz pedali sensor verisi esik degerden yuksek: %.2f\n",
           sensorValue);
    sensorValue = MAX_VOLTAGE;
  }

  // degeri motor hizina donustur
  // lineer haritalama
  // (sensorValue - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE) = throttle_orani
  // ( 0 ile 1 arasinda) throttle orani * MAX_MOTOR_SPEED = motor hizi (rpm)

  float throttleRatio =
      (sensorValue - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE);

  float motorSpeed = throttleRatio * MAX_MOTOR_SPEED;

  return motorSpeed;
}
