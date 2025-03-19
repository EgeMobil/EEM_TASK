#ifndef DEFINITION_H
#define DEFINITION_H

// Temel parametreler
#define MIN_SPEED_KMH       30.0f  // Minimum hız (km/saat)
#define MAX_SPEED_KMH      150.0f  // Maksimum hız (km/saat)
#define MIN_DISTANCE_M       2.0f  // Minimum güvenli mesafe (metre)
#define DEFAULT_TIME_GAP     2.0f  // Varsayılan takip mesafesi (saniye)

// ACC durumları
typedef enum {
    ACC_OFF,     // Kapalı
    ACC_STANDBY, // Hazır
    ACC_ACTIVE   // Aktif
} ACC_State;

// Return tipleri
typedef enum {
    ACC_OK,      // Başarılı
    ACC_ERROR    // Hata
} ACC_Result;

#endif
