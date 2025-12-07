#include "Ultrasonic.h"
#include "globals.h"


void us_setup() {
}

void us_loop() {
  long distance = ultrasonic.MeasureInCentimeters();



  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < alertDistance) {
    Serial.println("WARNING: Object detected!");
  } else {
  }

  delay(250);
}


