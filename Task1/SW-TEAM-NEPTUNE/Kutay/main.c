#include <unistd.h>

typedef enum{
    GUNDUZ, ALACAKARANLIK, GECE, HAREKET_ALGILAMA, SABAH}   State;

int main()
{
    State currentState;
    float lux;
    
  
    switch (currentState) {
      case GUNDUZ:
        //analogWrite(LED_PIN, 0);
        if (lux < 10)  // Alacakaranlık eşiği
          currentState = ALACAKARANLIK;
        break;
  
      case ALACAKARANLIK:
        //analogWrite(LED_PIN, 76);  // %30 parlaklık (0-255 ölçeğinde)
        if (lux < 1)      // Gece eşiği
          currentState = GECE;
        break;
  
      case GECE:
        //analogWrite(LED_PIN, 76);
        if (motion == HIGH)
          currentState = HAREKET_ALGILAMA;
        break;
  
      case HAREKET_ALGILAMA:
        //analogWrite(LED_PIN, 255);  // %100 parlaklık
        delay(5000);  // 5 saniye sonra geri dön
        currentState = GECE;
        break;
  
      case SABAH:
        //digitalWrite(LED_PIN, LOW);
        if (lux > 300)  // Gündüz eşiği
          currentState = GUNDUZ;
        break;
    }

    return 0;
}
