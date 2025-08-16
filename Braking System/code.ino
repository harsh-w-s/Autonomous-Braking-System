/*
 * 🚗 Autonomous Braking System
 * Author: Harshwardhan Solanki
 * 
 * Description:
 * Uses an ultrasonic sensor (HC-SR04) to detect obstacles in front of a toy car.
 * If an obstacle is too close (less than a threshold distance), 
 * the Arduino automatically stops the motor (applies brake).
 */

// Ultrasonic sensor pins
#define TRIG_PIN 9
#define ECHO_PIN 10

// Motor control pin (to L298N motor driver or relay)
#define MOTOR_PIN 5

// Safety distance threshold in cm
#define SAFE_DISTANCE 20  

long duration;
int distance;

void setup() {
  // Pin setup
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  // Start serial monitor for debugging
  Serial.begin(9600);

  // Initially allow motor to run
  digitalWrite(MOTOR_PIN, HIGH);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo pulse
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Print distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Autonomous braking logic
  if (distance > 0 && distance < SAFE_DISTANCE) {
    // Obstacle detected - apply brakes
    digitalWrite(MOTOR_PIN, LOW);
    Serial.println("⚠️ Obstacle ahead! Brakes applied.");
  } else {
    // Safe distance - keep moving
    digitalWrite(MOTOR_PIN, HIGH);
    Serial.println("✅ Clear path. Moving forward.");
  }

  delay(200); // Small delay for stability
}
