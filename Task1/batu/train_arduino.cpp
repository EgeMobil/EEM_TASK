/*
arduino simülasyon link:
https://wokwi.com/projects/417975623147266049
*/
const int switchPin = 2;  // Anahtar pini
int switchState = 0;  // Anahtarın durumu
const int iLED = 4;   // idle led
const int lLED = 5;   // loading led
const int mLED = 6;   // moving led
const int sLED = 7;   // stopping led

/*
kırmızı led idle
yeşil led loading
mavi led moving
sarı led stopping
*/

// Tren durumlarını tutan enum
typedef enum {
    IDLE,    // tren istasyonda bekliyor
    LOADING, // tren yolcu alıyor ve indiriyor
    MOVING,  // tren öbür istasyona hareket ediyor
    STOPPING // tren durağa yaklaştı yavaşladı ve durdu
} trainStates;

trainStates EgeMobil = IDLE;

void setup() {

  pinMode(iLED, OUTPUT);
  pinMode(lLED, OUTPUT);
  pinMode(mLED, OUTPUT);
  pinMode(sLED, OUTPUT);
  pinMode(switchPin, INPUT); 
  Serial.begin(9600);  
}

void updateTrain(trainStates* train) {
    static int station = 1;
    switch (*train) {
    case IDLE:
        digitalWrite(sLED, LOW);
        digitalWrite(iLED, HIGH);
        Serial.print(station);
        Serial.println(". istasyondasınız");
        Serial.println("Tren hazırlanmakta, şimdi yolcu alımı yapacak.");
        *train = LOADING;
        break;
    case LOADING:
        digitalWrite(iLED, LOW);
        digitalWrite(lLED, HIGH);
        station++;
        Serial.print("Tren yolcu alımını tamamladı, şimdi ");
        Serial.print(station);
        Serial.println(". istasyona doğru harekete geçiyor.");
        *train = MOVING;
        break;
    case MOVING:
        digitalWrite(lLED, LOW);
        digitalWrite(mLED, HIGH);
        Serial.println("Tren durağa yaklaşıyor, şimdi yavaşlayarak duracak.");
        *train = STOPPING;
        break;
    case STOPPING:
        digitalWrite(mLED, LOW);
        digitalWrite(sLED, HIGH);
        Serial.print("Tren ");
        Serial.print(station);
        Serial.println(". istasyonda durdu, şimdi bekleme moduna giriyor.");
        *train = IDLE;
        break;
    default:
        break;
    }
}

void loop() {
    // emri sorgula
    switchState = digitalRead(switchPin);

    // emir gelirse
    if (switchState == HIGH) {
        for (int i = 0; i < 4; i++) {
            updateTrain(&EgeMobil);  // Tren durumunu güncelle
            delay(2000);            // Bekleme süresi (2 saniye)

            // emri kontrol et
            switchState = digitalRead(switchPin);
            if (switchState == LOW) {  // emir gelirse dur
                Serial.println("Tren durduruldu.");
                break;
            }
        }
    } else {
        // emir geri alındı
        Serial.println("Tren duruyor.");
        digitalWrite(iLED, LOW); 
        digitalWrite(lLED, LOW);
        digitalWrite(mLED, LOW);
        digitalWrite(sLED, LOW);
        delay(500);
    }
}
