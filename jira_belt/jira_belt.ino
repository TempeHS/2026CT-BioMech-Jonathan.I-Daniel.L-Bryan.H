#include <Wire.h>
#include "LSM6DS3.h"
#include "Seeed_vl53l0x.h"
#include "globals.h"
#include "Ultrasonic.h"

LSM6DS3 imu(I2C_MODE, 0x6A);
Seeed_vl53l0x VL53L0X;

// Alert thresholds (mm)
const int criticalDistance = 100;   // < 10cm // TOF
const int warningDistance = 300;    // < 30cm // TOF
const int safeDistance = 500;       // > 50cm // TIF
const int alertDistance = 20;  // Alert if object within 20cm // US

const int USPin = 2;
const int AGPin = 4;
const int speakerPin = 5;
const int motorPin = 6;  
const int VibrationPin = 7;  

Ultrasonic ultrasonic(5);


void setup() {
  Serial.begin(9600);
  //vibration_motor_setup();
  //speaker_setup();
  us_setup();
  // tof_setup(); works

}

void loop() {
  // tof_loop(); works
  us_loop();
  //vibration_motor_loop();
  //speaker_loop();
  if (g_tof_distance <= 1000 & g_tof_distance > 2) {
    Serial.println("WARNING");
}

}
 