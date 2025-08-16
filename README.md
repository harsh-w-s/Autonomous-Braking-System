# 🚗 Autonomous Braking System

An **Autonomous Braking System** prototype built using an **ultrasonic sensor** and **Arduino**.  
The system detects obstacles in front of a toy car and applies brakes automatically if the driver fails to react in time, preventing collisions.

---

## 🎯 Objective
To design a low-cost prototype that simulates **Automatic Emergency Braking (AEB)**, a safety feature widely used in modern vehicles.

---

## 🛠️ Components Used
- Arduino Uno  
- Ultrasonic Sensor (HC-SR04)  
- DC Motor + Motor Driver (L298N)  
- Wheels & Chassis  
- Power Supply (Battery/USB)  
- Brake Mechanism (via motor control)

---

## ⚙️ Working Principle
1. The **ultrasonic sensor** measures the distance to an obstacle.  
2. If the distance is **greater than the safety threshold**, the car moves normally.  
3. If the distance is **less than the threshold**, the Arduino **cuts motor power / applies brake**.  
4. This mimics an **automatic emergency braking system** used in vehicles.

---

## 📜 Arduino Code (Sample)
```cpp
#define TRIG 9
#define ECHO 10
#define MOTOR 5

long duration;
int distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(MOTOR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 20) { 
    digitalWrite(MOTOR, LOW); // Stop motor (Brake applied)
  } else {
    digitalWrite(MOTOR, HIGH); // Keep moving
  }

  delay(100);
}
