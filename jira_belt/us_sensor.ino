#include "Ultrasonic.h"
#include "globals.h"

uint16_t g_us_distance = 0;

void us_setup() {
  Serial.println("Ultrasonic sensors init (D5 & D7)");
}

void us_loop() {
  long d1 = ultrasonic.MeasureInCentimeters();   // D5
  delay(80);                                     // avoid cross-talk
  long d2 = ultrasonic2.MeasureInCentimeters();  // D7

  uint16_t v1 = (d1 > 0 && d1 <= 400) ? (uint16_t)d1 : 0;
  uint16_t v2 = (d2 > 0 && d2 <= 400) ? (uint16_t)d2 : 0;

  if (v1 && v2)
    g_us_distance = min(v1, v2);
  else if (v1)
    g_us_distance = v1;
  else if (v2)
    g_us_distance = v2;
  else
    g_us_distance = 0;

  Serial.print("US1 (D5): ");
  Serial.print(v1);
  Serial.print(" cm  US2 (D7): ");
  Serial.print(v2);
  Serial.print(" cm  -> g_us_distance: ");
  Serial.print(g_us_distance);
  Serial.println(" cm");

  if (g_us_distance > 0 && g_us_distance < alertDistance) {
    Serial.println("WARNING: Object detected!");
  }

  delay(200);
}