#include "imu_globals.h"

const int buzzerPin = 3;
const int ledPin = 4;

void tof_setup() {
  Serial.begin(9600);
  Wire.begin(); // Initializes I2C bus (uses dedicated I2C pins on Grove Base Shield)
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.println("Proximity Alert System");
  Serial.println("Critical: < 10cm | Warning: < 30cm | Safe: > 50cm");
}

void tof_loop() {
  VL53L0X_RangingMeasurementData_t measurement;
  VL53L0X.PerformSingleRangingMeasurement(&measurement);

  if (measurement.RangeStatus == 0) {
    int distance = measurement.RangeMilliMeter;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" mm | ");

    if (distance < criticalDistance) {
      Serial.println("CRITICAL - TOO CLOSE!");
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 2000);
    } else if (distance < warningDistance) {
      Serial.println("WARNING - Approaching");
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 1000, 100);
      delay(100);
      noTone(buzzerPin);
    } else if (distance < safeDistance) {
      Serial.println("CAUTION - Monitor");
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
    } else {
      Serial.println("SAFE - Clear");
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
    }
  } else {
    Serial.println("No target detected");
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(100);
}