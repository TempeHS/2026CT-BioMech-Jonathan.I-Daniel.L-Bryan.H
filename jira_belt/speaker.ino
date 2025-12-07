void speaker_setup() {
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
  Serial.println("Alarm Siren");
}

void speaker_loop() {
  Serial.println("ALARM ACTIVE");

  // Rising siren (5 cycles)
  for (int cycle = 0; cycle < 5; cycle++) {
    // Sweep from 400Hz to 1000Hz
    for (int freq = 400; freq <= 1000; freq += 10) {
      tone(speakerPin, freq);
      delay(10);
    }
    // Sweep back down
    for (int freq = 1000; freq >= 400; freq -= 10) {
      tone(speakerPin, freq);
      delay(10);
    }
  }

  noTone(speakerPin);
  Serial.println("Alarm stopped\n");
  delay(10);
}
