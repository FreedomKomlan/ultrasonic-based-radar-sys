#include "ultrasonic.h"

void Ultrasonic::init(int triggerPin, int echoPin) {
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}