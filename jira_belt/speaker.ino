// Non-blocking speaker implementation

static bool speakerActive = false;  // true when warning beep should run
static bool speakerBeepOn = false;  // whether a beep is currently playing
static unsigned long lastBeepMillis = 0;
static unsigned long beepStartMillis = 0;

const unsigned long BEEP_INTERVAL_MS = 600;  // gap between beeps
const unsigned long BEEP_DURATION_MS = 150;  // length of each beep
const int SPEAKER_PIN_LOCAL = 8;             // local pin definition (matches main)

// initialize speaker pin
void speaker_setup() {
  pinMode(SPEAKER_PIN_LOCAL, OUTPUT);
  digitalWrite(SPEAKER_PIN_LOCAL, LOW);
}

// enable or disable background beeping
void speaker_set_active(bool active) {
  speakerActive = active;
  if (!active) {
    // stop any ongoing tone immediately
    noTone(SPEAKER_PIN_LOCAL);
    speakerBeepOn = false;
  } else {
    // kickstart immediate beep if desired
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
      // start beep
      tone(SPEAKER_PIN_LOCAL, 1000);  // start tone (non-blocking)
      speakerBeepOn = true;
      beepStartMillis = now;
      lastBeepMillis = now;
    }
  } else {
    // check if beep duration elapsed
    if (now - beepStartMillis >= BEEP_DURATION_MS) {
      noTone(SPEAKER_PIN_LOCAL);  // stop tone
      speakerBeepOn = false;
      // lastBeepMillis left at beep start time to schedule next gap
    }
  }
}
