#include <Wire.h>
#include "Seeed_vl53l0x.h"

Seeed_vl53l0x VL53L0X;

const int buzzerPin = 3;
const int ledPin = 4;

void tof_setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  if (VL53L0X.begin() != 0) {
    Serial.println("Sensor init failed!");
    while (1);
  }

  Serial.println("Proximity Alert System");
  Serial.println("Critical: < 10cm | Warning: < 30cm | Safe: > 50cm");
}

void tof_loop() {
  VL53L0X_RangingMeasurementData_t measurement;
  VL53L0X.performSingleRangingMeasurement(&measurement);

  if (measurement.RangeStatus == 0) {
    int distance = measurement.RangeMilliMeter;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" mm | ");

    if (distance < criticalDistance) {
      // CRITICAL - very close
      Serial.println("CRITICAL - TOO CLOSE!");
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 2000);  // Continuous high tone
    } else if (distance < warningDistance) {
      // WARNING - approaching
      Serial.println("WARNING - Approaching");
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 1000, 100);  // Beep
      delay(100);
      noTone(buzzerPin);
    } else if (distance < safeDistance) {
      // CAUTION - in range
      Serial.println("CAUTION - Monitor");
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
    } else {
      // SAFE - clear
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