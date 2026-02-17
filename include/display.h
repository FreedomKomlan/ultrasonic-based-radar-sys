#ifndef DISPLAY_H
#define DISPLAY_H
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"

void sendTextToDisplay(const char* text);
void homeScreen(void *pvParameters);
void lauchScreen(void *pvParameters);
#endif // DISPLAY_H