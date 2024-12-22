/*
arduino simülasyon link:
https://wokwi.com/projects/417975623147266049
*/
const int switchPin = 2;  // Anahtarın bağlandığı dijital pin
int switchState = 0;  // Anahtarın durumu
const int iLED = 4; // idle led
const int lLED = 5;// loading led
const int mLED = 6;// mLed
const int sLED = 7;// sLed

/*
kırmızı led ıdle
yeşil led loading
mavi sarı moving
sarı led stopping
*/

typedef enum {
    IDLE,    // The train is waiting in station
    LOADING, // Passengers are getting off or boarding the train.
    MOVING,  // The train is going.
    STOPPING // The train is slowing down and stopping.
} trainStates;

void setup() {
  // LED pinlerini OUTPUT olarak ayarlayın
  pinMode(iLED, OUTPUT);
  pinMode(lLED, OUTPUT);
  pinMode(mLED, OUTPUT);
  pinMode(sLED, OUTPUT);
  pinMode(switchPin, INPUT);  // Anahtarı giriş olarak ayarla
  Serial.begin(9600);  // Seri iletişimi başlat
}

void updateTrain(trainStates* train){
    static int station = 1;
    switch (*train)
    {
    case IDLE:
        digitalWrite(sLED, LOW);
        digitalWrite(iLED, HIGH);
        Serial.print(station);
        Serial.println(". istasyondasınız");
        Serial.println("Tren hazırlanmakta şimdi yolcu alımı yapacak.");
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
    trainStates EgeMobil = IDLE;
    switchState = digitalRead(switchPin);  // emiri kontrol et

    // Anahtar açıkken (HIGH olduğunda)
    if (switchState == HIGH) {
        while (switchState == HIGH) {  // emir gelirse çalışacak
        updateTrain(&EgeMobil);  // Durum güncellemesi
        delay(2000);  // Bekleme süresi (2 saniye)
        switchState = digitalRead(switchPin);}  // Anahtarın durumunu tekrar kontrol et
    } else {
        // Anahtar kapalı olduğunda
        Serial.println("tren duruyor");
        delay(500);  // 500ms bekle
    }
}
