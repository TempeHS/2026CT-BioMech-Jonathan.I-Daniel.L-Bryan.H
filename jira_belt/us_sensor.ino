#include "Ultrasonic.h"
#include "globals.h"

uint16_t g_us_distance = 0;

void us_setup() {}

void us_loop() {
  long g_us_distance = ultrasonic.MeasureInCentimeters();


  Serial.print("Distance: ");
  Serial.print(g_us_distance);
  Serial.println(" cm");

  if (g_us_distance > 0 && g_us_distance < alertDistance) {
    Serial.println("WARNING: Object detected!");
  } else {
  }

  delay(250);
}
