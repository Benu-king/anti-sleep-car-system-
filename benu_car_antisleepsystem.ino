//BENYAS

int relayPin = 8;
int buzzerPin = 9;
int ledPin = 10;
int RED = 3;
int GREEN = 5;
int BLUE = 6;

char state = ' '; 
char newState = ' '; 

unsigned long previousMillis = 0;
int redBlinkState = LOW;
int redBlinkDelay = 100; 

int greenLevel = 255;
int fadeAmount = 5;
int fadeDelay = 8;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  Serial.begin(9600);
  allOff();
}

void allOff() {
  analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);
}

void blueFlash() {
  analogWrite(BLUE, 0);
  delay(1000);
  analogWrite(BLUE, 255);
}

void loop() {
  unsigned long currentMillis = millis();
  if (Serial.available()) {
    newState = Serial.read();
    if (newState == 'S' || newState == 'G') {
      state = newState;
      allOff();        
      if (state == 'S') {
        digitalWrite(relayPin, LOW);
        analogWrite(RED, 0);
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(ledPin, HIGH);
        delay(1000);
        digitalWrite(buzzerPin, LOW);
      } 
      else if (state == 'G') {
        digitalWrite(relayPin, HIGH);
        digitalWrite(ledPin, LOW);
        blueFlash();
        greenLevel = 255;
      }
    }
  }
  if (state == 'S') {
    analogWrite(GREEN, 255);
    if (currentMillis - previousMillis >= redBlinkDelay) {
      previousMillis = currentMillis;
      redBlinkState = !redBlinkState;
      analogWrite(RED, redBlinkState ? 0 : 255);
    }
  } 
  else if (state == 'G') {
    analogWrite(RED, 255);
    if (currentMillis - previousMillis >= fadeDelay) {
      previousMillis = currentMillis;
      analogWrite(GREEN, greenLevel);
      greenLevel -= fadeAmount;
      if (greenLevel <= 0 || greenLevel >= 255) {
        fadeAmount = -fadeAmount; 
      }
    }
  }
}
