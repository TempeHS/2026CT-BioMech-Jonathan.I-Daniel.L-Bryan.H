

#include <Wire.h>
#include "Seeed_vl53l0x.h"

Seeed_vl53l0x VL53L0X;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println("VL53L0X Time-of-Flight Distance Sensor");

  // Initialize sensor
  if (VL53L0X.begin() != 0) {
    Serial.println("VL53L0X initialization failed!");
    Serial.println("Check I2C connection");
    while (1);
  }

  Serial.println("VL53L0X initialized successfully");
  Serial.println("Range: 30-2000mm | Resolution: 1mm");
}

void loop() {
  VL53L0X_RangingMeasurementData_t RangingMeasurementData;

  // Perform distance measurement
  VL53L0X.performSingleRangingMeasurement(&RangingMeasurementData);

  // Check measurement status
  if (RangingMeasurementData.RangeStatus == 0) {
    // Valid measurement
    int distance_mm = RangingMeasurementData.RangeMilliMeter;
    float distance_cm = distance_mm / 10.0;

    Serial.print("Distance: ");
    Serial.print(distance_mm);
    Serial.print(" mm (");
    Serial.print(distance_cm);
    Serial.println(" cm)");
  } else {
    // Out of range or error
    Serial.println("Out of range or no target detected");
  }

  delay(100);  // 100ms between readings
}