/*
  Purpose: Control vibration motor for haptic feedback
  Notes:
    1. Connect to digital port (D2-D8)
    2. HIGH = motor ON, LOW = motor OFF
    3. Can use PWM (analogWrite) for variable intensity
    4. Motor draws 50-150mA when active
    5. Add delays for distinct vibration patterns
  Author: Ben Jones 18/11/25
  Source: https://wiki.seeedstudio.com/Grove-Vibration_Motor/
*/

void vibration_motor_setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);

  Serial.println("Vibration Motor Test");

  // Test pattern: 3 short pulses
  for (int i = 0; i < 3; i++) {
    digitalWrite(motorPin, HIGH);
    delay(100);
    digitalWrite(motorPin, LOW);
    delay(200);
  }

  Serial.println("Test complete");
}

void vibration_motor_loop() {
  // Single vibration pulse every 5 seconds
  Serial.println("Vibrating...");
  digitalWrite(motorPin, HIGH);
  delay(500);  // Vibrate for 500ms
  digitalWrite(motorPin, LOW);

  Serial.println("Off");
  delay(5000);  // Wait 5 seconds
}