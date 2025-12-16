#include <Wire.h>
#include "LSM6DS3.h"
#include "Seeed_vl53l0x.h"
#include "globals.h"
#include "Ultrasonic.h"

LSM6DS3 imu(I2C_MODE, 0x6A);
Seeed_vl53l0x VL53L0X;

// Alert thresholds (mm)
const int criticalDistance = 100;  // < 10cm // TOF
const int warningDistance = 300;   // < 30cm // TOF
const int safeDistance = 500;      // > 50cm // TIF
const int alertDistance = 20;      // Alert if object gets closer than 20cm // Ultrasonic

const int AGPin = 4;
const int speakerPin = 8;
const int vibrationPin = 6;

// ToF is i2c by default. No pin definitions needed.

Ultrasonic ultrasonic(5);
Ultrasonic ultrasonic2(7);

// forward declarations (implemented in speaker.ino)
extern void speaker_set_active(bool active);
extern void speaker_loop();
extern void speaker_setup();

void setup() {
  Serial.begin(9600);
  // vibration_motor_setup();

  speaker_setup();  // initialize speaker hardware (safe even if unused)
  us_setup();
  tof_setup();
}

void loop() {
  // vibration_motor_loop();
  tof_loop();
  us_loop();

  bool desiredSpeaker = false;

  if (g_tof_distance <= warningDistance && g_tof_distance > 10) {
    Serial.println("TOF: WARNING");
    desiredSpeaker = true;
  } else if (g_tof_distance == 0) {
    Serial.println("TOF: No object or sensor error");
  } else {
    Serial.println("TOF: SAFE");
  }

  if (g_us_distance <= alertDistance && g_us_distance > 3) {
    Serial.println("US: ALERT (very close)");
    desiredSpeaker = true;
  } else if (g_us_distance <= 100 && g_us_distance > 3) {
    Serial.println("US: WARNING");
    desiredSpeaker = true;
  } else if (g_us_distance == 0) {
    Serial.println("US: No object or sensor error");
  } else {
    Serial.println("US: SAFE");
  }

  static bool prevDesired = false;
  if (desiredSpeaker != prevDesired) {
    speaker_set_active(desiredSpeaker);
    prevDesired = desiredSpeaker;
  }

  speaker_loop();  // non-blocking speaker handler */
}
