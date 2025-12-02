Notes: 
Find way to use +
(set up on i2c)

also has a temp sensor 
/*
  Purpose: Read 6-axis motion data (accelerometer + gyroscope)
  Notes:
    1. Connect to I2C port
     2. Accelerometer measures linear acceleration (g)
       3. Gyroscope measures angular velocity (degrees/second)
     4. Combined data enables orientation tracking
    5. Temperature sensor built-in
  Author: Ben Jones 14/7/23
  Source: https://github.com/Seeed-Studio/Seeed_Arduino_LSM6DS3
*/
























































#include <Wire.h>
#include "LSM6DS3.h"
#include "Seeed_vl53l0x.h"
#include "imu_globals.h"

LSM6DS3 imu(I2C_MODE, 0x6A);
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
 