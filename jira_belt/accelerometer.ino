/*
  Purpose: Read 6-axis motion data (accelerometer + gyroscope)
  Notes:
    1. Connect to I2C port
    2. Accelerometer measures linear acceleration (g)
    3. Gyroscope measures angular velocity (degrees/second)
    4. Combined data enables orientation tracking
    5. Temperature sensor built-in
  Author: Ben Jones 14/7/23
  Source: https://github.com/Seeed-Studio/Seeed_Arduino_LSM6DS3
*/


void accelerometer_setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println("LSM6DS3 6-Axis IMU");

  // Initialize sensor
  if (imu.begin() != 0) {
    Serial.println("LSM6DS3 initialization failed!");
    while (1);
  }

  Serial.println("LSM6DS3 initialized successfully");
  Serial.println("Format: AccelX, AccelY, AccelZ (g) | GyroX, GyroY, GyroZ (dps) | Temp (°C)");
}

void accelerometer_loop() {
  // Read accelerometer (g)
  float accelX = imu.readFloatAccelX();
  float accelY = imu.readFloatAccelY();
  float accelZ = imu.readFloatAccelZ();

  // Read gyroscope (degrees/second)
  float gyroX = imu.readFloatGyroX();
  float gyroY = imu.readFloatGyroY();
  float gyroZ = imu.readFloatGyroZ();

  // Read temperature (°C)
  float temp = imu.readTempC();

  // Display all data
  Serial.print("Accel: X=");
  Serial.print(accelX, 2);
  Serial.print("g Y=");
  Serial.print(accelY, 2);
  Serial.print("g Z=");
  Serial.print(accelZ, 2);
  Serial.print("g | Gyro: X=");
  Serial.print(gyroX, 2);
  Serial.print("° Y=");
  Serial.print(gyroY, 2);
  Serial.print("° Z=");
  Serial.print(gyroZ, 2);
  Serial.print("° | Temp: ");
  Serial.print(temp, 1);
  Serial.println("°C");

  delay(500);
}