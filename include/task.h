#ifndef TASK_H
#define TASK_H
#include "ultrasonic.h"
#include "display.h"
#include "communication.h"
#include "config.h"
#include "alert.h"
#include "my_credentials.h" // Include the credentials header for WiFi SSID and password
extern "C" {
// #include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"   // optional
#include "freertos/semphr.h"  // optional
// #include "driver/gpio.h"
}

struct  ScanTaskParams{
    /* data */
    ServoMotor* servo;
    Ultrasonic* us;
};

void ultrasonicTask(void *pvParameters);
void blink_Led_1_task(void *pvParameters);
void blink_Led_2_task(void *pvParameters);
void sendText_task(void *pvParameters);
// void homeScreen_task(void *pvParameters);
// void launchScreen_task(void *pvParameters);
void scanArea_task(void *pvParameters);
void scanArea_manual_mode_task(void *pvParameters);
#endif // TASK_H

