#include <Arduino.h>
#include "config.h"
#include "ultrasonic.h"


Ultrasonic ultrasonic;

void setup() {
  // put your setup code here, to run once:
  ultrasonic.init(TRIGGER_PIN, ECHO_PIN);
  // Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
  Serial.begin(115200);
} 

void loop() {
  // put your main code here, to run repeatedly:

  float distance = ultrasonic.measureDistance();
  Serial.println(distance);
}
