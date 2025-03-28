#include <stdio.h>
#include "brake_control_public.h"
#include "brake_control_private.h"
#include "brake_control_manager.h"
#include "abs_algorithm.h"
#include "definition.h"

/* Function declarations */
static void display_menu(void);
static void handle_brake_status(BrakeStatus status);

int main(void) {
    printf("Fren sistemi başlatılıyor...\n");
    
    // Initialize hardware
    if (!init_brake_hardware() || !init_wheel_sensors()) {
        printf("Donanım başlatılamadı!\n");
        return -1;
    }

    // Check system readiness
    if (!is_brake_system_ready()) {
        printf("Fren sistemi hazır değil!\n");
        return -1;
    }

    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                BrakeStatus status = Brake_Apply();
                handle_brake_status(status);
                break;
            }
            case 2: {
                BrakeStatus status = Brake_Release();
                handle_brake_status(status);
                break;
            }
            case 3: {
                float pressure;
                printf("Ayarlamak istediğiniz basıncı girin (0-%.1f bar): ", MAX_PRESSURE);
                scanf("%f", &pressure);
                BrakeStatus status = Brake_SetPressure(pressure);
                handle_brake_status(status);
                break;
            }
            case 4:
                printf("Çıkış yapılıyor...\n");
                Brake_Release();  // Ensure safe state before exit
                return 0;
            default:
                printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
                break;
        }

        system_delay(100);  // Add small delay between operations
    }
}

/**
 * @brief Displays the main menu options
 */
static void display_menu(void) {
    printf("\n=== Fren Kontrol Sistemi ===\n");
    printf("1 - Fren Uygula\n");
    printf("2 - Fren Bırak\n");
    printf("3 - Belirli Basınç Ayarla\n");
    printf("4 - Çıkış\n");
    printf("Seçiminizi yapın: ");
}

/**
 * @brief Handles brake operation status and displays appropriate message
 * @param status BrakeStatus to handle
 */
static void handle_brake_status(BrakeStatus status) {
    switch (status) {
        case BRAKE_OK:
            printf("İşlem başarılı. Mevcut basınç: %.2f bar\n", get_brake_pressure());
            break;
        case BRAKE_ABS_ACTIVE:
            printf("ABS devrede! Basınç otomatik ayarlanıyor.\n");
            break;
        case BRAKE_ERROR:
            printf("Sistem hatası! İşlem başarısız.\n");
            break;
        case BRAKE_INVALID_PARAM:
            printf("Geçersiz basınç değeri!\n");
            break;
        default:
            printf("Beklenmeyen hata!\n");
            break;
    }
}