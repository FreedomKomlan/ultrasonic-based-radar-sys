#include "task.h"
#include "ultrasonic.h"
#include "display.h"


void ultrasonicTask(void *pvParameters) {
    Ultrasonic *ultrasonic = static_cast<Ultrasonic *>(pvParameters);
    // Ultrasonic ultrasonic;

    while (true) {
        float distance = ultrasonic->measureDistance();
        Serial.println(distance);
        vTaskDelay(400 / portTICK_PERIOD_MS); // Delay for 1 second
    }
}

void blink_Led_1_task(void *pvParameters) {
    while (true) {
        digitalWrite(LED_1_PIN, HIGH);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Delay for 500 ms
        digitalWrite(LED_1_PIN, LOW);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Delay for 500 ms
    }
}

void blink_Led_2_task(void *pvParameters) {
    while (true) {
        digitalWrite(LED_2_PIN, HIGH);
        vTaskDelay(200 / portTICK_PERIOD_MS); // Delay for 200 ms
        digitalWrite(LED_2_PIN, LOW);
        vTaskDelay(200 / portTICK_PERIOD_MS); // Delay for 200 ms
    }
}

void sendText_task(void *pvParameters) {
    while (true) {
        sendTextToDisplay("Hello, World!");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
    }
}

void scanArea_task(void *pvParameters) {
    ServoMotor *servoMotor = static_cast<ServoMotor *>(pvParameters);
    // ServoMotor servoMotor;
    while (true) {
        for (int angle = ZONE_ANGLE_THRESHOLD_MIN_PRESET_DEG; angle <= ZONE_ANGLE_THRESHOLD_MAX_PRESET_DEG; angle += 5) {
            servoMotor->setAngle(angle);
            int actualAngle = servoMotor->getAngle();
            String text_to_send_screen = "Angle: " + String(actualAngle) + " deg";
            sendTextToDisplay(text_to_send_screen.c_str());
        }
        for (int angle = ZONE_ANGLE_THRESHOLD_MAX_PRESET_DEG; angle >= ZONE_ANGLE_THRESHOLD_MIN_PRESET_DEG; angle -= 5) {
            servoMotor->setAngle(angle);
            int actualAngle = servoMotor->getAngle();
            String text_to_send_screen = "Angle: " + String(actualAngle) + " deg";
            sendTextToDisplay(text_to_send_screen.c_str());
        }
    }
}