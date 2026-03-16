#include "task.h"
#include "ultrasonic.h"
#include "display.h"

// SETTINGS AND CONFIGURATION TASKS


// BOOT - 


// OPERATIONAL MODE TASKS

void ultrasonicTask(void *pvParameters) {
    Ultrasonic *ultrasonic = static_cast<Ultrasonic *>(pvParameters);
    // Ultrasonic ultrasonic;

    while (true) {
        float distance = ultrasonic->measureDistance();
        Serial.print("Distance: ");
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

static void waitServoArrival(ServoMotor* servo, int targetAngle) {
    const int initialAngle = servo->getAngle(); // Get the current angle of the servo
    const int angleDifference = abs(targetAngle - initialAngle); // Calculate the difference in angle
    const float t_move_s = (angleDifference / 60.0f) * SERVO_T60_S * SAFETY_MARGIN_S_FACTOR; // Calculate the time needed to move to the new angle with a safety margin
    const uint32_t t_move_ms = (uint32_t)(t_move_s * 1000.0f); // Convert time to milliseconds
    vTaskDelay(t_move_ms / portTICK_PERIOD_MS); // Delay to allow servo to reach the position
}
void scanArea_task(void *pvParameters) {
    auto* p = static_cast<ScanTaskParams*>(pvParameters); 
    // ServoMotor *servoMotor = static_cast<ServoMotor *>(pvParameters);
    // Ultrasonic *ultrasonic = static_cast<Ultrasonic *>(pvParameters);
    ServoMotor* servoMotor = p->servo;
    Ultrasonic* ultrasonic = p->us;

    float in_distance;
    // ServoMotor servoMotor;
    while (true) {
        for (int angle = ZONE_ANGLE_THRESHOLD_MIN_PRESET_DEG; angle <= ZONE_ANGLE_THRESHOLD_MAX_PRESET_DEG; angle += 1) {
            servoMotor->setAngle(angle);
            waitServoArrival(servoMotor, angle);
            int actualAngle = servoMotor->getAngle();
            in_distance = ultrasonic->measureDistance();
            String text_to_send_screen = "Angle: " + String(actualAngle) + " deg" + "\nDist. objet: " + String(in_distance) + " " + UNIT_DISTANCE;
            // String text_to_send_screen = "Angle: " + String(actualAngle) + " deg";
            sendTextToDisplay(text_to_send_screen.c_str());
            vTaskDelay(200 / portTICK_PERIOD_MS); // Delay to read the angle on the display before moving to the next one
        }
        for (int angle = ZONE_ANGLE_THRESHOLD_MAX_PRESET_DEG; angle >= ZONE_ANGLE_THRESHOLD_MIN_PRESET_DEG; angle -= 1) {
            servoMotor->setAngle(angle);
            waitServoArrival(servoMotor, angle);
            int actualAngle = servoMotor->getAngle();
            in_distance = ultrasonic->measureDistance();
            String text_to_send_screen = "Angle: " + String(actualAngle) + " deg" + "\nDist. objet: " + String(in_distance) + " " + UNIT_DISTANCE;
            // String text_to_send_screen = "Angle: " + String(actualAngle) + " deg";
            sendTextToDisplay(text_to_send_screen.c_str());
            vTaskDelay(200 / portTICK_PERIOD_MS); // Delay to read the angle on the display before moving to the next one
        }
    }
}

void scanArea_manual_mode_task(void *pvParameters){

}