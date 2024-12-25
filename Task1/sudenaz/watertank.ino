enum WaterTankState {
  FULL,        
  EMPTYING,    
  EMPTY,       
  FILLING      
};

WaterTankState currentState = EMPTY;

const int pumpPin = 9;
const int waterLevelSensorPin = A0;

int lowWaterLevel = 100; 
int highWaterLevel = 800; 

void handleStateTransitions() {
  
  int waterLevel = analogRead(waterLevelSensorPin);

  switch (currentState) {
    case FULL: 
      if (waterLevel < lowWaterLevel) {
        currentState = EMPTYING; 
        digitalWrite(pumpPin, LOW); 
        Serial.println("su tankı solu şimdi boşalacak.");
      }
      break;

    case EMPTYING: 
      if (waterLevel <= 0) {
        currentState = EMPTY; 
        digitalWrite(pumpPin, LOW); 
        Serial.println("su tankı boş.");
      }
      break;

    case EMPTY: 
      if (waterLevel >= highWaterLevel) {
        currentState = FILLING; 
        digitalWrite(pumpPin, HIGH); 
        Serial.println("boştu şimdi dolacak.");
      }
      break;

    case FILLING: 
      if (waterLevel >= highWaterLevel) {
        currentState = FULL; 
        digitalWrite(pumpPin, LOW); 
        Serial.println("su tankı dolu.");
      }
      break;
  }
}

void setup() {
  pinMode(pumpPin, OUTPUT);  
  digitalWrite(pumpPin, LOW); 

  Serial.begin(9600);  

  pinMode(waterLevelSensorPin, INPUT);  
}

void loop() {
  handleStateTransitions();  
  delay(1000);  
}

