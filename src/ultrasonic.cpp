#include "ultrasonic.h"

// Constructor
// Setup the trigger and echo pins
void Ultrasonic::init(int triggerPin, int echoPin) {
    _triggerPin = triggerPin;
    _echoPin = echoPin;
    pinMode(_triggerPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}

float Ultrasonic::measureDistance() {
    // Send a 10 microsecond pulse to trigger the measurement
    digitalWrite(_triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_triggerPin, LOW);

    // Measure the duration of the echo pulse
    long duration = pulseIn(_echoPin, HIGH);

    // Calculate distance in centimeters
    float distance = (duration / 2.0) * 0.0343; // Speed of sound is ~343 m/s

    return distance;
}