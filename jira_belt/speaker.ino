#include <Wire.h>
#include "LSM6DS3.h"
#include "Seeed_vl53l0x.h"
#include "globals.h"
#include "Ultrasonic.h"

// Non-blocking speaker implementation

static bool speakerActive = false;  // true when warning beep should run
static bool speakerBeepOn = false;  // whether a beep is currently playing
static unsigned long lastBeepMillis = 0;
static unsigned long beepStartMillis = 0;

const unsigned long BEEP_INTERVAL_MS = 600;  // gap between beeps
const unsigned long BEEP_DURATION_MS = 150;  // length of each beep

// initialize speaker pin
void speaker_setup() {
  pinMode(speakerPin, OUTPUT);
  digitalWrite(speakerPin, LOW);
}

void speaker_set_active(bool active) {
  if (active == speakerActive)
    return;  // only change on transition
  speakerActive = active;
  if (!active) {
    // stop any ongoing beep immediately
    digitalWrite(speakerPin, LOW);
    speakerBeepOn = false;
  } else {
    // kickstart immediate beep on transition
    lastBeepMillis = millis() - BEEP_INTERVAL_MS;  // cause immediate beep on next loop
  }
}

// non-blocking handler; call frequently from loop()
void speaker_loop() {
  unsigned long now = millis();
  if (!speakerActive)
    return;

  if (!speakerBeepOn) {
    if (now - lastBeepMillis >= BEEP_INTERVAL_MS) {
      // start beep (simple on/off - avoids timers)
      digitalWrite(speakerPin, HIGH);
      speakerBeepOn = true;
      beepStartMillis = now;
      lastBeepMillis = now;
    }
  } else {
    // check if beep duration elapsed
    if (now - beepStartMillis >= BEEP_DURATION_MS) {
      digitalWrite(speakerPin, LOW);
      speakerBeepOn = false;
      // lastBeepMillis left at beep start time to schedule next gap
    }
  }
}
