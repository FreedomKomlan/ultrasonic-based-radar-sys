#pragma once

// Fréquences
#define MEASURE_PERIOD_MS     40   // 25 Hz
#define DISPLAY_PERIOD_MS     80   // 12.5 Hz
#define BUTTONS_PERIOD_MS     20
#define ALERT_PERIOD_MS       50

// Tailles de stack
#define STACK_MEASURE         4096
#define STACK_DISPLAY         4096
#define STACK_BUTTONS         3072
#define STACK_ALERT           3072
#define STACK_FSM             4096

// Priorités
#define PRIO_MEASURE          3
#define PRIO_FSM              2
#define PRIO_BUTTONS          2
#define PRIO_DISPLAY          1
#define PRIO_ALERT            1

// Core
#define CORE_REALTIME         1
#define CORE_SUPPORT          0

// Seuils
#define DIST_THRESHOLD_CM     50   // exemple

// Pins
// Ultrasonic Sensor
#define TRIGGER_PIN           5
#define ECHO_PIN              18
// Servo Motor
#define SERVO_PIN             17
// Buzzer, Buttons, Display, LED
#define BUZZER_PIN            19
#define BUTTON_PIN            21
// #define DISPLAY_SDA_PIN       22
// #define DISPLAY_SCL_PIN       23
#define LED_PIN               23
