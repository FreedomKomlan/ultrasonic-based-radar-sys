#ifndef DISPLAY_H
#define DISPLAY_H
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"

extern Adafruit_SSD1306 display;

void initDisplay();
void sendDataToSerial(const int angle, const float distance);
void sendTextToDisplay(const char* text);
void startingScreen(void *pvParameters);
void homeScreen(void *pvParameters);
void lauchScreen(void *pvParameters);
#endif // DISPLAY_H