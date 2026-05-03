#define PIR_PIN 2
#define RELAY_PIN 8

unsigned long motionTimeout = 3000;
unsigned long lastMotionTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // OFF

  Serial.println("Calibrating PIR...");
  delay(30000);
  Serial.println("Ready");
}

void loop() {
  int pirState = digitalRead(PIR_PIN);
  Serial.println(pirState);  // DEBUG

  if (pirState == HIGH) {
    lastMotionTime = millis();
    digitalWrite(RELAY_PIN, LOW); // ON
  } 
  else {
    if (millis() - lastMotionTime > motionTimeout) {
      digitalWrite(RELAY_PIN, HIGH); // OFF
    }
  }

  delay(200);
}