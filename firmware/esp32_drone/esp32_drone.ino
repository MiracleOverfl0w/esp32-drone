
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#include "config.h"
#include "controller.h"
#include "gui.h"
#include "pid.h"


Adafruit_MPU6050 mpu;
MPU6050_offset offset;

DronePID PID;
void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_260_HZ);
  //MPUCalibration(mpu , offset);

  delay(100);
}

void loop() {
  
  
}
