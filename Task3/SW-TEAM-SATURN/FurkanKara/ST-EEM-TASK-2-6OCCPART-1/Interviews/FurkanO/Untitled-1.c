#include <stdio.h>
#include <stdint.h>

//Sensör Verisini Okuma
float pedal_sensor_1(); // 1. sensör
float pedal_sensor_2(); // 2. sensör

// uyguluma
float pedal_data(float sensor1, float sensor2);

// motor
void control_motor(float pedal_position);

// Sistem Katmanı 
float pedal_sensor_1() {
    // Gerçek sistemde ADC okuma işlemi yapılır
    return 2.5; // Örnek değer
}

float pedal_sensor_2() {
    // Gerçek sistemde ADC okuma işlemi yapılır
    return 2.6; // Örnek değer
}

float pedal_data(float sensor1, float sensor2) {
    // Sensörlerin belirli bir tolerans içinde olması gerekiyor
    if (sensor1 < 0.5 || sensor1 > 4.5 || sensor2 < 0.5 || sensor2 > 4.5) {
        return 0.0; 
    }
    if (abs(sensor1 - sensor2) > 0.2) { // Tolerans sınırı
        return 0.0; 
    }
    
    // Pedal pozisyonunu normalize edelim (0-100 arası)
    float normalized_value = ((sensor1 - 0.5) / 4.0) * 100.0;
    return normalized_value;
}

void control_motor(float pedal_position) {
    // Motor hızını belirleyen fonksiyon
    printf("Motor hızı: %.2f%%\n", pedal_position);
}

int main() {
    while (1) {
        float sensor1 = pedal_sensor_1();
        float sensor2 = pedal_sensor_2();
        
        float pedal_position = pedal_data(sensor1, sensor2);
        control_motor(pedal_position);
        
        // 10 ms bekleme süresi simülasyonu
        // Gerçek sistemde bu bir zamanlayıcı (timer) ile yapılır
        usleep(10000);
    }
    return 0;
}