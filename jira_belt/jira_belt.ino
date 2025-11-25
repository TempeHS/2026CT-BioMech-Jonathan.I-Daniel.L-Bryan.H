#include <Wire.h>
#include "Seeed_vl53l0x.h"
#include <LSM6DS3.h>
#include "imu_globals.h"
IMU_LSM6DS3 imu(I2C_MODE, 0x6A);

Seeed_vl53l0x VL53L0X;


// Alert thresholds (mm)
const int criticalDistance = 100;   // < 10cm
const int warningDistance = 300;    // < 30cm
const int safeDistance = 500;       // > 50cm

const int USPin = 2;
const int AGPin = 4;
const int speakerPin = 5;
const int motorPin = 6;  
const int VibrationPin = 7;  


void setup() {
speaker_setup();
}

void loop() {
speaker_loop();
}
 