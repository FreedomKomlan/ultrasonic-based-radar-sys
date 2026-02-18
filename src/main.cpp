#include <Arduino.h>
#include "config.h"
#include "ultrasonic.h"
#include "display.h"
#include "task.h"


Ultrasonic ultrasonic;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ultrasonic.init(TRIGGER_PIN, ECHO_PIN);
  initDisplay();
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  // Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
  digitalWrite(LED_1_PIN, HIGH);
  digitalWrite(LED_2_PIN, HIGH);
  xTaskCreatePinnedToCore(ultrasonicTask, "Ultrasonic Task", STACK_MEASURE, &ultrasonic, PRIO_MEASURE, NULL, CORE_REALTIME);
  xTaskCreatePinnedToCore(blink_Led_1_task, "Blink LED 1 Task", STACK_DISPLAY, NULL, PRIO_DISPLAY, NULL, CORE_SUPPORT);
  xTaskCreatePinnedToCore(blink_Led_2_task, "Blink LED 2 Task", STACK_DISPLAY, NULL, PRIO_DISPLAY, NULL, CORE_SUPPORT);
  xTaskCreatePinnedToCore(sendText_task, "Send Text Task", STACK_DISPLAY, NULL, PRIO_DISPLAY, NULL, CORE_SUPPORT);
} 

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(LED_PIN, HIGH);
  // delay(100);
  // float distance = ultrasonic.measureDistance();
  // Serial.println(distance);
}
