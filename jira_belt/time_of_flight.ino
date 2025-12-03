#include "globals.h"


#undef SERIAL
#define SERIAL Serial

uint16_t g_tof_distance = 0;

void tof_setup() {
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;
    SERIAL.begin(9600);
    Status = VL53L0X.VL53L0X_common_init();
    if (VL53L0X_ERROR_NONE != Status) {
        SERIAL.println("start vl53l0x mesurement failed!");
        VL53L0X.print_pal_error(Status);
        while (1);
    }

    VL53L0X.VL53L0X_high_accuracy_ranging_init();

    if (VL53L0X_ERROR_NONE != Status) {
        SERIAL.println("start vl53l0x mesurement failed!");
        VL53L0X.print_pal_error(Status);
        while (1);
    }
}

void tof_loop() {
    VL53L0X_RangingMeasurementData_t RangingMeasurementData;
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;

    memset(&RangingMeasurementData, 0, sizeof(VL53L0X_RangingMeasurementData_t));
    Status = VL53L0X.PerformSingleRangingMeasurement(&RangingMeasurementData);
    if (VL53L0X_ERROR_NONE == Status) {
        if (RangingMeasurementData.RangeMilliMeter >= 2000) {
            g_tof_distance = 0;
            SERIAL.println("out of range!!");
        } else {
            g_tof_distance = RangingMeasurementData.RangeMilliMeter;
            SERIAL.print("Measured distance:");
            SERIAL.print(RangingMeasurementData.RangeMilliMeter);
            SERIAL.println(" mm");
        }
    } else {
        SERIAL.print("mesurement failed !! Status code =");
        SERIAL.println(Status);
    }

    delay(300);
}



/* const int buzzerPin = 3;
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