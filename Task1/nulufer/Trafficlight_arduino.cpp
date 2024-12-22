// arduino linki= https://wokwi.com/projects/417981105407244289

//pinlerin bağlandığı noktaları belirtiyoruz
int redPin = 5;    
int yellowPin = 3; 
int greenPin = 4;  

enum TrafficLightState
{
    RED,
    YELLOW,
    GREEN
};

void updateTrafficLightState(TrafficLightState* currentState)
{
    switch (*currentState)
    {
    case RED: //kırmızıdan yeşile
        Serial.println("Kırmızı ışık: Dur");
        digitalWrite(redPin, HIGH);    
        digitalWrite(yellowPin, LOW);  
        digitalWrite(greenPin, LOW);   
        *currentState = GREEN;  
        break;

    case GREEN: //yeşilden sarıya
        Serial.println("Yeşil ışık: Geç");
        digitalWrite(redPin, LOW); 
        digitalWrite(yellowPin, LOW); 
        digitalWrite(greenPin, HIGH); 
        *currentState = YELLOW; 
        break;

    case YELLOW: //sarıdan kırmızıya
        Serial.println("Sarı ışık: Geçişe hazırlan");
        digitalWrite(redPin, LOW);    
        digitalWrite(yellowPin, HIGH); 
        digitalWrite(greenPin, LOW);  
        *currentState = RED;  
        break;

    default:
        Serial.println("Hatalı durum");
        digitalWrite(redPin, HIGH);    
        *currentState = RED;  
        break;
    }
}

void setup()
{
    Serial.begin(9600);

    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
}

void loop()
{
    TrafficLightState currentState = RED; 
    int iterations = 3;  //Döngünün kaç kere tekrar edeceğini gösterir

    for (int i = 0; i < iterations; i++)
    {
        updateTrafficLightState(&currentState); 

       //süreleri burada belirtiyoruz 
        switch (currentState)
        {
        case RED:
            delay(20000);  
            break;

        case GREEN:
            delay(10000);  
            break;

        case YELLOW:
            delay(5000);   
            break;
        }
    }

    Serial.println("Trafik ışığı kontrol sistemi tamamlandı.");
    delay(1000);   
}
