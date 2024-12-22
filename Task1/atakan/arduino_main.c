typedef enum{
  LED_OFF,
  LED_ON
}LEDState;

LEDState currentState = LED_OFF;
const int ledPin = 13; // Led'in bağlı olduğu pin
const int delayTime = 1000; // Ledin yanıp sönme süresi ms.

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
  Serial.println("Led Kontrol sistemi başlıyor");
}

void updateLEDState()
{
  switch(currentState)
    {
        case LED_OFF:
            Serial.println("LED söndü. Şimdi yanacak.. \n");
            digitalWrite(ledPin, HIGH);;
            currentState = LED_ON;
        break;
        
        case LED_ON:
            Serial.println("LED yandı. Şimdi sönecek.. \n");
            digitalWrite(ledPin, LOW);
            currentState = LED_OFF;
        break;
        
        default:
            Serial.println("LED hatalı durumda. Şimdi sönecek.. \n");
            digitalWrite(ledPin, LOW);
            currentState = LED_OFF;
        break;
    }
}


void loop() 
{
  // put your main code here, to run repeatedly:
  updateLEDState();
  delay(delayTime);
}
