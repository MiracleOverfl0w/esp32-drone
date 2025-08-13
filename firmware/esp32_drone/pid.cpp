#include "pid.h"

// Constructor implementation
DronePID::DronePID() {
    // Initialize members if needed
}

// Destructor implementation
DronePID::~DronePID() {
    // Cleanup if needed
}
DronePID::DronePID
(   float kp, 
    float ki, 
    float kd
) : KP(kp), 
    KI(ki), 
    KD(kd)
{};

