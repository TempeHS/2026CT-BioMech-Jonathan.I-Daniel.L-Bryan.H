#ifndef GLOBALS_H
#define GLOBALS_H

#include "LSM6DS3.h"
#include "Seeed_vl53l0x.h"
#include "Ultrasonic.h"

extern Ultrasonic ultrasonic;

extern LSM6DS3 imu;
extern Seeed_vl53l0x VL53L0X;

extern uint16_t g_tof_distance;

#endif