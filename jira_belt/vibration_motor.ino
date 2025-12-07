void vibration_motor_setup() {
  Serial.begin(9600);
  pinMode(vibrationPin, OUTPUT);

  Serial.println("Vibration Motor Test");

  // Test pattern: 3 short pulses
  for (int i = 0; i < 3; i++) {
    digitalWrite(vibrationPin, HIGH);
    delay(100);
    digitalWrite(vibrationPin, LOW);
    delay(200);
  }

  Serial.println("Test complete");
}

void vibration_motor_loop() {
  // Single vibration pulse every 5 seconds
  Serial.println("Vibrating...");
  digitalWrite(vibrationPin, HIGH);
}