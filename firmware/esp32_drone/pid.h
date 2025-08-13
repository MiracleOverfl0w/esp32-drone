#ifndef PID_H
#define PID_H

#include <math.h>
#include <complex>

class DronePID
{
private:
    float KP;
    float KI;
    float KD;
    float error;
    float prev_error;
    
public:
    DronePID();
    DronePID(float kp, float ki, float kd);
    ~DronePID();
    float getPIDValue();
};



#endif