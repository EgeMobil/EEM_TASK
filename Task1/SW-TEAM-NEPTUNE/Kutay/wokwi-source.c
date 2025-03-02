#define PIR_INPUT 9
#define LDR_INPUT A0
#define LED_PIN 6

void setup() {
  pinMode(PIR_INPUT, INPUT);
  pinMode(LDR_INPUT, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

typedef enum {
  GUNDUZ, ALACAKARANLIK, GECE, HAREKET_ALGILAMA, SABAH
} State;

const float GAMMA = 0.7;
const float RL10 = 50;

void loop() {
  State currentState;
  int motion = digitalRead(PIR_INPUT); //PIR input

  int analogValue = analogRead(LDR_INPUT);
  float voltage = analogValue / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

  switch (currentState) {
    case GUNDUZ:
      analogWrite(LED_PIN, 0);
      if (lux < 10)  // Alacakaranlık eşiği
        currentState = ALACAKARANLIK;
      break;

    case ALACAKARANLIK:
      analogWrite(LED_PIN, 76);  // %30 parlaklık (0-255 ölçeğinde)
      if (lux < 1)      // Gece eşiği
        currentState = GECE;
      break;

    case GECE:
      analogWrite(LED_PIN, 76);
      if (motion == HIGH)
        currentState = HAREKET_ALGILAMA;
      break;

    case HAREKET_ALGILAMA:
      analogWrite(LED_PIN, 255);  // %100 parlaklık
      delay(5000);  // 5 saniye sonra geri dön
      currentState = GECE;
      break;

    case SABAH:
      digitalWrite(LED_PIN, LOW);
      if (lux > 300)  // Gündüz eşiği
        currentState = GUNDUZ;
      break;
  }

  delay(1000);
}
