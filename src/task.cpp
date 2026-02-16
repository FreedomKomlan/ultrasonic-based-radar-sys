#include "ultrasonic.h"
#include "task.h"


void ultrasonicTask(void *pvParameters) {
    Ultrasonic *ultrasonic = static_cast<Ultrasonic *>(pvParameters);
    // Ultrasonic ultrasonic;

    while (true) {
        float distance = ultrasonic->measureDistance();
        Serial.println(distance);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
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