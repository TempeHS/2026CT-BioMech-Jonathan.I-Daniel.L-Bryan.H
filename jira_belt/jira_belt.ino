#include <Wire.h>
#include "Seeed_vl53l0x.h"

Seeed_vl53l0x VL53L0X;

const int VibrationPin = 1;  

const int USPin = 2;

const int TOFPin = 3;

const int AGPin = 4;

const int speakerPin = 5;

const int motorPin = 6;  


#include <Wire.h>
#include "LSM6DS3.h"

IMU_LSM6DS3 imu(I2C_MODE, 0x6A);  // I2C address 0x6A

void setup() {
speaker_setup();
}

void loop() {
speaker_loop();
}