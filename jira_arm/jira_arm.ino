void setup() {
  servo_setup();
  gsr_setup();
}

void loop() {
  galvanic_skin_response();
  servo_motor();
}