#include <math.h>
#include <stdio.h>
#include "../include/interface.h"

// Gercek ADC okuması yerine simulasyon icin bir sinus dalgasi kullaniyoruz.
// Bu simulasyon, gaz pedalinin konumunun zamanla artip azalmasini temsil eder.
float readGasPedalSensor(void) {
  static unsigned int counter = 0; // zamani simule etmek icin sayac
  const float min_voltage = 0.5f;
  const float max_voltage = 4.5f;

  // sinus dalgasi elde etmek icin gerekli parametreler
  float amplitude = (max_voltage - min_voltage) / 2.0f; 
  float offset = (max_voltage + min_voltage) / 2.0f; 

  float frequency = 0.05f; // her 10ms lik okuma icin 20 saniyelik periyot

  float value = amplitude * sin(2.0 * M_PI * frequency * counter) + offset;

  counter++;

  return value;
}
