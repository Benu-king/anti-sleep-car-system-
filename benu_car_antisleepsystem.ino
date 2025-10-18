int relayPin = 8;
int buzzerPin = 9;
int ledPin = 10;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char state = Serial.read();
    if (state == 'S') { // Stop car
      digitalWrite(relayPin, LOW);
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
    } else if (state == 'G') { // Go car
      digitalWrite(relayPin, HIGH);
      digitalWrite(ledPin, LOW);
    }
  }
}
