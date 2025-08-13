#ifndef CONFIG_H
#define CONFIG_H


#include <stdint.h>
#include <float.h>
#include <Adafruit_MPU6050.h>
#include "pid.h"
#ifndef G_FORCE 
#define G_FORCE 9.81
#endif 

#define acc(axis) acceleration.axis
#define gyro(axis) gyro.axis


typedef long long ll; 
typedef unsigned long long ull; 
typedef double db;
typedef long double ld;

typedef struct {
    float acc_x;
    float acc_y;
    float acc_z;
    float gyro_x;
    float gyro_y;
    float gyro_z;
}MPU6050_offset;

void MPUCalibration
(
    Adafruit_MPU6050 &__MPU__,
    MPU6050_offset &__OFFSET__
);


#endif