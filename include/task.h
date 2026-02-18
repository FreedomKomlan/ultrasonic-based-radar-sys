#ifndef TASK_H
#define TASK_H
extern "C" {
// #include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"   // optional
#include "freertos/semphr.h"  // optional
// #include "driver/gpio.h"
}

void ultrasonicTask(void *pvParameters);
void blink_Led_1_task(void *pvParameters);
void blink_Led_2_task(void *pvParameters);
void sendText_task(void *pvParameters);
// void homeScreen_task(void *pvParameters);
// void launchScreen_task(void *pvParameters);
#endif // TASK_H

