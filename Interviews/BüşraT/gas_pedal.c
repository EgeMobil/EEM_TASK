#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Sabitler
#define ADC_CHANNEL_1  0  
#define ADC_CHANNEL_2  1   
#define ADC_MAX_VALUE  4095
#define PEDAL_MIN_VOLTAGE 0.5
#define PEDAL_MAX_VOLTAGE 4.5
#define VREF 5.0  
#define SAFE_MODE_THRESHOLD 50  

// **************** SYSTEM LAYER (Sistem Katmanı) **************** //
// ADC simülasyonu - Sensör verilerini uyumlu hale getirme
uint16_t read_adc(uint8_t channel) {
    static uint16_t base_value = 2000;

    if (channel == ADC_CHANNEL_1) {
        base_value = (rand() % 100) + 2000;
        return base_value;
    }
    else if (channel == ADC_CHANNEL_2) {
        return base_value + (rand() % 10 - 5);
    }
    return 0;
}

// Motor hız kontrolü (PWM sinyali)
void set_motor_pwm(float duty_cycle) {
    printf("Motor hızı: %.2f%%\n", duty_cycle);
}

// **************** INTERFACE LAYER (Arayüz Katmanı) **************** //
// Pedal verisini işleyip % olarak hesaplar
float get_pedal_position() {
    uint16_t adc1 = read_adc(ADC_CHANNEL_1);
    uint16_t adc2 = read_adc(ADC_CHANNEL_2);

    // Sensörler uyumsuzsa hata durumu
    if (abs(adc1 - adc2) > SAFE_MODE_THRESHOLD) {
        printf("HATA: Sensör verileri tutarsız! Güvenli moda geçildi.\n");
        return -1;
    }

    // ADC -> Voltaj dönüşümü
    float voltage1 = (adc1 / (float)ADC_MAX_VALUE) * VREF;

    // Voltaj sınırlarını kontrol et
    if (voltage1 < PEDAL_MIN_VOLTAGE || voltage1 > PEDAL_MAX_VOLTAGE) {
        printf("HATA: Pedal voltajı hatalı! Güvenli moda geçildi.\n");
        return -1;
    }

    // % Gaz pedal konumu hesaplama
    return ((voltage1 - PEDAL_MIN_VOLTAGE) / (PEDAL_MAX_VOLTAGE - PEDAL_MIN_VOLTAGE)) * 100.0f;
}

// **************** SOURCE LAYER (Kaynak Katmanı) **************** //
// Motor hız verilerini ve pedal konumunu kaydet
void log_motor_data(float pedal_position, float motor_speed) {
    FILE* log_file = fopen("motor_log.txt", "a");
    if (log_file) {
        time_t now = time(NULL);
        fprintf(log_file, "%s | Pedal: %.2f%% | Motor: %.2f%%\n", ctime(&now), pedal_position, motor_speed);
        fclose(log_file);
    }
}

// **************** CONTROLLER LAYER (Kontrol Katmanı) **************** //
// Gaz pedalından alınan veriye göre motor hızını ayarla
void process_pedal_input() {
    float pedal_position = get_pedal_position();

    if (pedal_position < 0) {
        set_motor_pwm(0);
        log_motor_data(0, 0);
        return;
    }

    float motor_speed = pedal_position * 1.2;
    if (motor_speed > 100) motor_speed = 100;

    set_motor_pwm(motor_speed);
    log_motor_data(pedal_position, motor_speed);
}

// **************** INTERFACE: GÖSTERGE PANELİ **************** //
// Gösterge paneline pedal pozisyonu ve motor hızını gönder
void update_dashboard(float pedal_position, float motor_speed) {
    printf("[GÖSTERGE PANELİ] Pedal: %.2f%% | Motor Hız: %.2f RPM\n", pedal_position, motor_speed);
}

// **************** INTERFACE: ARAÇ KONTROL MODÜLÜ **************** //
// Araç kontrol modülüne pedal pozisyonu ve motor hızı gönder
void send_to_vehicle_control_module(float pedal_position, float motor_speed) {
    printf("[ARAÇ KONTROL] Pedal: %.2f%% | Motor: %.2f RPM\n", pedal_position, motor_speed);
}

// **************** APPLICATION LAYER (Uygulama Katmanı) **************** //
// Ana döngü: Her 10 ms'de bir pedal girişini okur ve işler
void main_loop() {
    while (1) {
        process_pedal_input();
        usleep(10000);  // 10 ms bekleme
    }
}

// **************** MAIN FUNCTION **************** //
int main() {
    printf("🚗🏁 Gaz Pedalı Kontrol Sistemi Başlatıldı...\n");
    main_loop();
    return 0;
}
