# Smart-PIR---Based-lighting-automation
This project implements an intelligent lighting system that automatically controls a light source based on human motion detection. Using a PIR (Passive Infrared) sensor and Arduino, the system turns ON the light when motion is detected and switches it OFF after a predefined delay when no motion is present.
# 💡 Smart Motion-Activated Lighting System using PIR Sensor and Arduino

## 📌 Overview
This project demonstrates an intelligent lighting system that automatically controls a light based on motion detection. Using a PIR (Passive Infrared) sensor and Arduino, the system turns ON the light when motion is detected and switches it OFF after a predefined delay when no motion is present.

This helps in reducing energy consumption and enables basic home automation.

---

## ⚙️ Features
- Motion detection using PIR sensor  
- Automatic light ON/OFF control  
- Adjustable delay for turning OFF  
- Energy-efficient solution  
- Simple and low-cost implementation  

---

## 🛠️ Components Required
- Arduino Uno (or compatible board)  
- PIR Sensor (HC-SR501)  
- Relay Module  
- Bulb / AC Load  
- Jumper Wires  
- Breadboard  

---

## 🔌 Circuit Connections

### PIR Sensor → Arduino
- VCC → 5V  
- GND → GND  
- OUT → Digital Pin 2  

### Relay Module → Arduino
- VCC → 5V  
- GND → GND  
- IN → Digital Pin 8  

### AC Load Connection (Bulb)
- Phase (Live) → COM (Relay)  
- NO (Relay) → Bulb  
- Neutral → Direct to Bulb  

---

## 💻 Code

```cpp
#define PIR_PIN 2
#define RELAY_PIN 8

unsigned long motionTimeout = 3000;
unsigned long lastMotionTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); // Relay OFF (Active LOW)

  delay(30000); // PIR stabilization time
}

void loop() {
  int pirState = digitalRead(PIR_PIN);

  if (pirState == HIGH) {
    digitalWrite(RELAY_PIN, LOW);  // Turn ON light
    lastMotionTime = millis();
  } 
  else {
    if (millis() - lastMotionTime > motionTimeout) {
      digitalWrite(RELAY_PIN, HIGH); // Turn OFF light
    }
  }

  delay(100);
}
