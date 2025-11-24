# 💧 Dry/Wet Waste Moisture Sensor (Tinkercad + Arduino)

An **IoT-inspired embedded system** that measures the **moisture content of waste** to classify it as **Dry**, **Medium**, or **Wet** using LEDs.  
Developed and simulated in **Tinkercad** using an **Arduino Uno** and a **Moisture Sensor**.

---

## 🚀 Objective
To design and implement an Arduino-based system that detects the moisture level in waste material and provides a real-time indication through LEDs, helping in **waste segregation** and **recycling efficiency**.

---

## 🧰 Hardware Requirements
- Arduino UNO  
- Moisture Sensor (Analog)  
- LEDs:  
  - Red – Dry Waste  
  - Yellow – Medium Moisture  
  - Green – Wet Waste  
- Breadboard & Jumper Wires  
- 220Ω Resistors  

---

## 💻 Software Requirements
- **Arduino IDE**
- **Tinkercad Circuits** (for simulation)
- **Serial Monitor** (for testing readings)

---

## ⚙️ Circuit Connections
docs/Screenshot 2025-11-24 184325.png
docs/Screenshot 2025-11-24 184355.png
docs/Screenshot 2025-11-24 184418.png









---

## 🧠 Working Principle
1. The **Moisture Sensor** reads the analog value from the material sample.  
2. The value is mapped to a **percentage (0–100%)**.  
3. Based on the range:
   - **≤ 25% → Dry (Red LED ON)**
   - **26–79% → Medium (Blue LED ON)**
   - **≥ 80% → Wet (Green LED ON)**
4. The result is printed in the **Serial Monitor** for verification.  

---

## 🔋 Arduino Code (C)
```c
int moistureValue;
float moisture_percentage;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  moistureValue = analogRead(A0);
  moisture_percentage = ((moistureValue / 539.00) * 100);

  if (moisture_percentage > 0 && moisture_percentage < 25) {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  } 
  else if (moisture_percentage >= 25 && moisture_percentage < 80) {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  } 
  else {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }

  Serial.print("Moisture: ");
  Serial.print(moisture_percentage);
  Serial.println("%");
  delay(1000);
}
