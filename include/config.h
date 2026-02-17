#pragma once

// Fréquences
#define MEASURE_PERIOD_MS     40   // 25 Hz

#define BUTTONS_PERIOD_MS     20
#define ALERT_PERIOD_MS       50

// Display parameters
#define OLED_RESET_PIN        -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define OLED_I2C_ADDRESS      0x3C // I2C address for the OLED display
#define SCREEN_WIDTH          128 // OLED display width, in pixels
#define SCREEN_HEIGHT         64  // OLED display height, in pixels
#define DISPLAY_PERIOD_MS     80   // 12.5 Hz

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
// Note: Adjust these pin numbers based on your actual hardware connections
// Ultrasonic Sensor
#define TRIGGER_PIN           5
#define ECHO_PIN              18
// Servo Motor
#define SERVO_PIN             2
// Buzzer, Buttons, Display, LED
#define BUTTON_L_PIN          16
#define BUTTON_R_PIN          17
#define DISPLAY_SDA_PIN       21
#define DISPLAY_SCL_PIN       22
#define LED_1_PIN             23
#define LED_2_PIN             19
#define BUZZER_PIN            4
