#include "config.h"
void MPUCalibration(
    Adafruit_MPU6050 &__MPU__,
    MPU6050_offset &__OFFSET__
)
{
    if (!__MPU__.begin()) {
        Serial.println("[X] Failed to begin MPU6050.");
        delay(2000);
        ESP.restart();
    }
    
    sensors_event_t _acc_, _gyro_, _temp_;
    
    float gyroSumX = 0, gyroSumY = 0, gyroSumZ = 0;    
    float accSumX = 0 , accSumY = 0, accSumZ = 0;

    unsigned long start_time = millis();
    int count = 0;
    
    while (millis() - start_time <= 5000){
        __MPU__.getEvent(&_acc_, &_gyro_, &_temp_);
        
        gyroSumX += _gyro_.gyro(x);
        gyroSumY += _gyro_.gyro(y);
        gyroSumZ += _gyro_.gyro(z);
        
        
        accSumX += _acc_.acc(x);
        accSumY += _acc_.acc(y);
        accSumZ += _acc_.acc(z);
        ++count;
        delay(10);
    }
    
    __OFFSET__.acc_x = 0.0 - accSumX/count;
    __OFFSET__.acc_y = 0.0 - accSumY/count;
    __OFFSET__.acc_z = G_FORCE - accSumZ/count;
   
    
    __OFFSET__.gyro_x = gyroSumX/count;
    __OFFSET__.gyro_y = gyroSumY/count;
    __OFFSET__.gyro_z = gyroSumZ/count;

}