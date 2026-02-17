#ifndef AlERT_H
#define ALERT_H
#include <Arduino.h>
#include "config.h"
void alert(void *pvParameters);
void blink_Led(int ledPin, int durationMs, int delayMs);
void buzz(void *pvParameters);

#endif // ALERT_H