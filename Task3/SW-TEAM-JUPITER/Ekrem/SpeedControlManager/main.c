#include "speed_control_public.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Rastgele olay üretme fonksiyonu
int getRandomEvent(int lastEvent) {
  int event;
  do {
    event = rand() % 6;
  } while (event == lastEvent);
  return event;
}

int main() {
  srand(time(0));

  int userSpeed;
  printf("Lütfen bir hız değeri girin (10-60 km/h arasında): \n\n");
  scanf("%d", &userSpeed);

  Speed_setTarget(userSpeed);
  printf(" Başlangıç Hızı: %d km/h\n\n\n", Speed_getCurrent());

  int lastEvent = -1;
  for (int i = 0; i < 15; i++) {
    int event = getRandomEvent(lastEvent);
    lastEvent = event;
    Speed_adjust(event);
  }

  printf(" Son hız: %d km/h\n", Speed_getCurrent());
  return 0;
}
