#include <Arduino.h>
#include "config.h"
#include "ultrasonic.h"
#include "display.h"
#include "task.h"


Ultrasonic ultrasonic;
ServoMotor servoMotor;

void setup() {
  // ************************************* Start up and hardware initialization ******************************************
  // put your setup code here, to run once:
  Serial.begin(115200);
  ultrasonic.init(TRIGGER_PIN, ECHO_PIN);
  initDisplay();
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  // Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
  digitalWrite(LED_1_PIN, HIGH);
  digitalWrite(LED_2_PIN, HIGH);
  servoMotor.init(SERVO_PIN, ZONE_ANGLE_THRESHOLD_MIN_PRESET_DEG, ZONE_ANGLE_THRESHOLD_MAX_PRESET_DEG);

  // ******************************************** Start tasks execution ***************************************************
  xTaskCreatePinnedToCore(ultrasonicTask, "Ultrasonic Task", STACK_MEASURE, &ultrasonic, PRIO_MEASURE, NULL, CORE_REALTIME);
  xTaskCreatePinnedToCore(blink_Led_1_task, "Blink LED 1 Task", STACK_DISPLAY, NULL, PRIO_DISPLAY, NULL, CORE_SUPPORT);
  xTaskCreatePinnedToCore(blink_Led_2_task, "Blink LED 2 Task", STACK_DISPLAY, NULL, PRIO_DISPLAY, NULL, CORE_SUPPORT);
  // xTaskCreatePinnedToCore(sendText_task, "Send Text Task", STACK_DISPLAY, NULL, PRIO_DISPLAY, NULL, CORE_SUPPORT);
  static ScanTaskParams scanParams{
      .servo = &servoMotor,
      .us = &ultrasonic
  };
  // xTaskCreatePinnedToCore(scanArea_task, "Scan Area Task", STACK_FSM, &servoMotor, PRIO_FSM, NULL, CORE_REALTIME); I only pass the servoMotor as parameter, but I also need to pass the ultrasonic object to be able to measure the distance in the scanArea_task function. To do this, I will create a struct that contains both the servoMotor and the ultrasonic objects and pass a pointer to this struct as parameter to the scanArea_task function.
  xTaskCreatePinnedToCore(scanArea_task, "Scan Area Task", STACK_FSM, &scanParams, PRIO_FSM, NULL, CORE_REALTIME);
} 

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(LED_PIN, HIGH);
  // delay(100);
  // float distance = ultrasonic.measureDistance();
  // Serial.println(distance);
}
