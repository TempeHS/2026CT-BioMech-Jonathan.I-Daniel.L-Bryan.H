Notes: 
set up as normal 

doesnt work (greyd out?)
Compilation error: 'class Ultrasonic' has no member named 'MeasureInCentimeters'
Please fix biriyani huang


oid setup() {  
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);  
}  
/*
 * HC-SR04 example sketch
 *
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 *
 * by Isaac100
 */

#include "Ultrasonic.h"

Ultrasonic ultrasonic(5);
const int alertDistance = 20;  // Alert if object within 20cm
const int ledPin = 13;  // Built-in LED

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
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
/*
  Purpose: Basic example of the Seeed Ultrasonic Ranger module
  Notes: Connect to a digital PIN
  Author: Ben Jones
  Contact: benjmain.jones21@det.nsw.edu.au
  Source: https://wiki.seeedstudio.com/Grove-Ultrasonic_Ranger/
  Library Source: https://github.com/Seeed-Studio/Seeed_Arduino_UltrasonicRanger
*/

// This is a different Ultrasonic Library to the one used with generic 4-pin sensors
// because we are using a Seeed Grove sensor with integrated signal processing
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
<<<<<<< HEAD

  1
    2
      3
        4
          5
            6
              7
                8
                  9
                    10
                      11
                        12
                          13
                            14
                              15
                                16
                                  17
                                    18
                                      19
                                        20
                                          21
                                            22
                                              23
                                                24
                                                  25
                                                    26
                                                      27
                                                        28
                                                          29
                                                            30
                                                              31
                                                                32
                                                                 33
                                                                 34
                                                                35
                                                              36
                                                            37
                                                          38
                                                        39
                                                      40
                                                    41
                                                  42
                                                43
                                              44
                                            45
                                          46
                                        47
                                      48
                                    49
                                  50
                                51
                              52  
                            53
                          54
                        55
                      56
                    57
                  58
                59
              60  
            61
          62
        63
      64
     65
    66
  67
  
=======
>>>>>>> a1d10281d1803255e6a389e9b181aa7959328829
