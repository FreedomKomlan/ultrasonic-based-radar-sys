#include <Arduino.h>
#include "config.h"
#include "ultrasonic.h"


Ultrasonic ultrasonic;

void setup() {
  // put your setup code here, to run once:
  ultrasonic.init(TRIGGER_PIN, ECHO_PIN);
  pinMode(LED_PIN, OUTPUT);
  // Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
  Serial.begin(115200);
  digitalWrite(LED_PIN, HIGH);
} 

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(LED_PIN, HIGH);
  // delay(100);
  float distance = ultrasonic.measureDistance();
  Serial.println(distance);
}
