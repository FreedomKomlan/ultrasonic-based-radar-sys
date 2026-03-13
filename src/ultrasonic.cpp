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
    // delayMicroseconds(2);
    vTaskDelay(2 / portTICK_PERIOD_MS); // Delay to ensure the trigger pin is low for a short period
    digitalWrite(_triggerPin, HIGH);
    // delayMicroseconds(10);
    vTaskDelay(10 / portTICK_PERIOD_MS); // Delay to ensure the trigger pin is high for the required duration
    digitalWrite(_triggerPin, LOW);

    // Measure the duration of the echo pulse
    long duration = pulseIn(_echoPin, HIGH);

    // Calculate distance in centimeters
    float distance = (duration / 2.0) * 0.0343; // Speed of sound is ~343 m/s

    return distance;
}

void ServoMotor::init(int pin, int min_ANGLE_DEG, int max_ANGLE_DEG) {
    ESP32PWM::allocateTimer(0); // Allocate a timer for the servo
    ESP32PWM::allocateTimer(1); // Allocate another timer if needed for multiple servos
    ESP32PWM::allocateTimer(2); // Allocate another timer if needed for multiple servos
    ESP32PWM::allocateTimer(3); // Allocate another timer if needed for multiple servos
    _servo.setPeriodHertz(50); // Set to 50 Hz for standard servos
    _servo.attach(pin);
    _servo.write(min_ANGLE_DEG); // Initialize to minimum angle
    vTaskDelay(500 / portTICK_PERIOD_MS); // Delay to allow servo to move to initial position
    _servo.write(max_ANGLE_DEG); // Move to maximum angle
    vTaskDelay(500 / portTICK_PERIOD_MS); // Delay to allow servo to move to initial position
    //...............
}

void ServoMotor::setAngle(int angle) {
    const int initialAngle = _servo.read(); // Get the current angle of the servo
    const int angleDifference = abs(angle - initialAngle); // Calculate the difference in angle
    const float t_move_s = (angleDifference / 60.0f) * SERVO_T60_S * SAFETY_MARGIN_S_FACTOR; // Calculate the time needed to move to the new angle with a safety margin
    const uint32_t t_move_ms = (uint32_t)(t_move_s * 1000.0f); // Convert time to milliseconds
    _servo.write(angle);
    vTaskDelay(t_move_ms / portTICK_PERIOD_MS); // Delay to allow servo to reach the position
}

int ServoMotor::getAngle() {
    return _servo.read();
}
