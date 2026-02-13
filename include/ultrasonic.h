#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include <Arduino.h>
#include "config.h"

class Ultrasonic {
private:
    int _triggerPin;
    int _echoPin;

public:
    Ultrasonic() = default;
    void init(int triggerPin, int echoPin);
    float measureDistance();
};

#endif // ULTRASONIC_H
