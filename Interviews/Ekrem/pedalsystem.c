#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PEDAL_VALUE 0.5
#define MAX_PEDAL_VALUE 4.5
#define TOTAL_STEPS 30
#define SUDDEN_CHANGE_THRESHOLD 0.3

int calculate_pedal_position(float sensor_data) {
  return (int)((sensor_data - MIN_PEDAL_VALUE) / (MAX_PEDAL_VALUE - MIN_PEDAL_VALUE) * 100);
}

int calculate_motor_speed(int position) {
  return position * 2;
}

void detect_sudden_change(float previous_data, float current_data) {
  if (fabs(current_data - previous_data) > SUDDEN_CHANGE_THRESHOLD) {
    printf("Uyarı: Ani pedal konum değişimi algılandı!\n");
  }
}

float generate_sensor_data(int step) {
  float sensor_data;
  if (step < 10) {
    sensor_data = MIN_PEDAL_VALUE + (step * (MAX_PEDAL_VALUE - MIN_PEDAL_VALUE) / 10.0);
  } else if (step < 20) {
    sensor_data = MIN_PEDAL_VALUE + ((step - 10) * (MAX_PEDAL_VALUE - MIN_PEDAL_VALUE) / 5.0);
  } else {
    sensor_data = MAX_PEDAL_VALUE - ((step - 20) * (MAX_PEDAL_VALUE - MIN_PEDAL_VALUE) / 5.0);
  }
  return fmin(fmax(sensor_data, MIN_PEDAL_VALUE), MAX_PEDAL_VALUE);
}

int main() {
  srand(time(0));

  int choice;
  float previous_data = MIN_PEDAL_VALUE; 

  do {
    printf("\n=== Gaz Pedalı Simülasyonu ===\n");
    printf("1 - Rastgele Simülasyon\n");
    printf("2 - Desene Dayalı Simülasyon\n");
    printf("3 - Kullanıcı Girişi ile Simülasyon\n");
    printf("0 - Çıkış\n");
    printf("Seçiminizi girin: ");
    scanf("%d", &choice);

    if (choice == 1) {
      printf("\nRastgele Simülasyon Çalıştırılıyor...\n");
      for (int i = 0; i < TOTAL_STEPS; i++) {
        float sensor_data = ((rand() / (float)RAND_MAX) * (MAX_PEDAL_VALUE - MIN_PEDAL_VALUE)) + MIN_PEDAL_VALUE;
        int position = calculate_pedal_position(sensor_data);
        int speed = calculate_motor_speed(position);

        detect_sudden_change(previous_data, sensor_data);
        previous_data = sensor_data;

        printf("Adım %d: Sensör Verisi: %.2fV, Pedal Pozisyonu: %d, Motor Hızı: %d\n",
               i + 1, sensor_data, position, speed);
      }
    } else if (choice == 2) {
      printf("\nDesene Dayalı Simülasyon Çalıştırılıyor...\n");
      for (int i = 0; i < TOTAL_STEPS; i++) {
        float sensor_data = generate_sensor_data(i);
        int position = calculate_pedal_position(sensor_data);
        int speed = calculate_motor_speed(position);

        detect_sudden_change(previous_data, sensor_data);
        previous_data = sensor_data;

        printf("Adım %d: Sensör Verisi: %.2fV, Pedal Pozisyonu: %d, Motor Hızı: %d\n",
               i + 1, sensor_data, position, speed);
      }
    } else if (choice == 3) {
      printf("\nKullanıcı Girişi ile Simülasyon Çalıştırılıyor...\n");
      for (int i = 0; i < TOTAL_STEPS; i++) {
        float sensor_data;
        printf("Adım %d için sensör verisini girin (%.2fV - %.2fV arası): ",
               i + 1, MIN_PEDAL_VALUE, MAX_PEDAL_VALUE);
        if (scanf("%f", &sensor_data) != 1 || sensor_data < MIN_PEDAL_VALUE || sensor_data > MAX_PEDAL_VALUE) {
          printf("Geçersiz giriş! %.2fV ile %.2fV arasında bir değer girin.\n",
                 MIN_PEDAL_VALUE, MAX_PEDAL_VALUE);
          while (getchar() != '\n');  
          i--;
          continue;
        }

        int position = calculate_pedal_position(sensor_data);
        int speed = calculate_motor_speed(position);

        detect_sudden_change(previous_data, sensor_data);
        previous_data = sensor_data;

        printf("Adım %d: Sensör Verisi: %.2fV, Pedal Pozisyonu: %d, Motor Hızı: %d\n",
               i + 1, sensor_data, position, speed);
      }
    } else if (choice == 0) {
      printf("Programdan çıkılıyor...\n");
    } else {
      printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
    }

  } while (choice != 0);

  return 0;
}
