#include "Ultrasonic.h"

// Pin definitions
const int TRIG_PIN = 7;      // Ultrasonic TRIG (Grove D7)
const int ECHO_PIN = 7;      // Ultrasonic ECHO (same pin for Grove sensor)
const int VIBRATION_PIN = 6; // Vibration motor (Grove D6, PWM capable)
const int BUZZER_PIN = 5;    // Buzzer (Grove D5, PWM capable)

// Distance threshold in cm
const int ALERT_DISTANCE = 20;

// Create ultrasonic sensor object
Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

void us_sensor_setup() {
  Serial.begin(9600);
  
  pinMode(VIBRATION_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  digitalWrite(VIBRATION_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  
  Serial.println("Ultrasonic sensor initialized with vibration & alert");
}

void us_sensor_loop() {
  // Measure distance in centimeters
  long distance = ultrasonic.MeasureInCentimeters();
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if object is too close
  if (distance < ALERT_DISTANCE && distance > 0) {
    // Object detected too close - activate alerts
    activateAlerts(distance);
  } else {
    // Object is far or no detection - stop alerts
    deactivateAlerts();
  }
  
  delay(100);
}

void activateAlerts(long distance) {
  // Vibration intensity increases as object gets closer
  int vibrationStrength = map(distance, ALERT_DISTANCE, 0, 50, 255);
  analogWrite(VIBRATION_PIN, vibrationStrength);
  
  // Buzzer tone increases as object gets closer
  int frequency = map(distance, ALERT_DISTANCE, 0, 500, 2000);
  tone(BUZZER_PIN, frequency);
  
  Serial.println("⚠️ ALERT: Object too close!");
}

void deactivateAlerts() {
  analogWrite(VIBRATION_PIN, 0);  // Stop vibration
  noTone(BUZZER_PIN);             // Stop buzzer
}