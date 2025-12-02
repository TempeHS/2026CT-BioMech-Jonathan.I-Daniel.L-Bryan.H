/* #include "Ultrasonic.h"

Ultrasonic ultrasonic(5);

void us_setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void us_loop() {
  long distance = ultrasonic.MeasureInCentimeters();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < alertDistance) {
    digitalWrite(ledPin, HIGH);  // Turn on LED if object is close
    Serial.println("WARNING: Object detected!");
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(250);
}

*/