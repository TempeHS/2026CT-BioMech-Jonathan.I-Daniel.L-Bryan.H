#include <Servo.h>

// Pin definitions
const int GSR_PIN = A0;   // Analog pin for GSR sensor
const int SERVO_PIN = 5;  // Digital pin for servo motor (D5)

// Threshold for stress detection (tune experimentally)
int stressThreshold = 520;

// Servo object
Servo myServo;

// -------------------- Setup Functions --------------------
void servo_setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(90); // Neutral position
}

void gsr_setup() {
  pinMode(GSR_PIN, INPUT);
  Serial.begin(9600);
}

// -------------------- Loop Functions --------------------
bool galvanic_skin_response() {
  int gsrValue = analogRead(GSR_PIN);
  Serial.print("GSR Value: ");
  Serial.println(gsrValue);

  // Return true if stress detected
  return (gsrValue > stressThreshold);
}

void servo_motor(bool stressed) {
  if (stressed) {
    myServo.write(0);   // Move servo to "alert" position
    Serial.println("Stress detected → Servo activated!");
  } else {
    myServo.write(90);  // Neutral position
    Serial.println("Relaxed state → Servo neutral.");
  }
}

// -------------------- Arduino Core --------------------
void setup() {
  servo_setup();
  gsr_setup();
}

void loop() {
  bool stressed = galvanic_skin_response();
  servo_motor(stressed);
  delay(200);
}
