//https://wokwi.com/projects/417988685526188033

enum CamasirState {
  CAMASIR_YIKAMA,
  CAMASIR_DURULAMA,
  CAMASIR_SIKMA
};

CamasirState currentState = CAMASIR_YIKAMA;

int redLed = 2;    // Yıkama LED'i
int yellowLed = 3; // Durulama LED'i
int greenLed = 4;  // Sıkma LED'i

bool suVar = true; // Su kontrolü

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  Serial.begin(9600);
  Serial.println("Makine çalışmaya başlıyor!");
}

void loop() {
  if (!suVar) {
    Serial.println("Su yok! İşlem durduruldu.");
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    while (true); // Su yoksa dur
  }

  switch (currentState) {
    case CAMASIR_YIKAMA:
      Serial.println("Su var. İşlem devam ediyor.");
      Serial.println("Çamaşırlar yıkanmaya başladı, birazdan durulanacak.");
      digitalWrite(redLed, HIGH);
      digitalWrite(yellowLed, LOW);
      digitalWrite(greenLed, LOW);
      delay(3000); // Yıkama süresi
      currentState = CAMASIR_DURULAMA;
      break;

    case CAMASIR_DURULAMA:
      Serial.println("Su var. İşlem devam ediyor.");
      Serial.println("Çamaşırlar durulanmaya başladı, birazdan sıkma yapılacak.");
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, HIGH);
      digitalWrite(greenLed, LOW);
      delay(2000); // Durulama süresi
      currentState = CAMASIR_SIKMA;
      break;

    case CAMASIR_SIKMA:
      Serial.println("Su var. İşlem devam ediyor.");
      Serial.println("Çamaşırlara sıkma yapılmaya başlandı, birazdan bitecek.");
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(greenLed, HIGH);
      delay(1500); // Sıkma süresi
      currentState = CAMASIR_YIKAMA; // Döngüye tekrar başla
      break;

    default:
      Serial.println("Hata: Geçersiz durum!");
      break;
  }
}

