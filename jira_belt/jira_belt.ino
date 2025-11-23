#include <Wire.h>
#include "Seeed_vl53l0x.h"

Seeed_vl53l0x VL53L0X;

const int buzzerPin = 3;
const int ledPin = 4;

const int speakerPin = 3;

const int motorPin = 3;  // Connect to D3


#include <Wire.h>
#include "LSM6DS3.h"

LSM6DS3 imu(I2C_MODE, 0x6A);  // I2C address 0x6A

void setup() {

}

void loop() {

}